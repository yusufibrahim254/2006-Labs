/* SYSC 2006 Lab 9 */

/* A node in a singly-linked list that stores values of type int. */

typedef struct intnode {
    int    value;
    struct intnode *next;
} intnode_t;


/* Functions presented in lectures. */

intnode_t *intnode_construct(int value, intnode_t *next);
intnode_t *push(intnode_t *head, int value);
int length(intnode_t *head);
void print_list(intnode_t *head);

/* Functions defined in Lab 9. */

intnode_t *add(intnode_t *head, int elem, int index);
void every_other(intnode_t *head);
