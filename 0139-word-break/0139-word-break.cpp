class Solution {
public:
    // bool wordBreakHelper(string s, unordered_set<string>& wordSet, int start) {
    //     if (start == s.length()) {
    //         return true; 
    //     }

    //     for (int end = start + 1; end <= s.length(); ++end) {
    //         string word = s.substr(start, end - start);
    //         if (wordSet.count(word) && wordBreakHelper(s, wordSet, end)) {
    //             return true; 
    //         }
    //     }

    //     return false; 
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();


        vector<bool>dp(n+1);
        dp[0] = true;

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] and wordSet.count(s.substr(j,i-j))){
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};