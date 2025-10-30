impl Solution {
    pub fn reverse_k_group(mut head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
          if k <= 1 || head.is_none() {
            return head;
        }
        
        let k = k as usize;
        let mut curr_node_opt = head;
        let mut stack_a: Vec<Vec<Box<ListNode>>> = Vec::new(); 
        let mut stack_b: Vec<Box<ListNode>> = Vec::new();

        while let Some(mut curr_node) = curr_node_opt {
            curr_node_opt = curr_node.next.take(); // Disconnect the node
            stack_b.push(curr_node);
            if stack_b.len() == k {
                stack_a.push(stack_b);
                stack_b = Vec::new();
            }
        }
        
        if !stack_b.is_empty() {
            stack_b.reverse();
            stack_a.push(stack_b);
        }

        let mut new_head: Option<Box<ListNode>> = None;

        for group in stack_a.into_iter().rev() {
            for mut val in group.into_iter() {
                val.next = new_head;
                new_head = Some(val);
            }
        }

        new_head
    }
}
