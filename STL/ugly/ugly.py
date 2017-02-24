#!/usr/bin/python3
from math import *
f=[2,3,5]
a=int(input())
while a!=0:
    if a==1:
        print(1)
        a=int(input())
        continue
    count=1
    j=2
    while count<a:
        t=j
        for i in f:
            while(t%i==0):
                t=t/i
        if t==1:
            count+=1
        j+=1
    print(j-1)
    a=int(input())
