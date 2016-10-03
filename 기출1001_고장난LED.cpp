#include <stdio.h>

int num1[3][10];
int num2[3][10];
int num3[6][10];

int chk1[3][10];
int chk2[3][10];
int chk3[6][10];

int led[10][7] = {
	{1,1,1,0,1,1,1}, // 0
	{0,0,1,0,0,1,1}, // 1
	{1,0,1,1,1,0,1}, // 2
	{1,0,1,1,0,1,1}, // 3
	{0,1,1,1,0,1,0}, // 4 
	{1,1,0,1,0,1,1}, // 5
	{1,1,0,1,1,1,1}, // 6
	{1,1,1,0,0,1,1}, // 7
	{1,1,1,1,1,1,1}, // 8
	{1,1,1,1,0,1,1}  // 9
};

int sol = 0xFFFFFF;

void init()
{

	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 7; i++)
		{
			num1[k][i] = 0;
			chk1[k][i] = 0;
		}
	}
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 7; i++)
		{
			num2[k][i] = 0;
			chk2[k][i] = 0;
		}
	}
	for (int k = 0; k < 6; k++)
	{
		for (int i = 0; i < 7; i++)
		{
			num3[k][i] = 0;
			chk3[k][i] = 0;
		}
	}
}

int Check(int tt)
{
	int aa[6] = { 0 };
	for (int i = 5; i > -1; i--)
	{
		aa[i] = tt % 10;
		tt = tt / 10;
	}

	for (int i = 0; i < 6; i++)
	{
		int temp = aa[i];
		if (chk3[i][temp] == 0) return 0;
	}
	return 1;
}

int main()
{
	// 입력
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 7; i++)
		{
			scanf("%d", &num1[k][i]);
		}
	}
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 7; i++)
		{
			scanf("%d", &num2[k][i]);
		}
	}
	for (int k = 0; k < 6; k++)
	{
		for (int i = 0; i < 7; i++)
		{
			scanf("%d", &num3[k][i]);
		}
	}

	// 체크배열
	int flag = 0;
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (led[i][j] == 0 && num1[k][j] == 1) {
					flag = 1; break;
				}
			}
			if (flag != 1) chk1[k][i] = 1;
			flag = 0;
		}
	}

	flag = 0;
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (led[i][j] == 0 && num2[k][j] == 1) {
					flag = 1; break;
				}
			}
			if (flag != 1) chk2[k][i] = 1;
			flag = 0;
		}
	}

	flag = 0;
	for (int k = 0; k < 6; k++)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (led[i][j] == 0 && num3[k][j] == 1) {
					flag = 1; break;
				}
			}
			if (flag != 1) chk3[k][i] = 1;
			flag = 0;
		}
	}

	// 숫자조합
	for (int n11 = 0; n11 < 9; n11++) {	if (chk1[0][n11] == 0) continue;
	for (int n12 = 0; n12 < 9; n12++) {	if (chk1[1][n12] == 0) continue;
	for (int n13 = 0; n13 < 9; n13++) { if (chk1[2][n13] == 0) continue;
	for (int n21 = 0; n21 < 9; n21++) {	if (chk2[0][n21] == 0) continue;
	for (int n22 = 0; n22 < 9; n22++) {	if (chk2[1][n22] == 0) continue;
	for (int n23 = 0; n23 < 9; n23++) {	if (chk2[2][n23] == 0) continue;

	int t1 = n11*100 +n12*10 + n13;
	int t2 = n21*100 +n22*10 + n23;
	int tt = t1*t2;

	// 가능한 조합인지 check
	if (Check(tt)) {
		if (tt < sol) sol = tt;
	}


	}
	}
	}
	}
	}
	}

	printf("%d", sol);
	
	sol = 0xFFFFF;

	init();
	return 0;
}