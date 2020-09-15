/*
 * 题目链接：https://www.acwing.com/problem/content/97/
 * 题意：给5*5个灯，初始状态亮着或者关闭，每次可以更改一个灯及其上下左右的灯的状态，问最少需要基本，可以打开所有的灯
 * 题解：枚举第一排灯的操作，共有1<<5，那么第一排操作确定后，仍然灭的灯，只能去操作第二排相应位置的灯，同理所有的操作都是确定，最终判断是否是全亮就ok
 */

#include <bits/stdc++.h>
using namespace std;

int state[5][5], ori_state[5][5];
int step = 0, ans = 100;
int fx[] = {1, 0, -1, 0, 0};
int fy[] = {0, 1, 0, -1, 0};

void change_state(int x, int y) {
	for (int i = 0; i < 5; ++i) {
		int nx = x + fx[i];
		int ny = y + fy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			state[nx][ny] = 1 - state[nx][ny];
		}
	}
}

bool check() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (state[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void copy() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            state[i][j] = ori_state[i][j];
        }
    }
}

void print() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			printf("%d ", state[i][j]);
		}
		puts("");
	}
}

void calc() {
    for (int mask = 0; mask < 1 << 5; ++mask) {
        copy();
        step = 0;
        for (int i = 0; i < 5; ++i) {
            if ((mask >> i) & 1) {
                change_state(0, i);
                step += 1;
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (state[i][j] == 0) {
                    change_state(i + 1, j);
                    step += 1;
                }
            }
        }
        //  print();
        if (check()) {
            cout << "FUCK " << step << endl;
            ans = min(ans, step);
        }
    }
}


int main() {
	int n;
	string s;
	scanf("%d", &n);
	for (int t = 0; t < n; ++t) {
		step = 0, ans = 100;
		for (int i = 0; i < 5; ++i) {
			cin >> s;
			for (int j = 0; j < 5; ++j) {
				ori_state[i][j] = s[j] - '0';
				// printf("%d\n", state[i][j]);
			}
		}
		calc();
		if (ans > 6) {
			puts("-1");
		} else {
			printf("%d\n", ans);
		}
	}
}
