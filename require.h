#ifndef REQUIRE_H
#define REQUIRE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>
 
#define SUCCESS 0
#define FAILURE -1

typedef enum {
    SMALLER = -1,
    EQUAL = 0,
    GREATER = 1
}CompareResult;
extern int is_negative;

typedef struct node
{
    int8_t data;
    struct node *prev;
    struct node *next;
}Dlist;

//DLL
Dlist* insert_last(Dlist *, int );
Dlist* create_list(char *);
void print_list(Dlist*);
Dlist* get_tail(Dlist *); 
int insert_at_first(Dlist **head, int data);

//For Division Operation
Dlist* copy_list(Dlist *);
// Remove leading zeros
Dlist* remove_leading_zeros(Dlist *);

//Operation
Dlist* add(Dlist*, Dlist*);
Dlist* subtract(Dlist*, Dlist*);
Dlist* multiplication(Dlist*, Dlist*);
Dlist* division(Dlist*, Dlist*);

//Important
CompareResult compare(Dlist *h1, Dlist *h2);
void free_list(Dlist *head);

#endif