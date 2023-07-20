import pandas as pd

def add(a,b):
    return a + b

def multiply(a, b):
    return a * b

def read_csv(file_path):
    df = pd.read_csv(file_path)
    return df
