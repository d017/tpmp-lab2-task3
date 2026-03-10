#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STUDENT {
    char* name;
    int kurs;
    int* ses;
};

STUDENT* create_student() {
    STUDENT* student = (STUDENT*)calloc(1, sizeof(STUDENT));
    return student;
}

void free_student(STUDENT* student) {
    if (student) {
        free(student->name);
        free(student->ses);
        free(student);
    }
}

void set_student_name(STUDENT* student, const char* name) {
    if (student && name) {
	if (student->name) {
            free(student->name);
        }
       
        student->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(student->name, name);
    }
}

const char* get_student_name(const STUDENT* student) {
    return student ? student->name : NULL;
}

void set_student_course(STUDENT* student, int course) {
    if (student) {
        student->kurs = course;
    }
}

int get_student_course(const STUDENT* student) {
    return student ? student->kurs : 0;
}

void set_student_mark(STUDENT* student, int mark_index, int mark) {
    if (student && student->ses && mark_index >= 0) {
        student->ses[mark_index] = mark;
    }
}

int get_student_mark(const STUDENT* student, int mark_index) {
    if (student && student->ses && mark_index >= 0) {
        return student->ses[mark_index];
    }
    return 0;
}

void input_student_data(STUDENT* student, int student_number, int session_size) {
    if (!student) return;
    
    char nameBuffer[100];
    
    printf("\n%dth student:\n", student_number);
    
    printf("Enter name: ");
    scanf("%99s", nameBuffer);
    set_student_name(student, nameBuffer);
    printf("Enter course: ");
    int course;
    scanf("%d", &course);
    set_student_course(student, course);
    
    student->ses = (int*)malloc(session_size * sizeof(int));
    
    printf("\nEnter session results (%d marks):\n", session_size);
    for (int j = 0; j < session_size; j++) {
        int mark;
        scanf("%d", &mark);
        set_student_mark(student, j, mark);
    }
}
