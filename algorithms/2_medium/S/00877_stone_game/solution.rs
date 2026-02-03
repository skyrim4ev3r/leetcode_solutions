impl Solution {
    pub fn stone_game(piles: Vec<i32>) -> bool {
        // len is even so first player can decide to get all items at even or odd indices
        // 1 6 1000 100 => if pick first => 1 + 1000
        // 1 6 1000 100 => if pick last => 100 + 6
        // because sum of all piles is odd so first player can always win
        true
    }
}
