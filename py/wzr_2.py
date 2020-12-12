"""
最も雨が降った月を検索するスクリプト
"""
import argparse
import pandas as pd
import xlrd
import matplotlib.pyplot as plt

class Weather_data:
    def __init__(self, file_path, sheet_name):
        self.df = pd.read_excel(file_path, index_col=0, parse_dates=True,sheet_name=sheet_name)
        self.plot_df = None
    def calc_mean_max(self, entity, column):
        df_mean = self.df.resample(entity).mean()
        self.plot_df = df_mean
        return df_mean[column].idxmax()
    def plot(self,img_name):
        self.plot_df.plot()
        plt.savefig(img_name)

if __name__ == '__main__':
    # 引数処理
    parser = argparse.ArgumentParser(description='')
    parser.add_argument('file_path', help='excelファイルのpath') 
    parser.add_argument('--sheet_name', default=0, help='excelファイルのシート名')
    parser.add_argument('--img_name', default="img.png", help='グラフの名前')
    args = parser.parse_args()

    # データ読み込み グラフ出力
    wd = Weather_data(args.file_path,args.sheet_name)
    mm = wd.calc_mean_max('M','precipitation')
    print("最も雨が降ったのは",mm.year,"年",mm.month,"月")
    wd.plot(args.img_name)

