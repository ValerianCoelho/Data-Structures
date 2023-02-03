#include <stdio.h>
#include <stdlib.h>

int queue[10];
int size;

int front = 0;
int rear = -1;

int isFull()
{
	if(rear == size-1)
		return 1;
	return 0;
}

int isEmpty()
{
	if(front > rear)
		return 1;
	return 0;
}

void enqueue(int item)
{
	rear = rear + 1;
	queue[rear] = item;
}

void dequeue()
{
	front = front + 1;
}

int peek()
{
	return queue[rear];
}

void display()
{
	printf("Queue : ");
	for(int i=front; i <= rear; i++)
		printf("%d ",queue[i]);
	printf("\n");
}

int main()
{
	int choice, item;
	printf("Enter the maximum size of the queue : ");
	scanf("%d",&size);
	system("cls");

	while(1)
	{
		printf("1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\n5)Exit\nEnter : ");
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
                enqueue(item);
                break;
			case 2:
				if(isEmpty())
				{
					printf("Underflow\n");
					break;
				}
				dequeue();
				break;
			case 3:
				if(isEmpty())
				{
					printf("The queue is Empty\n");
					break;
				}
				printf("Element at top : %d\n",peek());
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