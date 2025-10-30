class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int can{capacity};
        int count{0};
        const size_t len{plants.size()};

        for (size_t i{0}; i < len; ++i) {
            can -= plants[i];
            count += 1;
    
            if (i < len - 1 && can < plants[i + 1]) {
                count += 2 * (i + 1);
                can = capacity;
            }
        }

        return count;
    }
};
