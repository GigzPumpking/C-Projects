#pragma once

#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>

typedef struct Character Character;

Character *c_create(char* name, uint32_t hp, uint32_t atk);

void c_delete(Character *c);

char* c_name(Character *c);

uint32_t c_hp(Character *c);

uint32_t c_atk(Character *c);

void c_print(Character *c, FILE *outfile);
