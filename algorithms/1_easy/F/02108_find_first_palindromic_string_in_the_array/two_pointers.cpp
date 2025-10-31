class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string &word: words) {
            size_t right{word.size() - 1};
            size_t left{0};

            while (left < right) {
                if (word[left] != word[right]) {
                    break;
                }

                left += 1;
                right -= 1;
            }

            if (left >= right) {
                return word;
            }
        }

        return "";
    }
};
