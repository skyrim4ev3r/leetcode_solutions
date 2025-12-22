class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (
            (tomatoSlices & 1) == 1 ||
            tomatoSlices > cheeseSlices * 4 ||
            tomatoSlices < cheeseSlices * 2
        ) {
            return vector<int>{};
        }

        const int small{cheeseSlices};
        const int remain_tomato{tomatoSlices - small * 2};
        const int possible_upgrades{remain_tomato / 2};
        return vector<int>{possible_upgrades, small - possible_upgrades};
    }
};
