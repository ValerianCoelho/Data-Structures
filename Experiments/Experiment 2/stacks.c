#include <stdio.h>
#include <stdlib.h>

int stack[10];
int size;

int top = -1;

int isFull()
{
	if(top == size-1)
		return 1;
	return 0;
}

int isEmpty()
{
	if(top == -1)
		return 1;
	return 0;
}

void push(int item)
{
	top = top + 1;
	stack[top] = item;
}

void pop()
{
	top = top - 1;
}

int peek()
{
	return stack[top];
}

void display()
{
	printf("Stack : ");
	for(int i=0; i <= top; i++)
		printf("%d ",stack[i]);
	printf("\n");
}

int main()
{
	int choice, item;
	printf("Enter the maximum size of the stack : ");
	scanf("%d",&size);
	system("cls");

	while(1)
	{
		printf("1)Push\n2)Pop\n3)Peek\n4)Display\n5)Exit\nEnter : ");
		scanf("%d",&choice);
		system("cls");

		switch(choice)
		{
			case 1:
				if(isFull())
				{
					printf("Overflow\n");
					break;
				}
				printf("Enter the item : ");
                scanf("%d",&item);
                system("cls");
                push(item);
                break;
			case 2:
				if(isEmpty())
				{
					printf("Underflow\n");
					break;
				}
				pop();
				break;
			case 3:
				if(isEmpty())
				{
					printf("The Stack is Empty\n");
					break;
				}
				printf("Element at Top : %d\n",peek());
                break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
                printf("Invalid Option\n");
		}
	}
	return 0;
}