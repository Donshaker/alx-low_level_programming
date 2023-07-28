#include <stdio.h>

extern void custom_printf(); // Assembly function declaration

int main(void) {
    custom_printf();
    return 0;
}

