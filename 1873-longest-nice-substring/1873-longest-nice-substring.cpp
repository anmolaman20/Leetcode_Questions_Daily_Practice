class Solution {
public:
    string longestNiceSubstring(string s) {
        set<char> st(begin(s),end(s));
        for(int i=0;i<s.length();++i){
            if(st.count(toupper(s[i]))==0 or st.count(tolower(s[i]))==0){
                string s1 = longestNiceSubstring(s.substr(0,i));
                string s2 = longestNiceSubstring(s.substr(i+1));
                return s1.length()>=s2.length() ? s1 : s2;
            }
        }
        return s;
    }
};