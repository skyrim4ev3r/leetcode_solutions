class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> vec{};

        for (int &asteroid: asteroids) {
            if (asteroid > 0) {
                vec.push_back(asteroid);
            } else {
                while (!vec.empty() && vec.back() > 0 && vec.back() < abs(asteroid)) {
                    vec.pop_back();
                }

                if (!vec.empty() && vec.back() > 0 ) {
                    if (vec.back() == abs(asteroid)) {
                        vec.pop_back();
                    }

                    continue;
                }

                vec.push_back(asteroid);
            }
        }

        return vec;
    }
};
