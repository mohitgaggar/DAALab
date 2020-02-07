#include "session5_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Finds time elapsed from start to end in seconds
double time_elapsed(struct timespec start, struct timespec end);

int main(int argc, char const *argv[]) {
    // int a[7] = {10, 23, 30, 23,50, 60};
    // int a[7] = {10, 23, 30,40,50, 60};
    struct timespec start, end; //timestamps
    int n;
    scanf("%d",&n);
    Record A[n],B[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%ld%d",&A[i].serialnumber,&A[i].score);
    }
    for(i=0;i<n;i++)
    {
        B[i]=A[i];
    }
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    long count = InsertionSort(B, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    printf("%ld %lf\n",count,
    time_elapsed(start, end));
    for(i=0;i<n;i++)
    {
        B[i]=A[i];
    }
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    count = BubbleSort(B, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    printf("%ld %lf\n",count,
    time_elapsed(start, end));

    for(i=0;i<n;i++)
    {
        B[i]=A[i];
    }
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    count = SelectionSort(B, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    printf("%ld %lf\n",count,
    time_elapsed(start, end));


    // clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    // offset = searchLastOccurrence(a, 6, 23);
    // clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    // if(offset == 3) {
    //     printf("%lf sec spent on test1 of searchLastOccurrence()\n",
    //         time_elapsed(start, end));
    // } else {
    //     printf("FAILED test1 of searchLastOccurrence()\n");
    // }

    // clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    // int count = numOccurrences(a, 6, 23);
    // clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    // if(count == 2) {
    //     printf("%lf sec spent on test1 of numOccurrences()\n",
    //         time_elapsed(start, end));
    // } else {
    //     printf("FAILED test1 of numOccurrences()\n");
    // }
    return 0;
}

//Time elapsed from 'start' to 'end' in seconds
double time_elapsed(struct timespec start, struct timespec end) {
	double t;
	t = (end.tv_sec - start.tv_sec); //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
	return t;
}
