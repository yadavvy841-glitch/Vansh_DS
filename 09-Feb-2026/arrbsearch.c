#include<stdio.h>
int bsearch(int arr[],int n,int x)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(x>arr[mid])
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[]={7,7,8,8,8,9,9,9,9};
    int n=9;
    printf("%d",bsearch(arr,n,8));
}
