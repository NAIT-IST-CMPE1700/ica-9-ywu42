#pragma once
#ifndef Header
#define Header


// this struct function contains in it a student name , id and marks
typedef struct Student_info
{
	char* st_name;      // char pointer for student name
	int i_id;           //an integer for student id
	float f_marks;      // a float for student marks
	struct Student_info* next;      //struct pointer for linked lsit
}Student_info;

Student_info* make_node(int id, float mark, char* name);       //make a method of  make node of struct pointer

Student_info* make_list(int i_size);      //make a method of make list of struct type

void Id_nodeorder(Student_info* s_head);        //a method to sort the list in id ascending order
void mark_noderorder(Student_info* s_head);     //a methode to sort student list based on their marks
void display(Student_info* s_haed, int id_search, float mark_search);    //a method to display the student information

static const char names[10][15] = { "James","Nancy","Lily","Mason","Lander","Billy","Justin","Britney","Olala","Zoeyy" }; //this array contains strings to use for printing the names of student


#endif // !Header