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

    for(i=0; i<n ;i++) {
        if(list[i] == key){
            pos = i+1;
            break;
        }
    }
    if(pos == -1) printf("The element is not present in the list");
    else printf("The element is found at position : %d",pos);
}
