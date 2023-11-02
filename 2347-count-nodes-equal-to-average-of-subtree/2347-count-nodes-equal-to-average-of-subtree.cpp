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
    int ans = 0;
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        postOrder(root);
        return ans;
    }
    vector<int> postOrder(TreeNode* root){
        if(!root) return {0,0};

        vector<int> left = postOrder(root->left);
        vector<int> right = postOrder(root->right);

        int tsum = left[0] + right[0] + root->val;
        int tcnt = left[1] + right[1] + 1;

        if(root->val == (tsum)/(tcnt)) ans++;

        return {tsum,tcnt};
    }
};