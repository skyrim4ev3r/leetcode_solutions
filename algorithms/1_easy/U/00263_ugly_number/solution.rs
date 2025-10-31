impl Solution {
    pub fn is_ugly(mut n: i32) -> bool {

        if n <= 0 {
            return false;
        }

        let arr: [i32; 3] = [2, 3, 5];

        for num in arr.into_iter() {
            while n != 0 && n % num == 0 {
                n /= num;
            }
        }

        n == 1
    }
}
