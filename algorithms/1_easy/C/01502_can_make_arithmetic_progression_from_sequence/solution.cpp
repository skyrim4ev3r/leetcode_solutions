class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int diff{arr[1] - arr[0]};

        for (auto it{arr.cbegin() + 2}; it != arr.cend(); ++it) {
            if (*it - *(it - 1) != diff) {
                return false;
            }
        }

        return true;
    }
};
