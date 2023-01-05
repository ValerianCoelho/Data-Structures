#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *link;
};

struct node *creation(struct node *start, int no_of_terms)
{
    struct node *p;
    for(int i=0; i<no_of_terms; i++)
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));

        printf("Enter the coeff value of term %d : ", i+1);
        scanf("%d",&temp->coeff);

        printf("Enter the exp value of term %d : ", i+1);
        scanf("%d", &temp->exp);

        printf("\n");

        temp->link = NULL;

        if(start == NULL){
            start = temp;
            p = temp;
        }
        else{
            p->link = temp;
            p = p->link;
        }
    }
    return start;
}

struct node *insert(struct node *start, int coeff, int exp)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->coeff = coeff;
    temp->exp = exp;
    temp->link = NULL;

    // If the linked list is empty
    if(start == NULL){
        start = temp;
        return start;
    }

    struct node *p = start;

    // Traversing to the end of the Linked List
    while(p->link != NULL){
        p = p->link;
    }
    p->link = temp;
    return start;
}

struct node *add(struct node *sp1, struct node *sp2)
{
    struct node *p1 = sp1;
    struct node *p2 = sp2;
    struct node *start = NULL;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->exp > p2->exp)
        {
            start = insert(start, p1->coeff, p1->exp);
            p1 = p1->link;
        }
        else if(p2->exp > p1->exp)
        {
            start = insert(start, p2->coeff, p2->exp);
            p2 = p2->link;
        }
        else
        {
            start = insert(start, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    while(p1 != NULL)
    {
        start = insert(start, p1->coeff, p1->exp);
        p1 = p1->link;
    }
    while(p2 != NULL)
    {
        start = insert(start, p2->coeff, p2->exp);
        p2 = p2->link;
    }
    return start;
}

struct node *mult(struct node *sp1, struct node *sp2)
{
    struct node *p1 = sp1;
    struct node *p2 = sp2;
    struct node *start = NULL;

    if(p1 == NULL || p2 == NULL)
    {
        printf("The Multiplied Polynomial is zero");
        return start;
    }

    while(p1 != NULL)
    {
        p2 = sp2;
        while(p2 != NULL)
        {
            start = insert(start, p1->coeff * p2->coeff, p1->exp + p2->exp);
            p2 = p2->link;
        }
        p1 = p1->link;
    }
    return start;
}

void display(struct node *start)
{
    printf("Expression : ");
    struct node *p = start;
    while(p != NULL)
    {
        // Here 'x' is the unknown variable
        printf("%d x^%d",p->coeff, p->exp);
        p = p->link;
        if(p != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    // sp1 -> start_pointer_1
    struct node *sp1 = NULL;
    sp1 = insert(sp1, 7, 2);
    sp1 = insert(sp1, 5, 1);
    printf("\nPolynomial One :\n");
    display(sp1);

    // sp2 -> start_pointer_2
    struct node *sp2 = NULL;
    sp2 = insert(sp2, 3, 1);
    sp2 = insert(sp2, 4, 0);
    printf("\nPolynomial Two :\n");
    display(sp2);

    // rp -> result_pointer
    struct node *rp = NULL;

    // Adding
    rp = add(sp1, sp2);
    printf("\nAdding :\n");
    display(rp);

    // Multilplying
    printf("\nMultiplying :\n");
    rp = mult(sp1, sp2);
    display(rp);

    printf("\n");
    return 0;
}