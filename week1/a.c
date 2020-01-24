
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int n)
{
    for(long int i=0;i<(100000*n);i++)
    {

    }
}

//Time elapsed from 'start' to 'end' in seconds
double time_elapsed(struct timespec start, struct timespec end) {
	double t;
	t = (end.tv_sec - start.tv_sec); //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
	return t;
}

int main(int argc, char const *argv[])
{
    struct timespec start, end; //timestamps
    long int n;
    scanf("%d",&n);

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    func(n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    printf("%lf",time_elapsed(start, end));
    return 0;
}
