#include<stdio.h>
void display(int arr[],int n);
void merge(int arr[],int low,int mid,int high);
void merge_sort(int arr[],int low,int high);
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("\n");
}
void merge(int arr[],int low,int mid,int high)
{
    int a=mid-low+1;
    int b=high-mid;
    int arr1[a];
    int arr2[b];
    for(int i=0;i<a;i++)
    {
        arr1[i]=arr[low+i];

    }
    for(int j=0;j<b;j++)
    {
        arr2[j]=arr[j+mid+1];
    }
    int i=0;
    int j=0;
    int k=low;
    while(i<a&&j<b)
    {
        if (arr1[i]<arr2[j])
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<a)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<b)
    {
        arr[k]=arr2[j];
        k++; 
        j++;
    }
}
void merge_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main()
{
    int arr[]={67,64,37,25,75,25};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    merge_sort(arr,0,n-1);
    display(arr,n);
}