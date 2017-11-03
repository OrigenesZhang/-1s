#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;

int tmp0[3], tar0[3]; //  tmpy0, tmpz0;
int tmp1[3], tar1[3]; // 1, tmpy1, tmpz1;
int dir0, dir1;
int delta0, delta1;
bool st1 = true, st0 = true;

void getdir() {
	if (tmp0[0] != tar0[0]) dir0 = 0;
	else {
		if (tmp0[1] != tar0[1]) dir0 = 1;
		else {
			if (tmp0[2] != tar0[2]) dir0 = 2;
		}
	}
	delta0 = (tar0[dir0] - tmp0[dir0]) > 0 ? 1 : -1;

	if (tmp1[0] != tar1[0]) dir1 = 0;
	else {
		if (tmp1[1] != tar1[1]) dir1 = 1;
		else {
			if (tmp1[2] != tar1[2]) dir1 = 2;
		}
	}
	delta1 = (tar1[dir1] - tmp1[dir1]) > 0 ? 1 : -1;
}

bool safemove() {
	vector<int> t0(3);
	vector<int> t1(3);
	t0[0] = tmp0[0], t0[1] = tmp0[1], t0[2] = tmp0[2];
	t1[0] = tmp1[0], t1[1] = tmp1[1], t1[2] = tmp1[2];

	if (st0) t0[dir0] += delta0;
	if (st1) t1[dir1] += delta1;
	bool flag = true;
	if (t0[0]==t1[0] && t0[1]==t1[1] && t0[2]==t1[2]) flag = false;
	if (tmp0[0]==t1[0] && tmp0[1]==t1[1] && tmp0[2]==t1[2]) flag = false;
	if (t0[0]==tmp1[0] && t0[1]==tmp1[1] && t0[2]==tmp1[2]) flag = false;

	return flag;
}

void changedir0() {
	if (dir0 !=0 && dir1 !=0) dir0 = 0;
	if (dir0 !=1 && dir1 !=1) dir0 = 1;
	if (dir0 !=2 && dir1 !=2) dir0 = 2;
}
void changedir1() {
	if (dir0 !=0 && dir1 !=0) dir1 = 0;
	if (dir0 !=1 && dir1 !=1) dir1 = 1;
	if (dir0 !=2 && dir1 !=2) dir1 = 2;
}

void move() {
	if (st0) tmp0[dir0] += delta0;
	if (st1) tmp1[dir1] += delta1;
}
void move_step() {
	getdir();
	if (safemove()) {
		move();
	}
	else {
		if (st1 == false) changedir0();
		else changedir1();
		move();
	}
}

bool diest() {
	// puts("IN diest");
	if (tmp0[0] == tar0[0] && tmp0[1] == tar0[1] && tmp0[2] == tar0[2])
		st0 = false;
	if (tmp1[0] == tar1[0] && tmp1[1] == tar1[1] && tmp1[2] == tar1[2])
		st1 = false;
	if (st1 || st0) return true;
	return false;
}
void Print() {
	printf("(%d %d %d) (%d %d %d)\n",tmp0[0],tmp0[1],tmp0[2],tmp1[0],tmp1[1],tmp1[2]);
}

void move_rand() {
	dir0 = rand()%3;
	dir1 = rand()%3;
	delta0 = (rand()%2)*2-1;
	delta1 = (rand()%2)*2-1;
	// printf("dir0 %d delta0 %d\n",dir0, delta0);
	if (safemove()) {
		move();
		Print();
	}
}
int main() {
	cin >> tmp0[0] >> tmp0[1] >> tmp0[2];
	cin >> tar0[0] >> tar0[1] >> tar0[2];
	cin >> tmp1[0] >> tmp1[1] >> tmp1[2];
	cin >> tar1[0] >> tar1[1] >> tar1[2];
	Print();
	for (int i=1; i<=100; i++) {
		move_rand();
	}
	while (diest()) {
		move_step();
		Print();
	}
	return 0;
}

/*

0 0 0 2 2 2
1 1 2 0 0 0

-2 0 0 1 0 0
3 0 0 -1 0 0

0 0 0 1 0 0
1 0 0 0 0 0

*/
