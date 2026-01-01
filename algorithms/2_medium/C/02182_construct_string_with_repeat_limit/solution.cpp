class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        res.reserve(s.size());
        array<int, 26> freqs {};

        for (const char& ch : s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        vector<pair<char, int>> stack;
        stack.reserve(26);

        for (size_t i {0}; i < 26; ++i) {
            if (freqs[i] > 0) {
                stack.push_back({static_cast<char>(i + 'a'), freqs[i]});
            }
        }

        while (!stack.empty()) {
            auto [ch, freq] = stack.back();
            stack.pop_back();

            while (freq != 0) {
                const int curr_repeat {std::min(freq, repeatLimit)};
                freq -= curr_repeat;

                for (int i{0}; i < curr_repeat; ++i) {
                    res.push_back(ch);
                }

                if (freq > 0) {
                    if (stack.empty()) {
                        return res;
                    }

                    res.push_back(stack.back().first);
                    stack.back().second -= 1;

                    if (stack.back().second == 0) {
                        stack.pop_back();
                    }
                }
            }
        }

        return res;
    }
};
