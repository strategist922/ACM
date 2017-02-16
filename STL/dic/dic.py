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
    t=(re.split(r'\d+',l[j]))
    if t[0]=='':
        l[j]=t[1]
    else:
        l[j]=t[0]
    for a in l[j]:
        if re.match('[a-z]',a):
           pass
        else:
            l[j]=l[j].replace(a,'')
l=list(set(l))
l.sort()
print()
for a in l:
    print(a)
