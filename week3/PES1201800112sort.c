#include "sort.h"
void bubbleSort(int *a, int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        bubblePass(a,n-i);
    }
}

int isSorted(int *a, int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
            return 0;
    }
    return 1;
}


//Consider an array a[0] to a[n-1]. 
//For each element a[i], which is greater than or equal to all the
// elements from a[0] thru a[i-1], move a[i] to a[k] where all the elements from
// a[i+1] thru a[k] are less than a[i] and either k=n-1 or a[k+1] >= a[i].
//Essentially, one pass of bubbling larger elements from left to right.
//Eg: Array 1 4 3 2 6 5 is transformed to 1 3 2 4 5 6.
void bubblePass(int *a, int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
}


//Find the minimum number of BubblePasses required to sort by Bubble sort
// algorithm. Note that a sorted array does not require any bubblePasses. 
//Use isSorted() function before calling BubblePass().
int numBubblePasses(int *a, int n)
{
    int i=0;
    while(!isSorted(a,n))
    {
        bubblePass(a,n-i);
        i++;
    }
    return i;
}


//Find the offset (that is, index) of the maximum element in an array.
//In case of multiple occurrences of the maximum element,
// return the largest offset (that is, rightmost index).
int maxIndex(int *a, int n)
{
    int max=a[0],pos=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>=max)
            {
                max=a[i];
                pos=i;
            }
    }
    return pos;
}
//Consider an array a[0] to a[n-1].
//Let i be the largest offset of the maximum element in the array.
//Swap a[i] with a[n-1] only if i < n-1.
//Use maxIndex() declared above.
void swapWithMax(int *a, int n)
{
    int max,temp;
    max=maxIndex(a,n);
    if(n-1 > max)
    {
        temp=a[n-1];
        a[n-1]=a[max];
        a[max]=temp;
    }
    

}

//Implement Selection sort using maxIndex() and swapWithMax() declared above.
void selectionSort(int *a, int n)
{
    int temp,pos,min=0;
    for(int i=0;i<n;i++)
    {
        pos=i;
        min=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                pos=j;
                min=a[j];
            }
        }
        if(pos!=i)
        {
            temp=a[pos];
            a[pos]=a[i];
            a[i]=temp;
        }
    }
}

//Find the number of swaps in selectionSort() declared above.
int numSwaps(int *a, int n)
{
    int temp,pos,min=0,count=0,i;
    int max;
    for(i=0;i<n-1;i++)
    {
        if(isSorted(a,n))
            return count;
        else{
            max=maxIndex(a,n-i);
            if(max!=n-i-1){
            count++;
            swapWithMax(a,n-i);
            }
        }
    }
    return count;
}
