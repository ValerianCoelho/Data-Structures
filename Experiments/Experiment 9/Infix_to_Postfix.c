#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char symbol){
    stack[++top] = symbol;
}

char pop(){
    return stack[top--];
}

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

    int p = 0; // 'p' holds the index of array postfix
    char *symbol;

    printf("Enter the Infix Expression : ");
    scanf("%s", infix);

    symbol = infix;

    while(*symbol != '\0'){
        if(isalnum(*symbol)){
            postfix[p++] = *symbol;
        }
        else if(*symbol == '('){
            push(*symbol);
        }
        else if(*symbol == ')'){
            while(stack[top] != '('){
                postfix[p++] = pop();
            }
            pop(); // This statement pops the '(' symbol from the stack
        }
        else{
            while(priority(stack[top]) >= priority(*symbol)){
                postfix[p++] = pop();
            }
            push(*symbol);
        }
        symbol++;
    }
    while(top != -1){
        postfix[p++] = pop();
    }
    printf("Postfix Expression : %s", postfix);
    return 0;
}