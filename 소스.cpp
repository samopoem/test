#define _NO_CRT_SECURE_WARNINS


// 기출문제
#include  <stdio.h>
int N;
int a[7 + 10][7 + 10];
int so[7 + 10][7 + 10];
int ac[7 + 10][7 + 10];
int ar[7 + 10][7 + 10];
int sol;

int lo[7 * 2 + 10];
int lo2[7 * 2 + 10];

void DFS(int n, int m)
{
	if (n >= N) return;
	if (n == 3) return;
	
	Save();
	for (int i = 0; i < N; i++)
	{
		Change(i);
		DFS(n + 1, i);
		Restore();
	}
}

void Save()
{

}
void Change(int i)
{

}
void Restore()
{

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
	for (int i = 0; i < N ; i++)
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





//U: [TST]저글링 방사능 오염
#if 0
#include <stdio.h>
int N;
int a[100 + 10][100 + 10];
int b[100 + 10][100 + 10];
int c[100 + 10][100 + 10];
int bchk[100 + 10][100 + 10];
int cchk[100 + 10][100 + 10];
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1};

void BFS1(int i, int j)
{
	int ii, jj;
	if (bchk[i][j]) return;
	bchk[i][j] = 1; 

	for (int k = 0; k < 4; k++)
	{
		ii = i + di[k], jj = j + dj[k];
		if (ii < 0||ii>N||jj<0||jj>N ||
	}
	

}



int main(void)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%c", &a[i][j]);
			if (a[i][j] == 'R')
			{
				b[i][j] = 0;
				c[i][j] = 0;
			}
			else if (a[i][j] == 'G')
			{
				b[i][j] = 1;
				c[i][j] = 0;
			}
			else if (a[i][j] == 'B'){
				b[i][j] = 2;
				c[i][j] = 1;
			}
		}
	}

	int man = 0;
	int pig = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N ; j++)
		{
			BFS1(i, j);
			man++;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			BFS2(i, j);
			pig++;
		}
	}
	printf("%d %d", man, pig);

	return 0;
}

#endif


#if 0 
#include <stdio.h>
int X, Y;
int sx, sy;
int a[100 + 10][100 + 10];
int chk[100 + 10][100 + 10];

typedef struct {
	int x, y, d;
}Q_T;
Q_T Q[100 * 100 + 10];

int Wp, Rp;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int znum = 0;

int BFS(int x, int y)
{
	int tx, ty, td;
	int k, xx, yy;
	int num =0;

	Q[Wp].x = sx, Q[Wp].y = sy, Q[Wp++].d = 0; chk[sy][sx] = 1;
	while (Rp != Wp)
	{
		tx = Q[Rp].x, ty = Q[Rp].y, td = Q[Rp++].d;
		//if (x == ex && y == ey) return;
		
		for (int k = 0; k < 4; k++)
		{
			xx = tx + dx[k], yy = ty + dy[k];
			if (xx<1 || xx>X || yy<1 || yy>Y) continue;
			if(chk[yy][xx] || a[yy][xx] != 1) continue;
			Q[Wp].x = xx, Q[Wp].y = yy, Q[Wp++].d = td + 1; chk[yy][xx] = 1;
		}
	}
	return td;
}

int main(void)
{
	scanf("%d %d", &X, &Y);
	for (int i = 1; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	scanf("%d %d", &sx,&sy);

	int t;
	t = BFS(sx, sy);

	int sum = 0;
	int sum2 = 0;
	for (int i = 1; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{
			if (chk[i][j]) sum++;
			if (a[i][j]) sum2++;
		}
	}

	printf("%d\n", t+3);
	printf("%d\n", sum2-sum);

	return 0;
}
#endif

#if 0
#include <stdio.h>
int N;
int a[100 + 10] = { 0 };
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	int sum = 0;
	int temp = 0;

	sum = a[0] + a[1];
	for (int i = 2; i < N; i++)
	{
		sum = sum * 2 + a[i];
	}

	printf("%d", sum);
	return 0;
}


#endif

#if 0
#include <stdio.h>

int M,P;
int a[100 + 10][100 + 10];
int p[100 + 10][100 + 10];

int check(int i, int j)
{
	for (int k = 0; k < P; k++)
	{
		for (int l = 0; l < P; l++)
		{
			if (a[i + k][j + l] != p[k][l])
			{
				return 0;
			}
		}
	}

	return 1;
}

int main()
{
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	scanf("%d", &P);
	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < P; j++)
		{
			scanf("%1d", &p[i][j]);
		}
	}


	int ret = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i > (M - P)) continue;
			if (j > (M - P)) continue;
			ret += check(i, j);


		}
	}
	printf("%d", ret);


	return 0;
}


#endif


#if 0
#include <stdio.h>
int f[25];
int c[5][5] = { 0 };
int a[5][5];
int sol,bg;

int check(int b)
{
	int num = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (a[i][j] == b)
			{
				c[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		int bingo = 1;
		for (int j = 0; j < 5; j++)
		{
			bingo *= c[i][j];
		}
		if (bingo == 1) num++;
	}

	for (int j = 0; j < 5; j++)
	{
		int bingo = 1;
		for (int i = 0; i < 5; i++)
		{
			bingo *= c[i][j];
		}
		if (bingo == 1) num++;
	}

	int bingo = 1;
	for (int i = 0; i < 5; i++)
	{
		bingo *= c[i][i];
		
	}
	if (bingo == 1) num++;

	bingo = 1;
	for (int i = 0; i < 5; i++)
	{	
		bingo *= c[i][4-i];
	}
	if (bingo == 1) num++;
	return num;
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int k = 0; k < 25; k++)
	{
		scanf("%d", &f[k]);
	}
	
	for (int k = 0; k < 25; k++)
	{
		bg = check(f[k]);
		if (bg >= 3) break;
		sol++;
	}

	printf("%d", sol+1);




	return 0;
}

#endif


#if 0
#include <stdio.h>
int N,sol;
int a[100+10];
int b[100 + 10];
int Conv(int a)
{
	//123 / 10 = 12
    //123 % 10 = 3
	//
    //12/10 = 1
    //12%10 = 2
	//
    //1/10 = 0
	//1%10 = 1
			
	    int n = a;
		int c = 0;
		int d = 0;

	    while (n > 0)
		{
			d = n % 10;
			n = n / 10;
			c = c*10 + d;
		}


		return c;
}

//int check(int a, int b)
//{
//	int c = a + b;
//	int cnt = 0;
//	int temp[1000000 + 100] = { 0 };
//	int e = 0;
//	int i = 0;
//	while (c < 0)
//	{
//		c = c / 10;
//		e = c % 10;
//		temp[i++] = e;
//		cnt++;
//	}
//
//	if (cnt % 2 == 1) { //짝수
//		for (int i = 0; i < cnt/2 ; i++)
//		{
//			for (int i = N - 1; i < cnt/2; i++)
//			{
//				if (temp[i] != temp[N - 1]) return 0;
//			}
//		}
//	}
//	else { //홀수
//		for (int i = 0; i < cnt / 2; i++)
//		{
//			for (int i = N - 1; i <= cnt / 2; i++)
//			{
//				if (temp[i] != temp[N - 1]) return 0;
//			}
//		}
//	}
//
//
//	return 1;
//}

int check(int a, int b)
{
	int c = a + b;
	
	return 1;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	int yesNo = 0;
	for (int i = 0; i < N; i++)
	{
		b[i] = Conv(a[i]);
		int t1 = a[i];
		int t2 = b[i];
		//yesNo = check(t1, t2);
		yesNo = check(t1, t2);
		if(yesNo == 0) printf("NO");
		else printf("YES");
	}


	


	
	return 0;
}
#endif


#if 0
#include <stdio.h>
// 자바에서는 포인터가 없기 때문에 아래와 같이, 인덱스 i와 j를 통해 바꿔줌.
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void printA(int arr[], int k) {

	for (int i = 0; i < k; i++) {
		if (i == k - 1)
			printf("%d\n", arr[i]);
		else
			printf("%d,", arr[i]);
	}
}
void perm(int arr[], int depth, int n, int k) {

	if (depth == k) { // 한번 depth 가 k로 도달하면 사이클이 돌았음. 출력함.
		printA(arr, k);
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(arr, i, depth);
		printf("before");  printA(arr, k);
		perm(arr, depth + 1, n, k);
		swap(arr, i, depth);
		printf("after");  printA(arr, k);
	}

}

void main() {
		int arr[] = { 1, 2, 3, 4 };
		//perm(arr, 0, 4, 4);
		int a = 123;
		int aa[3] = { 0 };
		for (char i = 0; i < sizeof(a); i++)
		{
			aa[i] = (char)i;

		}



	}

#endif
