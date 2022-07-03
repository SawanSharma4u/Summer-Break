/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> myMap;
        ListNode* temp = head;
        int pos = 0;
        while(temp!=NULL){
            if(myMap.count(temp)!=0) return temp;
            myMap[temp] = pos;
            pos++;
            temp = temp->next;
        }
        return NULL;
    }
};