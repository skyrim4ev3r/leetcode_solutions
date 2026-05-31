class Solution {
public:
    static bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int64_t curr_mass = mass;

        for (const auto a : asteroids) {
            if (a > curr_mass) {
                return false;
            }

            curr_mass += a;
        }

        return true;
    }
};
