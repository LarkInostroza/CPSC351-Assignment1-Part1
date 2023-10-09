//Lark Inostroza
//CPSC 351 Project 1 Part 1
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

		//Exit Prompt
        if (command == "exit") {
            break;
        }

	    pid_t pid = fork();

        if (pid < 0) {
        	perror("fork");
            exit(-1);
        }
    
	    //Child Using Execlp
        else if (pid == 0) {
            const char *cmd = command.c_str();
            execlp(cmd, cmd, nullptr);
        }

	    //Parent
	    else {
            int child_status;
            pid_t child_pid = wait(&child_status);
        }
    }
    return 0;
}
