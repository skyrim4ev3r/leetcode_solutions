class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        curr_time = 0
        total_waiting = 0
        customers_len = len(customers)

        for customer in customers:

            arrive_time = customer[0]
            order_time = customer[1]

            if arrive_time >= curr_time:
                total_waiting += order_time
                curr_time = arrive_time + order_time
            else:
                waiting_time = curr_time - arrive_time
                total_waiting +=  waiting_time + order_time
                curr_time += order_time

        return total_waiting / customers_len
