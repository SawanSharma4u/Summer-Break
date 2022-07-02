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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp = head, *curr = head, *prev = NULL;
        while(temp!=NULL){
            temp = temp->next;
            if(curr->val!=val){
                prev = curr;
                curr = temp;
            }
            else{
                if(prev!=NULL) prev->next = temp;
                else head = temp;
                curr->next = NULL;
                delete curr;
                curr = temp;
            }
        }
        return head;
    }
};