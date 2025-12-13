# https://leetcode.com/problems/swap-sex-of-employees/

import pandas as pd

def swap_salary(salary: pd.DataFrame) -> pd.DataFrame:
    salary["sex"] = salary["sex"].replace({'f': 'm', 'm': 'f'})
    return salary

def swap_salary(salary: pd.DataFrame) -> pd.DataFrame:
    salary['sex'] = salary['sex'].apply(lambda x: 'm' if x == 'f' else 'f')
    return df

def swap_salary(salary: pd.DataFrame) -> pd.DataFrame:
    filter_m = salary['sex'] == 'm'
    salary['sex'] = salary['sex'].where(filter_m, 'm').where(~filter_m, 'f')
    return salary
