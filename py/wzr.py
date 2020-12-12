"""
最も雨が降った月を検索するスクリプトのプロトタイプ
"""
import pandas as pd
import xlrd
import matplotlib.pyplot as plt

df = pd.read_excel('./weather.xlsx', index_col=0, parse_dates=True)
month_ave = df.resample('M').mean()
month_ave_precipitation_max = month_ave['precipitation'].idxmax()
month_ave.plot()
plt.savefig("img.png")
#plt.show()
print("最も雨が降ったのは",month_ave_precipitation_max.year,"年",month_ave_precipitation_max.month,"月")