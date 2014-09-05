#ifndef TURING_H_
#define TURING_H_

#define TAPE_LEN 1024

#define turing_error(...) fprintf(stderr, __VA_ARGS__);\
    return TURING_ERROR

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
turing_status_t move_head(Turing *turing, int direction);

turing_status_t execute_instruction(Turing *turing, char *program);
turing_status_t execute_definite_instruction(Turing *turing, char *program);

#endif //  TURING_H_
