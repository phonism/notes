#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright (c) 2015 - Qi Lu <luqi.code@gmail.com>

grid = [[0] * 20 for i in range(20)]

for i in range(20):
    grid[i] = map(int, raw_input().split(' '))

res = 0

for i in range(17):
    for j in range(20):
        res = max(res, grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j])

for i in range(20):
    for j in range(17):
        res = max(res, grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3])

for i in range(17):
    for j in range(3, 20):
        res = max(res, grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3])

for i in range(17):
    for j in range(17):
        res = max(res, grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3])

print res
