def padovan(a):
    if a==2 or a==1 or a==0:
        return 1
    else:
        return(padovan(a-2)+padovan(a-3))
a=int(input())
print(f"{padovan(a):.2f}")