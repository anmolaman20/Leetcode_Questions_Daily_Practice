class Solution {
public:
    int fun(string &str, int k, char x){
        int head = 0, tail = 0, ans = 0,n = str.length();
        for(head=0;head<n;head++){
            if(str[head]==x){
                if(k>0) k--;
                else{
                    while(str[tail]!=x){
                        tail++;
                    }
                    tail++;
                }
            }

            ans = max(ans,head-tail+1);
        }  
        return ans; 
    }
    
    
    int maxConsecutiveAnswers(string str, int k) {
        return max(fun(str,k,'F'),fun(str,k,'T'));
    }
};