class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::rotate(nums.begin(), nums.end() - (static_cast<size_t>(k) % nums.size()), nums.end()); 
    }
};
