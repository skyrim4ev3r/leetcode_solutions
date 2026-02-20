class Solution {
public:
    static string makeLargestSpecial(const string& s) {
        const size_t len{ s.size() };
        if (len <= 2) {
            return s;
        }
        size_t left{ 0 };
        int balance{ 0 };
        vector<string> parts{};

        for (size_t right{ 0 }; right < len; ++right) {
            if (s[right] == '1') {
                balance += 1;
            } else {
                balance -= 1;
            }

            if (balance == 0) {
                string temp;
                temp.reserve(right - left + 1);
                temp.push_back('1');
                temp += makeLargestSpecial(s.substr(left + 1, right - left - 1));
                temp.push_back('0');
                parts.push_back(std::move(temp));
                left = right + 1;
            }
        }

        ranges::sort(parts, std::greater<>());

        string res;
        res.reserve(len);

        for (const auto& part : parts) {
            res += part;
        }

        return res;
    }
};
