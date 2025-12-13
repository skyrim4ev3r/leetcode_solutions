# https://leetcode.com/problems/rising-temperature/

import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather.sort_values(by="recordDate", inplace=True)
    prev_temp = weather["temperature"].shift(1)
    prev_date = weather["recordDate"].shift(1)
    filter1 = prev_temp < weather["temperature"]
    filter2 = prev_date + pd.Timedelta(days=1) == weather["recordDate"]
    res = weather[filter1 & filter2]

    return res[['id']].rename(columns={"id": "Id"})
