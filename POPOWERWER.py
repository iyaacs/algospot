T=input()
for t in range(0,T):
    raw=raw_input()
    raw=raw.strip()
    raws=raw.split(' ')
    X=int(raws[0])
    Y=int(raws[1])

    dic=dict()
    for i in range(1,X+1):
        for j in range(1,Y+1):
            dic[pow(i,j)]=1
    print len(dic)