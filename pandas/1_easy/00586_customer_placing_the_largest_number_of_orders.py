# https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/

import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    g = orders.groupby("customer_number").agg(
        order_count=("customer_number", "count")
    )

    max_order = g["order_count"].max()
    filter1 = g["order_count"] == max_order

    return g[filter1].reset_index()[["customer_number"]]
