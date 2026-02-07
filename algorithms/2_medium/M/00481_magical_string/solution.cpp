class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) {
            return 1;
        }

        const size_t target_len{ static_cast<size_t>(n) };
        string s;
        s.reserve(target_len + 1);
        s += "122";
        size_t index{ 2 };
        char curr_char{ '1' };

        while (s.size() < target_len) {
            s.push_back(curr_char);

            if (s[index] == '2' && s.size() < target_len) {
                s.push_back(curr_char);
            }

            curr_char = curr_char == '1' ? '2' : '1';
            index += 1;
        }

        return std::count(s.cbegin(), s.cend(), '1');
    }
};
