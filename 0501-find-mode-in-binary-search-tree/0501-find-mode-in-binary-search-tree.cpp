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
    int mxFreq = 0, currFreq = 0, prevVal = INT_MIN;
    vector<int> ans;

    void Inorder_Traversal_For_Getting_MaxFreq(TreeNode* root){
        if(root == NULL) return;
        Inorder_Traversal_For_Getting_MaxFreq(root->left);

        if(prevVal==root->val) currFreq++;
        else currFreq = 1;

        if(currFreq>mxFreq){
            mxFreq = currFreq;
        }

        prevVal = root->val;

        Inorder_Traversal_For_Getting_MaxFreq(root->right);
    }


    void Inorder_Traversal_For_Getting_elements_Having_Freq_MaxFreq(TreeNode* root){
        if(root==NULL) return;

        Inorder_Traversal_For_Getting_elements_Having_Freq_MaxFreq(root->left);

        if(prevVal == root->val) currFreq++;
        else currFreq = 1;
        

        if(currFreq == mxFreq) ans.push_back(root->val);

        prevVal = root->val;
        Inorder_Traversal_For_Getting_elements_Having_Freq_MaxFreq(root->right);
    }




    vector<int> findMode(TreeNode* root) {
        Inorder_Traversal_For_Getting_MaxFreq(root);
        currFreq = 0;
        prevVal = INT_MIN;
        Inorder_Traversal_For_Getting_elements_Having_Freq_MaxFreq(root);
        return ans;
    }
};


// class Solution {
// public:
//     int currFreq = 0, mxFreq = 0, prevVal = INT_MIN;
//     vector<int> ans;
//     void inorderTraversal(TreeNode* root){
//         if(!root) return;
//         inorderTraversal(root->left);
//         if(prevVal == root->val) currFreq++;
//         else currFreq = 1;
//         if(currFreq>mxFreq){
//             ans.clear();
//             ans.push_back(root->val);
//             mxFreq = currFreq;
//         }else if(currFreq==mxFreq){
//             ans.push_back(root->val);
//         }
//         prevVal = root->val;
//         inorderTraversal(root->right);

//     }
//     vector<int> findMode(TreeNode* root) {
//         inorderTraversal(root);
//         return ans;
//     }
// };




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