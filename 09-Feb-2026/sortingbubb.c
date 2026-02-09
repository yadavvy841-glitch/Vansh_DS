#include<stdio.h>
void display(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
void bubble_sort(int arr[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        int flag=1;
        for(int j=0;j<n-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=0;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
}
int main()
{
    int arr[]={9,8,7,6,5,4,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    bubble_sort(arr,n);
    display(arr,n);
}