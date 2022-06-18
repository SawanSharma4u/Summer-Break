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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next== NULL){
            return true;
        }
        ListNode* newHead = NULL;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            //We are creating a new node
            ListNode* newNode = new ListNode(temp->val);
            newNode->next = newHead;
            newHead = newNode;
            temp = temp->next;
        }
        temp = head;
       while(newHead!=NULL && temp!=NULL)
       {
           if(temp->val == newHead->val)
           {
            newHead=newHead->next;
            temp=temp->next;   
           }
           else
           {
           return false;
           }
       }
        return true;
    }
};