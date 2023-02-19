#include "character.h"
#include <stdlib.h>

struct Character {
    uint32_t hp;
    uint32_t atk;
    char* name;  
};

Character *c_create(char* name, uint32_t hp, uint32_t atk) {
    Character *c = calloc(1, sizeof(Character));
    c->name = name;
    c->hp = hp;
    c->atk = atk;
    return c;
}

void c_delete(Character *c) {
    free(c);
    c = NULL;
}

char* c_name(Character *c) {
    return c->name;
}

uint32_t c_hp(Character *c) {
    return c->hp;
}

uint32_t c_atk(Character *c) {
    return c->atk;
}

void c_print(Character *c, FILE *outfile) {
    fprintf(outfile, "Name: %s\n", c->name);
    fprintf(outfile, "HP: %" PRIu32 "\n", c->hp);
    fprintf(outfile, "ATK: %" PRIu32 "\n", c->atk);
}
