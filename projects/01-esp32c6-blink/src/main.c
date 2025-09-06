#include <zephyr/kernel.h>

int main(void)
{
    int counter = 0;
    
    /* Super simple - just print numbers every second */
    while (1) {
        printk("TEST %d\n", counter);
        counter++;
        k_msleep(1000);
    }
    
    return 0;
}