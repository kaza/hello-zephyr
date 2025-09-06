#include <zephyr/kernel.h>
#include <stdio.h>

int main(void)
{
    printf("Hello World! %s\n", CONFIG_BOARD);
    
    while (1) {
        printf("Running on Zephyr %d.%d.%d\n", 
               SYS_KERNEL_VER_MAJOR(KERNEL_VERSION_NUMBER),
               SYS_KERNEL_VER_MINOR(KERNEL_VERSION_NUMBER),
               SYS_KERNEL_VER_PATCHLEVEL(KERNEL_VERSION_NUMBER));
        k_sleep(K_SECONDS(2));
    }
    
    return 0;
}