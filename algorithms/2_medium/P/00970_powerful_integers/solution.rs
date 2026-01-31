impl Solution {
    pub fn powerful_integers(x: i32, y: i32, bound: i32) -> Vec<i32> {
        let mut i = 1_i32;
        let mut res: std::collections::HashSet<i32> = std::collections::HashSet::new();

        while i < bound {
            let mut j = 1_i32;

            while j + i <= bound {
                res.insert(i + j);
                j *= y;

                if y == 1 {
                    break;
                }
            }

            i *= x;

            if x == 1 {
                break;
            }
        }

        res.into_iter().collect::<Vec<i32>>()
    }
}
