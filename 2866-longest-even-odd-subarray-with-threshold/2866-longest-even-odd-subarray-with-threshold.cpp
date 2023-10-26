class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int th) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0 and nums[i]<=th){
                int cnt = 1;
                for(int j=i;j<n-1;j++){
                    if(nums[j]%2!=nums[j+1]%2 and nums[j+1]<=th){
                        cnt++;
                    }else{
                        break;
                    }
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};