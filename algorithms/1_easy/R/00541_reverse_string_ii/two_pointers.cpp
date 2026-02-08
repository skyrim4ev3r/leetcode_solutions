class Solution {
public:
    string reverseStr(string s, int k) {
        const size_t k_usize{ static_cast<size_t>(k) };
        const size_t len{ s.size() };

        for (size_t i{ 0 }; i < len; i += 2 * k_usize) {
            const auto start{ s.begin() + i };
            const auto end{ s.begin() + std::min(len, i + k_usize) };

            std::reverse(start, end);
        }

        return s;
    }
};
