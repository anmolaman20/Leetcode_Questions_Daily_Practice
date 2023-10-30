class Solution {
public:
    ListNode* find_Mid(ListNode* root){
        ListNode* slow = root, *fast = slow;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        ListNode* Mid = find_Mid(head);
        ListNode* bfrMid = head;
        
        if (Mid == head) {
            // Single element base case
            return new TreeNode(Mid->val);
        }
        
        while(bfrMid and bfrMid->next != Mid) bfrMid = bfrMid->next;
        
        if (bfrMid) {
            bfrMid->next = nullptr;
        }

        TreeNode* mainRoot = new TreeNode(Mid->val);
        mainRoot->left = sortedListToBST(head);
        mainRoot->right = sortedListToBST(Mid->next);
        return mainRoot;
    }
};
