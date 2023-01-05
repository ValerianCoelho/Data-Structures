#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../Header Files/TUI.h"

// #undef HighlightLen
// #define HighlightLen 60

struct node
{
    int data;
    struct node *link;
};

int count(struct node *start)
{
    int count = 0;
    struct node *current = start;
    while (current != NULL) {
        count++;
        current = current -> link;
    }
    return count;
}

void display(struct node *start)
{
    struct node *current = start;
    printf("The linked list is : ");
    while (current != NULL) {
        printf("%d ", current -> data);
        current = current -> link;
    }
}

void search(struct node *start, int item)
{
    int count = 0;
    struct node *current = start;
    while (current != NULL) {
        count++;
        if (current -> data == item) {
            printf("Element %d is found at position %d", item, count);
            return;
        }
        current = current -> link;
    }
    printf("Element %d not present in the linked list", item);
}

struct node *add_at_beg(struct node *start, int item)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = item;
    temp -> link = start;
    start = temp;
    return start;
}

struct node *add_at_end(struct node *start, int item)
{
    struct node *current = start;
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = item;
    temp -> link = NULL;

    // If the Linked List is empty
    if (start == NULL) {
        start = temp;
        return start;
    }
    
    // If the Linked List has only one node
    if (start -> link == NULL) {
        start -> link = temp;
        return start;
    }

    // If the linked List has more than one node
    while (current -> link != NULL) {
        current = current -> link;
    }
    current -> link = temp;
    return start;
}

struct node *add_before(struct node *start, int item, int element)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = item;

    // If you are adding 'item' before the first node
    if (start -> data == element) {
        temp -> link = start;
        start = temp;
        return start;
    }

    struct node *current = start;
    while (current -> link != NULL) {
        if (current -> link -> data == element) {
            temp -> link = current -> link;
            current -> link = temp;
            return start;
        }
        current = current -> link;
    }
    printf("\nElement not present");
    getch();
    return start;
}

struct node *add_after(struct node *start, int item, int element)
{
    struct node *current = start;
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = item;

    while (current != NULL) {
        if (current -> data == element) {
            temp -> link = current -> link;
            current -> link = temp;
            return start;
        }
        current = current -> link;
    }
    printf("\nElement not present");
    getch();
    return start;
}

struct node *add_at_pos(struct node *start, int item, int pos)
{
    struct node *current = start;
    struct node *temp = (struct node *) malloc(sizeof(struct node));

    if (pos > count(start)) {
        printf("\nPosition out of bounds");
        getch();
        return start;
    }

    for (int i = 1; i < pos && current != NULL; i++)
        current = current -> link;

    temp -> data = item;
    temp -> link = current -> link;
    current -> link = temp;
    return start;
}

struct node *del(struct node *start, int item)
{
    struct node *temp;

    // Deletion of the first node
    if(start -> data == item){
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }

    struct node *current = start;
    while(current -> link != NULL){
        if(current -> link -> data == item){
            temp = current -> link;
            current -> link = temp -> link;
            free(temp);
            return start;
        }
    }
}

struct node *reverse(struct node *start)
{
    struct node *prev = NULL;
    struct node *current = start;
    struct node *next;

    while (current != NULL) {
        next = current -> link;
        current -> link = prev;
        prev = current;
        current = next;
    }
    start = prev;
    return start;
}

int main() {
    struct node *start = NULL;
    int choice, prevChoice = 1, element, item, pos;
    char Header[40] = "Choose One of the Following Options :-";  
    char Options[9][100] = {
                            "Traversal",
                            "Searching",
                            "Insertion at the begining of the linked list",
                            "Insertion in an empty linked list",
                            "Insertion at the end of the linked list",
                            "Insertion in between the nodes",
                            "Deletion in a singly linked list",
                            "To count the number of elements in the linked list",
                            "Reversing a singly linked list"
                        };     
    while (1) {
        choice = WhiteHighlight(Header, Options, 9, prevChoice, 10);
        prevChoice = choice;

        switch (choice) {
            case 1:
                display(start);
                getch();
                break;
            case 2:
                printf("Enter the element to be searched : ");
                scanf("%d", & item);
                system("cls");
                search(start, item);
                getch();
                break;
            case 3:
                printf("Enter the element to be inserted : ");
                scanf("%d", & item);
                start = add_at_beg(start, item);
                break;
            case 4:
                printf("Enter the element to be inserted : ");
                scanf("%d", & item);
                start = add_at_beg(start, item);
                break;
            case 5:
                printf("Enter the element to be inserted : ");
                scanf("%d", & item);
                start = add_at_end(start, item);
                break;
            case 6:
                printf("1)Before a node\n2)After a node\n3)At a given position\nEnter : ");
                scanf("%d", & choice);
                system("cls");
                switch (choice) {
                case 1:
                    printf("Enter the element to be inserted : ");
                    scanf("%d", & item);
                    printf("\nEnter the element before which %d is to be inserted : ", item);
                    scanf("%d", & element);
                    start = add_before(start, item, element);
                    break;
                case 2:
                    printf("Enter the element to be inserted : ");
                    scanf("%d", & item);
                    printf("\nEnter the element after which %d is to be inserted : ", item);
                    scanf("%d", & element);
                    start = add_after(start, item, element);
                    break;
                case 3:
                    printf("Enter the element to be inserted : ");
                    scanf("%d", & item);
                    printf("\nEnter the position at which %d is to be inserted : ", item);
                    scanf("%d", & pos);
                    start = add_at_pos(start, item, pos);
                    break;
                }
                break;
            case 7:
                printf("Enter the element to be deleted : ");
                scanf("%d", &item);
                start = del(start, item);
                break;
            case 8:
                printf("The number of elements in the linked list is %d", count(start));
                getch();
                break;
            case 9:
                start = reverse(start);
                break;
        }
    }
    return 0;
}