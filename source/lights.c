#include "lights.h"
#include "elev.h"


void set_floor_lights(){
    int floor = elev_get_floor_sensor_signal();
    if(floor!=-1){
         elev_set_floor_indicator(floor);
    }
}


void set_order_lights_on(){
    for(int floor = 0; floor < 4; floor ++){
        for (int button = 0; button < 3; button++){
            if (!(floor==0 && button==1)){
                if(!(floor==3 && button==0)){
                    if(elev_get_button_signal(button, floor)){
                        elev_set_button_lamp(button, floor, 1);

                    }
                }
            }
        }
    }
}


void set_order_lights_off_current_floor(){
    int floor = elev_get_floor_sensor_signal();
    if(0 < floor && floor < 3 ){
        for(int button = 0; button < 3; button ++ ){
            elev_set_button_lamp(button, floor, 0);
        }
    }
    if(floor==0){
        elev_set_button_lamp(0, floor, 0);
        elev_set_button_lamp(2, floor, 0);
    }    
    if(floor== 3){
        for(int button = 1; button < 3; button ++){
            elev_set_button_lamp(button, floor, 0);
        }
    }
}


void set_all_order_lights_off(){
    for (int floor = 0 ; floor < 4; floor++){
        for (int button = 0; button < 3; button ++){
            if(!(floor ==  3 && button == 0)){
                if(!(floor == 0 && button == 1)){
                    elev_set_button_lamp(button, floor, 0);
                }
            }
        }
    }
}




