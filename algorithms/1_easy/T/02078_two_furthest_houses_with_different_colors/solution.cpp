class Solution {
public:
    int maxDistance(vector<int>& colors) {
        const size_t len{colors.size()};

        size_t right{len - 1};
        while (right > 0 && colors[right] == colors[0]) {
            right -= 1;
        }

        size_t left{0};
        while (left < len - 1 && colors[left] == colors[len - 1]) {
            left += 1;
        }

        return static_cast<int>(std::max(right, len - 1 - left));
    }
};
