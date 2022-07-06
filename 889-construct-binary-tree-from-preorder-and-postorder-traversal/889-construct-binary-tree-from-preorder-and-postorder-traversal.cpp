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
    TreeNode* help(vector<int>& preorder, int preS, int preE, vector<int>& postorder, int postS, int postE){
        if(preS > preE || postS > postE) return NULL;
        TreeNode* root = new TreeNode(preorder[preS]);
        int len = 0;
        for(int i = postS; i <= postE; i++){
            if(preS < preE && postorder[i]==preorder[preS+1]){
                len = i-postS+1;
                break;
            }
        }
        root->left = help(preorder, preS+1, preS+len, postorder, postS, postS + len-1);
        root->right = help(preorder, preS+len+1, preE, postorder, postS+len, postE-1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return help(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
};