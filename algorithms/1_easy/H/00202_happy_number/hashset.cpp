class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashset{};

        while (true) {
            if (n == 1) {
                return true;
            }

            if (!hashset.insert(n).second) {
                return false;
            }

            int new_n{0};
            while (n > 0) {
                new_n += std::pow(n % 10, 2);
                n /= 10;
            }
            n = new_n;
        }
    }
};
