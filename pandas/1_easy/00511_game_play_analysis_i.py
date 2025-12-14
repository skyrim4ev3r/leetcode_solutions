# https://leetcode.com/problems/game-play-analysis-i/

import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    activity.sort_values(by="event_date", inplace=True)
    activity.drop_duplicates("player_id", inplace=True)
    activity = activity[["player_id", "event_date"]]
    activity.sort_values(by="player_id", inplace=True)
    activity.rename(columns={'event_date': 'first_login'}, inplace=True)

    return activity
