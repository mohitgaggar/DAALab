#include"session12_WarshallsFloyds.h"

void transitive_closure_warshalls(int **graph, int n)
{
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
          graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
}

void all_pairs_shortest_path_distances_floyds(int **graph, int n)
{
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(graph[i][k] + graph[k][j] < graph[i][j])
          graph[i][j] = graph[i][k] + graph[k][j];
}
