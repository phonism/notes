#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

from math import sqrt

all_triplet = [-1] * 3030

for i in range(1, 3001):
    for j in range(1, 3001):
        k = i*i + j*j
        l = int(sqrt(k))
        if l*l == k and i+j+l <= 3000:
            all_triplet[i+j+l] = max(all_triplet[i+j+l], i*j*l)

test = int(raw_input())
for cas in range(test):
    n = int(raw_input())
    print all_triplet[n]
