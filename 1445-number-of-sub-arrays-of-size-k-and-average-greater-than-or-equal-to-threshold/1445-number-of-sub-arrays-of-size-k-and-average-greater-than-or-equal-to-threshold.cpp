class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        long sum = 0;
        int head=0,tail=0,n=arr.size(),ans=0;
        for(head=0;head<n;head++){
            sum += arr[head];

            while(head-tail+1>k){
                sum-=arr[tail];
                tail++;
            }

            if(head-tail+1==k){
                long long avg = sum / (head-tail+1);
                if(avg>=th) ans++; 
            }
        }
        return ans;
    }
};