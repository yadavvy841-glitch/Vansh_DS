#include<stdio.h>
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("\n");
}
int partition(int arr[],int p,int r)
{
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(arr[j]<x)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[p];
            arr[p]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[r];arr[r]=temp;
    return i+1;
}
void quick_sort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q=partition(arr,p,r);
        quick_sort(arr,p,q-1);
        quick_sort(arr,q+1,r);
    }
}
int main()
{
    int arr[]={66,74,84,58,34,76};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    quick_sort(arr,0,n-1);
    display(arr,n);
}