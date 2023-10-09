#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstring>

int main() {
    while (true) {
        std::cout << "cmd> ";
        std::string command;
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        }

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Child process
            const char *cmd = command.c_str();
            if (execlp(cmd, cmd, nullptr) == -1) {
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        } else { // Parent process
            int status;
            pid_t child_pid = wait(&status);

            if (child_pid == -1) {
                perror("wait");
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                std::cout << "Child exited with status " << exit_status << std::endl;
            } else {
                std::cerr << "Child process terminated abnormally." << std::endl;
            }
        }
    }

    return 0;
}
