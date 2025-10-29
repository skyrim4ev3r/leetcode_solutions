impl Solution {
    pub fn successful_pairs(spells: Vec<i32>, mut potions: Vec<i32>, success: i64) -> Vec<i32> {

        potions.sort_unstable();

        let max_i32_as_i64 = (i32::MAX) as i64;
        let spells_len = spells.len();
        let potions_len = potions.len();
        let mut res: Vec<i32> = Vec::with_capacity(spells_len);

        for spell in spells {
            let spell_i64 = spell as i64; 
            let mut min_success_num = (success + spell_i64 - 1)  / spell_i64; // Its ceiling of success / spell

            if min_success_num > max_i32_as_i64 {
                res.push(0);
            } else {
                let index = Self::lower_bound(&potions, & (min_success_num as i32));
                res.push((potions_len - index) as i32);
            }
        }

        res
    }

    #[inline]
    fn lower_bound<T: Ord>(arr: &[T], target: &T) -> usize {
        arr.binary_search_by(|num| match num.cmp(target) {
            std::cmp::Ordering::Less => std::cmp::Ordering::Less,
            _ => std::cmp::Ordering::Greater,
        }).unwrap_or_else(|x| x)
    }

}
