#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

from math import sqrt

def is_prime(n):
    for i in range(2, int(sqrt(n))+1):
        if n % i == 0:
            return False
    return True

test = int(input())
for cas in range(test):
    n = int(input())
    ans = 0
    for i in range(1, int(sqrt(n))+1):
        if n % i == 0:
            if is_prime(i):
                ans = max(i, ans)
            if is_prime(n/i):
                ans = max(n/i, ans)
    print ans        
