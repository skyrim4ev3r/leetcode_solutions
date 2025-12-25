class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ranges::sort(happiness, std::greater<>());
        long long max{0};

        for (int i{0}; const int& h : happiness) {
            if (h <= i || i == k) {
                break;
            }

            max += static_cast<long long>(h - i);
            i += 1;
        }

        return max;
    }
};
