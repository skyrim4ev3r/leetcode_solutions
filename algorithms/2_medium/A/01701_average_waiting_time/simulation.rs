impl Solution {
    pub fn average_waiting_time(customers: Vec<Vec<i32>>) -> f64 {

        let mut curr_time = 0_i64;
        let mut total_waiting = 0_i64;
        let customers_len = customers.len(); 

        for customer in customers.into_iter() {
            let arrive_time = customer[0] as i64;
            let order_time = customer[1] as i64;

            if arrive_time >= curr_time {
                total_waiting += order_time;
                curr_time = arrive_time + order_time;
            } else {
                let waiting_time = curr_time - arrive_time;
                total_waiting +=  waiting_time + order_time;
                curr_time += order_time;
            }
        }

        total_waiting as f64 / customers_len as f64
    }
}
