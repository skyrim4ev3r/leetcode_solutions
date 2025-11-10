// This code is just compact.
// It is not a good solution. not readable, but using only 2 lines of codes insides the function
impl Solution {
    pub fn reverse_submatrix(mut grid: Vec<Vec<i32>>, x: i32, y: i32, k: i32) -> Vec<Vec<i32>> {
        (0..k).into_iter().for_each(|j| (0..k / 2).into_iter().for_each(|i| (grid[(x + i) as usize][(y + j)  as usize],grid[(x + k - i -1) as usize][(y + j) as usize]) = (grid[(x + k - i - 1) as usize][(y + j) as usize],grid[(x + i) as usize][(y + j) as usize])));
        grid
    }
}
