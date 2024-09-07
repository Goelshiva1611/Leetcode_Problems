
class Solution {
public:
    vector<vector<int>> v;
    bool pathall(TreeNode* root, ListNode* head) {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;
        if (head->val != root->val)
            return false;
        bool a = pathall(root->left, head->next);
        bool b = pathall(root->right, head->next);
        return a || b;
    }
    bool finalpath(TreeNode* root, ListNode* head) {

        if (root == nullptr) {
            return false;
        }
        bool a = pathall(root, head);
        bool b = finalpath(root->left, head);
        bool c = finalpath(root->right, head);
        return a || b || c;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr)
            return false;
        return finalpath(root, head);
    }
};
