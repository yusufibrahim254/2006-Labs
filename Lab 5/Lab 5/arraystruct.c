﻿/* 
Yusuf Ibrahim - 101231208
arraystruct.c - SYSC 2006 Lab 5 
*/

#include <stdlib.h>  
#include <stdio.h>   

#include "arraystruct.h"


// part 1

/* Return the maximum value in the first n elements of array of integers, ar. 
   If n is less than or equal to 0, it returns 0.  
   This function uses array indices.  Do not change this function. */
int find_max_v0(const int ar[], int n) {
	int max;
	if (n<=0) {
		return 0; // ensure we proceed only if n is reasonable
	}
	max = ar[0];
	for (int i=1; i<n; i++) {
		if (ar[i]>max) {
			max = ar[i];
		}
	}
	return max;
}
/* Return the maximum value in the first n elements of an array of integers. 
   If n is less than or equal to 0, it returns 0.  
   This function uses a pointer to an array. */
int find_max_v1(const int *arp, int n) {

	int max;
	if (n <= 0) {
		return 0; // ensure we proceed only if n is reasonable
	}

	max = *arp;
	for (int i = 1; i < n; i++) {
		if (*(arp+i) > max) {
			max = *(arp + i);
		}
	}
	return max;
}


/* Return the maximum value in the first n elements of an array of integers. 
   If n is less than or equal to 0, it returns 0.  
   This function uses a walking pointer to the array. */
int find_max_v2(const int *arp, int n) {

	int max;
	if (n <= 0) {
		return 0; // ensure we proceed only if n is reasonable
	}

	max = *arp;
	for (int i = 1; i < n; i++) {
		if (*arp > max) {
			max = *arp;
		}
		arp++;
	}
	return max;
}


// part 2

/* Print fraction pointed to by pf in the form a/b. */
void print_fraction(const fraction_t* pf){
	fraction_t frac = *pf;
printf("%d/%d",frac.num,frac.den);
}


/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.  Copy this function from Lab 4.  No changes are needed.
*/
int gcd(int a, int b)
{
    int gcd, r;
    int q = abs(a);
	int p = abs(b);
	r = q % p;
    while (r != 0)
    {
        q = p;
        p = r;
		r = q % p;
    }

    gcd = p;

    return gcd;

}

/* Updates the fraction pointed to by pf to its reduced form.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
       positive, and the numerator and denominator have no common
       divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
       are made positive, or if the numerator is positive and the 
       denominator is negative, the numerator is made negative and the 
       denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
       common divisor. 
*/
void reduce(fraction_t* pf)
{
//fraction_t f = {0, 0};
	int gcdf = gcd (pf->num, pf->den);
	pf->num = (pf->num / gcdf);
	pf->den = (pf->den / gcdf);

	if (0 > pf->den){
		pf->num = (pf->num * -1);
		pf->den = (pf->den * -1);

}
}

/* Returns a pointer to a fraction (by reference) with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form.
*/
void make_fraction(int a, int b, fraction_t* pf)
{
\
	pf->num = a;
	pf->den = b;
	int gcdf = gcd (pf->num, pf->den);
	pf->num = (pf->num / gcdf);
	pf->den = (pf->den / gcdf);

	if (pf->den==0){
		printf("error");
		exit(0);
		}



}

/* Returns by reference a pointer to the sum of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void add_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* psum)
{
    psum->num = (pf1->num*pf2->den)+(pf1->den*pf2->num);
	psum->den = (pf1->den*pf2->den);
	make_fraction(psum->num,psum->den,psum);
}

/* Returns by reference a pointer to the product of fractions pointed to by pf1 and pf2.
   The fraction returned by this function is always in reduced form
 */
void multiply_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* pprod)
{
    pprod->num = (pf1->num*pf2->num);
	pprod->den = (pf1->den*pf2->den);
	make_fraction(pprod->num,pprod->den,pprod);
}

// part 3

/* Update the GPA of the student pointed to by studentp, assuming the student has numGrades.    Note that update_gpa must call calc_gpa for each student. */
void update_gpa(student_t *studentp, int numGrades) {
	
studentp->gpa = calc_gpa(studentp->grades,numGrades);
}

/* Calculate the GPA associated with the numGrades pointed to by gradesp.
   The implementation must use a walking pointer. 
   If the total weight of all courses is 0, a GPA of 0 is returned. */
float calc_gpa(const grade_t *gradesp, int numGrades) {
float sgw = 0.0;
float sgp = 0.0;
float gpa = 0.0;
	for (int i=0; i<numGrades; i++){
    sgw += ((gradesp))->weight;
    sgp +=(( gradesp))->gp * gradesp->weight;
		gradesp++;

	}
gpa = sgp/sgw;

	if (sgp == 0){
		gpa = 0;
	} 
	

	return gpa;
}
