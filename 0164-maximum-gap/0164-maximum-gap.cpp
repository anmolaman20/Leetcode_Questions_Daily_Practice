// class Solution {
// public:
//     #define all(c) c.begin(),c.end()
//     int maximumGap(vector<int>& nums) {
//         sort(all(nums));
//         int i=0;
//         int n = nums.size(),mx = INT_MIN;
//         while(i<n-1){
//             if(nums[i+1]-nums[i]>mx){
//                 mx = nums[i+1]-nums[i];
//             }
//             ++i;
//         }
//         return mx==INT_MIN ? 0 : mx;
//     }
// };


// class Solution {
// public:
//     int maximumGap(vector<int>& nums) {
//         int mx = INT_MIN;
//         for(auto& it : nums) mx = max(mx,it);
//         vector<bool> vec(mx+1);
//         for(auto& it : nums) vec[it] = true;
//         bool f1 = false, f2 = false;
//         int prev;
//         int ans = 0;
//         for(int i = 0;i<vec.size(); ++i){
//             if(vec[i]){
//                 if(!f1){
//                     f1 = true;
//                     prev = i;
//                 }
//                 else if(!f2){
//                     ans = max(ans,i-prev);
//                     prev = i;
//                 }
//             }
//         }
//         return ans;

//     }
// };


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;

        int mx = INT_MIN, mn = INT_MAX;
        for(auto& it : nums){
            mx = max(mx,it);
            mn = min(mn,it);
        }

        double gap = ((mx-mn)*1.0)/(n-1);
        if(gap < 1.0) gap = 1.0;

        vector<pair<int,int>> vec(n,{INT_MAX,INT_MIN});

        for(int i=0;i<n;i++){
            int pos = ((nums[i]-mn)/gap);
            vec[pos].first = min(vec[pos].first,nums[i]);
            vec[pos].second = max(vec[pos].second,nums[i]);
        }

        int prevMax = vec[0].second, ans = 0;

        for(int i=1;i<n;i++){
            if(vec[i].first == INT_MAX) continue;
            ans = max(ans,vec[i].first - prevMax);
            prevMax = vec[i].second;
        }

        return ans;
    }
};




