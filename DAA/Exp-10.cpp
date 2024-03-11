#include <bits/stdc++.h>
using namespace std;

int changeMaking(int coin[], int n, int sum)
{
    int a, b, x, y;

    int dp[n + 1][sum + 1];

    for (b = 0; b <= sum; b++)
        dp[0][b] = INT_MAX;

    for (a = 1; a <= n; a++)
        dp[a][0] = 0;

    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= sum; b++)
        {
            if (b >= coin[a - 1])
            {
                x = dp[a - 1][b];
                y = 1 + dp[a][b - coin[a - 1]];
                dp[a][b] = min(x, y);
            }
            else
                dp[a][b] = dp[a - 1][b];
        }
    }

    return dp[n][sum];
}

int main()
{
    int i;
    int k, sum;

    cout << "Enter the amount for whose change is needed" << endl;
    cin >> sum;

    cout << "Enter the denominations of coins availale" << endl;
    cin >> k;

    int coin[k];

    cout << "Enter the values of coins" << endl;
    for (i = 0; i < k; i++)
        cin >> coin[i];

    clock_t t = clock();
    cout << "The least number of coins whose sum is equal to required sum is" << endl;
    cout << changeMaking(coin, k, sum);

    t = clock() - t;
    float time_taken = (float)t / CLOCKS_PER_SEC;
    cout << endl
         << "Time taken by algorithm is :" << time_taken << endl;
    return 0;
}