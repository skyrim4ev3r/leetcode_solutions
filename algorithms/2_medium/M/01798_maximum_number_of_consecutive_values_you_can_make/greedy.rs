impl Solution {
    pub fn get_maximum_consecutive(mut coins: Vec<i32>) -> i32 {
        coins.sort_unstable();
        let mut curr = 0_i32;

        for coin in coins.into_iter() {
            if coin <= curr+ 1 {
                curr += coin;
            } else {
                break;
            }
        }

        curr + 1 // len([0..curr]) is curr + 1
    }
}
