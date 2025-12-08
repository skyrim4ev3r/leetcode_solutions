class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freqs{};

        for (const int& num : deck) {
            freqs[num] += 1;
        }

        int curr_gcd{0};

        for (const auto& [_, freq] : freqs) {
            curr_gcd = gcd(freq, curr_gcd);
        }

        return curr_gcd > 1;
    }
};
