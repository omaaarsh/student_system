#include "student.h"
/*
 * i am using macBook so i don't need to write this row that fix scanf and print if
 */
int main() {
    int choice;

    while (1) {
        // Print the menu
        printMenu();

        // Get the user's choice
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice input.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        // Process the choice
        switch (choice) {
            case 1: {
                student_data s;
                // Input student ID
                printf("Enter student ID: ");
                if (scanf("%d", &s.id) != 1 || s.id <= 0) {
                    printf("Invalid ID input.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                // Input student name
                printf("Enter student name: ");
                if (scanf("%49s", s.name) != 1) {
                    printf("Invalid name input.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                // Input student age
                printf("Enter student age: ");
                if (scanf("%d", &s.age) != 1 || s.age <= 0) {
                    printf("Invalid age input.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                // Input student GPA
                printf("Enter student GPA: ");
                if (scanf("%f", &s.gpa) != 1 || s.gpa < 0.0 || s.gpa > 4.0) {
                    printf("Invalid GPA input.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }

                // Add the student to the linked list
                addStudent(&s);
                break;
            }
            case 2:
                // Display all students
                displayStudents();
                break;
            case 3: {
                // Search for a student by ID
                int id;
                printf("Search for a student by ID\n");
                printf("Enter ID: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid ID input.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                searchStudentByID(id);
                break;
            }
            case 4:
                // Update student information
                printf("Update student information\n");{
                    int id;
                    printf("Enter ID: ");
                    if (scanf("%d", &id) != 1) {
                        printf("Invalid ID input.\n");
                        while (getchar() != '\n'); // Clear the input buffer
                        break;
                    }
                    updateStudent(id);
                }
                break;
            case 5:
                // Delete a student by ID
                printf("Delete a student by ID\n");{
                int id;
                printf("Enter ID: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid ID input.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                deleteStudent(id);
                }
                break;
            case 6:
                // Calculate average GPA
                printf("Calculate average GPA:\n");
                float average_GPA;
                average_GPA = calculateAverageGPA();
                printf("Average GPA: %.2f\n", average_GPA);
                break;
            case 7:
                // Find student with highest GPA
                printf("Find student with highest GPA\n");
                searchHighestGPA();
                break;
            case 8:
                // Exit the program
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
