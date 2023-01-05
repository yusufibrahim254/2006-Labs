/* arraystruct.h - SYSC 2006 Lab 5 */

// for part 2
typedef struct {
    int num;  // numerator
    int den;  // denominator
} fraction_t;


// for part 3
typedef struct {
	int code; // course code
	float weight; // course weight
	int gp; // course grade point
} grade_t;

typedef struct {
	int id;  // student id
	float gpa;  // student gpa
	grade_t grades[6]; // student grades
} student_t;


// for part 1
int find_max_v0(const int ar[], int n);
int find_max_v1(const int *arp, int n);
int find_max_v2(const int *arp, int n);


// for part 2
void make_fraction(int a, int b, fraction_t* pf);
void print_fraction(const fraction_t* pf);
void add_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* psum);
void multiply_fractions(const fraction_t* pf1, const fraction_t* pf2, fraction_t* pprod);

/* Helper functions. */
int gcd(int a, int b);
void reduce(fraction_t* pf);


// for part 3
void update_gpa(student_t *studentp, int numGrades);
float calc_gpa(const grade_t *pgrades, int numGrades);
