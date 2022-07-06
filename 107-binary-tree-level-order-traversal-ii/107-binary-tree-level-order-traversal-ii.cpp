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
    void help(TreeNode* root, int depth){
        if(root==NULL){
            return;
        }
        if(depth==ans.size()){
            vector<int> temp;
            ans.push_back(temp);
        }
        if(root->left) help(root->left, depth+1);
        if(root->right) help(root->right, depth+1);
        ans[depth].push_back(root->val);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root){
        help(root, 0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};