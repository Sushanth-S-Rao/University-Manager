// PROGRAM for implementation of Student Management System
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of students
int i = 0;

// Structure of the Student Instance
struct sinfo {
	char first_name[50];
	char last_name[50];
	int roll;
	float cgpa;
	int course_id[10];
} st[55];

// Function to add the student
void add_student()
{
	printf("Add the Students Details\n");
	printf("-------------------------\n");
	printf("Enter the first name of student\n");
	scanf("%s", st[i].first_name);
	printf("Enter the last name of student\n");
	scanf("%s", st[i].last_name);
	printf("Enter the Roll Number\n");
	scanf("%d", &st[i].roll);
	printf("Enter the CGPA you obtained\n");
	scanf("%f", &st[i].cgpa);
	printf("Enter the course ID of each course\n");

	for (int j = 0; j < 5; j++) {
		scanf("%d", &st[i].course_id[j]);
	}
	i = i + 1;
}

// Function to find the student by the roll number
void find_by_roll()
{
	int x;
	printf("Enter the Roll Number of the student\n");
	scanf("%d", &x);
	for (int j = 1; j <= i; j++) {
		if (x == st[i].roll) {
			printf("The Students Details are\n");
			printf("The First name is %s\n", st[i].first_name);
			printf("The Last name is %s\n", st[i].last_name);
			printf("The CGPA is %f\n", st[i].cgpa);
			printf("Enter the course ID of each course\n");
		}
		for (int j = 0; j < 5; j++) {
			printf("The course ID are %d\n", st[i].course_id[j]);
		}
		break;
	}
}

// Function to find the student by the first name
void find_by_firstname()
{
	char a[50];
	printf("Enter the First Name of the student\n");
	scanf("%s", a);
	int c = 0;

	for (int j = 1; j <= i; j++) {
		if (!strcmp(st[j].first_name, a)) {
			printf("The Students Details are\n");
			printf("The First name is %s\n", st[i].first_name);
			printf("The Last name is %s\n", st[i].last_name);
			printf("The Roll Number is %d\n ", st[i].roll);
			printf("The CGPA is %f\n", st[i].cgpa);
			printf("Enter the course ID of each course\n");

			for (int j = 0; j < 5; j++) {
				printf("The course ID are %d\n", st[i].course_id[j]);
			}
			c = 1;
		}
		else
			printf("The First Name not Found\n");
	}
}

// Function to find the students enrolled in a particular course
void find_by_course()
{
	int id;
	printf("Enter the course ID \n");
	scanf("%d", &id);
	int c = 0;

	for (int j = 1; j <= i; j++) {
		for (int d = 0; d < 5; d++) {
			if (id == st[j].course_id[d]) {
				printf("The Students Details are\n");
				printf("The First name is %s\n", st[i].first_name);
				printf("The Last name is %s\n", st[i].last_name);
				printf("The Roll Number is %d\n ", st[i].roll);
				printf("The CGPA is %f\n", st[i].cgpa);
				c = 1;
				break;
			}
			else
				printf("The First Name not Found\n");
		}
	}
}

// Function to print the total number of students
void total_students()
{
	printf("The total number of Student is %d\n", i);
	printf("\n you can have a max of 50 students\n");
	printf("you can have %d more students\n", 50 - i);
}

// Function to delete a student by the roll number
void delete_student()
{
	int a;
	printf("Enter the Roll Number which you want to delete\n");
	scanf("%d", &a);
	for (int j = 1; j <= i; j++) {
		if (a == st[j].roll) {
			for (int k = j; k < 49; k++)
				st[k] = st[k + 1];
			i--;
		}
	}
	printf("The Roll Number is removed Successfully\n");
}

// Function to update a students data
void update_student()
{

	printf("Enter the roll number to update the entry : ");
	long int x;
	scanf("%ld", &x);
	for (int j = 0; j < i; j++) {
		if (st[j].roll == x) {
			printf("1) first name\n"
				"2) last name\n"
				"3) roll number\n"
				"4) CGPA\n"
				"5) courses\n");
			int z;
			scanf("%d", &z);
			switch (z) {
			case 1:
				printf("Enter the new first name : \n");
				scanf("%s", st[j].first_name);
				break;
			case 2:
				printf("Enter the new last name : \n");
				scanf("%s", st[j].last_name);
				break;
			case 3:
				printf("Enter the new roll numnber : \n");
				scanf("%d", &st[j].roll);
				break;
			case 4:
				printf("Enter the new CGPA : \n");
				scanf("%f", &st[j].cgpa);
				break;
			case 5:
				printf("Enter the new courses \n");
				scanf(
					"%d%d%d%d%d", &st[j].course_id[0],
					&st[j].course_id[1], &st[j].course_id[2],
					&st[j].course_id[3], &st[j].course_id[4]);
				break;
			}
			printf("UPDATED SUCCESSFULLY\n");
		}
	}
}

// Driver code
void main()
{
	int choice, count;
	printf("Welcome to Student System Management!\n\n");
	while (i = 1) {
		printf("The Task that you want to perform\n");
		printf("1) Add the Student Details\n");
		printf("2) Find the Student Details by Roll Number\n");
		printf("3) Find the Student Details by First Name\n");
		printf("4) Find the Student Details by Course Id\n");
		printf("5) Find the Total number of Students\n");
		printf("6) Delete the Students Details by Roll Number\n");
		printf("7) Update the Students Details by Roll Number\n");
		printf("8) To Exit\n");
		printf("Enter your choice to find the task\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			add_student();
			break;
		case 2:
			find_by_roll();
			break;
		case 3:
			find_by_firstname();
			break;
		case 4:
			find_by_course();
			break;
		case 5:
			total_students();
			break;
		case 6:
			delete_student();
			break;
		case 7:
			update_student();
			break;
		case 8:
			exit(0);
			break;
		}
	}
}
