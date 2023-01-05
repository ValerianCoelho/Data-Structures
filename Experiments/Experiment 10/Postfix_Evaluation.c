#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(char item){
    stack[++top] = item - 48;
}

char pop(){
    return stack[top--];
}

int main()
{
    int n1, n2, n3;
    
    char postfix[100];
    char *symbol;
    
    printf("Enter the Postfix Expression : ");
    scanf("%s", postfix);

    symbol = postfix;

    while(*symbol != '\0'){
        if(isalnum(*symbol)){
            push(*symbol);
        }
        else{
            n2 = pop();
            n1 = pop();
            switch(*symbol){
                case '+': n3 = n1 + n2; break;
                case '-': n3 = n1 - n2; break;
                case '*': n3 = n1 * n2; break;
                case '/': n3 = n1 / n2; break;
            }
            push(n3 + 48);
        }
        symbol++;
    }
    printf("Result : %d", pop());
    return 0;
}