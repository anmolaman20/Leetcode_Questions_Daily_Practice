class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int head = 0, tail = 0, ans = 0;
        for(head = 0; head < n; ++head){
            mp[s[head]]++;
            while(mp[s[head]]>1){
                mp[s[tail]]--;
                tail++;
            }
            ans = max(ans,head-tail+1);
        }
        return ans;
        
    }
};












// class Solution {
// public:
//     bool IsRepeating(string str){
//         set<char> st;
//         for(auto &it : str){
//             st.insert(it);
//         }
//         return str.length() != st.size();
//     }
//     int lengthOfLongestSubstring(string s) {
//         int n = s.length();
//         int ans = INT_MIN;
//         string str;
//         vector<string> vec;
//         for(int i=0;i<n;++i){
//             str = "";
//             for(int j=i;j<n;j++){
//                 str += s[j];
//                 // if(!IsRepeating(str)){
//                 //     ans = max(ans,(int)str.length());
//                 // }
//                 vec.push_back(str);
//             }
//         }
//         for(auto it : vec){
//             cout<<it<<endl;
//         }

//         // int ans = INT_MIN;
//         for(auto &it : vec){
//             if(!IsRepeating(it)){
//                 ans = max(ans,(int)it.length());
//             }
//         }
//         return (ans==INT_MIN?0:ans);

//     }
// };