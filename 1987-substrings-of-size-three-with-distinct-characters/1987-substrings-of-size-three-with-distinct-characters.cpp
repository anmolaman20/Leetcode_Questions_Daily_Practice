class Solution {
public:
    int countGoodSubstrings(string nums) {
        map<int,int> mp;
        int head = 0, tail = 0, ans = 0, n = nums.length();
        if(n<3) return 0;
        for(head=0;head<n;head++){
            mp[nums[head]]++;

            while(mp[nums[head]]>1 or head-tail+1>3){
                mp[nums[tail]]--;
                if(mp[nums[tail]]==0) mp.erase(nums[tail]);
                tail++;
            }

            if(head-tail+1==3){
                ans++;
            }

            
        }
        return ans;
    }
};