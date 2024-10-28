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
public:
    
    void inorder(TreeNode *root ,vector<int>&ans) {
         if(root == NULL)return  ;
         inorder(root->left , ans) ;
         ans.push_back(root->val) ;
         inorder(root->right ,ans) ;
    }
    
    TreeNode* making(int s ,int e , vector<int>&ans) {
         if(s>e)return NULL;
         int mi = (s+e)/2 ;
         TreeNode* root =  new TreeNode(ans[mi]) ;
         root->left = making(s , mi -1 , ans) ;
         root->right = making(mi +1 , e , ans) ;
        return root ;
    }     


    TreeNode* balanceBST(TreeNode* root) {
       vector<int> ans ;
       inorder(root ,ans) ;
       return making(0 , ans.size() -1 , ans) ;      
    }
};