class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        for(auto& it : nums) st.insert(it);
        int dist_el = st.size();
        int n = nums.size();

        map<int,int> mp;
        int head = 0, tail = 0, ans = 0;
        for(head=0;head<nums.size();head++){
            mp[nums[head]]++;
            while(mp.size()==dist_el){
                ans+= (n-head);
                mp[nums[tail]]--;
                if(mp[nums[tail]]==0) mp.erase(nums[tail]);
                tail++;                
            }

        }
        return ans;
    }
};