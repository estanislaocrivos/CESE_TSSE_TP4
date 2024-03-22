/**
 * Archivo: leds.h
 *
 * Descrip.: Archivo contenedor de dec. funciones para controlar un array de 16 leds.
 *
 * Autor: Estanislao Crivos
 */

/* === Headers files inclusions =============================================================== */

#include <stdint.h>

#define selected_led_set_high_array (uint16_t)(1 << (led - 1))

/* === Public function declarations ============================================================ */

/**
 * Esta funcion inicializa el arreglo de LEDS en cero.
 */
void leds_init(uint16_t * puerto);

/**
 * Esta funcion pone en alto el LED indicado en led
 */
void leds_turn_on(int led);

/**
 * Esta funcion pone en bajo el LED indicado en led
 */
void leds_turn_off(int led);

/**
 * Esta funcion devuelve 1 si el estado del led indicado en led es alto. Sino, devuelve 0.
 */
int led_status(int led);
