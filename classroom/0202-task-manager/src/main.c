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
    printf("Press Enter to continue...");
    int c;  
    while ((c = getchar()) != '\n' && c != EOF);
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
    
    clearTerminal();
    printf("\n");
    printf("==================================\n");
    printf("             NEW TASK             \n");
    printf("==================================\n");
    printf("- ");
    
    // Get user input for the task
    fgets(task, sizeof(task), stdin);
    
    // Remove the newline character from the input
    task[strcspn(task, "\n")] = 0;
    
    // Open the file in append mode
    fp = fopen(FILE_PATH, "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    // Write the file
    fprintf(fp, "- %s\n", task);
    fclose(fp);

    printf("\n Task added successfully.\n");
    printf("==================================\n");
}


void showTasks() {
    FILE *fp;
    char buffer[256];
    fp = fopen(FILE_PATH, "r");
    
    clearTerminal();
    printf("==================================\n");
    printf("              ALL TASKS            \n");
    printf("==================================\n");
    
    // Valid if tasks file exists
    if (fp == NULL) {
        printf("No tasks found.\n ");
        return;
    }

    // Print the file content
    int num = 0;
    while(fgets(buffer, sizeof(buffer), fp)) {
        printf("[%d] %s", num, buffer);
        num++;
    }
    fclose(fp);

    printf("\n==================================\n");
}


void deleteTask() {
    int option, i = 0, j = 0, c;
    char buffer[256], tasks[50][100];
    FILE *fp;
    
    // Show tasks for deletion
    showTasks();
    printf("Delete Task: ");
    if (scanf("%d", &option) != 1) return;

    // Clear buffer
    while ((c = getchar()) != '\n' && c != EOF);

    // Open file
    fp = fopen(FILE_PATH, "r");
    if (fp == NULL) {
        printf("No tasks found");
        return;
    }

    // Copy tasks to an array
    while(fgets(buffer, sizeof(buffer), fp)) {
        strcpy(tasks[i], buffer);
        i++;
    }
    if (option>=i) return; 
    fclose(fp);

    // Overwrite file without selected task
    fp = fopen(FILE_PATH, "w");
    for(j=0; j<i; j++){
        if (j == option) continue;
        fputs(tasks[j], fp);
    }
    
    printf("\n==================================\n");
    printf("Task [%d] removed successfully.\n", option);
    printf("==================================\n");
    fclose(fp);


}


void finishCode() {
    clearTerminal();
    printf("==================================\n");
    printf("Thanks for using task manager!\n");
    printf("Finishing...\n");
    printf("==================================\n");
    exit(0);
}


int main() {
    int option;

    while (1)
    {
        showMenu();
        if (scanf("%d", &option) != 1) return 1;
        int c;  
        while ((c = getchar()) != '\n' && c != EOF);
        switch (option)
        {
        case 1:
            addTask();
            pressEnter();
            break;
        case 2:
            showTasks();
            pressEnter();
            break;
        case 3:
            deleteTask();
            pressEnter();
            break;
        default:
            finishCode();
            break;
        }
    }
    
    return 0;
}
