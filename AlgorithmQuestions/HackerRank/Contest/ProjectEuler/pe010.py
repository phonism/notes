#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

check = [False] * 1001000
sum_of_prime = [0] * 1001000
check[0], check[1] = True, True

for i in range(2, 1001000):
    j = i + i
    while j < 1001000:
        check[j] = True
        j += i

for i in range(1, 1001000):
    sum_of_prime[i] = sum_of_prime[i-1]
    if check[i] == False:
        sum_of_prime[i] += i

test = int(raw_input())
for i in range(test):
    n = int(raw_input())
    print sum_of_prime[n]
