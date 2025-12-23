class Solution {
public:
    vector<int> closestDivisors(int num) {
        int sqrt{static_cast<int>(std::sqrt(num + 2))};
        for (int  i{sqrt}; i >= 1; --i) {
            if (((num + 1) % i) == 0) {
                return vector<int>{(num + 1) / i, i};
            }

            if (((num + 2) % i) == 0) {
                return vector<int>{(num + 2) / i, i};
            }
        }

        return vector<int>{num + 1, 1};
    }
};
