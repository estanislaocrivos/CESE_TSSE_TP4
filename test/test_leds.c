/**
 * Archivo: test_leds.c
 *
 * Descrip.: Archivo contenedor de tests para probar las funciones de la libreria leds.h
 *
 * Autor: Estanislao Crivos
 */

// This is a modification... another modification...

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "leds.h"

/* === Public variable definitions ============================================================= */

static uint16_t leds_virtuales;
static const int LED = 3;

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */

void setUp(void)
{
    leds_init(&leds_virtuales);
}

/**
 * Descrip. del test: al iniciar el controlador los leds deben quedar
 * todos los bits en 0 sin importar el estado anterior.
 */
void test_todos_los_leds_deben_estar_apagados_al_iniciar_el_driver(void)
{
    TEST_ASSERT_EQUAL_UINT16(0x0000, leds_virtuales);
}

/**
 * Descrip. del test: con todos los leds apagados prender el led 3 y verificar que efectivamente el
 * bit 2 se pone en 1 y el resto de bit permanece en 0.
 */
void test_prender_un_led(void)
{
    leds_turn_on(LED);

    TEST_ASSERT_BIT_HIGH(
        LED - 1,
        leds_virtuales); // Verifica que el LED 3 (pos. 2 en el arreglo de bits) este en alto

    TEST_ASSERT_EQUAL_UINT16(0b0000000000000100,
                             leds_virtuales); // Verifica que solo el LED 3 este prendido
}

/**
 * Descrip. del test: apagar un led prendido y ver que efectivamente se apaga y que el resto no
 * cambia.
 */
void test_apagar_un_led(void)
{
    leds_turn_on(4);

    leds_turn_on(5);

    leds_turn_off(5);

    TEST_ASSERT_EQUAL_UINT16(0b0000000000001000, leds_virtuales);
}

/**
 * Descrip. del test: con todos los leds apagados prender un led
 * y verificar que al consultar el estado del mismo me informa que esta prendido.
 */
void test_prender_led_y_verificar_estado(void)
{
    leds_turn_on(7);

    TEST_ASSERT_EQUAL_INT(1, led_status(7));
}

/**
 * Descrip. del test: prender todos los leds que estan apagados antes de la operación
 */
void test_prender_leds_apagados(void)
{
    leds_turn_all_off();

    leds_turn_all_on();

    TEST_ASSERT_EQUAL_UINT16(0xFFFF, leds_virtuales);
}

/**
 * Descrip. del test: apagar todos los leds que estan prendidos antes de la operación
 */
void test_apagar_leds_prendidos(void)
{
    leds_turn_all_on();

    leds_turn_all_off();

    TEST_ASSERT_EQUAL_UINT16(0x0000, leds_virtuales);
}

/**
 * Descrip. del test: consultar el estado de un led.
 */
void test_consultar_estado_de_led(void)
{
    leds_turn_all_off();

    leds_turn_on(7);

    TEST_ASSERT_EQUAL_INT(1, led_status(7));

    TEST_ASSERT_EQUAL_INT(0, led_status(6));
}
