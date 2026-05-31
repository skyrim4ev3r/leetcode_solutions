int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (ptrdiff_t i = (ptrdiff_t) triangleSize - 2; i >= 0; i -= 1) {
        const ptrdiff_t cols = (ptrdiff_t) triangleColSize[i];

        for (ptrdiff_t j = 0; j < cols; ++j) {
            const int c1 = triangle[i + 1][j];
            const int c2 = triangle[i + 1][j + 1];
            triangle[i][j] += c1 < c2 ? c1 : c2;
        }
    }

    return triangle[0][0];
}
