L=[]
def Issue():
    if len(L)==0:
        print('Invalid')
    else:
        L.remove(L[0])

def Join(AadharID: int):
    L.append(AadharID)
    
def Check():
    if len(L)==0:
        print('Invalid')
    else:
        print(L[0])

def GetLine():
    if len(L)==0:
        print('Invalid')
    else:
        print(*L)

n=int(input())
for i in range(0,n):
    inp=input()
    if inp=='Check':
        Check()
    elif inp=='GetLine':
        GetLine()
    elif inp=="Issue":
        Issue()
    else:
        l=inp.split(' ')
        L.append(l[1])