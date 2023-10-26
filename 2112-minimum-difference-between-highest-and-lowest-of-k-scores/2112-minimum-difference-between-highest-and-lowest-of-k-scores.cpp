class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int head = 0, tail = 0, mn = INT_MAX, mx = INT_MAX, ans = INT_MAX;

        for(head=0;head<n;head++){
            mn = min(mn,nums[head]);
            mx = max(mn,nums[head]);

            if(head-tail+1>k){
                if(nums[tail]==mn) mn = nums[tail+1];
                if(nums[tail]==mx) mx = nums[tail+1];
                tail++;
            }

            if(head-tail+1==k){
                ans = min(ans, mx - mn);
            }
        }
        return ans;

    }
};