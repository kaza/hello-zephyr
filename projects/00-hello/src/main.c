#include <zephyr/kernel.h>
#include <stdio.h>

int main(void)
{
    printf("=== Zebra'S ZEPHYR PROJECT ===\n");
    printf("Board: %s\n", CONFIG_BOARD);
    
    for (int i = 1; i <= 10; i++) {
        printf("[%d] Hello zebrasaurus! Time: %d seconds\n", 
               i, i * 2);
        k_sleep(K_SECONDS(2));
    }
    
    printf("Program finished! Total runtime: 20 seconds\n");
    
    return 0;
}