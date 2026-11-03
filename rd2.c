#include <stdio.h>

char input[100];
int i = 0;

int e(), ep(), t(), tp(), f();

int main()
{
    printf("Recursive Descent Parser\n");
    printf("Grammar:\n");
    printf("E -> T E'\n");
    printf("E' -> + T E' | @\n");
    printf("T -> F T'\n");
    printf("T' -> * F T' | @\n");
    printf("F -> (E) | id\n");

    printf("\nEnter the string: ");
    scanf("%s", input);

    if (e() && input[i] == '\0')
        printf("\nString is accepted.\n");
    else
        printf("\nString is not accepted.\n");

    return 0;
}

int e()
{
    if (t())
        return ep();
    return 0;
}

int ep()
{
    if (input[i] == '+')
    {
        i++;
        if (t())
            return ep();
        return 0;
    }
    return 1;
}

int t()
{
    if (f())
        return tp();
    return 0;
}

int tp()
{
    if (input[i] == '*')
    {
        i++;
        if (f())
            return tp();
        return 0;
    }
    return 1;
}

int f()
{
    if (input[i] == '(')
    {
        i++;
        if (e())
        {
            if (input[i] == ')')
            {
                i++;
                return 1;
            }
        }
        return 0;
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') ||
             (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        return 1;
    }

    return 0;
}
