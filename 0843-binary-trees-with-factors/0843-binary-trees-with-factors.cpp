class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = pow(10,9) + 7;
        unordered_map<int,long> mp;
        sort(begin(arr),end(arr));
        int n = arr.size();
        mp[arr[0]] = 1;
        for(int i=1;i<n;i++){
            long count = 1;

            for(auto it : mp){
                int ele = it.first;
                if(arr[i]%ele==0 and mp.find(arr[i]/ele) != mp.end()){
                    count += (mp[ele]*mp[arr[i]/ele]);
                }
            }
            mp[arr[i]] = count;
        }

        int ans = 0;
        for(auto it : mp){
            ans = (ans + it.second)%mod;
        }

        return ans;
    }
};