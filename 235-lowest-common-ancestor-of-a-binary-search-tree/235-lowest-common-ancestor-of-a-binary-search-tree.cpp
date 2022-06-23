/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {        
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        TreeNode* ans;
        while(pendingNodes.size()){
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            if(front->val > p->val && front->val > q->val) pendingNodes.push(front->left);
            else if(front->val < p->val && front->val < q->val) pendingNodes.push(front->right);
            else{
                ans = front;
                break;
            }
        }
        return ans;
    }
};