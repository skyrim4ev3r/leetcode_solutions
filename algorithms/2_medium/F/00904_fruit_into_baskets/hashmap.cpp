class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruit_count;
        size_t left{0};
        const size_t len{fruits.size()};
        int max{0};

        for (size_t right{0}; right < len; ++right) {

            fruit_count[fruits[right]] += 1;
            while (fruit_count.size() > 2) {
                fruit_count[fruits[left]] -= 1;

                if (fruit_count[fruits[left]] == 0) {
                    fruit_count.erase(fruits[left]);
                }

                left += 1;
            }

            max = std::max(max, static_cast<int>(right - left + 1));
        }

        return max;
    }
};
