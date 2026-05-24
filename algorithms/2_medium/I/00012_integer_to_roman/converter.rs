impl Solution {
    pub fn int_to_roman(mut num: i32) -> String {
        static TOTAL_STEPS: usize = 13;
        static symbols_vals: [(&str, i32); TOTAL_STEPS] = [
            ("M", 1000), ("CM", 900), ("D", 500), ("CD", 400), ("C", 100), ("XC", 90),
            ("L", 50), ("XL", 40), ("X", 10), ("IX", 9), ("V", 5), ("IV", 4), ("I", 1)
        ];
        let mut res = String::with_capacity(20);

        for (sym, val) in symbols_vals.into_iter() {
            while num >= val {
                res.push_str(sym);
                num -= val;
            }
        }

        res
    }
}
