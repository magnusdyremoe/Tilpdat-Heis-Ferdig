
/**
 * @file
 * @brief Modulen skrur av og på alle etasje lys, ordre lys
 **/



/**
 * @brief Funksjonen sjekker hvilket etasje heisen er i og setter på etasjetlyset for etasjen. 
 * Hvis heisen er mellom etasjer setter etasjelyset for siste etasjen heisen var i.  
 */
void set_floor_lights();


/**
 * @brief Funksjonen sjekker hvilke ordre har blitt bestilt og setter på lyset for den orderen
 */
void set_order_lights_on();


/**
 * @brief Funksjonen slår av alle ordrelys i den etasjen heisen befinner seg i.
 */
void set_order_lights_off_current_floor();



/**
 * @brief Funksjonen slår av alle ordrelys i alle etasjer
 */
void set_all_order_lights_off();



