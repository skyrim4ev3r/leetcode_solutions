# https://leetcode.com/problems/big-countries/

import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    least_pop = 25_000_000
    least_area = 3_000_000
    res = world[(world["population"] >= least_pop) | (world["area"] >= least_area)]

    return res[["name", "population", "area"]]
