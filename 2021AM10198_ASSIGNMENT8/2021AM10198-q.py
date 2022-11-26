from datetime import datetime
start_time = datetime.now()
from typing import Tuple, List
# No other imports allowed

# PART OF THE DRIVER CODE

def input_sudoku() -> List[List[int]]:
	"""Function to take input a sudoku from stdin and return
	it as a list of lists.
	Each row of sudoku is one line.
	"""
	sudoku= list()
	for _ in range(9):
		row = list(map(int, input().rstrip(" ").split(" ")))
		sudoku.append(row)
	return sudoku

def print_sudoku(sudoku:List[List[int]]) -> None:
	"""Helper function to print sudoku to stdout
	Each row of sudoku in one line.
	"""
	for i in range(9):
		for j in range(9):
			print(sudoku[i][j], end = " ")
		print()

# You have to implement the functions below

def get_block_num(sudoku:List[List[int]], pos:Tuple[int, int]) -> int:
	"""This function takes a parameter position and returns
	the block number of the block which contains the position.
	"""
	# your code goes here
	row=pos[0]-1
	column=pos[1]-1
	row-=row%3
	column-=column%3
	num=row+(column/3)+1
	return int(num)

def get_position_inside_block(sudoku:List[List[int]], pos:Tuple[int, int]) -> int:
	"""This function takes parameter position
	and returns the index of the position inside the corresponding block.
	"""
	# your code goes here
	d=0
	c=0
	a=(pos[0]-1)%3
	b=(pos[1]-1)%3
	for i in range(3):
		if i==a:
			for j in range(3):
				c+=1
				if j==b:
					d='break'
					break
		else:
			c+=3
		if d=='break':
			break
	return c


def get_block(sudoku:List[List[int]], x: int) -> List[int]:
	"""This function takes an integer argument x and then
	returns the x^th block of the Sudoku. Note that block indexing is
	from 1 to 9 and not 0-8.
	"""
	# your code goes here
	l=[]
	a=b=d=0
	for r in range(0,7,3):
		for c in range(0,7,3):
			if x==r+(c/3)+1:
				a,b,d=r,c,'break'
				break
		if d=='break':
			break
	for i in range(3):
		for j in range(3):
			l.append(sudoku[r+i][c+j])
	return l
	
def get_row(sudoku:List[List[int]], i: int)-> List[int]:
	"""This function takes an integer argument i and then returns
	the ith row. Row indexing have been shown above.
	"""
	# your code goes here
	return sudoku[i-1]

def get_column(sudoku:List[List[int]], x: int)-> List[int]:
	"""This function takes an integer argument i and then
	returns the ith column. Column indexing have been shown above.
	"""
	# your code goes here
	l=[]
	for i in sudoku:
		l.append(i[x-1])
	return l

def find_first_unassigned_position(sudoku : List[List[int]]) -> Tuple[int, int]:
	"""This function returns the first empty position in the Sudoku. 
	If there are more than 1 position which is empty then position with lesser
	row number should be returned. If two empty positions have same row number then the position
	with less column number is to be returned. If the sudoku is completely filled then return `(-1, -1)`.
	"""
	# your code goes here
	c=d=e=0
	for i in range(9):
		for j in range(9):
			if sudoku[i][j]==0:
				c,d,e=i+1,j+1,'break'
				break
		if e=='break':
			break
	if c==0:
		return (-1,-1)
	else:
		return (c,d)

def valid_list(lst: List[int])-> bool:
	"""This function takes a lists as an input and returns true if the given list is valid. 
	The list will be a single block , single row or single column only. 
	A valid list is defined as a list in which all non empty elements doesn't have a repeating element.
	"""
	# your code goes here
	x=0
	for i in lst:
		if lst.count(i)>1 and i!=0:
			x="False"
			break
	if x=="False":
		return False
	else:
		return True

def valid_sudoku(sudoku:List[List[int]])-> bool:
	"""This function returns True if the whole Sudoku is valid.
	"""
	# your code goes here
	for row in sudoku:
		if valid_list(row)==False:
			return False
	for i in range(9):
		if valid_list(get_column(sudoku,i+1))==False:
			return False
	for j in range(9):
		if valid_list(get_block(sudoku,j+1))==False:
			return False
	return True

def get_candidates(sudoku:List[List[int]], pos:Tuple[int, int]) -> List[int]:
	"""This function takes position as argument and returns a list of all the possible values that 
	can be assigned at that position so that the sudoku remains valid at that instant.
	"""
	# your code goes here
	l=[]
	A=get_block(sudoku,get_block_num(sudoku,pos))
	B=get_row(sudoku,pos[0])
	C=get_column(sudoku,pos[1])
	for i in range(1,10):
		if (i not in A) and (i not in B) and (i not in C):
			l.append(i)
	return l

def make_move(sudoku:List[List[int]], pos:Tuple[int, int], num:int) -> List[List[int]]:
	"""This function fill `num` at position `pos` in the sudoku and then returns
	the modified sudoku.
	"""
	# your code goes here
	sudoku[pos[0]-1][pos[1]-1]=num
	return sudoku

def undo_move(sudoku:List[List[int]], pos:Tuple[int, int]):
	"""This function fills `0` at position `pos` in the sudoku and then returns
	the modified sudoku. In other words, it undoes any move that you 
	did on position `pos` in the sudoku.
	"""
	# your code goes here
	sudoku[pos[0]-1][pos[1]-1]=0
	return sudoku

def sudoku_solver(sudoku: List[List[int]]) -> Tuple[bool, List[List[int]]]:
	""" This is the main Sudoku solver. This function solves the given incomplete Sudoku and returns 
	true as well as the solved sudoku if the Sudoku can be solved i.e. after filling all the empty positions the Sudoku remains valid.
	It return them in a tuple i.e. `(True, solved_sudoku)`.

	However, if the sudoku cannot be solved, it returns False and the same sudoku that given to solve i.e. `(False, original_sudoku)`
	"""
	# your code goes here

	# to complete this function, you may define any number of helper functions.
	# However, we would be only calling this function to check correctness.
	og = sudoku.copy()
	if valid_sudoku(sudoku)==False:
		return (False,og)
	else:
		pos=find_first_unassigned_position(sudoku)
		if pos==(-1,-1):
			if valid_sudoku(sudoku)==False:
				return (False,og)
			else:
				return (True,sudoku)
		else:
			cand=get_candidates(sudoku,pos)
			val_i = 0
			for i in range(len(cand)):
				val_i = i
				make_move(sudoku,pos,cand[i])
				if find_first_unassigned_position(sudoku)==(-1,-1):
					return (True,sudoku)
				else:
					s =  sudoku_solver(sudoku)
					if s[0] == True:
						return s
					else:
						undo_move(sudoku,pos)
						continue
			if len(cand) == 0 or val_i >= len(cand) - 1 :
				undo_move(sudoku,pos)
				return (False,sudoku)

# PLEASE NOTE:
# We would be importing your functions and checking the return values in the autograder.
# However, note that you must not print anything in the functions that you define above before you 
# submit your code since it may result in undefined behaviour of the autograder.
# Following is the driver code
# you can edit the following code to check your performance.
if __name__ == "__main__":

	# Input the sudoku from stdin
	sudoku = input_sudoku()

	# Try to solve the sudoku
	possible, sudoku = sudoku_solver(sudoku)

	# Check if it could be solved
	if possible:
		print("Found a valid solution for the given sudoku :)")
		print_sudoku(sudoku)

	else:
		print("The given sudoku cannot be solved :(")
		print_sudoku(sudoku)
end_time = datetime.now()
print('Duration: {}'.format(end_time - start_time))