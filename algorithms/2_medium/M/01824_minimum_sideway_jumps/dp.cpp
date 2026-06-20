typedef ptrdiff_t isize;

constexpr int inf = 10'000'000;

class Solution {
public:
    static int minSideJumps(const vector<int>& obstacles) {
        assert(obstacles.size() > 1 && obstacles[0] == 0 && obstacles.back() == 0);
        auto dp = array<int, 3>{1, 0, 1};

        for (const auto obs : obstacles) {
            if (obs > 0) {
                dp[obs - 1] = inf;
            }

            const int min = *std::min_element(dp.cbegin(), dp.cend());

            for (isize i = 0; i < 3; i += 1) {
                if (i + 1 != obs) {
                    dp[i] = std::min(dp[i], 1 + min);
                }
            }
        }

        return *std::min_element(dp.cbegin(), dp.cend());
    }
};
