#include "character.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#define OPTIONS "n:h:a:"

int main(int argc, char **argv) {
    char *NAME = "Hero";
    bool customName = false;
    uint32_t HP = 50;
    uint32_t ATK = 10;
    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'n': NAME = strdup(optarg); customName = true; break;
        case 'h': HP = (uint32_t) strtoul(optarg, NULL, 10); break;
        case 'a': ATK = (uint32_t) strtoul(optarg, NULL, 10); break;
        }
    }

    Character *HERO = c_create(NAME, HP, ATK);
    printf("Name: %s\nHP: %u\nATK: %u\n", c_name(HERO), c_hp(HERO), c_atk(HERO));
    if (customName == true) {
        free(NAME);
        NAME = NULL;
    }
    return 0;
}
