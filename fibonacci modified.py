import sys
a = raw_input()
a,b,n=a.split()
a=int(a)
b=int(b)
n=int(n)
c = b+1
no=2
while(no<n):
    c=b*b+a
    a=b
    b=c
    no=no+1

print (b)