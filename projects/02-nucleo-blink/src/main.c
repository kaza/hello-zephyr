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
    printk("Speed ramp: 2000ms -> 10ms -> 2000ms\n");

    int delay_ms = 2000;
    int direction = -1;  /* -1 = speeding up, 1 = slowing down */
    
    while (1) {
        gpio_pin_set_dt(&led, led_state);
        printk("LED: %s (delay: %dms)\n", led_state ? "ON" : "OFF", delay_ms);
        led_state = !led_state;
        
        /* Adjust speed by 10% */
        if (direction == -1) {
            delay_ms = delay_ms * 90 / 100;  /* Speed up by 10% */
            if (delay_ms <= 10) {
                delay_ms = 10;
                direction = 1;  /* Start slowing down */
                printk("=== FASTEST! Now slowing down ===\n");
            }
        } else {
            delay_ms = delay_ms * 110 / 100;  /* Slow down by 10% */
            if (delay_ms >= 2000) {
                delay_ms = 2000;
                direction = -1;  /* Start speeding up */
                printk("=== SLOWEST! Now speeding up ===\n");
            }
        }
        
        k_msleep(delay_ms);
    }

    return 0;
}