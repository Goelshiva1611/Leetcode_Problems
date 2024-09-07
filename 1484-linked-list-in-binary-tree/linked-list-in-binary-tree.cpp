class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(root, head);
    }
    
private:
    bool dfs(TreeNode* node, ListNode* head) {
        if (!node) return false;
        return checkPath(node, head) || dfs(node->left, head) || dfs(node->right, head);
    }
    
    bool checkPath(TreeNode* node, ListNode* head) {
        if (!head) return true;
        if (!node) return false; 
        
        if (node->val != head->val) return false;
        
        return checkPath(node->left, head->next) || checkPath(node->right, head->next);
    }
};
