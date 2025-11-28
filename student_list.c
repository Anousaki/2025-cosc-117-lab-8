#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char first_name[64];
    char last_name[64];
    double gpa;
    struct Student* next; // Pointer to the next student in the list 
};

struct Student* create_student();
struct Student* add_student(struct Student* student_list, struct Student* new_student);
void print_list(struct Student* student_list);
void free_list(struct Student* student_list);

int main() {
    struct Student* student_list = NULL; // The start of our linked list
    char choice = 'y';

    printf("--- Student Roster Management ---\n");

    while (choice == 'y' || choice == 'Y') {   
        // Create the new node (new_student is a pointer to the newly created node)
        struct Student* new_student = create_student();
        // Add it to the list (implement this function in Task 1)
        student_list = add_student(student_list, new_student);
        printf("Add another student? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("\n--- Class Roster ---\n");
    // Print the list (implement this function in Task 2)
    print_list(student_list);

    // free the memory (all the nodes)
    free_list(student_list);

    return 0;
}

// This allocates memory, prompts the user, and fills the struct
struct Student* create_student() {
    // Allocate memory for one student struct
    struct Student* new_student = (struct Student*)malloc(sizeof(struct Student));
    
    if (new_student == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Prompt user for input, and store student information.
    printf("\nEnter Student ID: ");
	// &new_student->id is the same as &((*new_student).id)
    scanf("%d", &new_student->id); 
    
    printf("Enter First Name: ");
    scanf("%s", new_student->first_name); 
    
    printf("Enter Last Name: ");
    scanf("%s", new_student->last_name);
    
    printf("Enter GPA: ");
    scanf("%lf", &new_student->gpa);
    
    // Initialize next to NULL (it's not linked to anything yet)
    new_student->next = NULL;

    return new_student;
}

// Task 1: Implement this function
// It should return the new head of the list
struct Student* add_student(struct Student* student_list, struct Student* new_student) {
    // TODO: Link the new_student to the current list
    new_student->next = student_list;
    
    return new_student; // Return new_student (because it is now the front of the list)
}

// Task 2: Implement this function
void print_list(struct Student* student_list) {
    // TODO: Traverse the list and print student info
    struct Student* current = student_list;
    
    while(current != NULL) {
        printf("ID: %d, Name: %s %s, GPA: %.2f\n",
            current->id,
            current->first_name,
            current->last_name,
            current->gpa);
            current = current->next;
    }
}

// Task 3: Implement this function
void free_list(struct Student* student_list) {
    // TODO: Loop through the list and free every node
    // Careful! Don't lose the pointer to the next node before freeing current.
    struct Student* current = student_list;
    struct Student* next_node;

    while(current != NULL) {
    next_node = current->next;
    free(current);
    current = next_node;
    }

    printf("Memory freed.\n");
}