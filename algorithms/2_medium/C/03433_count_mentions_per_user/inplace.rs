use std::cmp::Ordering;

impl Solution {
    pub fn count_mentions(number_of_users: i32, mut events: Vec<Vec<String>>) -> Vec<i32> {
        events.sort_unstable_by(|a, b| {
            let ts_a = a[1].parse::<i32>().unwrap();
            let ts_b = b[1].parse::<i32>().unwrap();

            if ts_a == ts_b {
                return match a[0].as_bytes()[0] {
                    b'M' => Ordering::Greater,
                    _ => Ordering::Less
                }
            }

            ts_a.cmp(&ts_b)
        });

        let len = number_of_users as usize;
        let mut res = vec![0_i32; len];
        let mut status = vec![i32::MIN; len];
        let mut count_all = 0_i32;

        for event in events.iter() {
            let ts = event[1].parse::<i32>().unwrap();

            if event[0].as_bytes()[0] == b'O' {
                let id = event[2].parse::<usize>().unwrap();
                status[id] = ts + 60;
            } else if event[2].as_bytes()[0] == b'H' {
                for i in 0..len {
                    if status[i] <= ts {
                        res[i] += 1;
                    }
                }
            } else if event[2].as_bytes()[0] == b'A' {
                count_all += 1;
            } else {
                for part in event[2].split_whitespace() {
                    let id =  part[2..].parse::<usize>().unwrap();
                    res[id] += 1;
                }
            }
        }

        if count_all > 0 {
            for i in 0..len {
                res[i] += count_all;
            }
        }

        res
    }
}
