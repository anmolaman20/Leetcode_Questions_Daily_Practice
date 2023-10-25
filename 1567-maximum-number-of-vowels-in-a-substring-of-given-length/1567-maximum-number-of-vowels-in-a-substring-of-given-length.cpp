class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> st{'a','e','i','o','u'};
        int head = 0, n = s.length(), tail = 0, ans = 0, v = 0;
        for(head=0;head<n;head++){
            
            if(st.count(s[head])) v++;

            while((head-tail+1) > k){
                if(st.count(s[tail])) v--;
                tail++;
            }

            if((head-tail+1)==k){
                ans = max(ans,v);
            }

        }
        return ans;
    }
};