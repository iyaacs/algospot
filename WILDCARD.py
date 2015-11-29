import fnmatch
C=input()
for T in range(0,C):
    wild=raw_input()
    
    n=input()
    strarr=list()
    for i in range(0,n):
        buf=raw_input()
        strarr.append(buf)

    filtered=fnmatch.filter(strarr,wild)
    filtered.sort()
    for fil in filtered:
        print fil