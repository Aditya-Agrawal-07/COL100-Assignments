def PrintMatrix(A:list ):
	# Print function that can help you debug your solutions
	if A == None:
		print(A)
		return
	# It will print None if the input is None
	rows = len(A)
	cols = len(A[0])
	for i in range(rows):
		for j in range(cols):
			print(A[i][j], end = " ")
		print()
def CheckMatrix(A: list)->bool:
	L=[]
	c=len(A[0])
	for i in range(0,len(A)):
		if len(A[i])==0:
			L.append("False")
			break
		elif len(A[i])!=c:
			L.append("False")
			break
		else:
			for j in A[i]:
				if type(j)!=float:
					L.append("False")
					break
	if len(L)==0:
		return True
	else:
		return False

def Transpose(A:list) -> list:
	if CheckMatrix(A)==False:
		return None
	else:
		c=len(A)
		d=len(A[0])
		K=[]
		for j in range(0,d):
			M=[]
			for k in range(0,c):
				M.append(A[k][j])
			K.append(M)
		return K

def Multiplication(A:list,B:list) -> list:
	x=len(A)
	y=len(A[0])
	if CheckMatrix(A)==False:
		return None
	elif CheckMatrix(B)==False:
		return None
	elif len(B)!=y:
		return None
	else:
		P=[]
		for i in range(0,x):
			R=[]
			for j in range(0,len(B[0])):
				R.append(float(0))
			P.append(R)
		for i in range(0,x):
			for j in range(0,len(B[0])):
				for k in range(0,y):
					P[i][j] += A[i][k] * B[k][j]
		return P

def Addition(A:list,B:list) -> list:
	if CheckMatrix(A)==False:
		return None
	elif CheckMatrix(B)==False:
		return None
	elif len(A)!=len(B):
		return None
	elif len(A[0])!=len(B[0]):
		return None
	else:
		C=[]
		for i in range(0,len(A)):
			D=[]
			for j in range(0,len(A[0])):
				D.append(A[i][j]+B[i][j])
			C.append(D)
		return C

def Symmetric(A: list)->bool:
	if CheckMatrix(A)==False:
		return False
	elif len(A)!=len(A[0]):
		return False
	else:
		D=Transpose(A)
		if A==D:
			return True
		else:
			return False

matrixA = [[1.00,2.00,3.00],[2.00,3.00,4.00],[4.00,5.00,6.00]]
matrixB = [[1.00,0.00,2.00],[9.00,8.00,5.00],[5.00,8.00,0.00]]
matrixC = [["Hello"]]
matrixD = [[1.00,2.00],[5.00,7.00],[3.00,8.00]]

# Printing Matrix A
PrintMatrix(matrixA)

# Checking whether matrixC is a valid Matrix
print(CheckMatrix(matrixC))

# Printing the multiplication of matrixA and matrixB
PrintMatrix(Multiplication(matrixA,matrixB))

# Printing the addition of matrixA and matrixB
PrintMatrix(Addition(matrixA,matrixB))

# Is matrixA a symmetric matrix
print(Symmetric(matrixA))

# Printing the transpose of matrixA
PrintMatrix(Transpose(matrixA))