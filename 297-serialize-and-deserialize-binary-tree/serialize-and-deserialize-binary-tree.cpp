class Codec {
public:
    string s = "";
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "*";
        }
        queue<TreeNode*> qu;
        qu.push(root);
        s += to_string(root->val);
        s += '|';
        while (!qu.empty()) {
            int size = qu.size();
            string p = "";
            while (size--) {
                TreeNode* newnode = qu.front();
                qu.pop();
                if (newnode->left) {
                    qu.push(newnode->left);
                    p += to_string(newnode->left->val);

                } else
                    p += "*";
                p += '|';
                if (newnode->right) {
                    qu.push(newnode->right);
                    p += to_string(newnode->right->val);

                } else
                    p += "*";
                p += '|';
            }
            s += p;
        }
        int j = s.size() - 1;
        while (!isdigit(s[j - 1])) {
            s.pop_back();
            j--;
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data;
        if (data.size() == 1 && data[0] == '*') {
            return NULL;
        }
        int i = 0;
        string p = "";
        while (i < data.size() && data[i] != '|') {
            p += data[i];
            i++;
        }

        int value = stoi(p);
        TreeNode* dummy = new TreeNode(value);
        queue<TreeNode*> qu;
        i++;
        qu.push(dummy);
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                TreeNode* newnode = qu.front();
                qu.pop();
                if (i < data.size()) {
                    if (data[i] == '*') {
                        newnode->left = nullptr;
                        i++;
                    } else {
                        string p = "";
                        while (i < data.size() && data[i] != '|') {
                            p += data[i];
                            i++;
                        }
                        if (!p.empty()) {
                            TreeNode* first = new TreeNode(stoi(p));
                            qu.push(first);
                            newnode->left = first;
                        }
                    }
                }
                i++;
                if (i < data.size()) {
                    if (data[i] == '*') {
                        newnode->right = nullptr;
                        i++;
                    } else {
                        string p = "";
                        while (i < data.size() && data[i] != '|') {
                            p += data[i];
                            i++;
                        }
                        if (!p.empty()) {
                            TreeNode* first = new TreeNode(stoi(p));
                            qu.push(first);
                            newnode->right = first;
                        }
                    }
                }
                i++;
            }
        }
        return dummy;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));