class Solution {
public:
    int countVowelPermutation(int n) {
        long ans = 0;
        int mod = pow(10,9)+7;
        vector<vector<long>> dp(n+1,vector<long>(5,1));

        for(int i=2;i<=n;i++){
            dp[i][0] =( dp[i-1][1]) % mod;
            dp[i][1] = (dp[i-1][0] % mod + dp[i-1][2] % mod) % mod;
            dp[i][2] = (dp[i-1][0]  % mod + dp[i-1][1] % mod + dp[i-1][3] % mod + dp[i-1][4] % mod) % mod;
            dp[i][3] = (dp[i-1][2] % mod + dp[i-1][4] % mod) % mod;
            dp[i][4] = (dp[i-1][0]) % mod;
        }


        for(int i=0;i<5;i++){
            ans = (ans + dp[n][i])%mod;
        }
        return ans;

        
    }
};