from typing import List

def asc(inpt : str) -> str:  
    A=[]
    for k in inpt:
        A.append(k)
    B=[]
    C=[]
    D=[]
    X=""
    for i in A:
        if i=="1" or i=="2" or i=="3" or i=="4" or i=="5" or i=="6" or i=="7" or i=="8" or i=="9" or i=="0":
            c=0
            for j in range(0,len(A)):
                if i==A[j]:
                    c+=1
            if c%2!=0:
                B.append(int(i))
            else:
                C.append(i)
        else:
            C.append(i)
    B.sort()
    for n in B:
        D.append(str(n))
    D.extend(C)
    for m in D:
        X+=m
    return X

def sortings(lst : List[str]) -> List[str]:
    L=[]
    l=[]
    M=[]
    N=[]
    n=[]
    P=[]
    Q=[]
    for i in lst:
        L.append(asc(i))
    for j in L:
        c=0
        for b in range(0,26):
            if (chr(b+65) in j) or (chr(b+97) in j):
                c+=1
        if c==0 and j!='':
            M.append(j)
        elif j=='':
            M.append(None)
        else:
            for k in range(0,len(j)):
                if j[k]!="0" and j[k]!="1" and j[k]!="2" and j[k]!="3" and j[k]!="4" and j[k]!="5" and j[k]!="6" and j[k]!="7" and j[k]!="8" and j[k]!="9":
                    if k==0:
                        M.append(None)
                        break
                    else:
                        M.append(j[0:k])
                        break
    for a in range(0,len(M)):
        if type(M[a])==str:
            N.append(int(M[a]))
            l.append(M[a])
        else:
            l.append("-1")
    N.sort()
    for d in range(0,len(N)):
        for e in range(0,len(M)):
            if ((N[d])==int(l[e])) and (e not in n):
                n.append(e)
    for f in n:
        P.append(L[f])
    for g in L:
        if g not in P:
            Q.append(g)
    P.extend(Q)
    return P

if __name__=="__main__":
    lst = []             
    num = int(input())
    for i in range(num):
        inpt = input()
        lst.append(inpt) 
    lst = sortings(lst)  
    print (lst)          