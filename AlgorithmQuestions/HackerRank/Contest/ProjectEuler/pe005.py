#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

def gcd(a, b):
    return gcd(b, a%b) if b != 0 else a
        

test = int(input())
for cas in range(test):
    n = int(input())
    ans = 1
    for i in range(1, n+1):
        ans = ans * i / gcd(i, ans)
    print ans
