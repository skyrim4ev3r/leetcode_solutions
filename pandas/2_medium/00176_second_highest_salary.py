# https://leetcode.com/problems/second-highest-salary/

import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.groupby("salary", as_index=False).first()
    sorted_values = df["salary"].sort_values(ascending=False)
    secondlargest = sorted_values.iloc[1] if 2 <= len(sorted_values) else None
    return pd.DataFrame({"SecondHighestSalary": [secondlargest]})
