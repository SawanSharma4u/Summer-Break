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
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> ans;
    //     if(root==NULL) return ans;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     q.push(NULL);
    //     while(!q.empty()){
    //         TreeNode* front = q.front();
    //         q.pop();
    //         if(front->left) q.push(front->left);
    //         if(front->right) q.push(front->right);
    //         if(q.front()==NULL){
    //             ans.push_back(front->val);
    //             q.pop();
    //             if(!q.empty()) q.push(NULL);
    //         }
    //     }
    //     return ans;
    // }
};