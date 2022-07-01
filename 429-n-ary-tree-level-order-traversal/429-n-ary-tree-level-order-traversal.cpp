/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<vector<int>> ans;
    void help(queue<Node*>& q){
        if(q.empty()) return;
        queue<Node*> newQ;
        vector<int> temp;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            temp.push_back(front->val);
            for(int i = 0; i < front->children.size(); i++){
                newQ.push(front->children[i]);
            }
        }
        ans.push_back(temp);
        help(newQ);
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return ans;
        queue<Node*> q;
        q.push(root);
        help(q);
        return ans;
    }
};