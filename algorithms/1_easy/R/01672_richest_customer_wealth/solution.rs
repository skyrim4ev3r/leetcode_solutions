impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts.into_iter().fold(-1_i32, |max, account| max.max(account.into_iter().sum()))
    }
}
