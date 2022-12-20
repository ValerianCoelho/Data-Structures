#include <stdio.h>
#include <stdlib.h>
#include "..\Header Files\TUI.h"

struct node{
    int data;
    struct node *link;
};

struct node *front = NULL, *rear = NULL;

void enqueue(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){
        printf("Memory not allocated\n");
        getch();
        return;
    }

    printf("Enter the item to be inserted : ");
    scanf("%d", &temp->data);

    temp->link = NULL;

    if(front == NULL)   front = temp;
    else rear->link = temp;

    rear = temp;
}

void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
    }
    else{
        struct node *temp = front;
        front = front->link;

        int item = temp->data;
        free(temp);

        printf("Element %d was deleted\n", item);
    }
    getch();
}

void peek(){
    if(front == NULL){
        printf("Queue Underflow\n");
    }
    else{
        printf("Item at the back of the queue is %d\n", rear->data);
    }
    getch();
}

void display(){
    printf("Queue : ");
    struct node *temp = front;

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
    char Options[4][20] = {"Enqueue", "Dequeue", "Peek", "Display"};
    int choice;

    while(1){
        choice = WhiteHighlight(Header, Options, 4, prevChoice);
        prevChoice = choice;

        switch(choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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