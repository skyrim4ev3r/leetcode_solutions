class Solution {
public:
    static int getXORSum(const vector<int>& arr1, const vector<int>& arr2) {
        return reduce(arr1.begin(), arr1.end(), 0, bit_xor<>()) & reduce(arr2.begin(), arr2.end(), 0, bit_xor<>());
    }
};
