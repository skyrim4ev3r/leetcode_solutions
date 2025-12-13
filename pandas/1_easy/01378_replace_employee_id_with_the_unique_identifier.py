# https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/

import pandas as pd

def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    merge_df = pd.merge(employees, employee_uni, on="id", how="left")
    return merge_df[["unique_id", "name"]]
