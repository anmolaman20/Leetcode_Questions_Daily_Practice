class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int sr, sc;

        for(int gap = 0; gap < n; ++gap){
            for(int i = 0, j = gap; j < n; ++i, ++j){
                if(gap==0){
                    dp[i][j] = true;
                }else if(gap==1){
                    if(s[i]==s[j]) dp[i][j] = true;
                    else dp[i][j] = false;
                }else{
                    if(s[i]==s[j] and dp[i+1][j-1]) dp[i][j] = true;
                    else dp[i][j] = false;
                }

                if(dp[i][j]) sr = i, sc = j;
            }
        }

        string ans;
        for(int x = sr; x <= sc; x++) ans += s[x];
        return ans;
    }
};