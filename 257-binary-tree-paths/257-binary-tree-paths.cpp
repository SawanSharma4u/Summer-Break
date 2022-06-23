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
    vector<string> ans;
    void helper(TreeNode* root, string s){
        if(s.length()==0) s = s + to_string(root->val);
        else s = s +"->"+ to_string(root->val);
        if(root->left!=NULL) helper(root->left, s);
        if(root->right!=NULL) helper(root->right, s);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string str="";
        helper(root, str);
        return ans;
    }
};