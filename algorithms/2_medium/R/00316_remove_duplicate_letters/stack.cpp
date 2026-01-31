class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> freqs{};
        array<bool, 26> used{};
        string res{};

        for (const auto& ch : s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (const auto& ch : s) {
            const size_t index{ static_cast<size_t>(ch - 'a') };
            freqs[index] -= 1;

            if (!used[index]) {
                while (!res.empty() && res.back() > ch) {
                    const size_t index_last{ static_cast<size_t>(res.back() - 'a') };

                    if (freqs[index_last] == 0) {
                        break;
                    }

                    used[index_last] = false;
                    res.pop_back();
                }

                res.push_back(ch);
                used[index] = true;
            }
        }

        return res;
    }
};
