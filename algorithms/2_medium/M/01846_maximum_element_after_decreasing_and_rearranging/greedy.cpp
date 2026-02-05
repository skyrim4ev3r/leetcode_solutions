class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        ranges::sort(arr);
        int curr{ 0 };

        for (const auto& num : arr) {
            if (num > curr) {
                curr += 1;
            }
        }

        return curr;
    }
};
