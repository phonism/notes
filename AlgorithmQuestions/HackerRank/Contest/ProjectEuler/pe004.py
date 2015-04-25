#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

def is_palindrome(n):
    return str(n)[::-1] == str(n)

all_pal = []
for i in range(100, 1000):
    for j in range(100, 1000):
        if i*j > 1000000:
            break
        if is_palindrome(i*j):
             all_pal.append(i*j)

all_pal = sorted(all_pal)

test = int(input())
for cas in range(test):
    n = int(input())
    res = 0
    for pal in all_pal:
        if pal < n:
            res = max(res, pal)
        else:
            break
    print res
