class Solution {
public:
    string stringHash(string s, int k) {
        const size_t k_usize{static_cast<size_t>(k)};
        const size_t old_len{s.size()};
        const size_t new_len{(old_len + k_usize - 1) / k_usize};
        string new_s;
        new_s.reserve(new_len);
        int count{0};
        int sum{0};
        size_t curr_index{0};

        for (const char& ch : s) {
            count += 1;
            sum += static_cast<int>(ch - 'a');

            if (count == k || curr_index == old_len - 1) {
                count = 0;
                new_s.push_back(static_cast<char>(sum % 26) + 'a');
                sum = 0;
            }

            curr_index += 1;
        }

        return new_s;
    }
};
