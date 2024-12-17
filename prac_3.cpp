// Knapsack problem

#include <iostream>
using namespace std;

int knapsack(int cap, int w[], int val[], int n) {
    if (n == 0 || cap == 0) 
        return 0;
    if (w[n-1] > cap) 
        return knapsack(cap, w, val, n-1);
    else 
        return max(knapsack(cap, w, val, n-1), val[n-1] + knapsack(cap - w[n-1], w, val, n-1));
}

int main () {
    int cap = 35;
    int weight[] = {20, 40, 60};
    int profit[] = {60, 30, 10};
    int size = sizeof(weight) / sizeof(weight[0]);
    cout << knapsack(cap, weight, profit, size);
    return 0;
}