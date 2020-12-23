# LuckyQueen 学习笔记

+ [CF1463E. Plan of Lectures](https://codeforces.com/contest/1463/problem/E)
	+ 题意：要求构造一个1~n的排列，满足：1. p[i]出现在i之前。2. k个特殊pair(x,y)，在最终的排列中是紧挨着的。
	+ 题解：对于特殊pair，先进行缩点，缩点要记录每个点内的序，用于判断点内是否有环或者和原有的序有冲突。然后进行拓扑排序，如果不是拓扑序，代表不OK，如果是拓扑序就输出拓扑序即可。
	+ 标签：拓扑序，P4，L6