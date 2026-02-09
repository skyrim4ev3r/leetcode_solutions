class Solution {
public:
    static string longestWord(vector<string>& words) {
        ranges::sort(words, [](const auto& a, const auto& b) {
            return a.size() < b.size();
        });

        unordered_set<string> valids{};
        size_t max_seen_len{ 0 };

        for (const auto& w : words) {
            const size_t curr_word_len{ w.size() };

            if (curr_word_len > max_seen_len + 1) {
                break;
            }

            if (curr_word_len > 1 && !valids.contains(w.substr(0, curr_word_len - 1))) {
                continue;
            }

            max_seen_len = curr_word_len;
            valids.insert(w);
        }

        vector<string> valid_vec{};

        for (const auto& v : valids) {
            if (v.size() == max_seen_len) {
                valid_vec.push_back(v);
            }
        }
        ranges::sort(valid_vec);

        return valid_vec.empty() ? "" : valid_vec[0];
    }
};
