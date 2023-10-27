class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int cnt = 0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        
        int sr=0,sc=0;
        for(int g = 0; g<n; g++){
            
            for(int i=0,j=g; j<n ;i++,j++){
                
                if(g==0){
                    dp[i][j] = true;
                }else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j] =true;
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
                
                if(dp[i][j]){
                    sr = i;
                    sc = j;
                }
            }
        }
        
        string ans;
        for(int i=sr;i<=sc;i++){
            ans+=s[i];
        }
        return ans;
        
    }
};