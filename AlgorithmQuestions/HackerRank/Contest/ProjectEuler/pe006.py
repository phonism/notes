#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

sum_of_n = []
square_of_n = []
sum_of_square_n = []
sum_of_n.append(0)
square_of_n.append(0)
sum_of_square_n.append(0)

for i in range(1, 10001):
    sum_of_n.append(sum_of_n[i-1] + i)
    square_of_n.append(i * i)
    sum_of_square_n.append(sum_of_square_n[i-1] + i * i)

test = int(input())
for cas in range(test):
    n = int(input())
    print sum_of_n[n] * sum_of_n[n] - sum_of_square_n[n]
