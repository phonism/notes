#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

test = int(input())
for cas in range(test):
    n, k = map(int, raw_input().split(' '))
    s = raw_input()
    a = []
    for c in s:
        a.append(int(c))
    
    res = 0
    for i in range(0, len(a)-k):
        pro = 1
        for j in range(i, i+k):
            pro *= a[j]
        res = max(res, pro)
    print res

