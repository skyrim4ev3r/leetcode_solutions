class Solution {
public:
    string reverseWords(string s) {
        const size_t len{s.size()};
        size_t left{0};

        while (left < len) {
            size_t right{left};
            while (right < len - 1 && s[right + 1] != ' ') {
                right += 1;
            }

            const size_t next_index_for_left{right + 2};

            while (left < right) {
                const char temp{s[left]};
                s[left] = s[right];
                s[right] = temp;

                right -= 1;
                left += 1;
            }

            left = next_index_for_left;
        }

        return s;
    }
};
