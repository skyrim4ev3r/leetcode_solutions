//if all numbers be equal then 0 bitwise op needed, else 1 bitwise op with range of L=0 to R=nums.size()-1
class Solution {
public:
    int minOperations(vector<int>& nums) {
        return std::any_of(nums.begin(), nums.end(), [&](int num){ return num != nums[0];});
    }
};
