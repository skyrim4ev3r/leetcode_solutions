# https://leetcode.com/problems/combine-two-tables/

import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    merge_result = person.merge(address, on='personId', how='left')

    return merge_result[['firstName', 'lastName', 'city', 'state']]
