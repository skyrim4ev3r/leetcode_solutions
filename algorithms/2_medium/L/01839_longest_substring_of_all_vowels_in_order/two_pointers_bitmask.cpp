class Solution {
public:
    static int longestBeautifulSubstring(string word) {
        const size_t len{ word.size() };
        size_t left{ 0 };
        size_t right{ 0 };
        size_t longest{ 0 };
        int word_mask{ 0 };
        const int vowel_mask{ 1065233 }; // zyxwvutsrqponmlkjihgfedcba
                                         // 00000100000100000100010001 => 1065233

        while (right < len && left < len) {
            if (word[left] != 'a') {
                left += 1;
                right = left;
                word_mask = 0;
            } else {
                if (right > left && word[right - 1] > word[right]) {
                    word_mask = 0;
                    left = right;
                }

                const int shift_amount{ static_cast<int>(word[right] - 'a') };
                word_mask = (word_mask | (1 << shift_amount));

                if ((word_mask & vowel_mask) == vowel_mask) {
                    longest = std::max(longest, right - left + 1);
                }

                right += 1;
            }
        }

        return static_cast<int>(longest);
    }
};
