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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> fans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int ans = INT_MIN;
            for(int i=0;i<sz;i++){
                TreeNode* t = q.front();
                ans = max(ans,t->val);
                q.pop();

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            fans.push_back(ans);
        }
        return fans;
    }
};