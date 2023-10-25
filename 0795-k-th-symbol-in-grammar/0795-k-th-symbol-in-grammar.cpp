// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         vector<string> vec;
//         vec.push_back("0");
//         for(int i=0;i<n;i++){
//             string str = "";
//             for(int j=0;j<vec[i].size();j++){
//                 str += (vec[i][j]=='0' ? "01" : "10");
//             }
//             vec.push_back(str);
//         }

//         return vec[n-1][k-1] - '0';
//     }
// };




class Solution {
public:
    int kthGrammar(int n, int k) {
        n = (1 << (n-1));
        bool flag = true;

        while(n!=1){
            n/=2;
            if(k>n){
                k-=n;
                flag = !flag;
            }
        }

        return (flag ? 0 : 1);
    }
};