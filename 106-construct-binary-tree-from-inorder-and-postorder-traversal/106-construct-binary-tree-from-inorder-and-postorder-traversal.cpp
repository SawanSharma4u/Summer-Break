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
    TreeNode* help(vector<int>& postorder, int pS, int pE, vector<int>& inorder, int iS, int iE){
        if(pS > pE || iS > iE) return NULL;
        TreeNode* root = new TreeNode(postorder[pE]);
        int len;
        for(int i = iS; i <= iE; i++){
            if(inorder[i]==root->val){
                len = i-iS;
                break;
            }
        }
        root->left = help(postorder, pS, pS+len-1, inorder, iS, len+iS-1);
        root->right = help(postorder, pS+len, pE-1, inorder, len+iS+1, iE);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return help(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }
};