# https://leetcode.com/problems/user-activity-for-the-past-30-days-i/

import pandas as pd
import datetime as dt

def user_activity(activity: pd.DataFrame) -> pd.DataFrame:
    time_delta = pd.Timedelta("29 days")
    end_date = dt.datetime(2019, 7, 27)

    filter1 = activity["activity_date"].between(end_date - time_delta, end_date)

    result = activity[filter1]
    result = (
        result[["user_id", "activity_date"]]
        .groupby("activity_date", as_index=False)
        .agg(active_users=("user_id", "nunique"))
    )
    result.rename(columns={"activity_date": "day"}, inplace=True)

    return result
