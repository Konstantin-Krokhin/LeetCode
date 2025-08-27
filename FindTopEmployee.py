import pandas as pd
import os

"""
    Return a dataframe with a single column 'emp_id' containing the employee id
    with the highest total sales across all branches. If the input is empty,
    lacks required columns, or there is no unique top employee, return an empty
    dataframe with header ['emp_id'].
"""
def topEmp(df: pd.DataFrame) -> pd.DataFrame:
	if df is None or df.empty or not {'emp_id', 'sales'}.issubset(df.columns):
		return pd.DataFrame(columns = ['emp_id'])
	
	# Work on copy and properly convert column values to numeric treating N/A or missing as 0
	data = df.copy()
	data['sales'] = pd.to_numeric(data['sales'], errors = 'coerce').fillna(0)

	totals = data.groupby(['branch','emp_id'], as_index = True)['sales'].sum()

	if totals.empty:
		return pd.DataFrame(columns = ['emp_id'])

	max_value = totals.max()
	top_ids = totals[totals == max_value].index

	if len(top_ids) != 1:
		return pd.DataFrame(columns = ['emp_id'])

	return pd.DataFrame({'emp_id' : [top_ids[0]]})


if __name__ == "__main__":
	fptr = open(os.environ['OUTPUT_PATH'], 'w')
    df = pd.read_csv('/dev/stdin')
    result = topEmp(df)
    fptr.write(result.to_csv(index=False))
    fptr.close()