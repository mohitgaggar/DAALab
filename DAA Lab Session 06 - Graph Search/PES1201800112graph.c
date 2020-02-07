#include "graphSearch.h"
#include<stdio.h>

void dfs_1(int v,int n,const int graph[][n],int visited[n],int parent)
{
    visited[v]+=1;
    int w;
    for(w=0;w<n;w++)
    {
        if(graph[v][w]==1 && w!=parent)
        {
            if(visited[w])
                visited[w]++;
            else
            {
                dfs_1(w,n,graph,visited,v);
            }
            
        }
    }
}
void dfs_2(int v,int n,const int graph[][n],int visited[n],int k,int *count)
{
    visited[v]=1;
    (*count)++;
    int ab=0;
    int w;
    for(w=0;w<n;w++)
    {
        if(v > w)
            ab=v-w;
        else 
            ab=w-v;
        if(graph[v][w]==1 && ab<=k)
        {
            if(visited[w])
                visited[w]++;
            else
            {
                dfs_2(w,n,graph,visited,k,count);
            }
            
        }
    }
}


bool isTree(int n, const int graph[][n])
{
    int visited[n];
    int i;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    dfs_1(0,n,graph,visited,0);
    for(i=0;i<n;i++)
    {
        if(visited[i]!=1)
        {
            return false;
        }
    }
    return true;
}

Result pepesAnswers(int n, const int safeSeq[][n])
{
    Result obj;
    int i=0,count=0;
    int visited[n];
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    obj.numDeliveryFrogs=0;
    obj.maxHouses=0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
            {
                count=0;
                dfs_2(i,n,safeSeq,visited,n,&count);
                obj.numDeliveryFrogs++;
                if(obj.maxHouses < count)
                    obj.maxHouses=count;
                    
            }
    }
   
    return obj;
}
Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
    Result obj;
    int i=0,count=0;
    int visited[n];
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    obj.numDeliveryFrogs=0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
            {
                count=0;
                dfs_2(i,n,safeSeq,visited,k,&count);
                obj.numDeliveryFrogs++;
                if(obj.maxHouses < count)
                    obj.maxHouses=count;
            }
    }
    obj.maxHouses=visited[0];
    for(i=1;i<n;i++)
    {
        if(visited[i]>obj.maxHouses)
            obj.maxHouses=visited[i];
    }
    return obj;
}