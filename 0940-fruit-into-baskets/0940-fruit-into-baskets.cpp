class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int head = 0, tail = 0, n = fruits.size(),ans = 0;
        unordered_map<int,int>mp;

        for(head = 0; head<n; head++){
            
            mp[fruits[head]]++;

            while(mp.size()>2){
                mp[fruits[tail]]--;
                if(mp[fruits[tail]]==0) mp.erase(fruits[tail]);
                tail++;
            }                      
            
            ans = max(ans,head-tail+1);
        }

        
        return ans;
    }
};