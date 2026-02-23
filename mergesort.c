#include<stdio.h>
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
        k++;
        j++;
    }
    while(j<b)
    {
        arr[k]=arr2[j];
        k++; 
        j++;
    }
}
void merge_sort