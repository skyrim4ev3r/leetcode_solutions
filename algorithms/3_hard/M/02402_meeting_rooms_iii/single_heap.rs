use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Debug, Eq, PartialEq)]
struct Room {
    free_at: i64,
    id: i32,
    count: i32,
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

        let mut rooms: BinaryHeap<Room> = BinaryHeap::with_capacity(n as usize);

        for i in 0..n {
            rooms.push(Room {free_at: 0, id: i, count: 0});
        }

        for m in meetings.iter() {
            let start = m[0] as i64;
            let end = m[1] as i64;

            while let Some(top) = rooms.peek() && top.free_at < start {
                let mut room = rooms.pop().unwrap();
                room.free_at = start;
                rooms.push(room);
            }

            let mut room = rooms.pop().unwrap();
            room.free_at += end - start;
            room.count += 1;
            rooms.push(room);
        }

        let mut max_count = -1_i32;
        let mut max_id = -1_i32;

        for room in rooms.into_iter() {
            if room.count > max_count {
                max_count = room.count;
                max_id = room.id;
            } else if room.count == max_count && room.id < max_id {
                max_id = room.id;
            }
        }

        max_id
    }
}
