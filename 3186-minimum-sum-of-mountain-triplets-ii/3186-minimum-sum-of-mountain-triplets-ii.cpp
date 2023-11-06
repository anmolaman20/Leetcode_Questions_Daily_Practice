class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> ls(n);
        vector<int> rs(n);

        ls[0] = nums[0];
        rs[n-1] = nums[n-1];

        for(int i=1;i<n;i++){
            ls[i] = min(ls[i-1],nums[i]);
            rs[n-i-1] = min(rs[n-i],nums[n-i-1]);
        }

        for(auto& it : ls) cout<<it<<" ";
        cout<<endl;
        for(auto& it : rs) cout<<it<<" ";

        int ans = INT_MAX;

        for(int i=1;i<n-1;i++){
            if(ls[i-1]<nums[i] and rs[i+1]<nums[i]) ans = min(ans,ls[i-1]+nums[i]+rs[i+1]);
        }

        return ans==INT_MAX ? -1 : ans;
    }
};