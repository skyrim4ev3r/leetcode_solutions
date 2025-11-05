use std::collections::{BTreeSet, HashMap};
use std::cmp::Ordering;

#[derive(Debug, Eq, PartialEq)]
struct MaxPair {
    val: i32,
    freq: i32,
}

impl Ord for MaxPair {
    fn cmp(&self, other: &Self) -> Ordering {
        if other.freq == self.freq {
            other.val.cmp(&self.val)
        } else {
            other.freq.cmp(&self.freq)
        }
    }
}

impl PartialOrd for MaxPair {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

#[derive(Debug, Eq, PartialEq)]
struct MinPair {
    val: i32,
    freq: i32,
}

impl Ord for MinPair {
    fn cmp(&self, other: &Self) -> Ordering {
        if other.freq == self.freq {
            self.val.cmp(&other.val)
        } else {
            self.freq.cmp(&other.freq)
        }
    }
}

impl PartialOrd for MinPair {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}
impl Solution {
    pub fn find_x_sum(nums: Vec<i32>, k: i32, x: i32) -> Vec<i64> {
        let k_usize = k as usize;
        let x_usize = x as usize;
        let len = nums.len();
        let mut curr: BTreeSet<MinPair> = BTreeSet::new();
        let mut bench: BTreeSet<MaxPair> = BTreeSet::new();
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let mut res: Vec<i64> = Vec::with_capacity(len - k_usize + 1);
        let mut left = 0_usize;
        let mut sum = 0_i64;

        for num in nums[..k_usize].iter() {
            *freqs.entry(*num).or_insert(0) += 1;
        }

        for (val, freq) in freqs.iter() {
            curr.insert(MinPair{val: *val, freq: *freq});
            sum += (*val as i64) * (*freq as i64);
        }

        #[inline]
        fn fix(curr: &mut BTreeSet<MinPair>, bench: &mut BTreeSet<MaxPair>, sum: &mut i64, x: &usize) {
            while curr.len() > *x {
                let temp = curr.pop_first().unwrap();
                *sum -= (temp.val as i64) * (temp.freq as i64);
                bench.insert(MaxPair{val: temp.val, freq: temp.freq});
            }

            while curr.len() < *x && !bench.is_empty() {
                let temp = bench.pop_first().unwrap();
                *sum += (temp.val as i64) * (temp.freq as i64);
                curr.insert(MinPair{val: temp.val, freq: temp.freq});
            }

            while let Some(bench_top) = bench.iter().next() && let Some(curr_top) = curr.iter().next() {
                if bench_top.freq > curr_top.freq || (bench_top.freq == curr_top.freq && bench_top.val > curr_top.val) {
                    let b = bench.pop_first().unwrap();
                    *sum += (b.val as i64) * (b.freq as i64);
                    let t = curr.pop_first().unwrap();
                    *sum -= (t.val as i64) * (t.freq as i64);
                    curr.insert(MinPair{val: b.val, freq: b.freq});
                    bench.insert(MaxPair{val: t.val, freq: t.freq});
                } else {
                    break;
                }
            }
        }

        fix(&mut curr, &mut bench, &mut sum, &x_usize);
        res.push(sum);

        for right in k_usize..len {
            if nums[left] != nums[right] {
                *freqs.entry(nums[right]).or_insert(0) += 1;
                *freqs.entry(nums[left]).or_insert(0) -= 1;

                let new_freq_left = freqs[&nums[left]];
                let new_freq_right = freqs[&nums[right]];

                let old_freq_left = new_freq_left + 1;
                let old_freq_right = new_freq_right - 1;

                bench.remove(&MaxPair{val: nums[left], freq: old_freq_left});
                bench.remove(&MaxPair{val: nums[right], freq: old_freq_right});

                if curr.remove(&MinPair{val: nums[left], freq: old_freq_left}) {
                    sum -= (old_freq_left as i64) * (nums[left] as i64);
                }

                if curr.remove(&MinPair{val: nums[right], freq: old_freq_right}) {
                    sum -= (old_freq_right as i64) * (nums[right] as i64);
                }

                if new_freq_left != 0 {
                    bench.insert(MaxPair{val: nums[left], freq: new_freq_left});
                }
                bench.insert(MaxPair{val: nums[right], freq: new_freq_right});

                fix(&mut curr, &mut bench, &mut sum, &x_usize);                
            }

            res.push(sum);
            left += 1;
        }

        res
    }
}
