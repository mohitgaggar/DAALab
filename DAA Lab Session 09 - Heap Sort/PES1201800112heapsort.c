#include<stdio.h>
#include<stdlib.h>
#include "heapSort.h"
/**
 * Given an array a[], build a max heap by calling maxHeapify on each parent 
 * starting from the last non-leaf node(at n/2 - 1 th index) down to the root node(at 0th index).
 * Return a heap structure pointing to the same array a[], with size n.
 */
Heap buildMaxHeap(int *const a, int n)
{
    Heap h;
    h.a=a;
    h.size=n;
    int i;
    for (i = (n/2-1); i >=0; i--)
    {
        maxHeapify(h,i);
    }
    return h;

}

/**
 * MAX_HEAPIFY: Compare h.a[idx] with its two children(if they exist), 
 * and swap the smallest of the three with the element at idx, 
 * and recursively call maxHeapify on the child node that got swapped.
 */
void maxHeapify(Heap h, int idx)
{
    int c=1,temp;
    int n=h.size;
    if(2*idx+1 < h.size)
    { 
        if((2*idx+2)<n && h.a[2*idx+2] > h.a[2*idx+1])
            c=2;
        // printf("C= %d %d\n",c,h.a[2*idx +c]);
        if(h.a[2*idx+c] > h.a[idx])
        {
            temp=h.a[2*idx+c];
            h.a[2*idx+c]=h.a[idx];
            h.a[idx]=temp;
            maxHeapify(h,2*idx+c);
        }
        // printf("Q  ");
        // for(int i=0;i<h.size;i++)
        //     printf("%d ",h.a[i]);
        // printf("\n");
    }
}   

/**
 * HEAP_SORT: Sort array a[] by first building max heap, 
 * and then, iteratively swap the max element with last element
 * and call heapify on the root node. Remember to decrease heap.size after each iteration.
 */
void heapSort(int *const a, int n)
{
    int i;
    int temp;
    Heap h;
    h=buildMaxHeap(a,n);
    for(i=1;i<n;i++)
    {   
        temp=a[n-i];
        a[n-i]=a[0];
        a[0]=temp;
        h.size--;
        maxHeapify(h,0);

    }
}

/**
 * A great article to understand heap sort:
 * https://medium.com/basecs/heapify-all-the-things-with-heap-sort-55ee1c93af82
 */