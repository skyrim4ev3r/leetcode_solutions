class Solution {
public:
    static vector<int> powerfulIntegers(const int x, const int y, const int bound) {
        int i{ 1 };
        unordered_set<int> res{};

        while (i < bound) {
            int j{ 1 };

            while (j + i <= bound) {
                res.insert(i + j);
                j *= y;

                if (y == 1) {
                    break;
                }
            }

            i *= x;

            if (x == 1) {
                break;
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};
