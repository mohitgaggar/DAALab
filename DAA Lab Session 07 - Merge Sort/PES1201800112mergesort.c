#include<stdio.h>
#include "mergeSort.h"

// Merges two sorted halfs of an array into a single sorted array
void mergeSortedHalfs(int *a, int start, int mid, int end)
{
    int i,j,k=0;
    int b[end-start +1];
    i=start;
    j=mid+1;
    int p=0;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    while(i <= mid)
    {
        b[k++]=a[i++];
    }
    while(j <= end)
    {
        b[k++]=a[j++];
    }
    for(int k = start; k <= end; ++k)
        a[k] = b[k - start];
    
}

// Implement merge sort using the mergeSortedHalfs() declared above
// start is the index of the first element of the array
// end is the index of the last element of the array
void mergeSort(int *a, int start, int end)
{
    int mid;
    if(start < end)
    {
        mid=(end+start)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        mergeSortedHalfs(a,start,mid,end);
    }
}

// Implement insertion sort
// n - number of elements in the array
void insertionSort(int *A, int start, int end)
{
    int i,j;
    int temp;
    for(i=start+1;i<=end;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=start && A[j] > temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
}

// Implement a function which applies merge sort only if
// size of the array is larger than that of parameter
// if not apply insertion sort.
// Use mergeSortedHalfs() and insertionSort() declared above to do the same.
void selectiveMergeSort(int *a, int start, int end, int parameter)
{
    if((end-start) > parameter)
    {
        int mid;
        if(start < end)
        {
            mid=(end+start)/2;
            selectiveMergeSort(a,start,mid,parameter);
            selectiveMergeSort(a,mid+1,end,parameter);
            mergeSortedHalfs(a,start,mid,end);
        }  
    }
    else
    {
        insertionSort(a,start,end);
    }
    
}
