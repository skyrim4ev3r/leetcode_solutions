use std::collections::HashMap;

impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let mut freqs: HashMap<i32, i32> = HashMap::new();

        for num in nums.into_iter() {
            *freqs.entry(num).or_insert(0) += 1;
        }

        let mut dp = freqs.into_iter()
                          .map(|(val, freq)| (val, val * freq))
                          .collect::<Vec<(i32, i32)>>();

        dp.sort_unstable();
        let dp_len = dp.len();
        
        if dp_len == 1 {
            return dp[0].1;
        }

        dp[1].1 += if dp[0].0 + 1 < dp[1].0 { dp[0].1 } else { 0 };

        if dp_len == 2 {
            return dp[0].1.max(dp[1].1);
        }

        dp[2].1 += if dp[1].0 + 1 < dp[2].0 { dp[0].1.max(dp[1].1) } else { dp[0].1 };

        for i in 3..dp_len {
            dp[i].1 += {
                if dp[i - 1].0 + 1 < dp[i].0 { 
                    dp[i - 1].1.max(dp[i - 2].1)
                } else {
                    dp[i - 2].1.max(dp[i - 3].1)
                }
            };
        }

        dp[dp_len - 1].1.max(dp[dp_len - 2].1)
    }
}
