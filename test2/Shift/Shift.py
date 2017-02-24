#!/usr/bin/python3

count={}
str=input()
count[str]=1
l=(len(str))
for i in range(l):
    str=str[-1]+str[0:l-1]
    count[str]=(count.get(str,0))
print(len(count))
