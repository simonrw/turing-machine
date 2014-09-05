COMMON=-g -O0 -Wall -Wextra
LDFLAGS=
CFLAGS=
RUN=turing
CC=clang

all: $(RUN)

$(RUN): main.o turing.o
	$(CC) $^ -o $@ $(COMMON) $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(COMMON) $(CFLAGS)
