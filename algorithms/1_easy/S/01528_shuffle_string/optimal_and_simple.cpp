// This simple solutin in C++ can be consider optimal aswell
// Because of using const reference of s.
// Although it's technically possible to modify `s` directly without any copy,
// But the LeetCode function signature requires passing `s` by value. Therefore,
// modifying the original string is not advisable.

class Solution {
public:
    static string restoreString(const string &s, vector<int>& indices) {
        string res(indices.size(), ' ');

        for (size_t i{0}; i < s.size(); ++i) {
            res[static_cast<size_t>(indices[i])] = s[i];
        }

        return res;
    }
};
