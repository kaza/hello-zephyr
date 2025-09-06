#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    LOG_INF("Hello Zephyr! Starting application...");
    
    printk("Hello World from Zephyr RTOS!\n");
    printk("Board: %s\n", CONFIG_BOARD);
    
    int counter = 0;
    
    while (1) {
        LOG_INF("Counter: %d", counter++);
        k_msleep(1000);
    }
    
    return 0;
}