class Solution {
public:
    #define all(c) c.begin(),c.end()
    int maximumGap(vector<int>& nums) {
        sort(all(nums));
        int i=0;
        int n = nums.size(),mx = INT_MIN;
        while(i<n-1){
            if(nums[i+1]-nums[i]>mx){
                mx = nums[i+1]-nums[i];
            }
            ++i;
        }
        return mx==INT_MIN ? 0 : mx;
    }
};