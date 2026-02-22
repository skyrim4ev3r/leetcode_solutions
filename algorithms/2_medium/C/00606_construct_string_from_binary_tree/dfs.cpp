class Solution {
    static void dfs(TreeNode* curr_node, string& res) {
        if (curr_node == nullptr) {
            return;
        }

        res += to_string(curr_node->val);

        if (curr_node->left != nullptr || curr_node->right != nullptr) {
            res.push_back('(');
            dfs(curr_node->left, res);
            res.push_back(')');
            if (curr_node->right != nullptr) {
                res.push_back('(');
                dfs(curr_node->right, res);
                res.push_back(')');
            }
        }
    }
public:
    static string tree2str(TreeNode* root) {
        string res;
        dfs(root, res);

        return res;
    }
};
