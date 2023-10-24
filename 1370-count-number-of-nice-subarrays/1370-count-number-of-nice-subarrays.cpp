class Solution {
public:
    int atMostk(vector<int>& nums, int k){
        int head = 0, tail = 0, n = nums.size(), ans= 0;
        for(head=0;head<n;head++){
            if(nums[head]&1) k--;

            while(k<0){
                if(nums[tail]&1) k++;
                tail++;
            }

            ans += (head-tail+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostk(nums,k) - atMostk(nums,k-1);
    }
};