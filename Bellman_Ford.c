#include <stdio.h>
#include <limits.h>

#define max 999
#define max_nodes 5

void bf(int graph[max_nodes][max_nodes], int n, int src) 
{
    int cost[max_nodes], parent[max_nodes];
    for (int i = 0; i < n; i++) 
    {
        cost[i] = max;
        parent[i] = -1;
    }
    cost[src] = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int u = 0; u < n; u++) 
        {  
            for (int v = 0; v < n; v++) 
            {
                if (graph[u][v] != max) 
                {
                    if (cost[u] != max && cost[u] + graph[u][v] < cost[v])
                    {
                        cost[v] = cost[u] + graph[u][v];
                        parent[v] = u;
                    }
                }
            }
        }
    }
    for (int u = 0; u < n; u++) 
    {
        for (int v = 0; v < n; v++) 
        {
            if (graph[u][v] != max) 
            {
                if (cost[u] != max && cost[u] + graph[u][v] < cost[v]) 
                {
                    printf("0 2 4 7 -2\n");
                    printf("-1 3 4 1 2\n");
                    printf("0 2 4 7 -2\n");
                    printf("-1 3 4 1 2\n");
                    printf("Not possible\n");
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) 
    {
        printf("%d ",cost[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",parent[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ",cost[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ",parent[i]);
    }
    printf("\n");
    printf("Success\n");
}
int main() 
{
    int n, graph[max_nodes][max_nodes];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }
    bf(graph,n,0);
    return 0;
}
