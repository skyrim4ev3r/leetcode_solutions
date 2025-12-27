use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Debug, Eq, PartialEq)]
struct Room {
    free_at: i64,
    id: i32,
}

impl Ord for Room {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.free_at == other.free_at {
            return other.id.cmp(&self.id);
        }

        other.free_at.cmp(&self.free_at)
    }
}

impl PartialOrd for Room {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn most_booked(n: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        meetings.sort_unstable_by(|a, b| a[0].cmp(&b[0]));

        let mut in_use_rooms: BinaryHeap<Room> = BinaryHeap::with_capacity(n as usize);
        let mut free_rooms: BinaryHeap<i32> = BinaryHeap::with_capacity(n as usize);
        let mut counts = vec![0_i32; n as usize];

        for i in 0..n {
            free_rooms.push(-i);
        }

        for m in meetings.iter() {
            let start = m[0] as i64;
            let end = m[1] as i64;

            while let Some(top) = in_use_rooms.peek() && top.free_at <= start {
                free_rooms.push(-top.id);
                in_use_rooms.pop();
            }

            if let Some(id_negative) = free_rooms.pop() {
                let id = id_negative.abs();
                counts[id as usize] += 1;
                in_use_rooms.push(Room{free_at: end, id: id});                
            } else {
                let mut room = in_use_rooms.pop().unwrap();
                room.free_at += end - start;
                counts[room.id as usize] += 1;
                in_use_rooms.push(room);
            }
        }

        let mut max_count = -1_i32;
        let mut max_id = -1_i32;

        for (i, count) in counts.into_iter().enumerate() {
            if count > max_count {
                max_count = count;
                max_id = i as i32;
            }
        }

        max_id
    }
}
