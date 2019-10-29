#include "elev.h"
#include "init.h"
#include "door.h"
#include "queue.h"
#include "stop.h"
#include "lights.h"


#include <stdio.h>



enum states{
    INIT,
    RUNNING,
    IDLE,
    EMERGENCYSTOP,
    DOOR
};



//dddf
int main() {
    //Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }


   int state = INIT;
    while(1){
        switch (state) {
            case INIT:
                initialize_start();
                state = IDLE;
            break;
            case IDLE:
                update_queue();
                set_floor_lights();
                set_order_lights_on();
                to_running_from_floor();
                to_running_between_floors();

                if(get_stop()){
                    state=EMERGENCYSTOP;
                }
                if(check_order_at_floor()){
                    state = DOOR;
                }
                if(get_motor_direction_indicator()!=0){
                    state = RUNNING;
                }
                break;
            case RUNNING:
                update_queue();
                set_floor_lights();
                set_order_lights_on();
                set_above_which_floor();

                if(get_stop()){
                    state=EMERGENCYSTOP;
                }
                if(check_if_correct_floor()){
                    elev_set_motor_direction(0);
                    set_time_before(clock());
                    state=DOOR; 
                }
                break;
            case DOOR:
                door_open();
                update_queue();
                //set_floor_lights();
                set_order_lights_on();

                if(check_order_at_floor()){
                    set_time_before(clock());
                }

                queue_erase_floor_buttons();
                set_order_lights_off_current_floor();
                
                if(get_stop()){
                    state=EMERGENCYSTOP;
                }
                if(sec_difference()){
                    door_close();
                    update_motor_direction_indicator();
                    if(get_motor_direction_indicator()==0){
                        state = IDLE;
                    }
                    if(get_motor_direction_indicator()!=0){
                        elev_set_motor_direction(get_motor_direction_indicator());
                        state=RUNNING;
                    }
                }
                break;
            case EMERGENCYSTOP:
                set_stop_lamp();
                elev_set_motor_direction(0);
                set_motor_direction_indicator(0);

                if(elev_get_floor_sensor_signal()!=-1){
                    if(get_stop()){
                        erase_all_buttons();
                        set_all_order_lights_off();
                        door_open();
                        set_time_before(clock());
                    }
                    if(!get_stop()){
                        set_stop_lamp();
                        state=DOOR;
                    }
                }
                if(elev_get_floor_sensor_signal()==-1){
                    if(get_stop()){
                        erase_all_buttons();
                        set_all_order_lights_off();
                    }
                    if(!get_stop()){
                        set_stop_lamp();
                        state = IDLE;
                    }
                }
                break;
        }
    }
}
