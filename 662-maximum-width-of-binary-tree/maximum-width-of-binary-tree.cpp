/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr)
            return 1;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll maxi = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                ll level = q.front().second;
                q.pop();
                if (node->left)
                    q.push({node->left, 2 * level + 1});
                if (node->right)
                    q.push({node->right, 2 * level + 2});
            }
            if (!q.empty()) {
                ll l = q.front().second;
                ll r = q.back().second;
                maxi = max(maxi, r - l + 1);
            }
        }
        return maxi;
    }
};

/*
long long  levelorder(TreeNode* root) {
        if(root->left==nullptr && root->right ==nullptr)
        {
            return 1;
        }
        queue<pair<TreeNode*, long long >> qu;
        qu.push({root, 0});
        int  m = 0;
        while (!qu.empty()) {
            long long size = qu.size();
            vector<int> v;
            cout << size;
            while (size--) {
                auto it = qu.front();
                TreeNode* curr = it.first;
                long long p = it.second;
                qu.pop();
                if (curr->left) {
                    if (p < 0) {
                        qu.push({curr->left, p * 2});
                        v.push_back(p * 2);
                    } else {
                        if (p == 0) {
                            qu.push({curr->left, -1});
                            v.push_back(-1);

                        } else {
                            qu.push({curr->left, p * 2 - 1});
                            v.push_back(p * 2 - 1);
                        }
                    }
                }
                if (curr->right) {
                    if (p < 0) {
                        qu.push({curr->right, p * 2 + 1});
                        v.push_back(p * 2 + 1);
                    } else {
                        if (p == 0) {
                            qu.push({curr->right, 1});
                            v.push_back(1);
                        } else {
                            qu.push({curr->right, p*2});
                            v.push_back(p * 2);
                        }
                    }
                }
            }
            sort(v.begin(), v.end());
            if(v.size()==1)
            {
                m=max(m,1);
            }
            if (v.size() >= 2)
            {
                if((v[0]<0 && v[v.size()-1]<0)||(v[0]>0 && v[v.size()-1]>0))
                {
                    m = max(m, abs(abs(v[0]) -abs(v[v.size() - 1]))+1);

                }else
                    m = max(m, abs(v[0] -v[v.size() - 1]));
            }

            cout << "hello";
            cout << m;
        }
        return m;
    }*/
