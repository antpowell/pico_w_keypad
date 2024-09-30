#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define GPIO_LED_PIN 25

#define GPIO_ON 1
#define GPIO_OFF 0


int main()
{
    stdio_init_all();

    gpio_init(GPIO_LED_PIN);
    gpio_set_dir(GPIO_LED_PIN, GPIO_OUT);

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // Example to turn on the Pico W LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);

        gpio_put(GPIO_LED_PIN, GPIO_ON);
        sleep_ms(200);
        gpio_put(GPIO_LED_PIN, GPIO_OFF);
        sleep_ms(200);
    }
}
