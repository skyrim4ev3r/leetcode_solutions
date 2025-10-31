impl Solution {
    pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
        let s_len = s.len();
        let g_len = g.len();

        s.sort_unstable();
        g.sort_unstable();

        let (mut i, mut j, mut count) = (0_usize, 0_usize, 0_i32);
        while  i < s_len && j < g_len {
            if g[j] <= s[i] {
                count += 1;
                j += 1;
            }

            i += 1;
        }

        count
    }
}
