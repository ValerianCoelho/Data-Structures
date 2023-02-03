#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};


void display(struct node* start)
{
    // printf("The linked list is : ");
    printf("\033[95mThe linked list is : ");

    struct node *current = start;

    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\033[0m");
}

struct node *addatbeg(struct node* start, int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->data = item;
    temp->next = start;
    temp->prev = NULL;
    start = temp;

    return start;
}

struct node *addatend(struct node *start, int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->data = item;
    temp->next = NULL;

    struct node *current = start;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = temp;
    temp->prev = current;
    return start;

}

struct node*addafter(struct node *start, int item, int element)
{
    if(start == NULL)
    {
        printf("The List is empty");
        return start;
    }

    struct node *current = start;

    while(current!= NULL)
    {
        if(current->data == element)
        {
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->data = item;
            temp->next = current->next;
            temp->prev = current;
            current->next = temp;
            return start;
        }
        current = current->next;
    }
    printf("Element not found");
    return start;
}

struct node *addbefore(struct node *start, int item, int element)
{
    if(start == NULL)
    {
        printf("The list is empty");
        return start;
    }

    if(start->data == element)
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = item;
        temp->next = start;
        temp->prev = NULL;
        start->prev = temp;
        start = temp;
        return start;
    }

    struct node *current = start;

    while(current->next != NULL)
    {
        if(current->next->data == element)
        {
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->data = item;
            temp->next = current->next;
            temp->prev = current;
            current->next = temp;
            return start;
        }
        current = current->next;
    }
    printf("Element not found");
    return start;
}

struct node *addatpos(struct node *start, int item, int pos)
{
    if(start == NULL)
    {
        printf("The Linked List is empty");
        return start;
    }
    struct node *current = start;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;

    if(pos == 1)
    {
        temp->next = start;
        temp->prev = NULL;
        start = temp;
        return start;
    }

    for(int i=1; i<pos-1 && current != NULL; i++)
    {
        current = current->next;
    }

    if(current == NULL)
    {
        printf("Position out of bounds");
    }

    else
    {
        temp->next = current->next;
        temp->prev = current;
        current->next = temp;
    }
    return start;    
}

struct node *delete(struct node *start, int item)
{
    struct node *temp;
    struct node *current = start;

    if(start->data == item)
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
        return start;
    }

    while(current->next != NULL)
    {
        if(current->next->data == item)
        {
            temp = current->next;
            current->next = temp->next;
            if(temp->next != NULL)
                temp->next->prev = current;
            free(temp);
            return start;
        }
        current = current->next;
    }
    printf("Element not found");
    return start;
}

struct node *reverse(struct node* start)
{
    struct node *previousnode = NULL, *currentnode = start, *nextnode;
    while(currentnode != NULL)
    {
        nextnode = currentnode->next;
        currentnode->next = previousnode;
        currentnode->prev = nextnode;
        previousnode = currentnode;
        currentnode = nextnode;
    }
    start = previousnode;
    return start;
}

void search(struct node *start, int item)
{
    int pos = 0;
    struct node *current = start;
    while(current != NULL)
    {
        if(current->data == item)
        {
            printf("\033[95mElement %d found and pos %d\033[0m", item, pos+1);
            return;
        }
        pos++;
        current = current->next;
    }
    printf("Element %d not present in the linked list");
}

void count(struct node *start)
{
    int count = 0;
    struct node *current = start;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    printf("\033[95mThe no of elements in the linked list is %d\033[0m", count);
}

int main(){
    int choice, element, item, pos;
    struct node *start = NULL;
    system("cls");
    // printf("1)Traversal of a singly linked list\n2)Searching in a singly linked list\n3)Insertion at the begining of the linked list\n4)Insertion in an empty linked list\n5)Insertion at the end of the linked list\n6)Insertion before a node\n7)Insertion after a node\n8)Insertion at a particular position\n9)Insertion at the end\n10)Deletion in a singly linked list\n11)To count the number of elements in the linked list\n12)Reversing a singly linked list");    
    printf("\033[93m1)Traversal of a singly linked list\n2)Searching in a singly linked list\n\033[92m3)Insertion at the begining of the linked list\n4)Insertion in an empty linked list\n5)Insertion at the end of the linked list\n6)Insertion before a node\n7)Insertion after a node\n8)Insertion at a particular position\n\033[91m9)Deletion in a singly linked list\n\033[93m10)To count the number of elements in the linked list\n\033[94m11)Reversing a singly linked list\033[0m");    
    while(1)
    {
        printf("\nEnter Choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				display(start);
			break;
			
			case 2:
				printf("Enter the element to be searched : ");
				scanf("%d",&item);
				search(start, item);
			break;
			
			case 3:
				printf("Enter the element to be inserted : ");
				scanf("%d",&item);
				start = addatbeg(start, item);  display(start);
			break;
			
			case 4:
				printf("Enter the element to be inserted : ");
				scanf("%d",&item);
				start = addatbeg(start, item);  display(start);
			break;
			
			case 5:
				printf("Enter the element to be inserted : ");
				scanf("%d",&item);
				start = addatend(start, item);  display(start);
			break;
			
			case 6:
                printf("Enter the element to be inserted : ");
                scanf("%d",&item);
                printf("Enter the element before which %d is to be inserted : ", item);
                scanf("%d",&element);
                start = addbefore(start, item, element);
                display(start);
			break;

            case 7:
                printf("Enter the element to be inserted : ");
                scanf("%d",&item);
                printf("Enter the element after which %d is to be inserted : ", item);
                scanf("%d",&element);
                start = addafter(start, item, element); display(start);
            break;

            case 8:
                printf("Enter the element to be inserted : ");
                scanf("%d",&item);
                printf("Enter the position at which %d is to be inserted : ", item);
                scanf("%d", &pos);
                start = addatpos(start, item, pos); display(start);
			break;
			
			case 9:
                printf("Enter the Element you want to delete : ");
				scanf("%d", &item);
				start = delete(start, item);
                display(start);
			break;
			
			case 10:
				count(start);
			break;
			
			case 11:
				start = reverse(start);
                display(start);
			break;
		}
		
	}
    return 0;
}
