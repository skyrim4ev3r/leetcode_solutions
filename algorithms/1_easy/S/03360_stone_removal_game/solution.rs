impl Solution {
    pub fn can_alice_win(mut n: i32) -> bool {

        let mut step = 10;
        let mut is_winning = false;

        while step > 0 && step <= n {
            n -= step;
            step -= 1;
            is_winning = !is_winning;
        }

        is_winning    
    }
}
