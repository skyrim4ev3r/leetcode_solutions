class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        size_t i1{0}, j1{0}, i2{0}, j2{0};
        const size_t row1{word1.size()}, row2{word2.size()};

        while (i1 < row1 && i2 < row2) {
            if (word1[i1][j1] != word2[i2][j2]) {
                return false;
            }

            j1 += 1;
            j2 += 1;

            if (j1 == word1[i1].size()) {
                i1 += 1;
                j1 = 0;
            }

            if (j2 == word2[i2].size()) {
                i2 += 1;
                j2 = 0;
            }
        }

        return i1 == row1 && i2 == row2;
    }
};
