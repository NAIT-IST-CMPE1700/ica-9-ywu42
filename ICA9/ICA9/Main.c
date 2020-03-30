#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

	Student_info* start = make_list(10);       //decalring a list of ten students with different grade and id number

	char choice = '0';        //declaring a char with intialize zero

	//run a while loop until the char choice is not equal to 5
	while (choice != '5')
	{
		//display of menu for user to select
		printf("\n\nEnter 1 to display in order of ID Number\n");
		printf("Enter 2 to display based on student grade\n");
		printf("Enter 3 to display info of all students\n");
		printf("Enter 4 to display all students who have passed\n");
		printf("Enter 5 to exit \n\n");
		printf("Enter your choice: ");

		printf("\n");
		scanf_s("%c", &choice, sizeof(char));         //get user selection choice
		printf("\n");

		switch (choice)
		{
		case '1':
			printf("\n=============\n");
			Id_nodeorder(start);                //calling in descending order based on student id
			display(start, NULL, 0);            //printing in descending order based on student id
			printf("\n=============\n");
			break;
		case '2':
			printf("\n=============\n");
			mark_noderorder(start);            //calling in desending order based on student marks
			display(start, NULL, 0);           //printing in decsending order based on student marks
			printf("\n=============\n");
			break;
		case '3':
			printf("\n=============\n");
			display(start, NULL, 0);           //printing information of all students
			printf("\n=============\n");
			break;
		case '4':
			printf("\n=============\n");
			display(start, NULL, 50);         //printing information of those students who passed
			printf("\n=============\n");
			break;
		case '5':
			break;
		default:
			printf("wrong Input please select from above choices\n");          //wrong input
			break;
		}
		getchar();
	}
	exit(EXIT_SUCCESS);


}