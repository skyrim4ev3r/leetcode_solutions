class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        const size_t rows {land.size()};
        const size_t cols {land[0].size()};
        vector<vector<int>> res;

        for (size_t i_st {0}; i_st < rows; ++i_st) {
            for (size_t j_st {0}; j_st < cols; ++j_st) {
                if (land[i_st][j_st] == 1) {
                    size_t i_en {i_st};
                    size_t j_en {j_st};

                    while (i_en + 1 < rows && land[i_en + 1][j_st] == 1) {
                        i_en += 1;
                    }

                    while (j_en + 1 < cols && land[i_st][j_en + 1] == 1) {
                        j_en += 1;
                    }

                    for (size_t i {i_st}; i <= i_en; ++i) {
                        for (size_t j {j_st}; j <= j_en; ++j) {
                            land[i][j] = 0;
                        }
                    }

                    res.emplace_back(vector<int>{
                        static_cast<int>(i_st),
                        static_cast<int>(j_st),
                        static_cast<int>(i_en),
                        static_cast<int>(j_en)
                    });
                }
            }
        }

        return res;
    }
};
