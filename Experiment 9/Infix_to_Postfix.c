#include <stdio.h>
#include <ctype.h>

int priority(char symbol)
{
    if(symbol == '+' || symbol == '-')
        return 1;
    if(symbol == '*' || symbol == '/')
        return 2;
    if(symbol == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100];
    char postfix[100];
    char stack[100];

    int p = 0, top = -1; // 'p' holds the index of array postfix
    char *symbol;

    printf("Enter the Infix Expression : ");
    scanf("%s", infix);

    symbol = infix;

    while(*symbol != '\0'){
        if(isalnum(*symbol)){
            postfix[p++] = *symbol;
        }
        else if(*symbol == '('){
            stack[++top] = *symbol;
        }
        else if(*symbol == ')'){
            while(stack[top] != '('){
                postfix[p++] = stack[top--];
            }
            top--; // This statement pops the '(' symbol from the stack
        }
        else{
            while(priority(stack[top]) >= priority(*symbol)){
                postfix[p++] = stack[top--];
            }
            stack[++top] = *symbol;
        }
        symbol++;
    }
    while(top != -1){
        postfix[p++] = stack[top--];
    }
    printf("Postfix Expression : %s", postfix);
    return 0;
}