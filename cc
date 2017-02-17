
#if 0
#include <stdio.h>
int T;
int N;
int map[12][12];
int chk[12][12];
int sol;

int check()
{


	return 1;
}


void proccess()
{


}



void draw(int i, int j, int k)
{
	if (k == 0)
	{

	}
	else if (k == 1)
	{

	}
	else if (k == 2)
	{

	}
	else if (k == 3)
	{

	}
}

void back_draw(int i, int j, int k)
{


}



void DFS(int x, int y, int k)
{
	if (k == N) {
		if (check()) {
			proccess();
		}
	}

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			if (map[i][j] == 0) continue;
			for (int k = 0; k < 4; k++)
			{
				draw(i,j,k);
				DFS(i, j, k + 1);
				back_draw(i,j,k);
			}
		}
	}
}



int main()
{
	freopen("프로세서연결하기_input.txt", "r", stdin);
	scanf("%d", &T);

	for (int ts = 1; ts <= T; ts++)
	{
		scanf("%d", &N);

		DFS(0,0,0);

		printf("#%d %d\n", ts, sol);
	}


	return 0;
}

#endif

#if 1

#include <stdio.h>
int T;
int N;
int map[12][12];
int temp[12][12];
int chk[12][12];
int sol;

int arr[20];
int t[20];
int num;
//int cnt;
int min;


typedef struct {
	int i, j;
}Q_T;

Q_T Q[12];

int max;

void swap(int i, int j)
{
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void remake(int q)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = map[i][j];
		}
	}
}

void init()
{
	max = 0;
	min = 0x7fffffff;
	for (int i = 0; i < N; i++)
	{
		arr[i] = 0;
	}
}

void perm1(int n, int r, int q)
{
	if (r == 0) {

		//for check
		//for (int i = 0; i < q; i++)
		//{
		//	printf("%d ", t[i]);
		//}
		//printf("\n");
		int flag = 0;

		for (int k = 0; k < q; k++)
		{
			int si = Q[k].i;
			int sj = Q[k].j;
			flag = 0;

			//int sum = 0;
			//for (int i = 0; i < q; i++)
			//{
			//	sum += t[i];
			//}

			//if (sum == 3 && t[6] == 3)
			//{
			//	int a = 0;
			//}

			if (si == 0 || si == (N - 1) || sj == 0 || sj == (N - 1)) continue;

			if (t[k] == 0) // 왼쪽
			{
				for (int j = sj - 1; j >= 0; j--)
				{
					if (temp[si][j] != 0) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) break;
				for (int j = sj - 1; j >= 0; j--)
				{
					temp[si][j] += 2;
				}

			}
			else if (t[k] == 1) // 왼쪽
			{
				for (int j = sj + 1; j < N; j++)
				{
					if (temp[si][j] != 0){
						flag = 1;
						break;
					}
				}
				if (flag == 1) break;
				for (int j = sj + 1; j < N; j++)
				{
					temp[si][j] += 2;
				}
			}
			else if (t[k] == 2) // 위로
			{
				for (int i = si - 1; i >= 0; i--)
				{
					if (temp[i][sj] != 0){
						flag = 1;
						break;
					};
				}
				if (flag == 1) break;
				for (int i = si - 1; i >= 0; i--)
				{
					temp[i][sj] += 2;
				}
			}
			else if (t[k] == 3) // 아래로
			{
				for (int i = si + 1; i < N; i++)
				{
					if (temp[i][sj] != 0) {
						flag = 1;
						break;
					};
				}
				if (flag == 1) break;
				for (int i = si + 1; i < N; i++)
				{
					temp[i][sj] += 2;
				}
			}
			if (flag == 1) break;
		}

		if (flag == 1) { remake(q);  return; };

		int cnt = 0;
		int zcnt = 0;
		flag = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (temp[i][j] == 2) cnt++;
				if (temp[i][j] == 1) zcnt++;
			}
		}

		if (max < zcnt)
		{
			if (min > cnt)
			{
				min = cnt;
			}
			max = zcnt;
			
		}

		if (zcnt > max) {
			max = zcnt;
			min = cnt;
		}
		// 현재까지 연결된 Core의 수가 최댓값과 같으면서
		// 전선의 수는 최솟값보다 작을때, minLine 값을 갱신
		else if (zcnt == max && min > cnt)
			min = cnt;
		


		remake(q);
		//min = 0x7fffffff;


	}
	else
	{
		for (int i = n - 1; i >= 0; i--)
		{
			swap(n - 1, i);
			t[r - 1] = arr[n - 1];
			perm1(n, r - 1, q);
			swap(n - 1, i);
		}
	}
}


int main()
{
	freopen("프로세서연결하기_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int ts = 1; ts <= T; ts++)
	{
		scanf("%d", &N);
		init();

		for (int i = 0; i < N; i++)	arr[i] = i;
		


		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
				temp[i][j] = map[i][j];
				if (map[i][j] == 1)
				{
					Q[num].i = i;
					Q[num].j = j;
					num++;
				}
			}
		}


		perm1(4, N, N);

		printf("#%d %d\n", ts, min);
	}


	return 0;
}

#endif

#if 0
/*
* @file [MH1636] 프로세서 연결하기
* @brief 모범풀이법
* Copyright 2016 by Samsung Electronics, Inc.
*/


#include <stdio.h>


int N;
int map[12][12];
int core[12][2], cNum;
int maxCore, minLine;


void INPUT()
{



	scanf("%d", &N);
	int temp;
	cNum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp);
			// Core가 존재하는 셀의 경우
			if (temp) {
				core[cNum][0] = i; // 행 저장(i)
				core[cNum][1] = j; // 열 저장(j)
				// Core의 수 증가
				cNum++;
			}
			// map에 저장(input 으로 들어온 N*N 행렬)
			map[i][j] = temp;
		}
}


// Core의 번호, 현재까지 연결된 Core의 수, 현재까지 사용된 전선의 수를 받는 함수 sub
void sub(int n, int coreNum, int line)
{
	// return 조건 : Core를 모두 체크했을 경우
	if (n == cNum) {
		// 현재까지 연결된 Core의 수가 최댓값일 때, (maxLine)
		// 현재까지 사용된 전선의 수는 최솟값을 갱신 (minLine)
		if (coreNum > maxCore) {
			maxCore = coreNum;
			minLine = line;
		}
		// 현재까지 연결된 Core의 수가 최댓값과 같으면서
		// 전선의 수는 최솟값보다 작을때, minLine 값을 갱신
		else if (coreNum == maxCore && minLine > line)
			minLine = line;
		return;
	}


	// n번째 Core의 y, x
	int y = core[n][0];
	int x = core[n][1];


	// canLine : 해당 Core에 전선을 연결할 수 있는지에 대한 flag
	int canLine = 1;
	// y 값의 위쪽에 전선을 연결했을 때
	for (int i = y - 1; i >= 0; i--)
		if (map[i][x]) {
			// 연결 불가능(해당 위치에 이미 다른 core나 전선이 존재)하므로 break
			canLine = 0;
			break;
		}

	// 연결 가능할 경우
	if (canLine) {
		// 전선을 놓을 수 있는 위치에 해당하는 값들을 2로 갱신
		for (int i = y - 1; i >= 0; i--)
			map[i][x] = 2;
		// 다음 Core에 대해 진행
		// 연결된 Core수는 1개 증가, 연결된 전선 수는 y개 증가
		sub(n + 1, coreNum + 1, line + y);
		// 다른 방향에 대해서도 진행해줘야하므로 원상태로 복구
		for (int i = y - 1; i >= 0; i--)
			map[i][x] = 0;
	}


	// canLine : 해당 Core에 전선을 연결할 수 있는지에 대한 flag
	canLine = 1;
	// y 값의 아래쪽에 전선을 연결했을 때
	for (int i = y + 1; i < N; i++)
		if (map[i][x]) {
			// 연결 불가능(해당 위치에 이미 다른 core나 전선이 존재)하므로 break
			canLine = 0;
			break;
		}

	// 연결 가능할 경우
	if (canLine) {
		// 전선을 놓을 수 있는 위치에 해당하는 값들을 2로 갱신
		for (int i = y + 1; i < N; i++)
			map[i][x] = 2;
		// 다음 Core에 대해 진행
		// 연결된 Core수는 1개 증가, 연결된 전선 수는 N - y - 1개 증가
		sub(n + 1, coreNum + 1, line + N - y - 1);
		// 다른 방향에 대해서도 진행해줘야하므로 원상태로 복구
		for (int i = y + 1; i < N; i++)
			map[i][x] = 0;
	}


	// canLine : 해당 Core에 전선을 연결할 수 있는지에 대한 flag
	canLine = 1;
	// x 값의 왼쪽에 전선을 연결했을 때
	for (int i = x - 1; i >= 0; i--)
		if (map[y][i]) {
			// 연결 불가능(해당 위치에 이미 다른 core나 전선이 존재)하므로 break
			canLine = 0;
			break;
		}

	// 연결 가능할 경우
	if (canLine) {
		// 전선을 놓을 수 있는 위치에 해당하는 값들을 2로 갱신
		for (int i = x - 1; i >= 0; i--)
			map[y][i] = 2;
		// 다음 Core에 대해 진행
		// 연결된 Core수는 1개 증가, 연결된 전선 수는 x개 증가
		sub(n + 1, coreNum + 1, line + x);
		// 다른 방향에 대해서도 진행해줘야하므로 원상태로 복구
		for (int i = x - 1; i >= 0; i--)
			map[y][i] = 0;
	}


	// canLine : 해당 Core에 전선을 연결할 수 있는지에 대한 flag
	canLine = 1;
	// x 값의 오른쪽에 전선을 연결했을 때
	for (int i = x + 1; i < N; i++)
		if (map[y][i]) {
			// 연결 불가능(해당 위치에 이미 다른 core나 전선이 존재)하므로 break
			canLine = 0;
			break;
		}

	// 연결 가능할 경우
	if (canLine) {
		// 전선을 놓을 수 있는 위치에 해당하는 값들을 2로 갱신
		for (int i = x + 1; i < N; i++)
			map[y][i] = 2;
		// 다음 Core에 대해 진행
		// 연결된 Core수는 1개 증가, 연결된 전선 수는 N - x - 1개 증가
		sub(n + 1, coreNum + 1, line + N - x - 1);
		// 다른 방향에 대해서도 진행해줘야하므로 원상태로 복구
		for (int i = x + 1; i < N; i++)
			map[y][i] = 0;
	}


	// 해당 Core에 전선을 연결하지 않고 다음 Core로 넘어가기
	sub(n + 1, coreNum, line);
}


void SOLVE()
{
	maxCore = 0;
	minLine = 1000;
	// 0번 Core, 현재까지 0개의 Core연결, 0개의 전선 사용
	sub(0, 0, 0);
}


int main(void)
{

	freopen("프로세서연결하기_input.txt", "r", stdin);

	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		INPUT();
		SOLVE();
		printf("#%d %d\n", test_case, minLine);
	}

	return 0;
}


#endif
