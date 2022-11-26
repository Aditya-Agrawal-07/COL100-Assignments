a=float(input())
b=float(input())
p=int(input())
d=0
if p==1:
    d=a+b
elif p==2:
    d=a-b
elif p==3:
    d=a*b
elif p==4:
    d=a/b
else:
    d=a%b

print(f"{d:.2f}")