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
    static void dfs(TreeNode* curr, unordered_map<int, int>& freqs) {
        if (curr == nullptr) {
            return;
        }

        freqs[curr->val] += 1;

        dfs(curr->left, freqs);
        dfs(curr->right, freqs);
    }

    static inline unordered_map<int, int> init_freqs(TreeNode* root) {
        unordered_map<int, int> freqs{};
        dfs(root, freqs);
        return freqs;
    }

    static inline pair<int, int> max_freq_and_count_max_freq(const unordered_map<int, int>& freqs) {
        int max_freq{ 0 };
        int count{ 0 };

        for (const auto& [_, freq] : freqs) {
            if (freq > max_freq) {
                count = 1;
                max_freq = freq;
            } else if (freq == max_freq) {
                count += 1;
            }
        }

        return {max_freq, count};
    }

    static inline vector<int> calc_res(
        const unordered_map<int, int>& freqs,
        const int max_freq,
        const int count_max_freq
    ) {
        vector<int> res;
        res.reserve(static_cast<size_t>(count_max_freq));

        for (const auto& [val, freq] : freqs) {
            if (freq == max_freq) {
                res.push_back(val);
            }
        }

        return res;
    }
public:
    static vector<int> findMode(TreeNode* root) {
        const unordered_map<int, int> freqs{ init_freqs(root) };
        const auto [max_freq, count_max_freq] = max_freq_and_count_max_freq(freqs);
        const vector<int> res{ calc_res(freqs, max_freq, count_max_freq) };

        return res;
    }
};
