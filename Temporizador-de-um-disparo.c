#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define PIN_LED_BLUE 11
#define PIN_LED_RED 12
#define PIN_LED_GREEN 13
#define PIN_BUTTON 5

// Estados dos LEDs
bool leds_running = false;
int led_state = 0;  // 0 = Todos acesos, 1 = Azul apagado, 2 = Vermelho apagado, 3 = Verde apagado (fim)

// Callback para desligar LEDs progressivamente
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if (led_state == 0) {
        gpio_put(PIN_LED_BLUE, 0);   // Apaga o LED azul primeiro
    } else if (led_state == 1) {
        gpio_put(PIN_LED_RED, 0);    // Apaga o LED vermelho
    } else if (led_state == 2) {
        gpio_put(PIN_LED_GREEN, 0);  // Apaga o LED verde
        leds_running = false;  // Libera o botão para nova ativação
        led_state = 0;  // Reinicia o estado para a próxima ativação
        return 0;
    }
    
    led_state++;  // Avança para o próximo estágio
    add_alarm_in_ms(3000, turn_off_callback, NULL, false);  // Chama novamente após 3s

    return 0;
}

int main() {
    stdio_init_all();

    gpio_init(PIN_LED_BLUE);
    gpio_init(PIN_LED_RED);
    gpio_init(PIN_LED_GREEN);
    gpio_set_dir(PIN_LED_BLUE, GPIO_OUT);
    gpio_set_dir(PIN_LED_RED, GPIO_OUT);
    gpio_set_dir(PIN_LED_GREEN, GPIO_OUT);

    gpio_init(PIN_BUTTON);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);
    gpio_pull_up(PIN_BUTTON);

    while (true) {
        if (gpio_get(PIN_BUTTON) == 0 && !leds_running) {
            sleep_ms(50);  // Debounce
            if (gpio_get(PIN_BUTTON) == 0) {  // Confirma o clique
                // Liga todos os LEDs
                gpio_put(PIN_LED_BLUE, 1);
                gpio_put(PIN_LED_RED, 1);
                gpio_put(PIN_LED_GREEN, 1);
                leds_running = true;
                led_state = 0;

                // Inicia o processo de desligamento
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }
        sleep_ms(10);
    }
}
