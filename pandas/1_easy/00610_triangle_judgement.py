# https://leetcode.com/problems/triangle-judgement/

import pandas as pd

def triangle_judgement(triangle: pd.DataFrame) -> pd.DataFrame:
    x_y = (triangle["x"] + triangle["y"]) > triangle["z"]
    x_z = (triangle["x"] + triangle["z"]) > triangle["y"]
    y_z = (triangle["y"] + triangle["z"]) > triangle["x"]
    triangle["triangle"] = x_y & x_z & y_z
    triangle["triangle"] = triangle["triangle"].astype(str)
    triangle["triangle"] = triangle["triangle"].replace({"True": "Yes", "False": "No"})

    return triangle
