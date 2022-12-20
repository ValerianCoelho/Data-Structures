#include <stdio.h>
#include <stdlib.h>
#include "..\Header Files\TUI.h"

struct node{
    int data;
    struct node *link;
};

struct node *top = NULL;

void push(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){
        printf("Memory not allocated\n");
        getch();
    }
    else{
        printf("Enter the item to be pushed : ");
        scanf("%d", &temp->data);

        temp->link = top;
        top = temp;
    }
}

void pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
    }
    else{
        struct node *temp = top;
        top = top->link;

        int item = temp->data;
        free(temp);

        printf("Element %d was deleted\n", item);
    }
    getch();
}

void peek(){
    if(top == NULL){
        printf("Stack Underflow\n");
    }
    else{
        printf("Item at the top of the stack is : %d\n", top->data);
    }
    getch();
}

void display(){
    printf("stack : ");
    struct node *temp = top;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    } printf("\n");
    getch();
}

int main()
{
    int prevChoice = 1;
    char Header[40] = "Choose One of the Following Options :-";
    char Options[4][20] = {"Push", "Pop", "Peek", "Display"};
    int choice;

    while(1){
        choice = WhiteHighlight(Header, Options, 4, prevChoice);
        prevChoice = choice;

        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    }    
    return 0;
}