#include<stdio.h>
#include"tsp.h"
#include<limits.h>
#include<stdlib.h>
int tsp(int n, int graph[][n])
{
    int permutation[n],i,cost=0,min=INT_MAX;
    for(i=0;i<n;i++)
    {
        permutation[i]=i;
    }
    do{
        cost=getCost(n,graph,permutation);
        if(cost < min)
            min=cost;
    }
    while(get_next_permutation(permutation,n));
    return min;
}

int* printPath(int n, int graph[][n])
{
    int cost_min=tsp(n,graph);
    int * permutation=(int*)malloc(sizeof(int)*n),i,cost=0,min=INT_MAX;
    for(i=0;i<n;i++)
    {
        permutation[i]=i;
    }
    do{
        cost=getCost(n,graph,permutation);
        if(cost == cost_min)
            return permutation;
    }  
    while(get_next_permutation(permutation,n));
 
} 

int getCost(int n, int graph[][n], int *P)
{
    int cost=0;
    for(int i=0;i<n-1;i++)
    {
        cost+=graph[P[i]][P[i+1]];
    }
    cost +=graph[P[n-1]][P[0]];
    return cost;
}