class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        const size_t len{distance.size()};
        int min_distance = INT_MAX;

        int curr_distance{0};
        size_t curr_index{static_cast<size_t>(start)};
        size_t dest_index{static_cast<size_t>(destination)};

        while (curr_index != dest_index) {
            curr_distance += distance[curr_index];
            curr_index += 1;
            if (curr_index >= len) {
                curr_index = 0;
            }
        }

        min_distance = min(min_distance, curr_distance);

        curr_distance = 0;
        curr_index = static_cast<size_t>(start);

        while (curr_index != dest_index) {
            curr_index -= 1;
            if (curr_index >= len) {
                curr_index = len - 1;
            }
            curr_distance += distance[curr_index];
        }

        min_distance = min(min_distance, curr_distance);

        return min_distance;
    }
};
