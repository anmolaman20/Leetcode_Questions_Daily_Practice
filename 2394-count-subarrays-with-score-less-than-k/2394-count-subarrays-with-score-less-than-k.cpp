class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int head = 0, tail = 0, n = nums.size();
        long long sum = 0, score = 0, cnt = 0;
        for(head=0;head<n;head++){
            sum += nums[head];
            score = (sum) * (head-tail+1);

            while(score >= k){
                sum -= nums[tail];
                tail++;
                score = (sum)*(head-tail+1);
            }
            
            cnt += (head-tail+1);
        }
        return cnt;
    }
};