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

void leds_init(uint16_t * puerto)
{
    puntero = puerto;
    *puerto = 0;
    return;
}

/* ============================================================================================ */

void leds_turn_on(int led)
{
    *puntero |= Convert_LED_to_BIT(led);
}

/* ============================================================================================ */

void leds_turn_off(int led)
{
    *puntero &= ~Convert_LED_to_BIT(led);
}

/* ============================================================================================ */

int led_status(int led)
{
    return ((*puntero & Convert_LED_to_BIT(led)) != 0);
}

/* ============================================================================================ */

void leds_turn_all_off(void)
{
    *puntero &= 0x0000;
}

/* ============================================================================================ */

void leds_turn_all_on(void)
{
    *puntero |= 0xFFFF;
}

/* ============================================================================================ */
