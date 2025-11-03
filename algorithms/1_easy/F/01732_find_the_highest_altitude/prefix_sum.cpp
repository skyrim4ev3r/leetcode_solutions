class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum{0};
        int max_g{0};

        for (const int &g: gain) {
            sum += g;
            max_g = max(max_g, sum);
        }

        return max_g;
    }
};
