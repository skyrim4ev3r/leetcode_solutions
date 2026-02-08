// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;
impl Solution {

    #[inline(always)]
    fn init_freqs(root_rc_opt: Option<&Rc<RefCell<TreeNode>>> ) -> HashMap<i32, i32> {
        let mut freqs: HashMap<i32, i32> = HashMap::new();

        fn dfs_init_freqs(
            curr_rc_opt: Option<&Rc<RefCell<TreeNode>>>,
            freqs: &mut HashMap<i32, i32>,
         ) {
            if let Some(curr_rc) = curr_rc_opt {
                let curr = curr_rc.borrow();
                *freqs.entry(curr.val).or_insert(0) += 1;

                dfs_init_freqs(curr.left.as_ref(), freqs);
                dfs_init_freqs(curr.right.as_ref(), freqs);
            }
        };

        dfs_init_freqs(root_rc_opt, &mut freqs);

        freqs
    }

    #[inline(always)]
    fn max_freq_and_count_max_freq(freqs: &HashMap<i32, i32>) -> (i32, i32) {
        let mut max_freq = 0_i32;
        let mut count = 0_i32;

        for (_, freq) in freqs.iter() {
            if *freq > max_freq {
                count = 1;
                max_freq = *freq;
            } else if *freq == max_freq {
                count += 1;
            }
        }

        (max_freq, count)
    }

    #[inline(always)]
    fn calc_res(
        freqs: &HashMap<i32, i32>,
        max_freq: i32,
        count_max_freq: i32,
    ) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::with_capacity(count_max_freq as usize);
        
        for (val, freq) in freqs.iter() {
            if *freq == max_freq {
                res.push(*val);
            }
        }

        res
    }

    pub fn find_mode(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let freqs = Self::init_freqs(root.as_ref());
        let (max_freq, count_max_freq) = Self::max_freq_and_count_max_freq(&freqs);
        let res = Self::calc_res(&freqs, max_freq, count_max_freq);

        res
    }
}
