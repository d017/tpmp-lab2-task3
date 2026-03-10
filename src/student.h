#ifndef STUDENT_H
#define STUDENT_H



typedef struct STUDENT STUDENT;


STUDENT* create_student();


void free_student(STUDENT* student);

void set_student_name(STUDENT* student, const char* name);

const char* get_student_name(const STUDENT* student);

void set_student_course(STUDENT* student, int course);

int get_student_course(const STUDENT* student);

void set_student_mark(STUDENT* student, int mark_index, int mark);

int get_student_mark(const STUDENT* student, int mark_index);

void input_student_data(STUDENT* student, int student_number, int session_size);

#endif
