def sortings(inpt : str) -> str:  
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

if __name__=="__main__": 
    inpt = input()       
    out = sortings(inpt) 
    print (out)            