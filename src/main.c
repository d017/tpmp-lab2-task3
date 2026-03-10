#include <stdio.h>
#include <stdlib.h>
#include "student.h"


const int SES_SIZE = 5;

int main() {
    int n = 10;
    
   STUDENT** students = (STUDENT**)malloc(n * sizeof(STUDENT*));
    
   for (int i = 0; i < n; i++) {
        students[i] = create_student();
        input_student_data(students[i], i + 1, SES_SIZE);
    }
   
    printf("\nStudents:");
    for (int i = 0; i < n; i++) {
        printf("Student %d: %s, course %d\n", 
               i + 1, 
               get_student_name(students[i]),
               get_student_course(students[i]));
    }
    
    for (int i = 0; i < n; i++) {
        free_student(students[i]);
    }
    free(students);
    
    return 0;
}
