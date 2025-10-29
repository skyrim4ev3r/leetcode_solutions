class SubrectangleQueries {
    vector<vector<int>> rectangle;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rectangle{std::move(rectangle)} {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {

        size_t row1_usize{static_cast<size_t>(row1)};
        size_t row2_usize{static_cast<size_t>(row2)};
        size_t col1_usize{static_cast<size_t>(col1)};
        size_t col2_usize{static_cast<size_t>(col2)};

        for (size_t i{row1_usize}; i <= row2_usize; ++i) {
            for (size_t j{col1_usize}; j <= col2_usize; ++j) {
                rectangle[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col) {
        return rectangle[static_cast<size_t>(row)][static_cast<size_t>(col)];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
