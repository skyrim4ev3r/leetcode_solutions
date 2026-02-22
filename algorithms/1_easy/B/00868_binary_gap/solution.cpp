const size_t BITS_COUNT{ 32 };

class Solution {
public:
    static int binaryGap(int n) {
        auto prev_valid_bit{ pair<size_t, bool>{0, false} };
        size_t max_dist{ 0 };

        for (size_t i{ 0 }; i < BITS_COUNT; ++i) {
            const int mask{ 1 << i };

            if ((mask & n) != 0) {
                if (prev_valid_bit.second) {
                    max_dist = std::max(max_dist, i - prev_valid_bit.first);
                }

                prev_valid_bit = {i, true};
            }
        }

        return static_cast<int>(max_dist);
    }
};
