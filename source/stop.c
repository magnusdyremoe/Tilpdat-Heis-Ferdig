#include "stop.h"
#include "elev.h"





int get_stop(){
    return elev_get_stop_signal();
}

void set_stop_lamp(){
    elev_set_stop_lamp(get_stop());
}

