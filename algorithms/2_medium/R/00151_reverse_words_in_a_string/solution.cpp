class Solution {
public:
    static string reverseWords(string& s) {
        const size_t len = s.size();
        size_t left = 0;
        size_t write_idx = 0;

        while (true) {
            while (left < len && s[left] == ' ') {
                left += 1;
            }

            if (left == len) {
                break;
            }

            size_t right = left;
            while (right < len && s[right] != ' ') {
                right += 1;
            }

            std::reverse(s.begin() + left, s.begin() + right);

            if (write_idx > 0) {
                s[write_idx] = ' ';
                write_idx += 1;
            }

            while (left != right) {
                s[write_idx] = s[left];
                left += 1;
                write_idx += 1;
            }
        }

        s.resize(write_idx);
        std::reverse(s.begin(), s.end());

        return std::move(s);
    }
};
