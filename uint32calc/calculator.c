#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <inttypes.h>
#define OPTIONS "asmdi:j:H"
//a = add, s = sub, m = mul, d = div, n = num, m = num2, H = help

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
        case 'H': s = set_insert(s, 4); break;
        }
    }
    if (set_member(s, 4) || s == 0) {
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
                        "   -i num1         Set num1 to uint32_t (unsigned 32-bit int) (default value: 0).\n"
                        "   -j num2         Set num2 to uint32_t (unsigned 32-bit int) (default value: 0).\n"
                        "   -p elements     Specify number of elements to print (default: 100).\n");
        return -1;   
    }
    
    if (set_member(s, 0)) {
        res = num1 + num2; printf("%" PRIu32 " + %" PRIu32 "= %" PRIu32 "\n", num1, num2, res);
    } 

    if (set_member(s, 1)) {
        res = num1 - num2; printf("%" PRIu32 " - %" PRIu32 "= %" PRIu32 "\n", num1, num2, res);
    }

    if (set_member(s, 2)) {
        res = num1 * num2; printf("%" PRIu32 " * %" PRIu32 "= %" PRIu32 "\n", num1, num2, res);
    }

    if (set_member(s, 3)) {
        res = num1 / num2; rem = num1 % num2; printf("%" PRIu32 " / %" PRIu32 "= %" PRIu32 " remainder = %u\n", num1, num2, res, rem);
    }
    return 0;
}
