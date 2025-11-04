use std::collections::{BinaryHeap, HashMap};
use std::cmp::Ordering;

#[derive(Eq, PartialEq, Debug, Clone)]
struct Task {
    user_id: i32,
    task_id: i32,
    priority: i32,
}

impl Ord for Task {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.priority == other.priority {
            self.task_id.cmp(&other.task_id)
        } else {
            self.priority.cmp(&other.priority)
        }
    }
}

impl PartialOrd for Task {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct TaskManager {
    tasks_heap: BinaryHeap<Task>,
    tasks_map: HashMap<i32, Task>,
}

impl TaskManager {

    fn new(tasks: Vec<Vec<i32>>) -> Self {

        let mut tasks_heap = BinaryHeap::<Task>::new();
        let mut tasks_map = HashMap::<i32, Task>::new();

        for task in tasks.into_iter() {

            let task_id = task[1];

            let task = Task {
                user_id: task[0],
                task_id: task[1],
                priority: task[2],
            };

            tasks_heap.push(task.clone());
            tasks_map.insert(task_id, task);
        }

        Self {
            tasks_heap: tasks_heap,
            tasks_map: tasks_map,
        }
    }
    
    fn add(&mut self, user_id: i32, task_id: i32, priority: i32) {

        let task = Task {
                user_id: user_id,
                task_id: task_id,
                priority: priority,
        };

        self.tasks_heap.push(task.clone());
        self.tasks_map.insert(task_id, task);        
    }
    
    fn edit(&mut self, task_id: i32, new_priority: i32) {

        if let Some(mut task) = self.tasks_map.get_mut(&task_id) {
            task.priority = new_priority;
            self.tasks_heap.push(task.clone());
        }

    }
    
    fn rmv(&mut self, task_id: i32) {
        self.tasks_map.remove(&task_id);
    }
    
    fn exec_top(&mut self) -> i32 {

        while let Some(task_heap) = self.tasks_heap.pop() {

            let task_id = task_heap.task_id;
            let user_id = task_heap.user_id;
            if let Some(mut task_map) = self.tasks_map.get_mut(&task_id) {
                if task_heap.priority == task_map.priority 
                    && user_id == task_map.user_id
                    && task_id == task_map.task_id
                {
                    self.tasks_map.remove(&task_id);
                    return user_id;
                }
            }
        }

        -1i32
    }
}
