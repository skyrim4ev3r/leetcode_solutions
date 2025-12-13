# https://leetcode.com/problems/biggest-single-number/

import pandas as pd

def biggest_single_number(my_numbers: pd.DataFrame) -> pd.DataFrame:
    my_numbers = my_numbers.drop_duplicates(["num"], keep=False)
    num_max = my_numbers["num"].max()
    return pd.DataFrame({'num': [num_max]})
