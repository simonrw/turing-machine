#include <stdio.h>
#include <stdlib.h>

#include "turing.h"

#define MAX_PROGRAM_LENGTH 32

#define turing_try(statement) status = statement;\
                                       if (TURING_ERROR == status) {\
                                           return 1;\
                                       }


int main() {
    int status;
    Turing *turing;

    status = 0;
    turing = init_turing();
    status = execute_instruction(turing, "0 110\n1 110");
    if (TURING_ERROR == status) {
        fprintf(stderr, "Exiting\n");
        return 1;
    } else if (TURING_HALT) {
        printf("Program reached halt state!\n");
    }

    free_turing(turing);

    return 0;
}
