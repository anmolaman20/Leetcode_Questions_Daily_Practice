bool cmp(string s1,string s2){
    if(s1.length()<s2.length()) return true;
    else if(s1.length()==s2.length()) return s1<s2;
    else return false;
}
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // vector<string> ans;
        string ans;
        int n = s.size(), mn = INT_MAX;
        int i,j=0,cnt1=0;

        for(i=0;i<n;i++){
            if(s[i]=='1') cnt1++;


            while(cnt1>k){
                if(s[j]=='1') cnt1--;
                j++;
            }

            
            if(cnt1==k){
                while(s[j]=='0'){
                    // ans.push_back(s.substr(j,i-j+1));
                    if(i-j+1<=mn){
                        if(i-j+1==mn){
                            ans = (s.substr(j,i-j+1) < ans ? s.substr(j,i-j+1) : ans);
                        }else ans = s.substr(j,i-j+1);
                        mn = i-j+1;
                    }
                    j++;
                }
                if(i-j+1<=mn){
                        
                        if(i-j+1==mn){
                            ans = (s.substr(j,i-j+1) < ans ? s.substr(j,i-j+1) : ans);
                        }else ans = s.substr(j,i-j+1);
                        mn = i-j+1;
                    }
                // ans.push_back(s.substr(j,i-j+1));
            }

            

            
        }
        // sort(ans.begin(),ans.end(),cmp);
        // for(auto& it : ans) cout<<it<<endl;
        // if(ans.size()>=1)
        //     fans = ans[0];
        return ans;
    }
};