class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        // int iD = -1, vD = -1;
        // int n = size(nums);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         int iD = abs(i-j);
        //         int vD = abs(nums[i]-nums[j]);
        //         if(iD>=indexDifference and vD>=valueDifference) return {i,j};
        //     }
        // }
        // return {-1,-1};


        int n = nums.size();
        int id1 = 0, id2 = 0, mx = nums[0], mn = nums[0];
        for(int i=id;i<n;i++){
            if(nums[i-id]>mx){
                mx = nums[i-id];
                id1 = i-id;
            }

            if(nums[i-id]<mn){
                mn = nums[i-id];
                id2 = i-id;
            }

            if(abs(nums[i]-nums[id1])>=vd) return {id1,i};
            if(abs(nums[i]-nums[id2])>=vd) return {id2,i};
        }
        return {-1,-1};
    }
};