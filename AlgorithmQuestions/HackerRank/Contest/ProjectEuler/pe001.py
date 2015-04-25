#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

def get_sum(n, m):
    t = n / m
    return (m + t * m) * t / 2

test = int(input())
for cas in range(test):
    n = int(input())
    n -= 1
    print get_sum(n, 3) + get_sum(n, 5) - get_sum(n, 15)
