#include "require.h"

int is_negative = 0;
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("USAGE: ./apc <Num1> <OP> <Num2>\n");
        printf("addition +, Subtraction -, Multiplication x, Division /\n");
        return FAILURE;
    }
    if (strlen(argv[2]) != 1)
    {
        printf("ERROR: Operator Must be single Character\n");
        printf("addition +, Subtraction -, Multiplication x, Division /\n");
        return FAILURE;
    }
    char op = argv[2][0];
    int sign1 = 1, sign2 = 1;
    if (argv[1][0] == '-')
        sign1 = -1;
    if (argv[3][0] == '-')
        sign2 = -1;

    if (!(op == '+' || op == '-' || op == 'x' || op == '/'))
    {
        printf("ERROR: Invalid Oprator\n");
        return FAILURE;
    }

    Dlist *num1 = create_list(argv[1]);
    Dlist *num2 = create_list(argv[3]);
    Dlist *Result = NULL;
    int result_sign = 1;

    if (!num1 || !num2)
    {
        printf("ERROR: List creation failed\n");
        return FAILURE;
    }
    is_negative = 0;
    switch (op)
    {
    case '+':
        if (sign1 == sign2)
        {
            Result = add(num1, num2);
            result_sign = sign1;
        }
        else
        {
            int cmp = compare(num1, num2);
            if (cmp == GREATER)
            {
                Result = subtract(num1, num2);
                result_sign = sign1;
            }
            else if (cmp == SMALLER)
            {
                Result = subtract(num2, num1);
                result_sign = sign2;
            }
            else
            {
                Result = insert_last(NULL, 0);
                result_sign = 1;
            }
        }
        break;

    case '-':
        if (sign1 != sign2)
        {
            Result = add(num1, num2);
            result_sign = sign1;
        }
        else
        {
            CompareResult cmp = compare(num1, num2);

            if (cmp == GREATER)
            {
                Result = subtract(num1, num2);
                result_sign = sign1;
            }
            else if (cmp == SMALLER)
            {
                Result = subtract(num2, num1);
                result_sign = -sign1;
            }
            else
            {
                Result = insert_last(NULL, 0);
                result_sign = 1;
            }
        }
        break;

    case 'x':
        Result = multiplication(num1, num2);
        result_sign = sign1 * sign2;
        break;
    case '/':
        Result = division(num1, num2);
        result_sign = sign1 * sign2;
    }

    Result = remove_leading_zeros(Result);
    
    printf("Result: ");
    if (result_sign == -1 && !(Result->data == 0 && Result->next == NULL))
        printf("-");

    print_list(Result);

    free_list(num1);
    free_list(num2);
    free_list(Result);

    return SUCCESS;
}
