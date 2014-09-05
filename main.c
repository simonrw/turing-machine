#include <stdio.h>
#include <stdlib.h>

#include "turing.h"

#define MAX_PROGRAM_LENGTH 32

#define turing_try(statement) status = statement;\
                                       if (TURING_ERROR == status) {\
                                           return 1;\
                                       }


int main() {
    turing_status_t status;
    Turing *turing;

    status = 0;
    turing = init_turing();
    turing_try(move_head_left(turing));
    turing_try(move_head_right(turing));
    free_turing(turing);

    return 0;
}
