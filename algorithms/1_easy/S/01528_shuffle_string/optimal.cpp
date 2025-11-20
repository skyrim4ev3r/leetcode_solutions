// O(n) time, O(1) space
// Although there are nested loops, the structure of the swaps ensures that the overall time complexity is O(n).

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        const size_t len{indices.size()};

        for (size_t i{0}; i < len; ++i) {
            size_t curr_index{static_cast<size_t>(indices[i])};

            while (curr_index != i) {
                const char temp_ch{s[i]};
                s[i] = s[curr_index];
                s[curr_index] = temp_ch;

                const int temp{indices[i]};
                indices[i] = indices[curr_index];
                indices[curr_index] = temp;

                curr_index = static_cast<size_t>(indices[i]);
            }
        }

        return s;
    }
};
