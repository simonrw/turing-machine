#ifndef TURING_H_
#define TURING_H_

#define TAPE_LEN 1024

typedef int bool;

typedef enum {
    TURING_OK,
    TURING_HALT,
    TURING_ERROR
} turing_status_t;

typedef struct Turing {
    bool *tape;
    bool *p;
} Turing;

Turing *init_turing();
void free_turing(Turing *turing);
turing_status_t execute_instruction(Turing *turing, char *program);
turing_status_t execute_definite_instruction(Turing *turing, char *program);

#endif //  TURING_H_
