class Solution {
public:
    static int largestAltitude(const vector<int>& gain) {
        int sum = 0;
        int max_g = 0;

        for (const auto g : gain) {
            sum += g;
            max_g = std::max(max_g, sum);
        }

        return max_g;
    }
};
