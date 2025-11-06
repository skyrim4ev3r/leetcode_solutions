impl Solution {
    pub fn square_is_white(coordinates: String) -> bool {
        ((coordinates.as_bytes()[0] - b'a') & 1) != ((coordinates.as_bytes()[1] - b'1') & 1)
    }
}
