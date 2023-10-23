class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> hash(26), temp(26), ans;
       for(auto& it : p) hash[it-'a']++;
       int tail = 0;

       for(int head=0;head<s.length();head++){
           temp[s[head]-'a']++;
           while(head-tail+1>p.size()){
               temp[s[tail]-'a']--;
               tail++;
           }

           if(temp==hash) ans.push_back(tail);
       }
       return ans;
    }
};







// class Solution {
// public:
//     string ss;
//     bool isAnagram(string str){
//         sort(str.begin(),str.end());
//         return str==ss;
//     }
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> ans;
//         int n = (int)s.length();
//         int m = (int)p.length();
//         if(m>n) return {};
//         ss = p;
//         sort(ss.begin(),ss.end());

//         for(int i=0;i<=n-m;i++){
//             string str = s.substr(i,m);
//             if(isAnagram(str)) ans.push_back(i);
//         }
//         return ans;
//     }
// };