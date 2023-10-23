class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = INT_MIN;
        int head = 0, tail = 0, n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0;
        for(head = 0; head < n; ++head){
            mp[nums[head]]++;
            sum+=nums[head];
            while(mp[nums[head]]>1){
                mp[nums[tail]]--;
                sum -= nums[tail];
                tail++;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};