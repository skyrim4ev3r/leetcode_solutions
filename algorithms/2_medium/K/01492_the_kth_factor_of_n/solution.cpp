class Solution {
public:
    int kthFactor(int n, int k) {
        const int sqrt_n{ static_cast<int>(sqrt(n)) };
        vector<int> rest_factors{};

        for (int i{ 1 }; i <= sqrt_n; ++i) {
            if (n % i == 0) {
                k -= 1;
                if (k == 0) {
                    return i;
                }

                const int other{ n / i };
                if (i != other) {
                    rest_factors.push_back(other);
                }
            }
        }

        const size_t len_rest_factors{ rest_factors.size() };
        if (len_rest_factors < static_cast<size_t>(k)) {
            return -1;
        }

        return rest_factors[len_rest_factors - static_cast<size_t>(k)];
    }
};
