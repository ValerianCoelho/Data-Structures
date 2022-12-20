#include <stdio.h>
#include <stdlib.h>
#include "../Header Files/TUI.h"

struct node{
    int data;
    struct node *link;
};

struct node *front = NULL, *rear = NULL;

void enqueue(){
    int item;
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data to be inserted : ");
    scanf("%d", &item);

    temp->data = item;

    if(front == NULL)
    {
        front = temp;
        rear = temp; 
        temp->link = temp; // Making temp point to itself
    }
    else
    {
        rear->link = temp; // Adding the node to the end of the queue
        temp->link = front; // Linking the last node to the first node
        rear = temp; // Setting rear value to temp, which is now the last node
    }
}

void dequeue(){
    struct node *temp;
    if(front == NULL)
    {
        printf("Queue Underflow ");
    }
    else
    {
        if(front == front->link) // Checking if only one node is present in the queue
        {
            temp = front;
            front = NULL;
        }
        else
        {
            temp = front;
            front = front->link; // Updating the front's value, by making it point to the next node in the queue
            rear->link = front; // Updating the link of the last node to the new front node
        }
        printf("Element %d Deleted ", temp->data);
        free(temp);
    }
    getch();
}

void peek()
{
    if(front == NULL){
        printf("Queue is Empty ");
    }
    else{
        printf("Element at the rear : %d ", rear->data);
    }
    getch();
}

void display(){
    if(front == NULL){
        printf("Queue is empty ");
    }
    else{
        struct node *temp = front;
        printf("Queue : ");

        do{ 
            printf("%d ", temp->data);
            temp = temp->link;
        }while(temp != front);
    }
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