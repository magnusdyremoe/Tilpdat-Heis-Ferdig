

/**
 * @file
 * @brief Modulen tar alle bestillinger, oppdaterer alle bestillinger. Holder 
 * styr på hvilke retning motoren skal kjøre før, under og etter at en bestilling er utført
 **/




#ifndef MEMORY_QUEUE_H
#define MEMORY_QUEUE_H



/**
 * @brief Funksjonen sjekker om noen bestillinger er gjort over gitte etasje.
 * @param[in] sensor det er gitte etasje.
 * @return returnerer 1 om en ordre er gjort over gitte etasje.
 * Ellers retunrer 0.
 */
int queue_check_above(int sensor);

/**
 * @brief Funksjonen sjekker om noen bestillinger er gjort under gitte etasje.
 * @param[in] sensor det er gitte etasje.
 * @return returnerer 1 om en ordre er gjort under gitte etasje.
 * Ellers retunrer 0.
 */
int queue_check_below(int sensor);


/**
 * @brief Funksjonen antar at heisen er i en etasje og ingen bestillinger har blitt gjort tidligere. 
 * Funksjonen bestemmer hvilke retning heisen skal kjøre og setter motorpådraget i riktig retning.
 */
void to_running_from_floor();

/**
 * @brief Funksjonen antar at heisen er mellom to etasjer og ingen bestillinger har blitt gjort tidligere. 
 * Funksjonen bestemmer hvilke retning heisen skal kjøre og setter motorpådraget i riktig retning.
 */
void to_running_between_floors();



/**
 * @brief Funksjonen sjekker om flere enn to bestillinger er gjort i gitte etassje
 * @param[in] floor Gitte etasje
 * @return Returnerer 1 om to bestillinger er gjort. Eller returnerer den 0. 
 */
int check_if_two_buttons_at_given_floor_is_pressed(int floor);


/**
 * @brief Funksjonen tar og oppdaterer alle bestillinger. 
 */
void update_queue();


/**
 * @brief Funksjonen sletter alle utførte bestillinger. 
 */
void queue_erase_floor_buttons();


/**
 * @brief Funksjonen sjekker om det er lagret noen bestillinger. 
 * @return Returnerer 1 om det er lagret bestillinger. Ellers returnerer den 0.
 */
int  check_for_saved_orders();


/**
 * @brief Funksjoen returner variabelen motor_direction_indicator.
 * @return Funksjoen returner variabelen motor_direction_indicator.
 */
int get_motor_direction_indicator();



int command_button__at_floor();

int down_buttton_at_floor();

int up_buttton_at_floor();


/**
 * @brief Funksjonen sjekker om heisen er i en etasje det er gjort bestilling til.
 * @return Returnerer 1 om heisen skal stoppet. Ellers 0.
 */
int check_if_correct_floor();


void update_motor_direction_indicator();

/**
 * @brief Funksjoen sletter alle bestilligner lagret. 
 */
void erase_all_buttons();


/**
 * @brief Funksjoen tilegner variablene motor_direction_indicator til variablen value
 * @param[in] value verdien motor_direction_indicator skal få.
 */
void set_motor_direction_indicator(int value);


int check_order_at_floor();


void set_above_which_floor();

int get_above_which_floor();

#endif