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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        vector<ListNode*> arr;
        
        while(temp){
            arr.push_back(temp);
            temp=temp->next;
        }
        int n = arr.size();
        cout<<n<<endl;
        for(auto it : arr) cout<<it->val<<" ";
        cout<<endl;
        for (int i = 1; i < n; i++) {
            ListNode* key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j]->val > key->val) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }

        for(auto it : arr) cout<<it->val<<" ";


        for(int i=0;i<n-1;i++){
            // cout<<arr[i]->val<<" ";
            arr[i]->next = arr[i+1];
        }
        arr[n-1]->next = NULL;
        return arr[0];
    }
};