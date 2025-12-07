class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        array<int, 26> freqs_p{};
        const size_t words_len{words.size()};
        size_t curr_selected_index{words_len};

        for (const char& ch : licensePlate) {
            if (ch >= 'a' && ch <= 'z') {
                freqs_p[static_cast<size_t>(ch - 'a')] += 1;
            }

            if (ch >= 'A' && ch <= 'Z') {
                freqs_p[static_cast<size_t>(ch - 'A')] += 1;
            }
        }

        for (size_t i{0}; i < words_len; ++i) {
            if (curr_selected_index != words_len && words[curr_selected_index].size() <= words[i].size()) {
                continue;
            }

            array<int, 26> freqs_w{};

            for (const char& ch : words[i]) {
                if (ch >= 'a' && ch <= 'z') {
                    freqs_w[static_cast<size_t>(ch - 'a')] += 1;
                }
            }

            bool is_good = true;

            for (size_t i{0}; i < 26; ++i) {
                if (freqs_p[i] > freqs_w[i]) {
                    is_good = false;
                    break;
                }
            }

            if (is_good) {
                curr_selected_index = i;
            }
        }

        return words[curr_selected_index];
    }
};
