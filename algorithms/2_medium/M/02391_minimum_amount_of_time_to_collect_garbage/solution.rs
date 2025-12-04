impl Solution {
    pub fn garbage_collection(garbage: Vec<String>, travel: Vec<i32>) -> i32 {
        let mut last_p = 0_i32;
        let mut last_g = 0_i32;
        let mut last_m = 0_i32;

        let mut curr_possible_p = 0_i32;
        let mut curr_possible_g = 0_i32;
        let mut curr_possible_m = 0_i32;

        for (i, s) in garbage.iter().enumerate() {
            let mut count_p = 0_i32;
            let mut count_g = 0_i32;
            let mut count_m = 0_i32;

            if i > 0 {
                curr_possible_p += travel[i - 1];
                curr_possible_g += travel[i - 1];
                curr_possible_m += travel[i - 1];
            }

            for byte in s.as_bytes().iter() {
                match *byte {
                    b'P' => count_p += 1,
                    b'G' => count_g += 1,
                    _ => count_m += 1,
                }
            }

            if count_p > 0 {
                curr_possible_p += count_p;
                last_p = curr_possible_p;
            }

            if count_g > 0 {
                curr_possible_g += count_g;
                last_g = curr_possible_g;
            }

            if count_m > 0 {
                curr_possible_m += count_m;
                last_m = curr_possible_m;
            }
        }

        last_p + last_g + last_m
    }
}
