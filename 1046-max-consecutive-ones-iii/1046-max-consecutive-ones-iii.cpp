class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int tail = 0, head = 0, ans = 0;
        int n = nums.size();
        int cnt1 = 0 , cnt0 = 0;
        for(head = 0;head<n;head++){
            if(nums[head]==1) cnt1++;
            else cnt0++;

            if(cnt0>k){
                while(nums[tail]!=0){
                    tail++;
                    cnt1--;
                }
                tail++;
                cnt0--;
            }

            ans = max(ans,cnt0+cnt1);
        }
        return ans;
    }
};