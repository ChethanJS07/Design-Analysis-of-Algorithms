#include <stdio.h>
#include<stdlib.h>

#define no_of_vertices 6

int main() 
{
  int n, i, j;
  int g[no_of_vertices][no_of_vertices];
  scanf("%d", &n);
  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < n; j++) 
    {
      scanf("%d", &g[i][j]);
    }
  }

  int vertex_cover[no_of_vertices] = {0};
  int count=0;
  for (i = 0; i < n; i++) 
  {
    for (j = i+1; j < n; j++) 
    {
        
      if (g[i][j] && !vertex_cover[i] && !vertex_cover[j]) 
      {
        vertex_cover[i] = vertex_cover[j] = 1;
      } 
    }
  }

  for (i = 0; i < n; i++) 
  {
    if (vertex_cover[i]) 
    {
      count+=1;
    }
  }
  printf("%d\n",count); 
  for (i = 0; i < n; i++) 
  {
    if (vertex_cover[i]) 
    {
      printf("%d ", i+1);
    }
  }
  printf("\n");
  return 0;
}
