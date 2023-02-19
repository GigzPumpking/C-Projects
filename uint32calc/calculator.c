#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <inttypes.h>
#define OPTIONS "asmdrei:j:H"
//a = add, s = sub, m = mul, d = quo, r = mod, e = power, n = num, m = num2, H = help

typedef uint32_t Set;

Set set_insert(Set s, uint8_t x) {
    return (s | (1 << x));
}
//sets xth bit in Set s to true (1)

bool set_member(Set s, uint8_t x) {
    if ((s & (1 << x)) == 0) {
        return false;
    }
    return true;
}
//checks xth bit in Set s and returns its boolean value

//Use Sets as a boolean cabinet to check for operations.

uint32_t add(uint32_t num1, uint32_t num2) {
    return num1 + num2;
}

uint32_t sub(uint32_t num1, uint32_t num2) {
    if (num1 < num2) {
        printf("%" PRIu32 " is less than %" PRIu32 ". Since we are working with unsigned integers, the following value will be unsigned, but still represents a negative integer.\n", num1, num2);
        return num2 - num1;
    }
    //Check if num1 is less than num2. Subtracting such values would cause issues as we are dealing with unsigned ints. It would wrap around to the limit of a uint32_t, which is 4,294,967,295
    else {
        return num1 - num2;
    }
}

uint32_t mul(uint32_t num1, uint32_t num2) {
    return num1 * num2;
}

uint32_t quo(uint32_t num1, uint32_t num2) {
    return num1 / num2;
}

uint32_t mod(uint32_t num1, uint32_t num2) {
    return num1 % num2;
}

uint32_t power(uint32_t num1, uint32_t num2) {
    uint32_t res = num1;
    for (uint32_t i = 1; i < num2; i++) {
        res *= num1;
    }
    return res;
    //starts at 1 because res is initialized as num1
}

//Addition, Subtraction, Multiplication, Division, Modulus, and Exponents functions

int main(int argc, char **argv) {
    uint32_t num1 = 0, num2 = 0, res = 0, rem = 0;
    Set s = 0;
    //default values
    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        //checks for any entered flags
        switch (opt) {
        case 'i': num1 = (uint32_t) strtoul(optarg, NULL, 10); break;
        case 'j': num2 = (uint32_t) strtoul(optarg, NULL, 10); break;
        //translates optarg into uint32_t format in base 10
        case 'a': s = set_insert(s, 0); break;
        case 's': s = set_insert(s, 1); break;
        case 'm': s = set_insert(s, 2); break;
        case 'd': s = set_insert(s, 3); break;
        case 'r': s = set_insert(s, 4); break;
        case 'e': s = set_insert(s, 5); break;
        case 'H': s = set_insert(s, 31); break;
        }
    }
    if (set_member(s, 31) || s == 0) {
        fprintf(stderr, "\nSYNOPSIS\n"
                        "   A simple add/sub/mul/div calculator for unsigned integers. No decimals: displays remainder if any.\n"
                        "\n"
                        "USAGE\n"
                        "   ./calculator [-asmdi:j:H] [-i num1] [-j num2]\n"
                        "\n"
                        "OPTIONS\n"
                        "   -H              Display program help and usage. If no operation was clarified, help will be displayed.\n"
                        "   -a              Adds num1 and num2.\n"
                        "   -s              Subtract num1 and num2.\n"
                        "   -m              Multiply num1 and num2.\n"
                        "   -d              Divide num1 and num2, displays remainder.\n"
                        "   -r              Mods num1 and num2 (returns the remainder).\n"
                        "   -e              Raises num1 to the power of num2.\n"
                        "   -i num1         Set num1 to uint32_t (unsigned 32-bit int) (default value: 0).\n"
                        "   -j num2         Set num2 to uint32_t (unsigned 32-bit int) (default value: 0).\n"
                        "   -p elements     Specify number of elements to print (default: 100).\n");
        return -1;   
    }
    
    if (set_member(s, 0)) {
        res = add(num1, num2); printf("%" PRIu32 " + %" PRIu32 " = %" PRIu32 "\n", num1, num2, res);
    } 

    if (set_member(s, 1)) {
        res = sub(num1, num2); printf("%" PRIu32 " - %" PRIu32 " = %" PRIu32 "\n", num1, num2, res);
    }

    if (set_member(s, 2)) {
        res = mul(num1, num2); printf("%" PRIu32 " * %" PRIu32 " = %" PRIu32 "\n", num1, num2, res);
    }

    if (set_member(s, 3)) {
        res = quo(num1, num2); rem = mod(num1, num2); printf("%" PRIu32 " / %" PRIu32 " = %" PRIu32 ", remainder = %u\n", num1, num2, res, rem);
    }
    
    if (set_member(s, 4)) {
        res = mod(num1, num2); printf("%" PRIu32 " mod %" PRIu32 " = %" PRIu32 "\n", num1, num2, res);
    }

    if (set_member(s, 5)) {
        res = power(num1, num2); printf("%" PRIu32 " ^ %" PRIu32 " = %" PRIu32 "\n", num1, num2, res);
    }
    return 0;
}
