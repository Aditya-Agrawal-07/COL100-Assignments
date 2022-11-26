ID=[]
B=[]
def Highest():
    if len(B)==0:
        print('Invalid')
    else:
        c=B.index(max(B))
        print(ID[c])

def Order(orderID: int, BillValue:int):
    B.append(BillValue)
    ID.append(orderID)

def Serve():
    if len(B)==0:
        print('Invalid')
    else:
        c=B.index(max(B))
        B.remove(B[c])
        ID.remove(ID[c])
    
n=int(input())
for i in range(0,n):
    inp=input()
    if inp=="Serve":
        Serve()
    elif inp=="Highest":
        Highest()
    else:
        l=inp.split(' ')
        Order(int(l[1]),int(l[2]))