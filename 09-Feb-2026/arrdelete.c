#include<stdio.h>
void display(int arr[],int n);
int deleteElement(int arr[],int n,int x);
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d\n",arr[i]);
}
int deleteElement(int arr[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            break;
        }
    }
    if(i==n)
    {
        printf("not possible");
        return n;
    }
    for(int j=i;j<=n-2;j++)
    {
        arr[j]=arr[j+1];
    }
    return n-1;
}
int main()
{
    int arr[10]={10,20,30,40,50,60,70};
    int n=7;
    n =deleteElement(arr,n,40);
    display(arr,n);
    
}