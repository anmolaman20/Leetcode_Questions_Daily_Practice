class Solution {
public:
    vector<string> ans;
    void help(string s1,string s2, int n){

        if(n==3 and s1.size()<=3 and s1.size()!=0){
            ans.push_back(s2+s1);
            if((s1.size()>1 and s1[0] == '0') || (s1.size() == 3 and s1>"255")){
                ans.pop_back();
            }
        }

        if(n<3){
            if(s1.size()>1){
                help(s1.substr(1),s2+s1.substr(0,1)+".",n+1);
            }

            if(s1.size() > 2 and s1[0] != '0'){
                help(s1.substr(2),s2+s1.substr(0,2)+".",n+1);
            }

            if(s1.size() > 3 and s1[0] != '0' and s1.substr(0,3)<="255"){
                help(s1.substr(3),s2+s1.substr(0,3)+".",n+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12 and s.size()<4) return {};
        help(s,"",0);
        return ans;
    }
};