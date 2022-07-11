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
    TreeNode* help(string & trv, int d, int st, int end){
        if(st>end) return NULL;
        int li = st+1;
        while(li <= end && trv[li]!='-'){
            li++;
        }
        int temp = stoi(trv.substr(st, li-st));
        TreeNode* root = new TreeNode(temp);
        int leftSt = li+d+1;
        int rightSt = leftSt+1;
        while(rightSt<=end && trv[rightSt]!='-'){
            rightSt++;
        }
        int dash = 0;
        for(; rightSt <= end; rightSt++){
            if(trv[rightSt]!='-' && dash==d+1){
                break;
            }
            if(trv[rightSt]!='-'){
                dash = 0;
        
            }
            else dash++;
        }
        if(rightSt == end+1){
            root->left = help(trv, d+1, leftSt, end);
            root->right = NULL;
        }
        else{
            root->left = help(trv, d+1, leftSt, rightSt-d-2);
            root->right = help(trv, d+1, rightSt, end);
        }
        return root;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        return help(traversal, 0, 0, traversal.length()-1);
    }
};