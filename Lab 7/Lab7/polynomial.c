/* polynomial.c 
- SYSC 2006 Lab 7 
- Yusuf Ibrahim 101231208
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "polynomial.h"

/* Print a polynomial term in the form ax^n; for example,
 * a term with coefficient 4 and exponent 5 is printed as 4x^5.
 */
void print_term(term_t *term)
{
	printf("%dx^%d\n", (*term).coeff, (*term).exp);
}

/* Make a polynomial term with coefficient coeff and exponent exp
 * and return the pointer to the term.
 *
 * Memory for the term is allocated from the heap.
 *
 * Terminate the program via assert if:
 * (1) coeff is 0;
 * (2) malloc fails.
 */
term_t *make_term(int coeff, int exp)
{

	assert(coeff != 0);

	term_t *poly_list = (term_t*)malloc(sizeof(term_t));
	(*poly_list).coeff = coeff;
	(*poly_list).exp = exp;  

  return poly_list;
}

/* Return the value of a polynomial term; i.e., return ax^n for a term with
 * coefficient a and exponent n when evaluated at x.
 * Example: if a term has coefficient 3 and exponent 2 and x is 4.0, 
 * this function returns 3(4.0^2), which is 48.0.
 */
double eval_term(term_t *term, double x)
{
	double eval;
	eval = (*term).coeff * pow(x, (*term).exp);
    return eval;
}

/* Make a polynomial that has 0 terms and return the pointer to the polynomial. 
 * The polynomial can store up to MAX_TERMS terms (see polynomial.h).
 *
 * Memory for the polynomial is allocated from the heap.
 *
 * Terminate the program via assert if malloc fails.
 */
polynomial_t *make_polynomial(void)
{
	polynomial_t *poly_list2 = (polynomial_t*)malloc(sizeof(polynomial_t));
	assert(poly_list2 != NULL);
    return poly_list2;
}

/* Add a term to a polynomial.
 *
 * This function doesn't check if the polynomial already contains a term with the
 * same exponent as the term being added; in other words, it's the caller's 
 * reponsibility to ensure that the polynomial doesn't have terms with duplicate 
 * exponents.
 *
 * Terminate the program via assert if there's no room in the polynomial for 
 * additional terms.
 */
void add_term(polynomial_t *poly, term_t *term)
{
	assert((*poly).num_terms < MAX_TERMS);
	(*poly).terms[(*poly).num_terms] = term;
	(*poly).num_terms += 1;
}

/* Return the value of a polynomial when it is evaluated at x.
 *
 * Terminate the program via assert if the polynomial has 0 terms.
 */
double eval_polynomial(polynomial_t *poly, double x)
{
	assert((*poly).terms != 0);
	double sum;
	for (int i = 0; i < (*poly).num_terms; i++) {
		sum += eval_term((*poly).terms[i], x);
	}
    return sum;
}
