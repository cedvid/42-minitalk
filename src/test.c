#include <signal.h>
#include <stdio.h>

void handler(int sig) {
    printf("Signal %d received\n", sig);
}