#include "elev.h"
#include "init.h"



void initialize_start(){
    while(elev_get_floor_sensor_signal() < 0 ){
        elev_set_motor_direction(-1);
    }
    elev_set_motor_direction(0);    

}
