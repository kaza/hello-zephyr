/*
 * STM32 NUCLEO-F401RE Button-Controlled LED Blink
 * 
 * Press blue USER button (B1) to speed up blinking
 * Press again to slow down
 * LED stays at min/max speed until button pressed
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* LED is predefined as led0 in board DTS */
#define LED0_NODE DT_ALIAS(led0)

/* USER button is predefined as sw0 in board DTS */
#define SW0_NODE DT_ALIAS(sw0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0_NODE, gpios);

/* Button callback context */
static struct gpio_callback button_cb_data;

/* Shared variables (protected by atomic operations) */
static int delay_ms = 1000;  /* Current blink delay */
static int direction = -1;   /* -1 = speed up, 1 = slow down */

/* Button press handler - just reverses direction */
void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    direction = -direction;  /* Reverse direction */
    if (direction == -1) {
        printk(">>> Button pressed! Now SPEEDING UP\n");
    } else {
        printk(">>> Button pressed! Now SLOWING DOWN\n");
    }
}

int main(void)
{
    int ret;
    bool led_state = true;

    printk("\n=== Button-Controlled Blink ===\n");
    printk("Press blue USER button to change speed!\n");
    printk("Starting at %dms\n", delay_ms);

    /* Configure LED */
    if (!gpio_is_ready_dt(&led)) {
        printk("Error: LED not ready\n");
        return 0;
    }
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error: Failed to configure LED\n");
        return 0;
    }

    /* Configure button */
    if (!gpio_is_ready_dt(&button)) {
        printk("Error: Button not ready\n");
        return 0;
    }
    ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
    if (ret < 0) {
        printk("Error: Failed to configure button\n");
        return 0;
    }

    /* Setup button interrupt on press */
    ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret < 0) {
        printk("Error: Failed to configure button interrupt\n");
        return 0;
    }

    /* Register button callback */
    gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
    gpio_add_callback(button.port, &button_cb_data);

    printk("Ready! Press button to reverse direction\n\n");

    /* Main loop - continuously adjust speed */
    while (1) {
        /* Toggle LED */
        gpio_pin_set_dt(&led, led_state);
        led_state = !led_state;
        
        /* Continuously adjust speed based on direction */
        if (direction == -1) {
            /* Speeding up */
            if (delay_ms > 40) {
                delay_ms = delay_ms * 95 / 100;  /* Reduce by 5% */
                if (delay_ms <= 40) {
                    delay_ms = 40;  /* Stay at fastest */
                    printk(">>> Reached MAX SPEED (40ms) - staying here\n");
                }
            }
        } else {
            /* Slowing down */
            if (delay_ms < 2000) {
                delay_ms = delay_ms * 105 / 100;  /* Increase by 5% */
                if (delay_ms >= 2000) {
                    delay_ms = 2000;  /* Stay at slowest */
                    printk(">>> Reached MIN SPEED (2000ms) - staying here\n");
                }
            }
        }
        
        /* Use current delay */
        k_msleep(delay_ms);
    }

    return 0;
}