#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

f = []
f.append(1)
f.append(1)

for i in range(2, 1000):
    f.append(f[i-1] + f[i-2])
    if f[i] > 4*10**16:
        break

test = int(input())
for cas in range(test):
    n = int(input())
    print sum(f[i] for i in range(1, len(f)) if f[i] <= n and f[i] % 2 == 0)
