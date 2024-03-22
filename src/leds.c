/**
 * Archivo: leds.c
 *
 * Descrip.: Archivo contenedor de def. funciones para controlar un array de 16 leds.
 *
 * Autor: Estanislao Crivos
 */

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Private variable declarations =========================================================== */

static uint16_t * puntero;

/* === Public function implementation ========================================================= */

void leds_init(uint16_t * puerto) {
    puntero = puerto;
    *puerto = 0;
    return;
}

void leds_turn_on(int led) {
    *puntero |= selected_led_set_high_array;
}

void leds_turn_off(int led) {
    *puntero &= ~selected_led_set_high_array;
}

int led_status(int led) {
    if ((*puntero & selected_led_set_high_array) != 0) {
        return 1;
    } else {
        return 0;
    }
}
