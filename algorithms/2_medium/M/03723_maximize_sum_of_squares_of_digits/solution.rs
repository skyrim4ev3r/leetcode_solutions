impl Solution {
    pub fn max_sum_of_squares(mut num: i32, mut sum: i32) -> String {

        if num * 9 < sum {
            return "".to_string();
        }

        let num_usize = num as usize;
        let mut res: Vec<u8> = vec![b'0'; num_usize];

        for i in 0..num_usize {
            if sum == 0 { 
                break;
            }

            let curr_dig = sum.min(9);
            sum -= curr_dig;
            res[i] = b'0' + curr_dig as u8;
        }

        String::from_utf8_lossy(&res).into_owned()
    }
}
