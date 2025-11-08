class Solution {
public:
    int reverseDegree(string s) {
        int sum{0};

        for(int i{0}; const char &ch: s) {
            sum += static_cast<int>('z' - ch + 1) * (i + 1);
            ++i;
        }

        return sum;
    }
};
