#include "door.h"
#include "elev.h"

#include <time.h>

clock_t before;


void door_open(){
    elev_set_door_open_lamp(1);
}


void door_close(){
    elev_set_door_open_lamp(0);
}


void set_time_before( clock_t time){
    before = time; 
}


clock_t get_time_before(){
    return before;
}


int sec_difference(){
    int trigger = 2;//den skal være to 
    clock_t difference = clock() - get_time_before();
    int sec_difference = difference/CLOCKS_PER_SEC;
    if(sec_difference > trigger){
        return 1;
    }
    return 0; 
}
