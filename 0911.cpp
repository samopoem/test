#define _CRT_SECURE_NO_WARNINGS

// 샘플
#if 0
#include <stdio.h>
int sol;
int main()
{
	printf("%d", sol);
}
#endif

// 0911 기출 문제
#if 1
#define _NO_CRT_SECURE_WARNINS

#include  <stdio.h>
int N;
int a[7 + 10][7 + 10];
int so[7 + 10][7 + 10];
int ac[7 + 10][7 + 10];
int ar[7 + 10][7 + 10];
int sol;


int temp[7 + 10][7 + 10];
int lo[7 * 2 + 10];
int lo2[7 * 2 + 10];


int Check()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] != so[i][j]) return 0;
		}
	}
	return 1;
}
void Save()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = a[i][j];
		}
	}
}
void Change(int n)
{
	if (N / 4 == 0)
	{
		for (int i = 0; i < N; i++)
		{
			a[i][n] = ar[i][n];
		}
	}
	else {
		for (int j = 0; j < N; j++)
		{
			a[n][j] = ac[n][N - j];
		}
	}
}
void Restore()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = temp[i][j];
		}
	}
}
void DFS(int n, int m)
{
	if (Check() == 1) {
		sol = n;
		return;
	}

	if (n >= 4) {
		return;

	}
	
	Save();
	for (int i = 0; i < N; i++)
	{
		Change(i);
		
		DFS(n + 1, i);
		Restore();
	}
}




int main()
{
	int k = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &a[i][j]);
			lo[k] = a[i][j];
			lo2[k] = a[i][j];
			ac[i][N - j - 1] = a[i][j];
			ar[N - i - 1][j] = a[i][j];
			k++;
		}
	}



	for (int i = 0; i < N*N - 1; i++)
	{
		for (int j = i; j < N*N; j++)
		{
			if (lo2[i] > lo2[j]) {
				int t = lo2[i];
				lo2[i] = lo2[j];
				lo2[j] = t;
			}
		}
	}

	k = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			so[i][j] = lo2[k];
			k++;
		}
	}

	DFS(0, 0);

	printf("%d", sol);
}



#endif

// 기업투자(BASIC)
#if 0
#include <stdio.h>
int sol_arr[20];
int invest_arr[20];
int M, N;
int company[20][1 + 300];
int sol;

void Invest(int n, int money, int benefit)
{
	int i;
	if (n >= N)
	{
		if (sol<benefit)
		{
			sol = benefit;
			for (i = 0; i<N; i++)
			{
				sol_arr[i] = invest_arr[i];
			}
		}
		return;
	}
	for (i = 0; i <= money; i++)
	{
		invest_arr[n] = i;
		Invest(n + 1, money - i, benefit + company[n][i]);
		invest_arr[n] = 0;
	}
}
void Input_Data(void)
{
	int i, j, m;
	scanf("%d %d", &M, &N);
	for (i = 0; i<M; i++)
	{
		scanf("%d", &m);
		for (j = 0; j<N; j++)
		{
			scanf("%d", &company[j][m]);
		}
	}
}

int main(void)
{
	int i;
	Input_Data();
	Invest(0, M, 0);
	printf("%d\n", sol);
	for (i = 0; i<N; i++)
	{
		printf("%d ", sol_arr[i]);
	}
	return 0;
}
#endif
// L: [SOL]별 그리기 6
#if 0
#include <stdio.h>
int N;
void print_star(int a)
{
	if (a == 0)
	{
	printf("\n");

		return;

	  }

	printf("*");

	print_star(a - 1);

}



void print_line(int a)

{

	print_star(a);

	if (N == a)return;

	print_line(a + 1);

	print_star(a);

}



int main(void)

{



	scanf("%d", &N);





	print_line(1);;



	return 0;

}
#endif

// 샘플
#if 0
#define ABS(x) ((x)<0?-(x):(x))
#define MAX(x,y) ((x)>(y)?(x):(y))
#include <stdio.h>
int sol;
int main()
{
	printf("%d\n", ABS(-5+3));
	printf("%d\n", MAX(-5, 3));
}
#endif
// U: [SOL]저글링 방사능 오염
#if 0
#include <stdio.h>

typedef struct {
	int y, x, d;
}Q_T;
Q_T Q[100 * 100 + 10];

int Rp, Wp, X, Y, sx, sy, ex, ey;

int a[100 + 10][100 + 10];
int chk[100 + 10][100 + 10];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int sol;
int BFS(int sy, int sx) {
	int ty, tx, td; // 방향 변수
	int k, yy, xx; // 다음 위치
	Q[Wp].y = sy; Q[Wp].x = sx; Q[Wp++].d = 3; chk[sy][sx] = 1; // 초기 값 입력 및 marking
	a[sy][sx] == 0;
	
	while (Rp != Wp) {
		ty = Q[Rp].y, tx = Q[Rp].x, td = Q[Rp++].d; // 데이터를 꺼낸다.
		//if (ty == ey && tx == ex) return td; // 목적지와 위치가 같으면 길이를 리턴
		for (k = 0; k<4; k++) { // 네방향으로 서치
			yy = ty + dy[k], xx = tx + dx[k]; // 다음 방향 계산
			if (yy<1 || yy>Y || xx<1 || xx>X) continue; // 영역 밖이면 continue;
			if (chk[yy][xx] || a[yy][xx] != 1) continue; // 갔던 길이거나, 못가는 길이면 continue;
			Q[Wp].y = yy, Q[Wp].x = xx, Q[Wp++].d = td + 1; chk[yy][xx] = 1; // 데이터를 입력 하고, 길이를 증가, 그 위치는 marking 한다.
			a[yy][xx] = 0;
		}
	}
	
	return td;
}
int main()
{
	int y, x, t;
	//scanf("%d %d", &sx, &sy);
	scanf("%d %d", &X, &Y);
	for (y = 1; y <= Y; y++)
	{
		for (x = 1; x <= X; x++)
		{
			scanf("%1d", &a[y][x]);
		}
	}
	scanf("%d %d", &sx, &sy);


	
	t = BFS(sy,sx);
	sol = t;
	
	printf("%d", sol);
	return 0;
}
#endif
// N: [TST]미로 탈출 로봇
#if 0
#include <stdio.h>

typedef struct {
	int y, x, d;
}Q_T;
Q_T Q[100 * 100 + 10];

int Rp, Wp, X, Y, sx, sy, ex, ey;

int a[100 + 10][100 + 10];
int chk[100 + 10][100 + 10];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


int BFS(void) {
	int ty, tx, td; // 방향 변수
	int k, yy, xx; // 다음 위치
	Q[Wp].y = sy; Q[Wp].x = sx; Q[Wp++].d = 0; chk[sy][sx] = 1; // 초기 값 입력 및 marking
	while (Rp != Wp) {
		ty = Q[Rp].y, tx = Q[Rp].x, td = Q[Rp++].d; // 데이터를 꺼낸다.
		if (ty == ey && tx == ex) return td; // 목적지와 위치가 같으면 길이를 리턴
		for (k = 0; k<4; k++) { // 네방향으로 서치
			yy = ty + dy[k], xx = tx + dx[k]; // 다음 방향 계산
			if (yy<1 || yy>Y || xx<1 || xx>X) continue; // 영역 밖이면 continue;
			if (chk[yy][xx] || a[yy][xx] != 0)continue; // 갔던 길이거나, 못가는 길이면 continue;
			Q[Wp].y = yy, Q[Wp].x = xx, Q[Wp++].d = td + 1; chk[yy][xx] = 1; // 데이터를 입력 하고, 길이를 증가, 그 위치는 marking 한다.
		}
	}
	return -1;
}
int main()
{
	int y, x, t;
	scanf("%d %d", &X, &Y);
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	for (y = 1; y <= Y; y++)
	{
		for (x = 1; x <= X; x++)
		{
			scanf("%1d", &a[y][x]);
		}
	}
	t = BFS();
	printf("%d", t);
	return 0;
}
#endif

// M: [TST]최소 비용으로 포장 다시 하기
#if 0
#include <stdio.h>
int N, sol;
int a[5000 + 10];
int main(void)
{
	int i, j, k, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (k = 1; k <= N - 1; k++) {
		for (i = k; i < k + 2; i++) {
			for (j = i + 1; j <= N; j++) {
				if (a[i]>a[j]) {
					t = a[i], a[i] = a[j], a[j] = t;
				}
			}
		}
		a[k + 1] = a[k] + a[k + 1];
		sol += a[k + 1];
	}
	printf("%d", sol);
	return 0;
}

//output
//13

//input
//3
//2 2 5
#endif

// L: [TST]같은 모양 찾기 simple
#if 0
#include <stdio.h>
int M, P;
int a[100 + 10][100 + 10], b[100 + 10][100 + 10];
int sol;
int Check(int si, int sj)
{
	int i, j;
	for (i = 0; i < P; i++) {
		for (j = 0; j < P; j++) {
			if (b[i][j] != a[si + i][sj + j]) return 0;
		}
	}
	return 1;
}
int main()
{
	int i, j;
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	scanf("%d", &P);
	for (i = 0; i < P; i++) {
		for (j = 0; j < P; j++) {
			scanf("%1d", &b[i][j]);
		}
	}
	for (i = 0; i < M - P + 1; i++) {
		for (j = 0; j < M - P + 1; j++) {
			if (Check(i, j)) sol++;
		}
	}
	printf("%d", sol);
	return 0;
}
//output
//1

//input
//10
//0000000001
//1110000000
//0000001000
//0000101000
//1111111111
//0000101000
//0000001000
//0000000000
//1110000000
//0000000001
//3
//100
//111
//100


#endif
// K: [TST]빙고
#if 0
#include <stdio.h>
int a[5 + 10][5 + 10];
int c[5 + 10][5 + 10];
int d;
int sol;
int chk1[5 + 10];
int chk2[5 + 10];
int chk3, chk4;
int cnt;
int Bingo(int d)
{
	int i, j;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (a[i][j] != d) continue;

			if (++chk1[i] == 5) cnt++;
			if (++chk2[j] == 5) cnt++;
			if (i + j == 4) {
				if (++chk3 == 5) cnt++;
			}
			if (i == j) {
				if (++chk4 == 5) cnt++;
			}
			if (cnt >= 3) return 1;
			return 0;
		}
	}
	return 0;
}
int main()
{
	int i, j, d;
	for ( i = 0; i < 5; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int num = 1;
	for (int i = 0; i < 25; i++)
	{
		scanf("%d", &d);
		if (Bingo(d)) break;
		num++;
	}


	printf("%d", num);
}


#endif


// R: [TST]오름차순 정렬 (퀵정렬)
#if 0
#include <stdio.h>
int N;
int a[30000 + 10];

void Quick(int s, int e)
{
	int T = s, P = e;
	int t;

	if (s >= e) return;

	for (int L = s; L < P; L++)
	{
		if (a[L] < a[P])
		{
			t = a[L], a[L] = a[T], a[T] = t;
			T++;
		}
	}
	t = a[P], a[P] = a[T], a[T] = t;
	Quick(s, T - 1);
	Quick(T + 1, e);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	Quick(0, N - 1);

	for (int i = 0; i < N; i++)
	{
		printf("%d", a[i]);
	}

	return 0;
}



#endif


#if 0
#include <stdio.h>
int N,M;
int sym;
int reverse(int num)
{
	int rnum=0;
	while (num > 0)
	{
		rnum *= 10;
		rnum += num % 10;
		num /= 10;
	}
	return rnum;
}

int main()
{
	scanf("%d", &N);

	int i;
	int new_num;

	for (i = 0; i < N; i++)
	{
		scanf("%d", &M);

		new_num = M + reverse(M);
		if (new_num == reverse(new_num)) sym = 1;
		else sym = 0;

		if (sym == 1) printf("YES\n");
		else printf("NO\n");
	}
}

#endif

#if 0
#include <stdio.h>
#define MAX 5
int func(int arr[])
{
	for (int i = 0; i < MAX - 1 ; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return 0;
}

int main()
{
	int arr[5] = { 1, 3, 3, 2, 5 };
	func(arr);
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	int n = 3;
	for (int i = 0; i < (1 << 4); i++)
	{
		for (int j = 3; j > -1; j--)
		{
			int b = (i & (1 << j))>0 ? 1 : 0;
			printf("%d", b);
		}
		printf("\n");
	}

	return 0;
} 
#endif


