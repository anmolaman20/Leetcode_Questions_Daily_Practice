// class Solution {
// public:
//     int getWinner(vector<int>& arr, int k) {
//         int cnt = 1;
//         // int winner = ((arr[0] > arr[1]) ? arr[0] : arr[1]);
//         int winner;
//         if(arr[0]>arr[1]) {winner = arr[0],arr.push_back(arr[1]);}
//         else {winner = arr[1],arr.push_back(arr[0]);}

//         arr.erase(arr.begin());
//         arr.erase(arr.begin());

//         cout<<winner<<endl;

//         for(int i=2;i<arr.size();++i){
//             if(winner>arr[i]) {arr.push_back(arr[i]), cnt++;}
//             else {arr.push_back(winner), winner = arr[i], cnt = 1;}
//             arr.erase(arr.begin());
//             if(cnt==k) return winner;
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int current = arr[0]; 
        int consecutiveWins = 0; 

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > current) {
                current = arr[i];
                consecutiveWins = 1;
            } else {
                consecutiveWins++;
            }

            if (consecutiveWins == k) {
                return current;
            }
        }

        return current;
    }
};
