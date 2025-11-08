class Solution {
public:
    int minSensors(int n, int m, int k) {
        int w{2 * k + 1};
        return ((n + w - 1) / w) * ((m + w - 1) / w);
    }
};
