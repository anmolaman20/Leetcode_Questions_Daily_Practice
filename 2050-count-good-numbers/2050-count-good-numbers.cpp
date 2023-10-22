// class Solution {
// public:
//     int mod = 1e9 + 7;
//     int countGoodNumbers(long long n) {
//         if(n==1) return 5;
//         long long x = n/2;
//         long long ans = 1;
//         while(x--){
//             ans = ans*20;
//             ans %= mod;
//         }
//         if(n%2!=0){
//             ans = ans * 5;
//             ans %= mod;
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int mod = 1e9 + 7;

    long long power(long long base, long long exponent) {
        if (exponent == 0) return 1;
        if (exponent % 2 == 0) {
            long long temp = power(base, exponent / 2);
            return (temp * temp) % mod;
        } else {
            return (base * power(base, exponent - 1)) % mod;
        }
    }

    int countGoodNumbers(long long n) {
        if (n == 1) return 5;
        long long exp = n / 2;
        
        
        long long ans = (power(4, exp) * power(5, exp)) % mod;
        
        if(n%2!=0){
            ans = ans * 5;
            ans %= mod;
        }
        return ans;
    }
};






