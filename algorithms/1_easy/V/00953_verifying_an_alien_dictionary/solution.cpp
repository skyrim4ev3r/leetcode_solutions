class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<int, 26> order_values{};

        for (size_t i{0}; i < 26; ++i) {
            const size_t order_values_index{static_cast<size_t>(order[i] - 'a')};
            order_values[order_values_index] = static_cast<int>(i);
        }

        const size_t len{words.size()};

        for (size_t i{1}; i < len; ++i) {
            const string& prev{words[i - 1]};
            const string& curr{words[i]};
            const size_t min_len_words{std::min(prev.size(), curr.size())};
            bool are_prefix_equal{true};

            for (size_t j{0}; j < min_len_words; ++j) {
                const size_t index1{static_cast<size_t>(prev[j] - 'a')};
                const size_t index2{static_cast<size_t>(curr[j] - 'a')};

                if (order_values[index1] > order_values[index2]) {
                    return false;
                }

                if (order_values[index1] < order_values[index2]) {
                    are_prefix_equal = false;
                    break;
                }
            }

            if (are_prefix_equal && prev.size() > curr.size()) {
                return false;
            }
        }

        return true;
    }
};
