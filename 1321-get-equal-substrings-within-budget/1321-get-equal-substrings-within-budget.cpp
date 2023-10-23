class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, head = 0, tail = 0, n = s.length(),cnt =0;
        for(head = 0; head < n; ++head){
            if(s[head]==t[head]) cnt++;
            else if(abs(t[head]-s[head])<=maxCost){
                maxCost -= abs(t[head]-s[head]);
                cnt++;
            }else{
                while(abs(t[head]-s[head])>maxCost){
                    maxCost += abs(t[tail]-s[tail]);
                    tail++;
                    cnt--;
                }
                maxCost -= abs(t[head]-s[head]);
            }
            ans = max(ans,head-tail+1);
        }
        return ans;
    }
};