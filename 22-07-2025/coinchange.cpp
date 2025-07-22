#include <iostream>
#include <vector>
#include <algorithm>
// this code find ways of coin combined change problem
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution sol;
    vector<int> coins;
    int amount, coin;

    cout << "Enter the amount: ";
    cin >> amount;
    cout << "Enter the number of coin types: ";
    int n;
    cin >> n;

    cout << "Enter the coin values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coin;
        coins.push_back(coin);
    }

    int result = sol.change(amount, coins);
    cout << "Number of ways to make change: " << result << endl;

    return 0;
}