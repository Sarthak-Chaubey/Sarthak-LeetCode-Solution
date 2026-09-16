int MOD = 1000000007;
int dp[1000][1001][2];

class Solution {
public:
    int numberOfSets(int n, int k) {
        memset(dp, 0, sizeof(dp));

        dp[0][0][0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;

                dp[i][j][1] = dp[i - 1][j][1];

                if (j > 0)
                    dp[i][j][1] = ((long long)dp[i][j][1] +
                                   dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) %
                                  MOD;
            }
        }

        return (dp[n - 1][k][0] + dp[n - 1][k][1]) % MOD;
    }
};