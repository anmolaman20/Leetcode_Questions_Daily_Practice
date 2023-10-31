class Solution {
public:
    vector<int> Split(string s){
        vector<int> ans;
        int n = s.size();
        int i = 0;
        while(i<n){
            int revision = 0;
            while(i<n and s[i]!='.'){
                revision = revision * 10 + (s[i]-'0');
                ++i;
            }
            ans.push_back(revision);
            ++i;
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<int> vec1 = Split(version1);
        vector<int> vec2 = Split(version2);

        int n = vec1.size(), m = vec2.size();
        int i=0;

        while(i<n || i<m){
            int v1 = (i<n) ? vec1[i] : 0;
            int v2 = (i<m) ? vec2[i] : 0;

            if(v1<v2) return -1;
            else if(v1>v2) return 1;

            i++;
        }
        return 0;
    }
};