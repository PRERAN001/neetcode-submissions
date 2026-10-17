/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    void dfsserialize(TreeNode* root, vector<string>& ans) {
        if (root == NULL) {
            ans.push_back("lol");
            return;
        }
        ans.push_back(to_string(root->val));
        dfsserialize(root->left, ans);
        dfsserialize(root->right, ans);
    }

    string join(vector<string>& v, string sep) {
        string temp = "";

        for (int i = 0; i < v.size(); i++) {
            temp += v[i];
            if (i != v.size() - 1) {
                temp += sep;
            }
        }

        return temp;
    }

    vector<string> split(string a) {
        vector<string> v;
        string temp = "";

        for (char c : a) {
            if (c == ',') {
                v.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        if (!temp.empty()) {
            v.push_back(temp);
        }

        return v;
    }

    TreeNode* dfsdeserialize(vector<string>& v, int& i) {
        if (i >= v.size() || v[i] == "lol") {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(v[i]));
        i++;

        root->left = dfsdeserialize(v, i);
        root->right = dfsdeserialize(v, i);

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> v;
        dfsserialize(root, v);
        return join(v, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = split(data);
        int i = 0;
        return dfsdeserialize(v, i);
    }
};