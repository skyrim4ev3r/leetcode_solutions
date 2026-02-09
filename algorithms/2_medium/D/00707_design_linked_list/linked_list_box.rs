struct Node {
    val: i32,
    next: Option<Box<Node>>,
}

impl Node {
    fn new(val: i32) -> Self {
        Self {
            val: val,
            next: None,
        }
    }
}

struct MyLinkedList {
    len: usize,
    head: Option<Box<Node>>,
}

impl MyLinkedList {
    fn new() -> Self {
        Self {
            len: 0,
            head: None,
        }
    }

    fn get(&self, index: i32) -> i32 {
        let index = index as usize;
        if (index >= self.len) { return -1; }
        let mut curr = self.head.as_ref().unwrap();
        for i in 0..index {
            curr = curr.next.as_ref().unwrap();
        }
        curr.val
    }

    fn add_at_head(&mut self, val: i32) {
        let mut node = Box::new(Node::new(val));
        node.next = self.head.take();
        self.head = Some(node);
        self.len += 1;
    }

    fn add_at_tail(&mut self, val: i32) {
        self.add_at_index(self.len as i32, val);
    }

    fn add_at_index(&mut self, index: i32, val: i32) {
        let index = index as usize;
        if (index > self.len) { return; };

        if index == 0 {
            self.add_at_head(val);
        } else {
            let mut new_node = Box::new(Node::new(val));
            let mut curr = self.head.as_mut().unwrap();
            for _ in 1..index {
                curr = curr.next.as_mut().unwrap();
            }
            new_node.next = curr.next.take();
            curr.next = Some(new_node);
            self.len += 1;
        }
    }

    fn delete_at_index(&mut self, index: i32) {
        let index = index as usize;
        if index >= self.len { return; }

        if self.len == 1 {
            self.head = None;
            self.len = 0;
        } else if index == 0 {
            self.head = self.head.take().unwrap().next;
            self.len -= 1;
        } else {
            let mut curr = self.head.as_mut().unwrap();
            for _ in 1..index {
                curr = curr.next.as_mut().unwrap();
            }
            curr.next = curr.next.take().unwrap().next.take();
            self.len -= 1;
        }
    }
}
