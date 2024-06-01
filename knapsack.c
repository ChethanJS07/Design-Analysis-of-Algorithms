#include <stdio.h>

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

void knapsack(int n, int profit[], int weight[], int capacity) 
{
    int i, w;
    int K[n + 1][capacity + 1];
    for (i = 0; i <= n; i++) 
    {
        for (w = 0; w <= capacity; w++) 
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(profit[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int selected[n];
    for (i = 0; i < n; i++) 
    {
        selected[i] = 0;
    }
    int j = capacity;
    for (i = n; i > 0 && j > 0; i--) 
    {
        if (K[i][j] != K[i - 1][j]) 
        {
            selected[i - 1] = 1;
            j -= weight[i - 1];
        }
    }
    for (i = 0; i < n; i++) 
    {
        printf("%d ", selected[i]);
    }
    printf("\n");
    printf("%d\n", K[n][capacity]);
}

int main() 
{
    int n, i, capacity;
    scanf("%d", &n);
    int profit[n], weight[n];
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &profit[i]);
    }
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &weight[i]);
    }
    scanf("%d", &capacity);
    knapsack(n, profit, weight, capacity);
    return 0;
}
