impl Solution {
    pub fn four_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        
        let mut res: Vec<Vec<i32>> = Vec::new();
        let len = nums.len();

        if len < 4 {
            return res;
        }

        let target_i64 = target as i64;

        nums.sort_unstable();

        let mut first = 0_usize;
        while first < len - 3 {
            if first > 0 && nums[first] == nums[first - 1] {
                first += 1;
                continue;
            }

            let mut second = first + 1;
            while second < len - 2 {
                if second > first + 1 && nums[second] == nums[second - 1] {
                    second += 1;
                    continue;
                }

                let mut third = second + 1;
                let mut fourth = len - 1;

                while third < fourth {
                    let curr_sum = nums[first] as i64 + nums[second] as i64 + nums[third] as i64 + nums[fourth] as i64;

                    if curr_sum == target_i64 {

                        res.push(vec![nums[first], nums[second], nums[third], nums[fourth]]);

                        fourth -= 1;
                        while third < fourth && nums[fourth] == nums[fourth + 1] {
                            fourth -= 1;
                        }

                        third += 1;
                        while third < fourth && nums[third] == nums[third - 1] {
                            third += 1;
                        }
                    } else if curr_sum < target_i64 {
                        third += 1;
                    } else {
                        fourth -= 1;
                    }
                }

                second += 1;
            }

            first += 1;
        }

        res
    }
}
