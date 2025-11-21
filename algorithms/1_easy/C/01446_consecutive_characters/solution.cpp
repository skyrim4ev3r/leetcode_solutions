class Solution {
public:
    int maxPower(string s) {
        int curr_power{1};
        int max_power{1};
        const size_t len{s.size()};

        for (size_t i{1}; i < len; ++i) {
            if (s[i] == s[i - 1]) {
                curr_power += 1;
                max_power = std::max(max_power, curr_power);
            } else {
                curr_power = 1;
            }
        }

        return max_power;
    }
};
