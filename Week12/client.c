#include<stdio.h>
#include<stdlib.h>
#include"session12_WarshallsFloyds.h"

int main()
{
  int n;
  scanf("%d",&n);
  int **graph = (int**)malloc(n*sizeof(int*));
  for(int i=0;i<n;i++)
    graph[i] = (int*)malloc(n*sizeof(int*));

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%d",&graph[i][j]);

  transitive_closure_warshalls(graph, n);

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      printf("%d ",graph[i][j]);
    printf("\n");
  }
  printf("\n");

  scanf("%d",&n);
  int **graph1 = (int**)malloc(n*sizeof(int*));
  for(int i=0;i<n;i++)
    graph1[i] = (int*)malloc(n*sizeof(int*));

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%d",&graph1[i][j]);

  all_pairs_shortest_path_distances_floyds(graph1, n);

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      printf("%d ",graph1[i][j]);
    printf("\n");
  }
  printf("\n");


}
// int main()
// {
//   int graph[4][4] =
//   {
//     {0,0,0,1},
//     {1,0,0,0},
//     {0,0,0,1},
//     {0,1,0,0}
//   };
//
//   transitive_closure_warshalls(graph, 4);
//   for(int i=0;i<4;i++)
//   {
//     for(int j=0;j<4;j++)
//       printf("%d ",graph[i][j]);
//     printf("\n");
//   }
//
//   int graph1[4][4] =
//   {
//     {0,1000000,3,1000000},
//     {2,0,1000000,1000000},
//     {1000000,7,0,1},
//     {6,1000000,1000000,0}
//   };
//
//   all_pairs_shortest_path_distances_floyds(graph1, 4);
//   for(int i=0;i<4;i++)
//   {
//     for(int j=0;j<4;j++)
//       printf("%d ",graph1[i][j]);
//     printf("\n");
//   }
// }
