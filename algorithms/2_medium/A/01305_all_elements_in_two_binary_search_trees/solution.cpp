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
    void travers(TreeNode* node, vector<int> &vec) {
        if (node == nullptr) {
            return;
        }

        travers(node->left, vec);
        vec.push_back(node->val);
        travers(node->right, vec);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1{};
        vector<int> vec2{};

        travers(root1, vec1);
        travers(root2, vec2);
        const size_t vec1_len{vec1.size()};
        const size_t vec2_len{vec2.size()};

        vector<int> res{};
        res.reserve(vec1_len + vec2_len);

        size_t i1{0};
        size_t i2{0};

        while (i1 < vec1_len && i2 < vec2_len) {
            if (vec1[i1] <= vec2[i2]) {
                res.push_back(vec1[i1]);
                i1 += 1;
            } else {
                res.push_back(vec2[i2]);
                i2 += 1;
            }
        }

        while (i1 < vec1_len) {
            res.push_back(vec1[i1]);
            i1 += 1;
        }

        while (i2 < vec2_len) {
            res.push_back(vec2[i2]);
            i2 += 1;
        }

        return res;
    }
};
