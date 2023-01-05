#include <stdio.h>

char stack[100];
int top = -1;

char peek(){
    return stack[top];
}

void push(char symbol){
    stack[++top] = symbol;
}

char pop(){
    return stack[top--];
}

int priority(char symbol){
    if(symbol == '(' || symbol == ')')
        return 1;
    if(symbol == '[' || symbol == ']')
        return 2;
    if(symbol == '{' || symbol == '}')
        return 3;
}

int main()
{
    char expression[100];
    char *symbol;

    printf("Enter the Expression : ");
    scanf("%s", expression);

    symbol = expression;

    while(*symbol != '\0'){
        if(*symbol == '(' || *symbol == '[' || *symbol == '{')
        {
            push(*symbol);
        }
        else if(*symbol == ')' || *symbol == ']' || *symbol == '}')
        {
            if(priority(peek()) == priority(*symbol))
                pop();
            else
                break;
        }
        symbol++;
    }
    if(top == -1)   printf("Expression is Valid");
    else    printf("Expression is not Valid");
    
    return 0;
}