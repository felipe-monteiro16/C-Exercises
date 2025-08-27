#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_FILE "./students.dat"
#define TEXT_FILE "./students.txt"

// Student struct definition
typedef struct {
    int registration;
    char name[50];
    float average;
} Student;

void clearTerminal() {
    // Clear terminal screen based on operating system
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
    clearTerminal();
    printf("\n");
    printf("====================================\n");
    printf("        STUDENT REGISTRATION        \n");
    printf("====================================\n");
    printf("1. Register New Student\n");
    printf("2. List All Students\n");
    printf("3. Search Student\n");
    printf("4. Exit\n");
    printf("====================================\n");
    printf("Select an option: ");
}

void registerStudent() {
    FILE *fp;
    Student student;
    
    clearTerminal();
    printf("\n");
    printf("====================================\n");
    printf("        REGISTER NEW STUDENT        \n");
    printf("====================================\n");
    
    // Get student data from user input
    printf("Registration number: ");
    scanf("%d", &student.registration);
    
    printf("Name: ");
    while (getchar() != '\n'); // Clear input buffer
    fgets(student.name, sizeof(student.name), stdin);
    // Remove newline character from name
    student.name[strcspn(student.name, "\n")] = 0;
    
    printf("Average: ");
    scanf("%f", &student.average);
    
    // Open binary file in append mode
    fp = fopen(BINARY_FILE, "ab");
    if (fp == NULL) {
        printf("Error opening binary file.\n");
        pressEnter();
        return;
    }
    
    // Write student struct to binary file
    fwrite(&student, sizeof(Student), 1, fp);
    fclose(fp);
    
    // Also write to text file for readability
    fp = fopen(TEXT_FILE, "a");
    if (fp != NULL) {
        fprintf(fp, "Registration: %d | Name: %s | Average: %.2f\n", 
                student.registration, student.name, student.average);
        fclose(fp);
    }
    
    printf("\nStudent registered successfully!\n");
    pressEnter();
}

void listStudents() {
    FILE *fp;
    Student student;
    int count = 0;
    
    clearTerminal();
    printf("\n");
    printf("====================================\n");
    printf("           ALL STUDENTS             \n");
    printf("====================================\n");
    
    fp = fopen(BINARY_FILE, "rb");
    if (fp == NULL) {
        printf("No students found or error opening file.\n");
        pressEnter();
        return;
    }
    
    printf("%-12s %-30s %s\n", "Registration", "Name", "Average");
    printf("------------------------------------------------------------\n");
    
    // Read and display all students from binary file
    while (fread(&student, sizeof(Student), 1, fp) == 1) {
        printf("%-12d %-30s %.2f\n", student.registration, student.name, student.average);
        count++;
    }
    
    fclose(fp);
    
    if (count == 0) {
        printf("No students registered.\n");
    } else {
        printf("\nTotal students: %d\n", count);
    }
    
    pressEnter();
}

void searchStudent() {
    FILE *fp;
    Student student;
    int searchReg;
    int found = 0;
    
    clearTerminal();
    printf("\n");
    printf("====================================\n");
    printf("          SEARCH STUDENT            \n");
    printf("====================================\n");
    
    printf("Enter registration number to search: ");
    scanf("%d", &searchReg);
    
    fp = fopen(BINARY_FILE, "rb");
    if (fp == NULL) {
        printf("No students found or error opening file.\n");
        pressEnter();
        return;
    }
    
    // Search for student with matching registration number
    while (fread(&student, sizeof(Student), 1, fp) == 1) {
        if (student.registration == searchReg) {
            printf("\nStudent found:\n");
            printf("Registration: %d\n", student.registration);
            printf("Name: %s\n", student.name);
            printf("Average: %.2f\n", student.average);
            found = 1;
            break;
        }
    }
    
    fclose(fp);
    
    if (!found) {
        printf("\nStudent with registration %d not found.\n", searchReg);
    }
    
    pressEnter();
}

void exitProgram() {
    clearTerminal();
    printf("Exiting program...\n");
    printf("Thank you for using the Student Registration System!\n");
}

int main() {
    int option;
    
    do {
        showMenu();
        if (scanf("%d", &option) != 1) {
            // Clear input buffer on invalid input
            while (getchar() != '\n');
            option = 0;
        }
        
        switch (option) {
            case 1:
                registerStudent();
                break;
            case 2:
                listStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                exitProgram();
                break;
            default:
                printf("Invalid option! Please try again.\n");
                pressEnter();
                break;
        }
    } while (option != 4);
    
    return 0;
}
