#include <iostream>
#include "ProcessManagement.hpp"
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include "../encryptDecrypt/Cryption.hpp"


using namespace std;
ProcessManagement::ProcessManagement() {}

bool ProcessManagement::submitToQueue(unique_ptr<Task> task) {
    taskQueue.push(move(task));
    return true;
}

void ProcessManagement::executeTasks() {
    while (!taskQueue.empty()) {
        unique_ptr<Task> taskToExecute = move(taskQueue.front());
        taskQueue.pop();
        cout << "Executing task: " << taskToExecute->toString() << endl;
        // Add a breakpoint here in VS Code
        executeCryption(taskToExecute->toString());
        // int childProcessToRun = fork();
        // if (childProcessToRun == 0) {
        //     // Child process
        //     string taskStr = taskToExecute->toString();
        //     char* args[3];
        //     args[0] = strdup("./cryption");  // Use the correct path to your cryption executable
        //     args[1] = strdup(taskStr.c_str());
        //     args[2] = nullptr;
        //     execv("./cryption", args);  // Use the correct path to your cryption executable
        //     // If execv returns, there was an error
        //     cerr << "Error executing cryption" << endl;
        //     exit(1);
        // } else if (childProcessToRun > 0) {
        //     // Parent process
        //     // Wait for the child process to complete
        //     int status;
        //     waitpid(childProcessToRun, &status, 0);
        // } else {
        //     // Fork failed
        //     cerr << "Fork failed" << endl;
        //     exit(1);
        // }
    }
}