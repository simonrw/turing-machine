#include "turing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Turing *init_turing() {
    Turing *turing = malloc(sizeof(*turing));
    turing->tape = calloc(TAPE_LEN, sizeof(bool));
    turing->p = &turing->tape[TAPE_LEN / 2];
    return turing;
}

void free_turing(Turing *turing) {
    free(turing->tape);
    free(turing);
}

turing_status_t execute_instruction(Turing *turing, char *program) {
    char zero_case[7], one_case[7];
    strncpy(zero_case, program, sizeof(zero_case) - 2);
    strncpy(one_case, program + 6, sizeof(one_case) - 1);
    zero_case[5] = '\0';
    zero_case[6] = '\0';
    turing_status_t status;

    bool value_under_pointer = *turing->p;
    if (0 == value_under_pointer) {
        printf("Found 0\n");
        status = execute_definite_instruction(turing, zero_case);
        if (TURING_HALT == status) {
            return TURING_HALT;
        }
    } else if (1 == value_under_pointer) {
        printf("Found 1\n");
        status = execute_definite_instruction(turing, one_case);
        if (TURING_HALT == status) {
            return TURING_HALT;
        }
    } else {
        turing_error("Bad instruction found: %d\n", value_under_pointer);
    }
    return TURING_OK;
}

turing_status_t execute_definite_instruction(Turing *turing, char *program) {
    bool set_instruction,
         pointer_movement,
         goto_card;

    set_instruction = program[2] - '0';
    pointer_movement = program[3] - '0';
    goto_card = program[4] - '0';

    printf("Setting value to %d\n", set_instruction);
    *turing->p = set_instruction;

    if (0 == pointer_movement) {
        printf("Moving pointer left\n");
        (*turing->p)--;
    } else if (1 == pointer_movement) {
        printf("Moving pointer right\n");
        (*turing->p)++;
    } else {
        turing_error("Invalid move value found: %d\n", pointer_movement);
    }

    if (0 == goto_card) {
        return TURING_HALT;
    }


    return TURING_OK;
}
