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
public:
    void postorder(vector<int>& v, Node* root) {
        if (root == nullptr) {
            return;
        }
        for (int i = 0; i < root->children.size(); i++) {
            postorder(v, root->children[i]);
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        postorder(v, root);
        return v;
    }
};