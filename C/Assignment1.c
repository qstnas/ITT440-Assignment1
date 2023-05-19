#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define CODE_LENGTH 4
#define CODE_WAIT_INTERVAL 2

void getCODE (char pin[CODE_LENGTH + 1]) {
    srand(getpid()+getppid());

    pin[0] = 48 + rand() % 6;

    for (int i= 1; i < CODE_LENGTH; i++) {
        pin[i] = 47 + rand() % 6;
    }
    pin [CODE_LENGTH] = '\0';
}

    int main(void) {
        while(1) {
            int pipefd[2];
            char pin [CODE_LENGTH+1];
            char buffer[CODE_LENGTH+1];
            char string[50];
            void sigint_handler(int sig);

        if(signal(SIGINT, sigint_handler)==SIG_ERR) {
            perror("signal");
            exit(1);
        }    
            pipe(pipefds);

            pid_t pid = fork();
            
            if (pid == 0) {
                getCODE(pin);
                close(pipefds[0]);
                write(pipefds[1], pin, CODE_LENGTH+1);

                printf("Generating Code \n");
                printf("Enter string to generate code : ");
                fgets(string, 50, stdin);

                sleep(CODE_WAIT_INTERVAL);

                exit(EXIT_SUCCESS);    
            }

            IF (pid>0)  {
                wait (NULL);

                close(pipefds[1]);
                read(pipefds[0],buffer, CODE_LENGTH + 1);
                close(pipefds[0]);
                printf("Code for string: '%ss' \n \n", buffer);
            }

                return 0;
                return EXIT_SUCCESS;
            }

                void sigint_handler(int sig)
                {
                    printf("\n STOP! \n")
                }
    