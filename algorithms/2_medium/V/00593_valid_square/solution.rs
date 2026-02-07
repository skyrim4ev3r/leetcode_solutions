impl Solution {
    #[inline(always)]
    fn manhattan_dist(p1: &Vec<i32>, p2: &Vec<i32>) -> i32 {
        (p1[0] - p2[0]).abs() + (p1[1] - p2[1]).abs()
    }

    #[inline(always)]
    fn is_square(sides: &[i32; 4], diags: &[i32; 2]) -> bool {
        sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3] && diags[0] == diags[1]
    }

    pub fn valid_square(p1: Vec<i32>, p2: Vec<i32>, p3: Vec<i32>, p4: Vec<i32>) -> bool {
        let d12 = Self::manhattan_dist(&p1, &p2);
        let d13 = Self::manhattan_dist(&p1, &p3);
        let d14 = Self::manhattan_dist(&p1, &p4);
        let d23 = Self::manhattan_dist(&p2, &p3);
        let d24 = Self::manhattan_dist(&p2, &p4);
        let d34 = Self::manhattan_dist(&p3, &p4);

        if d12 == 0 || d13 == 0 || d14 == 0 || d23 == 0 || d24 == 0 || d34 == 0 {
            return false;
        }

        let sides1 = [d12, d13, d24, d34];
        let diags1 = [d14, d23];

        let sides2 = [d12, d14, d23, d34];
        let diags2 = [d13, d24];

        let sides3 = [d13, d14, d23, d24];
        let diags3 = [d13, d24];

        Self::is_square(&sides1, &diags1) ||
        Self::is_square(&sides2, &diags2) ||
        Self::is_square(&sides3, &diags3)
    }
}
