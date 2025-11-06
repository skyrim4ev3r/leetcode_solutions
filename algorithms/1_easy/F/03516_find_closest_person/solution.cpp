class Solution {
public:
    int findClosest(int x, int y, int z) {
        return (abs(z-x) < abs(y-z)) + 2 *((abs(z-x) > abs(y-z)));
    }
};
