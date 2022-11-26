def numwords(n):
    L=[]
    M=[]
    for i in range(0,n):
        inpstr=input()
        L.append(inpstr)
    for j in L:
        j=j.replace(' ',',')
        j=j.replace('.',',')
        l=j.split(",")
        while("" in l) :
            l.remove("")
        M.append(len(l))
    m=min(M)
    print(f"{m:.2f}")
n=int(input())
numwords(n)
             