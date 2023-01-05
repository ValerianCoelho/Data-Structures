#include <stdio.h>

int array[100];

void merge(int left, int mid, int right){
    int leftArray[10];
    int rightArray[10];
   
    int sizeOfLeftArray = mid - left + 1;
    int sizeOfRightArray = right - (mid + 1) + 1;

    // Eg:-
    // Left            mid (mid+1)    right
    // ┌────┬────┬────┬────┬────┬────┬────┐
    // │ 32 │ 23 │ 11 │ 71 │ 42 │ 63 │ 35 │
    // └────┴────┴────┴────┴────┴────┴────┘
    // Left = 0
    // mid = 3
    // right = 6

    // sizeOfLeftArray = mid - left + 1 = 3 - 0 + 1 = 4
    // sizeOfRightArray = right - (mid + 1) + 1 = 6 - (3+1) + 1 = 3

    // ┌────┬────┬────┬────┐
    // │ 32 │ 23 │ 11 │ 71 │ leftArray
    // └────┴────┴────┴────┘
    // ┌────┬────┬────┐
    // │ 42 │ 63 │ 35 │ rightArray
    // └────┴────┴────┘
   
    // Copying Elements from 'array' to 'leftArray'
    for(int i=0; i<sizeOfLeftArray; i++){
        leftArray[i] = array[left + i];
    }
   
    // Copying Elements from 'array' to 'rightArray'
    for(int i=0; i<sizeOfRightArray; i++){
        rightArray[i] = array[(mid + 1) + i];
    }
   
    int i = 0; // For Left array index
    int j = 0; // For Right array index
    int k = left; // For main array index
   
    while(i < sizeOfLeftArray && j < sizeOfRightArray){
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < sizeOfLeftArray) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < sizeOfRightArray) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergesort(int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
   
    mergesort(left, mid);
    mergesort(mid+1, right);
   
    merge(left, mid, right);
}


int main() {
    int size;
    printf("Enter the number of elements : ");
    scanf("%d", &size);
   
    printf("Enter the elements in the array : ");
    for(int i=0; i<size; i++){
        scanf("%d", &array[i]);
    }
    mergesort(0, size-1);
   
    for(int i = 0; i<size; i++){
        printf("%d ", array[i]);
    }
    return 0;
}