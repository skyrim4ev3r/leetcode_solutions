impl Solution {
    pub fn total_money(n: i32) -> i32 {

        let mut curr_investment = 1_i32;
        let mut total_investment = 0_i32;

        for day in 1..=n {
            total_investment += curr_investment;
            curr_investment += 1;
            if day % 7 == 0 {
                curr_investment -=  6;
            }
        }

        total_investment
    }
}
