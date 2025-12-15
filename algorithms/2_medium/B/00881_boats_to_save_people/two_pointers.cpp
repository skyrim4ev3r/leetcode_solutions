class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        const size_t len{people.size()};
        int count{0};
        size_t left{0};
        size_t right{len - 1};

        while (right < len && left <= right) {
            if (left < right && people[left] + people[right] <= limit) {
                left += 1;
            }

            count += 1;
            right -= 1;
        }

        return count;
    }
};
