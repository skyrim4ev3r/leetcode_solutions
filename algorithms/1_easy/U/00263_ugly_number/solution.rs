impl Solution {
    const arr: [i32; 3] = [2, 3, 5];

    pub fn is_ugly(mut n: i32) -> bool {
        if n <= 0 {
            return false;
        }

        for num in Self::arr {
            while n != 0 && n % num == 0 {
                n /= num;
            }
        }

        n == 1
    }
}
