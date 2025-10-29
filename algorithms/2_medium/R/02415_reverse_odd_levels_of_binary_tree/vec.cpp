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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> vec_a{}, vec_b{};
        int curr_level{0};

        vec_a.push_back(root);

        while (!vec_a.empty()) {
            if ((curr_level & 1) == 1) {
                size_t left{0};
                size_t right{vec_a.size() - 1};

                while (left < right) {
                    int temp{vec_a[left]->val};
                    vec_a[left]->val = vec_a[right]->val;
                    vec_a[right]->val = temp;
                    right -= 1;
                    left += 1;
                }
            }

            for (TreeNode* &node: vec_a) {
                if (node->left != nullptr) {
                    vec_b.push_back(node->left);
                }

                if (node->right != nullptr) {
                    vec_b.push_back(node->right);
                }
            }

            vec_a = move(vec_b);
            curr_level += 1;
        }

        return root;
    }
};
