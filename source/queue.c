#include "elev.h"
#include "queue.h"

#include <stdlib.h>

/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
*/


int queue[4];

int motor_direction_indicator = 0;

int above_floor;

int queue_check_above(int sensor){
    for(int floor = 0; floor < 4; floor++){
        if(0 < queue[floor]){
            if(sensor < floor){
                return 1;
            }
        }
    }
    return 0;
}

int queue_check_below(int sensor){
    for(int etasje = 0; etasje < 4; etasje++){
        if(0 < queue[etasje]){
            if(etasje < sensor){
                return 1;
            }
        }
    }
    return 0;
}

int check_if_two_buttons_at_given_floor_is_pressed(int floor){
    for(int button = 0; button < 3; button++){
        if (!(floor==0 && button==1)){
            if(!(floor==3 && button==0)){
                if(elev_get_button_signal(button, floor)){
                    if(queue[floor]-1 !=button){
                        if(queue[floor]!=0){
                            return 1;
                        }
                    }
                }
            }
        }

    }

    return 0;
}

void erase_all_buttons(){
    for(int floor = 0; floor < 4; floor++){
        queue[floor] = 0;
    }
}


void queue_erase_floor_buttons(){
    int floor=elev_get_floor_sensor_signal();
    if(floor>-1){
        queue[floor] = 0;
    }
}

int check_for_saved_orders(){
    int orders = 0;
    for(int floor = 0; floor < 4; floor++){
        if(queue[floor] > 0){
            orders=orders+1;
        }
    }
    return orders;

}

int get_motor_direction_indicator(){
    return motor_direction_indicator;
}

void set_motor_direction_indicator( int value){
    motor_direction_indicator = value;
}


int command_button__at_floor() {
    for (int floor = 0; floor < 4; floor++){
        if(queue[floor]==3){
            if(floor==elev_get_floor_sensor_signal()){
                return 1;
            }
        }
    }
    return 0;
}

int down_buttton_at_floor(){
    for(int floor = 0; floor < 4; floor++){
        if(queue[floor]==2){
            if(floor==elev_get_floor_sensor_signal()){
                return 1;
            }
        }
    }
    return 0;
}

int up_buttton_at_floor(){
    for(int floor = 0; floor < 4; floor++){
        if(queue[floor]==1){
            if(floor==elev_get_floor_sensor_signal()){
                return 1;
            }
        }
    }
    return 0;
}


void update_motor_direction_indicator(){
    if(check_for_saved_orders()==0){
        set_motor_direction_indicator(0);
    }
    if(queue_check_above(elev_get_floor_sensor_signal()) && !queue_check_below(elev_get_floor_sensor_signal())){
            set_motor_direction_indicator(1);
            }
    if(!queue_check_above(elev_get_floor_sensor_signal()) && queue_check_below(elev_get_floor_sensor_signal())){
            set_motor_direction_indicator(-1);
        }
}


void to_running_from_floor(){
    if(elev_get_floor_sensor_signal()!=-1){
        if(queue_check_above(elev_get_floor_sensor_signal())){
            elev_set_motor_direction(1);
            set_motor_direction_indicator(1);
        }
        if(queue_check_below(elev_get_floor_sensor_signal())){
            elev_set_motor_direction(-1);
            set_motor_direction_indicator(-1);
        }
        if(queue_check_above(elev_get_floor_sensor_signal())==0 && queue_check_below(elev_get_floor_sensor_signal())==0){
            elev_set_motor_direction(0);
            set_motor_direction_indicator( 0);
        }
    }
}

void to_running_between_floors(){
    if(elev_get_floor_sensor_signal()==-1){
        if(queue_check_above(get_above_which_floor())){
            elev_set_motor_direction(1);
            set_motor_direction_indicator(1);
        }
        if(queue_check_below(get_above_which_floor())){
            elev_set_motor_direction(-1);
            set_motor_direction_indicator(-1);
        }
        if(queue[get_above_which_floor()] > 0){
            elev_set_motor_direction(-1);
            set_motor_direction_indicator(-1);
        }
    }
}

void set_above_which_floor(){
    if(elev_get_floor_sensor_signal()!=-1){
        if(get_motor_direction_indicator()==1){
            above_floor=elev_get_floor_sensor_signal();
        }
        if(get_motor_direction_indicator()==-1){
            above_floor=elev_get_floor_sensor_signal()-1;
        }
    }
}


int get_above_which_floor(){
    return above_floor;
}


void update_queue(){
    for( int floor = 0; floor < 4; floor++){
        if(check_if_two_buttons_at_given_floor_is_pressed(floor)){
             queue[floor]=2;
         }
    }
    for(int floor = 0; floor <4; floor++){
        for(int button = 0; button < 3; button ++){
            if(queue[floor]==0){
                if (!(floor==0 && button==1)){
                    if(!(floor==3 && button==0)){
                        if(elev_get_button_signal(button, floor)){
                            queue[floor]=button+1;
                        }
                    }

                }

            }
        }
    }
}


int check_if_correct_floor(){
    if(command_button__at_floor()){
        return 1;
    }
    if(get_motor_direction_indicator()==-1){
        if(down_buttton_at_floor()){
            return 1;
        }
        if(up_buttton_at_floor()){
            if(!queue_check_below(elev_get_floor_sensor_signal())){
                return 1;
            }
        }
    }

    if(get_motor_direction_indicator()==1){
        if(up_buttton_at_floor()){
            return 1;
            }
        if(down_buttton_at_floor()){
            if(!queue_check_above(elev_get_floor_sensor_signal())){
                return 1;
            }
        }
    }
    return 0;
}




int check_order_at_floor(){
    for (int floor = 0; floor < 4; floor++){
        if(queue[floor] > 0){
            if(elev_get_floor_sensor_signal()==floor){
                return 1;
            }
        }
    }
    return 0;
}
