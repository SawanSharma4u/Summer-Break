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
    vector<vector<int>> ans;
    void help(queue<TreeNode*>& q){
        if(q.empty()) return;
        queue<TreeNode*> newQ;
        vector<int> temp;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            temp.push_back(front->val);
            if(front->left) newQ.push(front->left);
            if(front->right) newQ.push(front->right);
        }
        ans.push_back(temp);
        help(newQ);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        help(q);
        return ans;
    }
};