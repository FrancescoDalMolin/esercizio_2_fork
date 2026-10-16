#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 3

int main(void) {
    for (int i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(1);
        }

        if (pid == 0) {
            printf("Figlio %d: PID = %d\n", i + 1, getpid());
            fflush(stdout);
            sleep(2);
            exit(0);
        }
    }

    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    printf("Padre: tutti i figli hanno terminato.\n");
    return 0;
}