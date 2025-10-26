class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* curr{root};

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                curr = curr->right;
            } else if (curr->right == nullptr) {
                curr->right = curr->left;
                curr->left = nullptr;
            } else {
                TreeNode* temp{curr->left};

                while (temp->right != nullptr) {
                    temp = temp->right;
                }

                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
                curr = curr->right;
            }
        }
    }
};
