/*
 * STM32 NUCLEO-F401RE LED Blink
 * 
 * The Nucleo board has a built-in green LED (LD2) connected to PA5
 * This LED is predefined in the board's device tree as "led0"
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* The Nucleo board has led0 alias already defined! */
#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
    int ret;
    bool led_state = true;

    printk("===Zebra STM32 NUCLEO-F401RE Blink ===\n");
    printk("Board name of this zebra: %s\n", CONFIG_BOARD);

    if (!gpio_is_ready_dt(&led)) {
        printk("Error: LED device not ready\n");
        return 0;
    }

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error: Failed to configure LED pin\n");
        return 0;
    }

    printk("LED Blink Started! Watch the green LED (LD2)!\n");

    while (1) {
        gpio_pin_set_dt(&led, led_state);
        printk("LED: %s\n", led_state ? "ON" : "OFF");
        led_state = !led_state;
        k_msleep(1000);
    }

    return 0;
}