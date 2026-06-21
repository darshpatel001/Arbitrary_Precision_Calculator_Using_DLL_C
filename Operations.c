#include "require.h"



// -------------------- ADD --------------------
Dlist* add(Dlist* h1, Dlist* h2)
{
    Dlist *t1 = get_tail(h1);
    Dlist *t2 = get_tail(h2);

    Dlist *res = NULL;
    int carry = 0;

    while (t1 || t2 || carry)
    {
        int sum = carry;

        if (t1)
        {
            sum += t1->data;
            t1 = t1->prev;
        }

        if (t2)
        {
            sum += t2->data;
            t2 = t2->prev;
        }

        Dlist *new = malloc(sizeof(Dlist));
        if (!new)
        {
            printf("ERROR: Memory allocation failed\n");
            exit(FAILURE);
        }

        new->data = sum % 10;
        new->prev = NULL;
        new->next = res;

        if (res)
            res->prev = new;

        res = new;
        carry = sum / 10;
    }

    return res;
}



// -------------------- SUBTRACT --------------------
// ASSUMPTION: h1 >= h2 ALWAYS
Dlist* subtract(Dlist *h1, Dlist *h2)
{
    Dlist *t1 = get_tail(h1);
    Dlist *t2 = get_tail(h2);

    Dlist *res = NULL;
    int borrow = 0;

    while (t1 || t2)
    {
        int d1 = 0, d2 = 0;

        if (t1)
        {
            d1 = t1->data;
            t1 = t1->prev;
        }

        if (t2)
        {
            d2 = t2->data;
            t2 = t2->prev;
        }

        // Apply previous borrow
        d1 = d1 - borrow;

        if (d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        int sub = d1 - d2;

        insert_at_first(&res, sub);
    }

    // Remove leading zeros
    while (res && res->data == 0 && res->next)
    {
        Dlist *temp = res;
        res = res->next;
        res->prev = NULL;
        free(temp);
    }

    return res;
}


// -------------------- MULTIPLICATION --------------------
Dlist* multiplication(Dlist* h1, Dlist* h2)
{
    Dlist *t2 = get_tail(h2);
    Dlist *result = NULL;

    int zeros = 0;

    while (t2)
    {
        Dlist *temp = NULL;
        Dlist *t1 = get_tail(h1);
        int carry = 0;

        while (t1 || carry)
        {
            int prod = carry;

            if (t1)
            {
                prod += t1->data * t2->data;
                t1 = t1->prev;
            }

            Dlist *new = malloc(sizeof(Dlist));
            if (!new)
            {
                printf("ERROR: Memory allocation failed\n");
                exit(FAILURE);
            }

            new->data = prod % 10;
            new->prev = NULL;
            new->next = temp;

            if (temp)
                temp->prev = new;

            temp = new;
            carry = prod / 10;
        }
        
        // Append zeros (place value)
        for (int i = 0; i < zeros; i++)
            temp = insert_last(temp, 0);

        if (result)
        {
            Dlist *new_res = add(result, temp);
            free_list(result);
            free_list(temp);
            result = new_res;
        }
        else
        {
            result = temp;
        }

        zeros++;
        t2 = t2->prev;
    }

    return remove_leading_zeros(result);
}



// -------------------- COPY LIST --------------------
Dlist* copy_list(Dlist *head)
{
    Dlist *new = NULL;

    while (head)
    {
        new = insert_last(new, head->data);
        head = head->next;
    }

    return new;
}



// -------------------- DIVISION --------------------
Dlist* division(Dlist* dividend, Dlist* divisor)
{
    // Division by zero
    if (!divisor || (divisor->data == 0 && divisor->next == NULL))
    {
        printf("ERROR: Division by zero\n");
        exit(FAILURE);
    }

    // If dividend < divisor → result = 0
    if (compare(dividend, divisor) == SMALLER)
        return insert_last(NULL, 0);

    Dlist *temp = NULL;
    Dlist *result = NULL;

    Dlist *t = dividend;

    while (t)
    {
        // Bring down next digit
        temp = insert_last(temp, t->data);
        temp = remove_leading_zeros(temp);

        int count = 0;

        // Repeated subtraction
        while (compare(temp, divisor) != SMALLER)
        {
            Dlist *new_temp = subtract(temp, divisor);

            free_list(temp);
            temp = new_temp;

            count++;
        }

        result = insert_last(result, count);
        t = t->next;
    }

    result = remove_leading_zeros(result);

    // cleanup temp (remainder not used)
    if (temp)
        free_list(temp);

    return result;
}