#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
//*****************************************************
//making a a stuct pointer method called make_node
//which acces memebers of the struct pointer
//******************************************************
Student_info* make_node(int id, float mark, char* name)
{
	Student_info* new_mod = (Student_info*)malloc(sizeof(Student_info*));
	new_mod->st_name = name;
	new_mod->i_id = id;
	new_mod->f_marks = mark;
	new_mod->next = NULL;
	return new_mod;

}
//**************************************************
// this struct pointer make an array of 10 students 
//id and assin grades to them
//**************************************************
Student_info* make_list(int i_size)
{
	srand(time(NULL));                 //for creating random integers
	int ran_num = rand() % 100 + 1;    //creating random integer between 1 -100
	int id_num = rand() % 1000 + 1;    // creating ten random integers between 1 to 1000
	Student_info* start = make_node(id_num, ran_num, names[0]);   //assign the random integers tostruct pointer
	Student_info* s_current = start;

	//running a loop to itterate through the list
	for (int count = 1; count < i_size; count++)
	{
		ran_num = rand() % 100 + 1;
		int id_num = rand() % 1000 + 1;
		s_current->next = make_node(id_num, ran_num, names[count]);
		s_current = s_current->next;
	}
	return start;
}
//*******************************************************************
//this method display the list of students sorting them based upon 
//their id number in descending order
//*******************************************************************
void Id_nodeorder(Student_info* s_head)
{
	Student_info* s_crnt = s_head;
	Student_info* temp;
	while (s_crnt != NULL)
	{
		temp = s_crnt->next != NULL ? s_crnt->next : NULL;
		while (temp != NULL)
		{
			if (s_crnt->i_id > temp->i_id)
			{
				Student_info tempData = { s_crnt->st_name,s_crnt->i_id,s_crnt->f_marks };
				s_crnt->i_id = temp->i_id; s_crnt->f_marks = temp->f_marks; s_crnt->st_name = temp->st_name;
				temp->i_id = tempData.i_id; temp->f_marks = tempData.f_marks; temp->st_name = tempData.st_name;

			}
			temp = temp->next;


		}
		s_crnt = s_crnt->next;
	}
}
//****************************************************************
//this method will go through the list of students and sort them 
//based upon their grades from highest to lowest
//****************************************************************
void mark_noderorder(Student_info* s_head)
{
	Student_info* s_crnt = s_head;
	Student_info* temp;
	while (s_crnt != NULL)
	{
		temp = s_crnt->next != NULL ? s_crnt->next : NULL;
		while (temp != NULL)
		{
			if (s_crnt->f_marks < temp->f_marks)
			{
				Student_info tempData = { s_crnt->st_name,s_crnt->i_id,s_crnt->f_marks };
				s_crnt->i_id = temp->i_id; s_crnt->f_marks = temp->f_marks; s_crnt->st_name = temp->st_name;
				temp->i_id = tempData.i_id; temp->f_marks = tempData.f_marks; temp->st_name = tempData.st_name;

			}
			temp = temp->next;

		}
		s_crnt = s_crnt->next;
	}

}
//********************************************************************
// void display will go through the list of struct nad
// and display the result of the choice selected by the user
//*********************************************************************
void display(Student_info* Display, int id_search, float mark_search)
{
	Student_info* s_crnt = Display;
	while (s_crnt != NULL)
	{
		if (s_crnt->i_id != id_search && id_search != NULL)
		{
			s_crnt = s_crnt->next;
			continue;
		}
		if (s_crnt->f_marks < mark_search && mark_search >= 0)
		{
			s_crnt = s_crnt->next;
			continue;
		}
		printf("\nID: %i", s_crnt->i_id);
		printf("\nName: %s", s_crnt->st_name);
		printf("\nMark: %.1f", s_crnt->f_marks);
		s_crnt = s_crnt->next;
	}
}


