#include "ss.h"

void sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[j] < arr[i])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}
int searchFirstOccurrence(int arr[], int n, int key)
{
    sort(arr,n);
    int beg=0,mid,end=n-1;
    while(beg<=end)
    {
        mid=(end+beg)/2;
        printf("END=%d MID=%d BEG=%d \n",end,mid,beg);
        // for(int k=0;k<100000000;k++)
        //     {k++;}
        if(arr[mid]==key)
        {
            printf("found pos=%d",mid+1);
            return mid;
        }
        else if(arr[mid]<key)
        {
            beg=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    printf("Not found\n");
    return-1;
}
void main()
{
    int a[]={100,10,20,30,400,50,60,70};
    // sort(a,8);
    int p=searchFirstOccurrence(a,8,4020);
}
int searchLastOccurrence(int arr[], int n, int key)
{
    int i=0;
    for(i=n-1;i>=0;i--)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int numOccurrences(int arr[], int n, int key)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            count++;
        }
    }
    return count;
}