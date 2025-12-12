use std::cmp::Ordering;
use std::collections::VecDeque;

struct Data {
    event_type: u8,
    timestamp: i32,
    body: String,
}

impl Solution {
    pub fn count_mentions(number_of_users: i32, mut events: Vec<Vec<String>>) -> Vec<i32> {
        let len_users = number_of_users as usize;;
        let mut res = vec![0_i32; len_users];
        let mut count_all = 0_i32;
        let mut count_here = 0_i32;
        let mut count_here_minus_60 = 0_i32;
        let len_events = events.len();
        let mut events_data: Vec<Data> = Vec::with_capacity(len_events);
        let mut q: VecDeque<i32> = VecDeque::with_capacity(100);

        for mut event in events.into_iter() {
            let event_type = event[0].as_bytes()[0];
            let mut ts = event[1].parse::<i32>().unwrap();

            if event_type == b'O' {
                ts += 60;
            }

            events_data.push(Data{event_type: event_type, timestamp: ts, body: event.pop().unwrap()});
        }

        events_data.sort_unstable_by(|a, b| {
            if a.timestamp == b.timestamp {
                return match a.event_type {
                    b'M' => Ordering::Greater,
                    _ => Ordering::Less
                }
            }

            a.timestamp.cmp(&b.timestamp)
        });        

        for event in events_data.iter() {
            while let Some(front) = q.front() && *front + 60 < event.timestamp {
                count_here_minus_60 += 1;
                q.pop_front();
            }

            if event.event_type == b'O' {
                let id = event.body.parse::<usize>().unwrap();
                res[id] = res[id] - (count_here - count_here_minus_60);
            } else if event.body.as_bytes()[0] == b'H' {
                count_here += 1;
                q.push_back(event.timestamp);
            } else if event.body.as_bytes()[0] == b'A'  {
                count_all += 1;
            } else {
                for part in event.body.split_whitespace() {
                    let id =  part[2..].parse::<usize>().unwrap();
                    res[id] += 1;
                }
            }
        }

        for i in 0..len_users {
            res[i] += count_all + count_here;
        }

        res
    }
}
