struct StockSpanner {
    stack: Vec<(i32, i32)>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {

    fn new() -> Self {
        Self {
            stack: Vec::new()
        }
    }

    fn next(&mut self, price: i32) -> i32 {
        let mut count = 1_i32;

        while let Some((prev_price, prev_count)) = self.stack.last() && *prev_price <= price {
            count += *prev_count;
            self.stack.pop();
        }

        self.stack.push((price, count));

        count
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * let obj = StockSpanner::new();
 * let ret_1: i32 = obj.next(price);
 */
