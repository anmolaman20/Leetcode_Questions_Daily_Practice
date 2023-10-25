class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        set<int> st;
        map<int,int> mp;
        int head = 0, tail = 0, n = cards.size(), ans = INT_MAX;
        for(head=0;head<n;head++){
            if(st.count(cards[head])){
                while(cards[tail]!=cards[head]) st.erase(cards[tail]), tail++;
                ans = min(ans,head-tail+1);
                tail++;
                
            }else{
                st.insert(cards[head]);
            }

            // mp[cards[head]]++;

            // while(mp[cards[head]]>1){
            //     ans = min(ans,head-tail+1);
            //     mp[cards[tail]]--;
            //     tail++;
            // }
        }
        return (ans==INT_MAX ? -1 : ans);
    }
};