#include "debugger.h"
void print_binary(int n) {
    // Assuming int is 16 bits
    for (int i = 2 * 8 - 1; i >= 0; i--) {
        // Print either 1 or 0 depending on the bit at position i
        putchar((n & (1 << i)) ? '1' : '0');
    }
    putchar('\n');  // Newline for clarity
}
