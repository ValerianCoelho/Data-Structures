#include <stdio.h>

int array[100];

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int low, int high){
    int pivot = array[high];
    int i = low;
    int j = high-1;

    while(i<=j){
        while(array[i] < pivot){ // We use '<' operator because, if array[i] == pivot, we don't want to increase i-index
            i++;
        }
        while(array[j] >= pivot && j >= i){ // We use '>=' operator because, if array[j] == pivot, we want to decrease j-index
            j--;
        }
        if(i < j){ // i > j, then all the elements are in their place for the current iteration
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i], &array[high]); // swapping the pivot element with array[i]
    return i; // We return the partition element index
}

void quicksort(int low, int high){
    if(low >= high){
        return;
    }
    int pi = partition(low, high);

    quicksort(low, pi-1);
    quicksort(pi+1, high);
}

int main()
{
    int size;
    printf("Enter the number of elements : ");
    scanf("%d", &size);
   
    printf("Enter the elements in the array : ");
    for(int i=0; i<size; i++){
        scanf("%d", &array[i]);
    }

    quicksort(0, size-1);

    printf("Sorted Array : ");
    for(int i = 0; i<size; i++){
        printf("%d ", array[i]);
    }
    return 0;
}