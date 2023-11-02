/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    ListNode* node;
    Solution(ListNode* head) {
        node = head;
        while(head){
            ++cnt;
            head=head->next;
        }
        cout<<cnt<<" ";
    }
    
    int getRandom() {
        int val = rand() % cnt;
        int s = 0;
        ListNode* curr = node;

        while(s<val){
            curr = curr->next;
            s++;
        }
        
        
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */