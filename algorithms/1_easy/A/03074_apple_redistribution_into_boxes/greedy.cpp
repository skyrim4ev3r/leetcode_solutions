class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total_apples{reduce(apple.begin(), apple.end(), 0)};
        sort(capacity.begin(), capacity.end());
        int count{0};

        while (total_apples > 0) {
            int curr_capacity{capacity.back()};

            capacity.pop_back();
            count += 1;
            total_apples -= curr_capacity;
        }

        return count;
    }
};
