#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

def get_num_of_divisors(n):
    return sum(1 for i in range(n) if n%(i+1)==0)

test = int(raw_input())
for cas in range(test):
    n = int(raw_input())
    cur, idx = 1, 2
    while get_num_of_divisors(cur) <= n:
        cur += idx
        idx += 1
    print cur
