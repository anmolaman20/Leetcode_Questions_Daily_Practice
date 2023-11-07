class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int mnt = 0;
        int ans = 0;
        int n = dist.size();

        for(int i=0;i<n;i++) dist[i] = ceil((dist[i]*1.0)/speed[i]);

        sort(dist.begin(),dist.end());

        for(int i=0;i<n;i++){
            if(dist[i] > mnt) ans++;
            else break;
            mnt++;
        }
        return ans;
    }
};