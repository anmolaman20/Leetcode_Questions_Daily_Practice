// //Recursive
// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if(n<1) return false;
//         if(n==1) return true;
//         return ((n%4)==0 and isPowerOfFour(n/4));
//     }
// };


// //Brute-force
// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if(n<=0) return false;
//         if(n==1) return true;

//         while(n>1){
//             if(n%4) return false;
//             n/=4;
//         }
//         return n==1;
//     }
// };



// //Observation on bits
// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         int cntSet = 0, cntSetPos, tPos = 1;

//         while(n){
//             if(n&1){
//                 cntSet++;
//                 cntSetPos=tPos;
//             }
//             if(cntSet>1) return false;
//             n>>=1;
//             tPos++;
//         }
//         return cntSet==1 and (cntSetPos%2);
//     }
// };


//bitmanipulation
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;

        for(int i=0;i<32;i+=2){
            if(n==(1<<i)) return true;
        }
        return false;
    }
};