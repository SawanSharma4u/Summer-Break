/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void help(queue<Node*> q){
        queue<Node*> newQ;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(!q.empty()){
                front->next = q.front();
            }
            if(front->left) newQ.push(front->left);
            if(front->right) newQ.push(front->right);
        }
        if(!newQ.empty()) help(newQ);
    }
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        help(q);
        return root;
    }
};