#include "student.h"

node *head = NULL; // Define the head pointer

// Function to check if the linked list is empty
int is_empty(void) {
    return head == NULL;
}

// Function to create a new node with given student data
node* createNode(const student_data *ptr) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }
    new_node->data = *ptr;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new student to the linked list
void addStudent(const student_data *const ptr) {
    if (ptr == NULL) {
        printf("Invalid student data\n");
        return;
    }

    // Check if memory allocation fails
    node *new_node = createNode(ptr);
    if (new_node == NULL) {
        return;
    }

    // Check if the list is empty
    if (is_empty()) {
        head = new_node;
        printf("Successfully added\n");
        return;
    }

    // Traverse the list to check for duplicate ID and insert at the end
    node *current = head;
    while (current->next != NULL) {
        if (current->data.id == new_node->data.id) {
            printf("Error: This ID exists\n");
            free(new_node);
            return;
        }
        current = current->next;
    }

    // Check the last node for duplicate ID
    if (current->data.id == new_node->data.id) {
        printf("Error: This ID exists\n");
        free(new_node);
        return;
    }

    // Insert the new node at the end of the list
    current->next = new_node;
    printf("Successfully added\n");
}

// Function to display the details of all students
void displayStudents(void) {
    if (is_empty()) {
        printf("No students\n");
        return;
    }
    // Traverse the list to print students' data
    node *current = head;
    while (current != NULL) {
        printf("[ID: %d, Name: %s, Age: %d, GPA: %.2f]\n",
               current->data.id, current->data.name, current->data.age, current->data.gpa);
        current = current->next;
    }
}

// Function to search for a student by their ID and display their details if found
void searchStudentByID(int id) {
    if (is_empty()) {
        printf("No students\n");
        return;
    }
    node *current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            printf("Student found: [ID: %d, Name: %s, Age: %d, GPA: %.2f]\n",
                   current->data.id, current->data.name, current->data.age, current->data.gpa);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found\n", id);
}

// Function to update the details of a student with the given ID
void updateStudent(int id) {
    if (is_empty()) {
        printf("No students\n");
        return;
    }
    node *current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            student_data s;
            s.id = id;
            printf("Enter student name: ");
            scanf("%49s", s.name);
            printf("Enter student age: ");
            if (scanf("%d", &s.age) != 1 || s.age <= 0) {
                printf("Invalid age input.\n");
                while (getchar() != '\n'); // Clear the input buffer
                return;
            }
            printf("Enter student GPA: ");
            if (scanf("%f", &s.gpa) != 1 || s.gpa < 0.0 || s.gpa > 4.0) {
                printf("Invalid GPA input.\n");
                while (getchar() != '\n'); // Clear the input buffer
                return;
            }
            current->data = s;
            printf("Student details updated successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found\n", id);
}

// Function to calculate and return the average GPA of all students
float calculateAverageGPA(void) {
    if (is_empty()) {
        printf("No students\n");
        return 0.0;
    }
    float sum = 0.0;
    int counter = 0;
    node *current = head;
    while (current != NULL) {
        sum += current->data.gpa;
        current = current->next;
        counter++;
    }
    if (counter == 0) {
        printf("No students\n");
        return 0.0; // Avoid division by zero
    }
    return sum / counter;
}

// Function to find and display the student with the highest GPA
void searchHighestGPA(void) {
    if (is_empty()) {
        printf("No students\n");
        return;
    }
    node *current = head;
    node *max = head;
    while (current != NULL) {
        if (current->data.gpa > max->data.gpa) {
            max = current;
        }
        current = current->next;
    }
    if (max != NULL) {
        printf("Student with highest GPA: [ID: %d, Name: %s, Age: %d, GPA: %.2f]\n",
               max->data.id, max->data.name, max->data.age, max->data.gpa);
    } else {
        printf("Error finding student with highest GPA\n");
    }
}

// Function to delete a student from the linked list by their ID
void deleteStudent(int id) {
    if (is_empty()) {
        printf("No students\n");
        return;
    }
    node *current = head;
    node *previous = NULL;
    if (current != NULL && current->data.id == id) {
        head = current->next; // Move the head to the next node
        free(current); // Free the memory of the old head
        printf("Student with ID %d deleted.\n", id);
        return;
    }
    while (current != NULL && current->data.id != id) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Student with ID %d not found\n", id);
        return;
    }
    previous->next = current->next;
    free(current); // Free the memory of the deleted node
    printf("Student with ID %d deleted.\n", id);
}

// Function to print the menu
void printMenu(void) {
    const char *menu = "*------------------------------------*\n"
                       "1. Add a Student\n"
                       "2. Display All Students\n"
                       "3. Search for a Student by ID\n"
                       "4. Update Student Information\n"
                       "5. Delete a Student by ID\n"
                       "6. Calculate Average GPA\n"
                       "7. Find Student with Highest GPA\n"
                       "8. Exit\n"
                       "*------------------------------------*\n";
    printf("%s", menu);
}
