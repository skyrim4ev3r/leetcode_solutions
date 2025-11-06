class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        const size_t len{height.size()};
        vector<int> res{};

        for (size_t i{1}; i < len; ++i) {
            if (height[i - 1] > threshold) {
                res.push_back(static_cast<int>(i));
            }
        }

        return res;
    }
};
