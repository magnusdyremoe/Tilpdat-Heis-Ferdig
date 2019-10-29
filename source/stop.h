
/**
 * @file
 * @brief Modulen håndeter stopp lampen og holder oversikt om stoppknappen har blitt trykket.
 **/




/**
 * @brief Funksjonen sjekker om stoppknappen er trykket. 
 * @return Returnerer 1 om den er trykket, returnerer 0 ellers
 */
int get_stop();



/**
 * @brief Funksjonen setter på stopp lyset bare hvis stoppknappen er trykket. Funksjonen slår av stopplyset om stoppknappen ikke er trykket.
 */
void set_stop_lamp();
