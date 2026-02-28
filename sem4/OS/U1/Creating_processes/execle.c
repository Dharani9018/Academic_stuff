#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("Using execle() to execute `env` command:\n");

   char *new_env[] = { "Myvar=HelloWorld", "Path=/usr/bin", NULL};

    if (fork() == 0) {
        // Child process
        execle("/usr/bin/env", "env", NULL, new_env); //allows passing env. var. explicitly
        // If execle() fails
       // execlp("ls", "ls", (char *)NULL); //searches for the program in the directories listed in path env var
        perror("execle failed");
        exit(1);
    }

    // Parent process waits for child
    wait(NULL);
    printf("execle() example finished.\n");
    return 0;
}
