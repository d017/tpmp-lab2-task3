#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int compare_students(const void* a, const void* b) {
    STUDENT* student_a = *(STUDENT**)a;
    STUDENT* student_b = *(STUDENT**)b;
    
    return strcmp(get_student_name(student_a), get_student_name(student_b));
}

const int SES_SIZE = 5;

int main() {
	int n = 10;
    
	STUDENT** students = (STUDENT**)malloc(n * sizeof(STUDENT*));
    
	for (int i = 0; i < n; i++) {
		students[i] = create_student();
		input_student_data(students[i], i + 1, SES_SIZE);
	}

	qsort(students, n, sizeof(STUDENT*), compare_students);
	printf("\nStudents:\n");
	for (int i = 0; i < n; i++) {
		printf("Student %d: %s, course %d\n", 
		       i + 1, 
		       get_student_name(students[i]),
		       get_student_course(students[i]));
	}
	
	int total_mark = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < SES_SIZE; j++)
			total_mark += get_student_mark(students[i], j);
	
	double avg = total_mark / ((double) (n * SES_SIZE))
	int above_avg = 0;
	for (int i = 0; i < n; i++) {
		double stud_avg = 0.;
		for (int j = 0; j < SES_SIZE; j++)
			stud_avg += get_student_mark(students[i], j);
		stud_avg /= SES_SIZE;
		if (stud_avg > avg)
			above_avg++;
	}
	if (above_avg == 0) {
		printf("No students with average above total average");
	}
	else {
		printf("Students with average above total average: %d\n", above_avg);
		for (int i = 0; i < n; i++) {
			double stud_avg = 0.;
			for (int j = 0; j < SES_SIZE; j++)
				stud_avg += get_student_mark(students[i], j);
			stud_avg /= SES_SIZE;
			if (stud_avg > avg)
				printf("Student %d: %s, course %d, average %.2lf\n", 
				       i + 1, 
				       get_student_name(students[i]),
				       get_student_course(students[i]),
				       stud_avg);
		}
	}
	
	for (int i = 0; i < n; i++) {
		free_student(students[i]);
	}
	free(students);

	return 0;
}
