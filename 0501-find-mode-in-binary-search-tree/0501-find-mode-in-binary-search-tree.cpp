/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int currFreq = 0, mxFreq = 0, prevVal = INT_MIN;
    vector<int> ans;
    void f(TreeNode* root){
        if(!root) return;
        f(root->left);
        if(prevVal == root->val) currFreq++;
        else currFreq = 1;
        if(currFreq>mxFreq){
            ans.clear();
            ans.push_back(root->val);
            mxFreq = currFreq;
        }else if(currFreq==mxFreq){
            ans.push_back(root->val);
        }
        prevVal = root->val;
        f(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        f(root);
        return ans;
    }
};




//class Solution {
// public:
//     unordered_map<int,int> mp;
//     int mxfreq = INT_MIN;
//     void preOrder(TreeNode* root){
//         if(!root) return;
//         mp[root->val]++;
//         mxfreq = max(mxfreq,mp[root->val]);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
//     vector<int> findMode(TreeNode* root) {
//         vector<int> ans;
//         preOrder(root);
//         for(auto& it : mp){
//             if(it.second==mxfreq) ans.push_back(it.first);
//         }
//         return ans;
//     }
// };