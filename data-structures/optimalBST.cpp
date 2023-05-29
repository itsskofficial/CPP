#include <bits/stdc++.h>
using namespace std;

int sum(int frequency[], int fIndex, int j)
{
    int sum = 0;
    for (int x = fIndex; x <= j; x++)
        sum += frequency[x];
    return sum;
}

int optimalCost(int frequency[], int fIndex, int j)
{
    // if (j < fIndex)
    //     return 0;
    // if (j == fIndex)
    //     return frequency[fIndex];

    int frequencySum = sum(frequency, fIndex, j);

    int min = INT_MAX;

    for (int r = fIndex; r <= j; ++ r)
    {
        int cost = optimalCost(frequency, fIndex, r - 1) + optimalCost(frequency, r + 1, j);
        if (cost < min)
            min = cost;
    }

    return min + frequencySum;
}

int main()
{
    int keys[] = {10, 12, 20};
    int frequency[] = {34, 8, 50};

    int n = sizeof(keys) / sizeof(keys[0]);

    cout << "Cost of Optimal BST is " << optimalCost(frequency, 0, n - 1);

    return 0;
}