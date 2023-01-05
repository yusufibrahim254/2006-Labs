﻿/* main.c - SYSC 2006 Lab 5 
 *
 * Do not modify any of the code in this file.
 */

#include <stdlib.h>  // exit
#include <stdio.h>   // printf

#include "arraystruct.h"

int main(void)
{
        // part 1

	// We start by finding the maximum element in the first "n" elements of an array three different ways.
	int anArray[] = {7,2,-5,100,3};

	// test find_max_v0
	printf("find_max_v0: The largest element in the first 5 elements of anArray is: %d\n",find_max_v0(anArray,5));
	printf("find_max_v0: The largest element in the first 3 elements of anArray is: %d\n",find_max_v0(anArray,3));
	printf("find_max_v0: The largest element in the first -2 elements of anArray is: %d\n\n",find_max_v0(anArray,-2));

	// test find_max_v1 (You have to complete this function)
	printf("find_max_v1: The largest element in the first 5 elements of anArray is: %d\n",find_max_v1(&anArray[0],5));
	printf("find_max_v1: The largest element in the first 3 elements of anArray is: %d\n",find_max_v1(&anArray[0],3));
	printf("find_max_v1: The largest element in the first -2 elements of anArray is: %d\n\n",find_max_v1(&anArray[0],-2));

	// test find_max_v2 (You have to complete this function)
	printf("find_max_v2: The largest element in the first 5 elements of anArray is: %d\n",find_max_v2(&anArray[0],5));
	printf("find_max_v2: The largest element in the first 3 elements of anArray is: %d\n",find_max_v2(&anArray[0],3));
	printf("find_max_v2: The largest element in the first -2 elements of anArray is: %d\n\n",find_max_v2(&anArray[0],-2));

        // part 2

	// Now we are going to test the updated fraction functions
	fraction_t f1 = {6,8};
	fraction_t f2 = {4,2};
	fraction_t result;

	// Reduce the fractions
	print_fraction(&f1);
	printf(" reduces to ");
	reduce(&f1);
	print_fraction(&f1);
	printf("\n\n");

	print_fraction(&f2);
	printf(" reduces to ");
	reduce(&f2);
	print_fraction(&f2);
	printf("\n\n");
	
	// add the fractions
	add_fractions(&f1,&f2,&result);
	printf("Adding ");
	print_fraction(&f1);
	printf(" and ");
	print_fraction(&f2);
	printf(" gives: ");
	print_fraction(&result);
	printf("\n\n");

	// multiply the fractions
	multiply_fractions(&f1,&f2,&result);
	printf("Multiplying ");
	print_fraction(&f1);
	printf(" and ");
	print_fraction(&f2);
	printf(" gives: ");
	print_fraction(&result);
	printf("\n\n");

        // part 3

	// set up an array of student data
	const int STSIZE = 10;
	const int GRSIZE = 6;
	student_t students[STSIZE];
	for (int i=0; i<STSIZE; i++) {
		students[i].id = i*10+7;
		students[i].gpa = 0;
		for (int j=0; j<GRSIZE; j++) {
			students[i].grades[j].code = (i+j)*5+2;
			students[i].grades[j].weight = (j%2+1)*0.5;
			students[i].grades[j].gp = (i+j)%13;
		}
	}
	
	// print the student data before calculating GPAs
	for (int i=0; i<STSIZE; i++) {
		printf("Student Index: %d  Student ID: %d  Student GPA: %.1f\n", i, students[i].id, students[i].gpa);
		for (int j=0; j<GRSIZE; j++) {
			printf("\t Grade Index: %d  Grade Code: %d  Grade Weight: %.1f  Grade Point: %d\n", j, students[i].grades[j].code, students[i].grades[j].weight, students[i].grades[j].gp);
		}
	}
	printf("\n"); 
	
	// update the students' GPAs
	for (int i=0; i<STSIZE; i++){
		update_gpa(&students[i],GRSIZE);
	}
	
	// print the student (updated) GPAs
	for (int i=0; i<STSIZE; i++){
		printf("Student Index: %d  Student ID: %d  Student GPA: %.1f\n", i, students[i].id, students[i].gpa);
	}
	printf("\n");
	
	return 0;
}
