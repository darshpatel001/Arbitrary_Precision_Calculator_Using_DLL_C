#include "require.h"

Dlist* insert_last(Dlist *head, int data){
    Dlist *new = malloc(sizeof(Dlist));
    if(!new){
        printf("INFO: Memory allocation failed\n");
        exit(FAILURE);
    }
    new->data = data;
    new->next = new->prev = NULL;

    if(!head)
        return new;
    
    Dlist *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new;
    new->prev = temp;

    return head;
}

Dlist* create_list(char *str){
    if(!str || str[0] == '\0'){
        printf("ERROR: Empty input\n");
        exit(FAILURE);
    }

    Dlist *head = NULL;
    int i = 0;
    if(str[0] == '-'){
        is_negative = -1;
        i = 1;
    }

    for(; str[i]; i++){
        if(str[i]<'0' || str[i]>'9'){
            printf("ERROR: Invalid Number\n");
            exit(FAILURE);
        }
        head = insert_last(head, str[i]-'0');
    }
    head = remove_leading_zeros(head);
    return head;
}

void print_list(Dlist* head){
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}

Dlist* get_tail(Dlist *head){
    while(head && head->next)
        head = head->next;
    return head;
}
// Remove leading zeros
Dlist* remove_leading_zeros(Dlist *head)
{
    while (head && head->data == 0 && head->next)
    {
        Dlist *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    return head;
}

CompareResult compare(Dlist *h1, Dlist *h2){
    int len1 = 0, len2 = 0;
    Dlist *t1 = h1, *t2 = h2;

    while(t1){len1++; t1 = t1->next;}
    while(t2){len2++; t2 = t2->next;}

    if(len1>len2)   return GREATER;
    if(len1<len2)   return SMALLER;

    while (h1 && h2)
    {
        if(h1->data > h2->data) return GREATER;
        if(h1->data < h2->data) return SMALLER;

        h1 = h1->next;
        h2 = h2->next;
    }
    return EQUAL;
    
}

void free_list(Dlist *head){
    while(head){
        Dlist *temp = head;
        head = head->next;
        free(temp);
    }
}

int insert_at_first(Dlist **head, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (!new)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head)
        (*head)->prev = new;

    *head = new;

    return SUCCESS;
}