class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count{0};
        const size_t len2{arr2.size()};

        for (const int& num1 : arr1) {
            const size_t pos = lower_bound(arr2.cbegin(), arr2.cend(), num1) - arr2.cbegin();
            bool can_be_count{true};

            if (pos + 1 < len2 && abs(num1 - arr2[pos + 1]) <= d) {
                can_be_count = false;
            }

            if (pos < len2 && abs(num1 - arr2[pos]) <= d) {
                can_be_count = false;
            }

            if (pos != 0 && abs(num1 - arr2[pos - 1]) <= d) {
                can_be_count = false;
            }

            if (can_be_count) {
                count += 1;
            }
        }

        return count;
    }
};
