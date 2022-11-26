Inpstr=input()
N=len(Inpstr)
if N==1:
    print('YES')
elif N==2:
    if Inpstr[0]==Inpstr[1]:
        print('YES')
    else:
        print('NO')
elif N==3:
    if Inpstr[0]==Inpstr[2]:
        print('YES')
    else:
        print('NO')
else:
    if Inpstr[0]==Inpstr[3]:
        if Inpstr[1]==Inpstr[2]:
            print('YES')
        else:
            print('NO')
    else:
        print('NO')

