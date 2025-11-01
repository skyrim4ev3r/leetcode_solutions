class Solution {
public:
    string smallestPalindrome(string s) {
        array<int, 26> freqs{};

        for (const char &ch: s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        size_t left{0};
        size_t right{s.size() - 1};

        for (size_t i{0}; i < 26; ++i) {
            // Input is valid, so if freq of any char be odd
            // then string len is also odd, and this char will be only char with odd freq
            if ((freqs[i] & 1) == 1) {
                size_t mid_index{s.size() / 2};
                s[mid_index] = i + 'a';
            }

            for (int _count{0}; _count < freqs[i] / 2; _count += 1) {
                s[left] = i + 'a';
                s[right] = i + 'a';
                left += 1;
                right -= 1;
            }
        }

        return s;
    }
};
