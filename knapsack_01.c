#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0-1 Knapsack problem
void knapsack(int n, int weights[], int profits[], int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Find selected items
    int selected[n];
    int i = n, j = capacity;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            selected[i - 1] = 1;
            j -= weights[i - 1];
        } else {
            selected[i - 1] = 0;
        }
        i--;
    }

    // Print the selected items and total profit
    printf("Binary vector of item selection: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", selected[i]);
    }
    printf("\n");
    printf("Maximally optimal profit: %d\n", dp[n][capacity]);
}

int main() {
    int n;
    printf("Enter the number of entries: ");
    scanf("%d", &n);

    int profits[n], weights[n];
    printf("Enter the profits: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    printf("Enter the weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    knapsack(n, weights, profits, capacity);

    return 0;
}
