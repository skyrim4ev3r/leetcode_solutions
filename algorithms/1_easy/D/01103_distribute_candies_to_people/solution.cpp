class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        if (num_people == 1) {
            return vector<int>{candies};
        }

        const size_t len{static_cast<size_t>(num_people)};
        vector<int> res{vector<int>(len, 0)};
        int curr_count{1};
        size_t curr_index{0};

        while (candies > 0) {
            res[curr_index] += std::min(curr_count, candies);
            candies -= curr_count;
            curr_count += 1;
            curr_index += 1;

            if (curr_index == len) {
                curr_index = 0;
            }
        }

        return res;
    }
};
