class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int wsz = 2 * k + 1;
        vector<int> ans(n,-1);
        if(n<wsz) return ans;

        long long sum = 0;
        int head = 0, tail = 0;

        for(head=0;head<n;head++){
            sum += nums[head];
            while(head-tail+1 > wsz){
                sum-=nums[tail];
                tail++;
            }


            if(head-tail+1 == wsz){
                ans[head-k] = sum / wsz;
            }
        }
        return ans;
    }
};