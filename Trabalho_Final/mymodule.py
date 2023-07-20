import pandas as pd

def add(a,b):
    return a + b

def multiply(a, b):
    return a * b

def read_csv(file_path):
    try:
        df = pd.read_csv(file_path)
    except FileNotFoundError:
        df = pd.DataFrame()
        df.to_csv(file_path, index=False)
    if df.empty:
        df = pd.DataFrame()
    return df

def insert_into_csv(file_path):
    df = read_csv(file_path)
    df.insert()

def list_csv_columns(file_path):
    df = pd.read_csv(file_path)
    columns = df.columns.tolist()
    return columns