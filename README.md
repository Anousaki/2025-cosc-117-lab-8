# COSC 117 Lab 8 - Structs and Linked Lists

#### Due Tuesday, Dec 9, 23:59

## Introduction and Objectives

In the previous lab, you worked with basic variables and arrays. While arrays are useful, they have limitations: they have a fixed size.

For this lab, you will use **Structs** to create custom data types and **Linked Lists**.

You will implement a program to manage a class roster. Unlike an array, a linked list can grow dynamically as you add more students. Each student will be represented by a node containing their ID, First Name, Last Name, and GPA.

A template file, `student_list.c`, is provided. Upon successful completion of this lab, you will be able to:

- Define and use C **Structures** (`struct`) to group related data.
- Dynamically allocate memory using `malloc`.
- Manipulate pointers to link data nodes together.
- Traverse a linked list to display data.
- Properly release memory using `free` to avoid memory leaks.

## Lab Preparation

Fork the repository: https://github.com/Chaoping/2025-cosc-117-lab-8. On your own fork, click the green "<> Code" button, then choose Codespaces, and open a new code space. This will open VS Code in web, and it has gcc available. Alternatively, download the **`student_list.c`** file.

Read through the provided code.

- Notice the `struct Student` definition at the top.
- Notice that `create_student` is already written for you. It handles the `malloc` (memory allocation) logic.
- Notice the `main` function handles the user input loop.

## The Program Logic

### Task 1. The `add_student()` function

The `main` function has a `while` loop. In every iteration, function `create_student()` is called, which creates a `Student` struct on the heap and returns the pointer to it. Then, the `add_student()` function adds the newly created student in the student list. It is your job to implement the `add_student()` function. You should add the new student to the front of the list. This is the most efficient way to add to a linked list. (Why not add it to the end of the list?)

**Hints:**

1. The function receives the current address of the list and the `new_student` node.
2. Point the `new_student->next` to the current *front*.
3. Return the address of the new student. (The new student is now the new front of the list).

**In your lab document, copy and paste your completed `add_student` function.**

### Task 2. The `print_list()` function

This function should traverse the list from beginning to end and print the details of every student.

**Hints:**

1. Create a temporary pointer (e.g., `current`).
2. Create a `while` loop that runs as long as `current` is not `NULL`.

**In your lab document, copy and paste your completed `print_list` function.**

### Task 3. The `free_list()` function

In C, if you allocate memory manually (which `create_student` does), you must release it manually. If you don't, you create a "memory leak."

The `free_list()` will free the memory used by all the students in the student list.

**Hints:**

1. Before you free a node, make sure you have at least a copy of the pointer to the next node. 

**In your lab document, copy and paste your completed `free_list` function.**

## Compiling and Running

Compile your code:

```
gcc student_list.c -o student_list
```

Run the program:

```
./student_list
```

Enter the following data when prompted:

- Student 1: ID: `101`, First: `Alice`, Last: `Smith`, GPA: `3.8`
- Student 2:** ID: `102`, First: `Bob`, Last: `Jones`, GPA: `2.5`
- Student 3: ID: `103`, First: `Charlie`, Last: `Brown`, GPA: `3.1`

When asked to add another student, type `n` to finish input.

**Take a screenshot of your terminal showing the list being printed and the "Memory freed" message.**

## Submitting Your Lab

Export your document to **PDF**. Submit both your `student_list.c` file and your PDF containing the code snippets and screenshot to Moodle.