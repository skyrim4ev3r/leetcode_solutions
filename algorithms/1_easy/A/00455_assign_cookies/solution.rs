impl Solution {
    pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
        s.sort_unstable();
        g.sort_unstable();

        let len_s = s.len();
        let len_g = g.len();
        let mut count = 0_i32;
        let mut index_g = 0_usize;
        let mut index_s = 0_usize;

        while index_s < len_s && index_g < len_g {
            if g[index_g] <= s[index_s] {
                count += 1;
                index_g += 1;
            }

            index_s += 1;
        }

        count
    }
}
