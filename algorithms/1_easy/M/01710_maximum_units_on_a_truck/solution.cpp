class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        const size_t len{boxTypes.size()};
        int count{0};
        sort(boxTypes.begin(), boxTypes.end(), [](const auto& a, const auto& b) {
            return b[1] < a[1];
        });

        size_t box_index{0};
        while (truckSize > 0 && box_index < len) {
            int curr = min(boxTypes[box_index][0], truckSize);
            truckSize -= curr;
            count += curr * boxTypes[box_index][1];
            box_index += 1;
        }

        return count;
    }
};
