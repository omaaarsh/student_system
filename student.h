#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>

// Define a structure to store student data
typedef struct {
    int id;            /* Student ID */
    char name[50];     /* Student Name */
    int age;           /* Student Age */
    float gpa;         /* Student GPA */
} student_data;

// Define a structure to represent a node in a linked list
typedef struct node {
    student_data data; /* Student data */
    struct node *next; /* Pointer to the next node (student) */
} node;

extern node *head; // Declare the head pointer

// Function declarations
int is_empty(void);
node* createNode(const student_data *ptr);
void addStudent(const student_data *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);
void printMenu(void);

#endif // STUDENT_H
