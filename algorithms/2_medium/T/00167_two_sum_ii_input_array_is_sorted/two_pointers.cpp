class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        size_t left{0};
        size_t right{numbers.size() - 1};

        while (left < right) {
            const int sum{numbers[left] + numbers[right]};

            if (sum == target) {
                return vector<int>{static_cast<int>(left) + 1, static_cast<int>(right) + 1};
            }

            if (sum < target) {
                left += 1;
            } else {
                right -= 1;
            }
        }

        return vector<int>{-1, -1};
    }
};
