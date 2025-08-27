#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_PATH "./tasks.txt"


void clearTerminal() {
    // This function is intended to clear the terminal screen.
    // The implementation may vary based on the operating system.
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void pressEnter() {
    printf("\n\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
    clearTerminal();

}


void showMenu() {
    // This function displays the main menu of the task manager.
    clearTerminal();
    printf("\n");
    printf("==================================\n");
    printf("           TASK MANAGER           \n");
    printf("==================================\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Delete Task\n");
    printf("4. Exit\n");
    printf("==================================\n");
    printf("Select an option: ");
}


void addTask() {
    FILE *fp;
    char task[100];
    
    fp = fopen(FILE_PATH, "a");

    clearTerminal();
    printf("\n");
    printf("==================================\n");
    printf("             NEW TASK             \n");
    printf("==================================\n");
    printf("Text:");

    // Get user input for the task
    while (getchar() != '\n');
    fgets(task, sizeof(task), stdin);

    // Remove the newline character from the input
    task[strcspn(task, "\n")] = 0;

    // Open the file in append mode
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    

}


void finish_code() {
    clearTerminal();
    printf("Finishing...");
}


int main() {
    int option;

    showMenu();
    if (scanf("%d", &option) != 1) return 1;

    switch (option)
    {
    case 1:
        addTask();
        break;
    
    default:
        finish_code();
        break;
    }
    return 0;
}
