class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        long long prod = 1;
        int tail = 0, n = nums.size();
        int ans = 0;
        
        for (int head = 0; head < n; ++head) {
            prod *= nums[head];
            
            while (prod >= k) {
                prod /= nums[tail];
                tail++;
            }
            
          
            ans += (head - tail + 1);
        }
        
        return ans;
    }
};
