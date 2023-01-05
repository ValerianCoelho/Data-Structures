#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *insert(struct node *start, int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;

    // If the Linked List has only one node
    if(start == NULL){
        start = temp;
        return start;
    }

    struct node *current = start;

    // Traversing till the end of the linked list
    while(current->link != NULL){
        current = current->link;
    }
    current->link = temp;
    return start;
}

void display(struct node *start)
{
    struct node *current = start;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}

struct node* merge(struct node *sp1, struct node *sp2)
{
    struct node *start;

    while(sp1 != NULL && sp2 != NULL){
        if(sp1->data < sp2->data)
        {
            start = insert(start, sp1->data);
            sp1 = sp1->link;
        }
        else
        {
            start = insert(start, sp2->data);
            sp2 = sp2->link;
        }
    }
    while(sp1 != NULL){
        start = insert(start, sp1->data);
        sp1 = sp1->link;
    }
    while(sp2 != NULL){
        start = insert(start, sp2->data);
        sp2 = sp2->link;
    }
    return start;
}

int main()
{
    struct node *sp1 = NULL;
    sp1 = insert(sp1, 1);
    sp1 = insert(sp1, 3);
    sp1 = insert(sp1, 5);
    printf("Linked List 1 : ");
    display(sp1);

    struct node *sp2 = NULL;
    sp2 = insert(sp2, 2);
    sp2 = insert(sp2, 4);
    sp2 = insert(sp2, 6);
    printf("Linked List 2 : ");
    display(sp1);

    struct node *rp = NULL;
    rp = merge(sp1, sp2);
    printf("Merged Linked List : ");
    display(rp);
    return 0;
}