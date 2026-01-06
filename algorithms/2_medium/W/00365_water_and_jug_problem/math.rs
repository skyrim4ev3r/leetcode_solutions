impl Solution {
    pub fn can_measure_water(x: i32, y: i32, target: i32) -> bool {
        fn gcd(mut a: i32, mut b: i32) -> i32 {
            while b != 0 {
                let temp = b;
                b = a % b;
                a = temp;
            }

            a
        }

        target <= x + y && target % gcd(x, y) == 0
    }
}
