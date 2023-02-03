#include <stdio.h>
int main()
{
    int n, i,key, pos = -1, list[30];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    
    printf("Enter the elements in the list : ");
    for(i=0; i<n ;i++) {
        scanf("%d",&list[i]);
    }

    printf("Enter the element you want to search : ");
    scanf("%d",&key);

    int low = 0;
    int high = n-1;
    int mid = (low+high)/2;

    while(low <= high){
        if(key == list[mid]){
            pos = mid + 1;
            break;
        }
        else if(key < list[mid]) {
            high = mid-1;
        }  
        else if(key > list[mid]) {
            low = mid + 1;
        }  
        
        mid = (low + high)/2;
    }
    if(pos == -1)   printf("The element is not present in the list");
    else    printf("The element is found at position : %d",pos);
    return 0;
}
