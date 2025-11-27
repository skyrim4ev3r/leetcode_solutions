class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        vector<int> digits{};
        digits.reserve(6);
        int count{0};

        for (int i{low}; i <= high; ++i) {
            int temp{i};

            digits.resize(0, 0);

            while (temp > 0) {
                digits.push_back(temp % 10);
                temp /= 10;
            }

            if ((digits.size() & 1) == 1) {
                continue;
            }

            const size_t half{digits.size() / 2};
            const int left = reduce(digits.cbegin(), digits.cbegin() + half);
            const int right = reduce(digits.cbegin() + half, digits.cend());

            if (left == right) {
                count += 1;
            }
        }

        return count;
    }
};
