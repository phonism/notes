#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

prime = []
check = [False] * 100000
prime.append(0)

for i in range(2, 100000):
    if (check[i] == False):
        prime.append(i)
    j = i
    while j < 100000:
        check[j] = True
        j += i

test = int(input())
for cas in range(test):
    n = int(input())
    print prime[n]
