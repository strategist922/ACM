#!/usr/bin/python3
import re
# f='abcdefghigklmnopqist'
l=[]
while True:
    try:
        a=input()
        s=a.split()
        l.extend(list(s))
    except:
        break
for j in range(len(l)):
    l[j]=l[j].lower()
    a=re.split(r'[^a-z]+',l[j])
    for m in a:
        if m!='':
            l[j]=m
            break
l=list(set(l))
l.sort()
print()
for a in l:
    print(a)
