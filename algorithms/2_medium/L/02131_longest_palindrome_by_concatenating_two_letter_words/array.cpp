class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        array<array<int, 26>, 26> freqs{};
        int max_len{ 0 };

        for (const auto& word : words) {
            const size_t i{ static_cast<size_t>(word[0] - 'a') };
            const size_t j{ static_cast<size_t>(word[1] - 'a') };

            const size_t complement_i{ j };
            const size_t complement_j{ i };

            if (freqs[complement_i][complement_j] > 0) {
                // If complement_string exist then
                // Add both string & complement_string with total len of 4
                max_len += 4;
                freqs[complement_i][complement_j] -= 1;
            } else {
                freqs[i][j] += 1;
            }
        }

        // If self-palindrome strings are left,
        // Then we can use 1 of them as the middle part of final string.
        // Strings like: aa, bb, cc,..
        for(size_t i{ 0 }; i < 26; ++i) {
            if (freqs[i][i] > 0) {
                max_len += 2;
                break;
            }
        }

        return max_len;
    }
};
