class Solution {
public:
    vector<int> temp;
    set<int> st;
    
    vector<string> buildArray(vector<int>& target, int n) {
        for(auto& it : target) st.insert(it);
        vector<string> ans;
        for(int i = 1; i<=n; ++i){
            temp.push_back(i);
            ans.push_back("Push");
            if(st.count(i)==0 and temp.size()) {temp.pop_back(),ans.push_back("Pop");}
            if(temp==target) return ans;
        }
        return ans;
    }
};