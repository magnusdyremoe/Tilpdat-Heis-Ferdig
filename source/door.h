#include <time.h>

/**
 * @file
 * @brief Modulen håndterer døren. Starter timer fra når døren åpnes.
 **/



#ifndef MEMORY_DOOR_H
#define MEMORY_DOOR_H


/**
 * @brief Funksjonen slår på dørlyset.
 */

void door_open();


/**
 * @brief Funksjonen slår av dørlyset.
 */
void door_close();


/**
 * @brief Funksjonen starter en timer når funksjonen blir kalt.
 * @param[in] time Variablen tilegnes tidspunktet funksjonen blir kalt.
 */
void set_time_before( clock_t time);


/**
 * @brief Funksjonen returnerer variabelen time. 
 * @return variablen before.
 */
clock_t get_time_before();


/**
 * @brief Funksjonen sammenligner tiden nå med tiden som er lagret i variabelen before.
 * @return 1 hvis tidsdifferansen er over 3 sekunder, ellers returnerer den 0. 
 */
int sec_difference();



#endif

