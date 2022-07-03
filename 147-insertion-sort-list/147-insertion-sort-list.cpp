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
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        for(int i = 1; i < arr.size(); i++){
            int j = i-1;
            int temp = arr[i];
            while(j >= 0 && temp < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
        temp = head;
        int i = 0;
        while(temp!=NULL){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};