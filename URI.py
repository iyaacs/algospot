from urllib import unquote

T=input()

for i in range(0,T):
    s=raw_input()
    print unquote(s)