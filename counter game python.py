t=int(input())
while(t>0):
    n=int(input())
    no=0;
    while(n!=1):
        val=0
        while(pow(2,val)<=n):
            val=val+1
        val=val-1
        if(pow(2,val)==n):
            n=n/2
        else:
            n=n-pow(2,val);
        no=no+1
    if(no%2==0):
        print "Richard"
    else:
        print "Louise"
    t=t-1
