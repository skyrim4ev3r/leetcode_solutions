impl Solution {
    pub fn find_array(mut pref: Vec<i32>) -> Vec<i32> {
        (1..pref.len()).into_iter().rev().for_each(|i| pref[i] ^= pref[i-1]);

        pref
    }
}
