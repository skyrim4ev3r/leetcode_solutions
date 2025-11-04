use std::collections::{HashSet, HashMap, VecDeque};
use std::cmp::Ordering;

#[derive(PartialEq, Eq, Hash, Clone)]
struct Packet {
    source: i32,
    destination: i32,
    timestamp: i32,
}

struct Router {
    packets_set: HashSet<Packet>,
    packets_linkedlist: VecDeque<Packet>,
    memoryLimit: usize,
    dest_map: HashMap<i32, VecDeque<i32>>,
}

impl Router {

    fn new(memoryLimit: i32) -> Self {
        Self {
            packets_set: HashSet::new(),
            packets_linkedlist: VecDeque::new(),
            memoryLimit: memoryLimit as usize,
            dest_map: HashMap::new()
        }
    }

    fn add_packet(&mut self, source: i32, destination: i32, timestamp: i32) -> bool {
        let packet = Packet { source, destination, timestamp };

        if let Some(_) = self.packets_set.get(&packet) {
            return false;
        }

        if self.packets_set.len() == self.memoryLimit {
            let _ = self.forward_packet();
        }

        self.packets_set.insert(packet.clone());
        self.dest_map.entry(destination).or_insert_with(VecDeque::new).push_back(timestamp);
        self.packets_linkedlist.push_back(packet);

        true
    }

    fn forward_packet(&mut self) -> Vec<i32> {

        if let Some(packet) = self.packets_linkedlist.pop_front() {
            self.packets_set.remove(&packet);

            self.dest_map.get_mut(&packet.destination).map(|vec| vec.pop_front());//remove front element of 

            return vec![packet.source, packet.destination, packet.timestamp];
        }

        Vec::new()
    }

    fn get_count(&self, destination: i32, start_time: i32, end_time: i32) -> i32 {

        if let Some(vec_deque) = self.dest_map.get(&destination) {
            (Self::upper_bound(vec_deque, end_time) - Self::lower_bound(vec_deque, start_time)) as i32
        } else {
            0
        }
    }

    fn lower_bound(vec_deque: &VecDeque<i32>, target: i32) -> usize {
        vec_deque.binary_search_by(|&v| {
            match v.cmp(&target) {
                Ordering::Less => Ordering::Less,
                Ordering::Equal => Ordering::Greater,
                Ordering::Greater => Ordering::Greater,
            }
        }).unwrap_err()
    }

    fn upper_bound(vec_deque: &VecDeque<i32>, target: i32) -> usize {
        vec_deque.binary_search_by(|&v|{
            match v.cmp(&target) {
                Ordering::Less => Ordering::Less,
                Ordering::Equal => Ordering::Less,
                Ordering::Greater => Ordering::Greater,
            }
        }).unwrap_err()
    }
}
