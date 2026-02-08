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
    static string join(const vector<string>& vec, const string& separator) {
        std::ostringstream oss;
        const size_t len{ vec.size() };

        for (size_t i{ 0 }; i < len; ++i) {
            oss << vec[i];

            if (i != vec.size() - 1) {
                oss << separator;
            }
        }

        return oss.str();
    }

    static void dfs(TreeNode* curr, vector<string>& res, vector<string>& temp) {
        if (curr == nullptr) {
            return;
        }

        temp.push_back(to_string(curr->val));

        if (curr->left == nullptr && curr->right == nullptr) {
            res.push_back(join(temp, "->"));
        } else {
            dfs(curr->left, res, temp);
            dfs(curr->right, res, temp);
        }

        temp.pop_back();
    }
public:
    static vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res{};
        vector<string> temp{};

        dfs(root, res, temp);

        return res;
    }
};
