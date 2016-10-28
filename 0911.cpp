#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
// 최소비용으로 포장다시하기
#if 01
#include <stdio.h>
int N, sol;
int a[5000 + 10];
int main(void)
{
 int i, j, k, t;
 scanf("%d", &N);
 for (i = 1; i <= N; i++) scanf("%d", &a[i]);
 for (k = 1; k <= N - 1; k++){
  for (i = k; i < k + 2; i++){
   for (j = i + 1; j <= N; j++){
    if (a[i]>a[j]){
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
#endif
// 같은 모양 찾기 simple
#if 0
#include <stdio.h>
int M, P, sol;
int a[100 + 10][100 + 10], b[100 + 10][100 + 10];
int Check(int si, int sj){
 int i, j;
 for (i = 1; i <= P; i++){
  for (j = 1; j <= P; j++){
   if (b[i][j] != a[si+i-1][sj+j-1]) return 0;
  }
 }
 return 1;
}
int main(void)
{
 int i, j;
 scanf("%d", &M);
 for (i = 1; i <= M; i++){
  for (j = 1; j <= M; j++){
   scanf("%1d", &a[i][j]);
  }
 }
 scanf("%d", &P);
 for (i = 1; i <= P; i++){
  for (j = 1; j <= P; j++){
   scanf("%1d", &b[i][j]);
  }
 }
 for (i = 1; i <= M-P+1; i++){
  for (j = 1; j <= M-P+1; j++){
   if (Check(i, j)) sol++;
  }
 }
 printf("%d", sol);
 return 0;
}
#endif
// 빙고
#if 0
#include <stdio.h>
int a[5 + 10][5 + 10];
int chk1[5 + 10], chk2[5 + 10], chk3, chk4, cnt;
int Bingo(int d){
 int i, j;
 for (i = 1; i <= 5; i++){
  for (j = 1; j <= 5; j++){
   if (a[i][j] != d) continue;
   if (++chk1[i] == 5) cnt++;
   if (++chk2[j] == 5) cnt++;
   if (i + j == 6){
    if (++chk3 == 5) cnt++;
   }
   if (i == j){
    if (++chk4 == 5) cnt++;
   }
   if (cnt >= 3) return 1;
   return 0;
  }
 }
 return 0;
}
int main(void)
{
 int i, j, d;
 for (i = 1; i <= 5; i++){
  for (j = 1; j <= 5; j++){
   scanf("%d", &a[i][j]);
  }
 }
 for (i = 1; i <= 25; i++){
  scanf("%d", &d);
  if (Bingo(d)) break;
 }
 printf("%d", i);
 return 0;
}
#endif
// 건물세우기(BASIC)
#if 0
#include <stdio.h>
int N, sol=0x7fffffff;
int a[15 + 10][15 + 10];
int chk[15+10], sc[15+10], s[15+10];
void DFS(int n, int cost){
 int i;
 if (sol <= cost) return;
 if (n > N){
  if (sol > cost){
   sol = cost;
   for (i = 1; i <= N; i++) s[i] = sc[i];
  }
  return;
 }
 for (i = 1; i <= N; i++){
  if (chk[i]) continue;
  chk[i] = 1, sc[n] = i;
  DFS(n + 1, cost + a[n][i]);
  chk[i] = 0, sc[n] = 0;
 }
}
int main(void)
{
 int i, j;
 scanf("%d", &N);
 for (i = 1; i <= N; i++){
  for (j = 1; j <= N; j++){
   scanf("%d", &a[i][j]);
  }
 }
 DFS(1, 0);
 printf("%d\n", sol);
 for (i = 1; i <= N; i++) printf("%d ", s[i]);
 return 0;
}
#endif
// 농장탈출
#if 0
#include <stdio.h>
int N, sol;
int a[20 + 10];
int Check(int n, int m){
 while (n > 0 && m > 0){
  if (n % 10 + m % 10 > 9) return 0;
  n /= 10, m /= 10;
 }
 return 1;
}
void DFS(int n, int c, int sum){
 if (N - n + 1 + c <= sol) return;
 if (n > N){
  if (sol < c) sol = c;
  return;
 }
 DFS(n + 1, c, sum); // 소를 안태우는 경우
 if (Check(sum, a[n])) DFS(n + 1, c + 1, sum + a[n]); // Y
}
int main(void)
{
 int i;
 scanf("%d", &N);
 for (i = 1; i <= N; i++) scanf("%d", &a[i]);
 DFS(1, 0, 0);
 printf("%d", sol);
 return 0;
}
#endif

// 주사위 던지기2
#if 0
#include <stdio.h>
int N, M;
int s[7 + 10];
void DFS(int n, int sum){
 int i;
 if (n > N){
  if (sum == M){
   for (i = 1; i <= N; i++) printf("%d ", s[i]);
   printf("\n");
  }
  return;
 }
 for (i = 1; i <= 6; i++){
  s[n] = i;
  DFS(n + 1, sum + i);
 }
}
int main(void){
 scanf("%d %d", &N, &M);
 DFS(1, 0);
 return 0;
}
#endif
// 더하기
#if 0
#include <stdio.h>
int T, N, K, b;
int a[20 + 10];
int main(void){
 int i, sum;
 scanf("%d", &T);
 while (T--){
  scanf("%d %d", &N, &K);
  for (i = 0; i < N; i++) scanf("%d", &a[i]);
  for (b = 0; b < (1 << N); b++){
   sum = 0;
   for (i = 0; i < N; i++){
    sum += a[i] * ((b >> i) & 0x1);
   }
   if (sum == K) break;
  }
  if (b < (1 << N)) printf("YES\n");
  else printf("NO\n");
 }
 return 0;
}
#endif
// 더하기
#if 0
#include <stdio.h>
int T, N, K;
int a[20 + 10];
int DFS(int n, int sum){
 if (K == sum) return 1;
 if (n > N|| sum > K) return 0;
 if(DFS(n + 1, sum + a[n])) return 1; // 더하는 경우
 if(DFS(n + 1, sum)) return 1;   // 더하지 않는 경우
 return 0;
}
int main(void){
 int i;
 scanf("%d", &T);
 while (T--){
  scanf("%d %d", &N, &K);
  for (i = 1; i <= N; i++) scanf("%d", &a[i]);
  if (DFS(1, 0)) printf("YES\n");
  else printf("NO\n");
 }
 return 0;
}
#endif
// 단지 번호붙이기
#if 0
#include <stdio.h>
int N, cnt;
int a[25 + 10][25 + 10], s[25*25+20];
int chk[25 + 10][25 + 10];
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
void Fill(int i, int j){
 int k, ii, jj;
 if (chk[i][j]) return;
 chk[i][j] = 1, s[cnt]++;
 for (k = 0; k < 4; k++){
  ii = i + di[k], jj = j + dj[k];
  if (ii<1 || ii>N || jj<1 || jj>N||a[ii][jj]!=1) continue;
  Fill(ii, jj);
 }
}
int main(void)
{
 int i, j, t;
 scanf("%d", &N);
 for (i = 1; i <= N; i++){
  for (j = 1; j <= N; j++){
   scanf("%1d", &a[i][j]);
  }
 }
 for (i = 1; i <= N; i++){
  for (j = 1; j <= N; j++){
   if (chk[i][j] || a[i][j] != 1) continue;
   Fill(i, j);
   cnt++;
  }
 }
 for (i = 0; i < cnt - 1; i++){
  for (j = i + 1; j < cnt; j++){
   if (s[i]>s[j]){
    t = s[i], s[i] = s[j], s[j] = t;
   }
  }
 }
 printf("%d\n", cnt);
 for (i = 0; i < cnt; i++) printf("%d\n", s[i]);
 return 0;
}
#endif
// 마을 위성사진II
#if 0
#include <stdio.h>
int N, sol;
int a[100 + 10][100 + 10];
int chk[100 + 10][100 + 10];
int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void Fill(int i, int j){
 int k, ii, jj;
 if (chk[i][j]) return;
 chk[i][j] = 1;
 for (k = 0; k < 8; k++){
  ii = i + di[k], jj = j + dj[k];
  if (ii<1 || ii>N || jj < 1 || jj>N) continue;
  if (a[ii][jj]!=1) continue;
  Fill(ii, jj);
 }
}
int main(void)
{
 int i, j;
 scanf("%d", &N);
 for (i = 1; i <= N; i++){
  for (j = 1; j <= N; j++){
   scanf("%1d", &a[i][j]);
  }
 }
 for (i = 1; i <= N; i++){
  for (j = 1; j <= N; j++){
   if (chk[i][j] || a[i][j] != 1) continue;
   Fill(i, j);
   sol++;
  }
 }
 printf("%d", sol);
 return 0;
}
#endif
// 퀵정렬
#if 0
#include <stdio.h>
int N;
int a[30000 + 10];
void Quick(int s, int e){
 int L, T=s, P=e, t;
 if (s >= e) return;
 for (L = s; L < P; L++){
  if (a[L] < a[P]){
   if (L != T){ t = a[L], a[L] = a[T], a[T] = t; }
   T++;
  }
 }
 if (P != T){ t = a[P], a[P] = a[T], a[T] = t;}
 Quick(s, T - 1); // 좌측
 Quick(T + 1, e); // 우측
}
int main(void)
{
 int i;
 scanf("%d", &N);
 for (i = 1; i <= N; i++){
  scanf("%d", &a[i]);
 }
 Quick(1, N);
 for (i = 1; i <= N; i++){
  printf("%d ", a[i]);
 }
 return 0;
}
#endif
// 피보나치수열
#if 0
#include <stdio.h>
int N;
int F[100] = { 0, 1, 1, };
int Fibo(int n){
 if (F[n] != 0) return F[n];
 return F[n] = Fibo(n - 1) + Fibo(n - 2);
}
int main(void)
{
 int i;
 scanf("%d", &N);
 printf("%d", Fibo(N));
 return 0;
}
#endif
// 미로 탈출 로봇
#if 0
#include <stdio.h>
typedef struct{
 int y, x, d;
}Q_T;
Q_T Q[100 * 100 + 10];
int Rp, Wp, X, Y, sx, sy, ex, ey;
int a[100 + 10][100 + 10];
int chk[100 + 10][100 + 10];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int BFS(void){
 int ty, tx, td, k, yy, xx;
 Q[Wp].y = sy, Q[Wp].x = sx, Q[Wp++].d = 0, chk[sy][sx] = 1;
 while (Rp != Wp){
  ty = Q[Rp].y, tx = Q[Rp].x, td = Q[Rp++].d;
  if (ty == ey && tx == ex) return td;
  for (k = 0; k < 4; k++){
   yy = ty + dy[k], xx = tx + dx[k];
   if (yy<1 || yy>Y || xx<1 || xx>X) continue;
   if (chk[yy][xx] || a[yy][xx] != 0) continue;
   Q[Wp].y = yy, Q[Wp].x = xx, Q[Wp++].d = td + 1, chk[yy][xx] = 1;
  }
 }
 return -1;
}
int main(void)
{
 int y, x, t;
 scanf("%d %d", &X, &Y);
 scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
 for (y = 1; y <= Y; y++){
  for (x = 1; x <= X; x++){
   scanf("%1d", &a[y][x]);
  }
 }
 t = BFS();
 printf("%d", t);
 return 0;
}
#endif
// 합의 회문수
#if 0
#include <stdio.h>
int N;
int a[100 + 10];
int Rev(int n){
 int s = 0;
 while (n > 0){
  s = s * 10 + n % 10;
  n = n / 10;
 }
 return s;
}
int main(void){
 int i, t;
 scanf("%d", &N);
 for (i = 1; i <= N; i++){ scanf("%d", &a[i]); }
 for (i = 1; i <= N; i++){
  t = Rev(a[i]);
  t = t + a[i];
  if (t == Rev(t)) printf("YES\n");
  else printf("NO\n");
 }
 return 0;
}
#endif
// 알파벳
#if 0
#include <stdio.h>
char a[30 + 10], c, sol;
int cnt[128 + 10];
int main(void)
{
 int i, max=0;
 scanf("%s", &a[0]);
 for (i = 0; a[i]; i++){
  cnt[a[i]]++;
 }
 for (c = 'a'; c <= 'z'; c++){
  if (max < cnt[c]){
   max = cnt[c], sol = c;
  }
 }
 printf("%c", sol);
 return 0;
}
#endif
// 100 만들기
#if 0
#include <stdio.h>
int a[9 + 10];
int main(void)
{
 int i, j, t, sum=0;
 for (i = 0; i < 9; i++){
  scanf("%d", &a[i]);
  sum += a[i];
 }
 for (i = 0; i < 8; i++){
  for (j = i + 1; j < 9; j++){
   if (a[i]>a[j]){
    t = a[i], a[i] = a[j], a[j] = t;
   }
  }
 }
 for (i = 0; i < 8; i++){
  for (j = i + 1; j < 9; j++){
   if (a[i] + a[j] == sum - 100) break;
  }
  if (j < 9) break;
 }
 for (t = 0; t < 9; t++){
  if (t == i || t == j) continue;
  printf("%d\n", a[t]);
 }
 return 0;
}
#endif
// 악수
#if 0
#include <stdio.h>
int R, C, sol;
char a[50 + 10][50 + 10];
int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int Count(int i, int j){
 int k, ii, jj, r=0;
 for (k = 0; k < 8; k++){
  ii = i + di[k], jj = j + dj[k];
  if (ii < 0 || ii >= R || jj < 0 || jj >= C) continue;
  if (a[ii][jj] != 'o') continue;
  r++;
 }
 return r;
}
int main(void)
{
 int i, j, t;
 scanf("%d %d", &R, &C);
 for (i = 0; i < R; i++){
  scanf("%s", &a[i][0]);
 }
 for (i = 0; i < R; i++){
  for (j = 0; j < C; j++){
   if (a[i][j] != '.') continue;
   t = Count(i, j);
   if (sol < t) sol = t;
  }
 }
 for (i = 0; i < R; i++){
  for (j = 0; j < C; j++){
   if (a[i][j] != 'o') continue;
   sol += Count(i, j);
   a[i][j] = '.';
  }
 }
 printf("%d", sol);
 return 0;
}
#endif
// 숫자근
#if 0
#include <stdio.h>
int N, sol;
int a[1000 + 10];
int Root(int n){
 int r = 0;
 for (;;){
  r = 0;
  while (n > 0){
   r += n % 10;
   n /= 10;
  }
  if (r < 10) return r;
  n = r;
 }
}
int main(void)
{
 int i, max=0, t;
 scanf("%d", &N);
 for (i = 1; i <= N; i++){
  scanf("%d", &a[i]);
 }
 for (i = 1; i <= N; i++){
  t = Root(a[i]);
  if (max < t) {
   max = t, sol = a[i];
  }
  if (max == t && sol > a[i]){
   sol = a[i];
  }
 }
 printf("%d", sol);
 return 0;
}
#endif
// 연속부분최대곱
#if 0
#include <stdio.h>
int N;
double a[10000 + 10], sol=0, mul=1;
int main(void)
{
 int i;
 scanf("%d", &N);
 for (i = 1; i <= N; i++){
  scanf("%lf", &a[i]);
 }
 for (i = 1; i <= N; i++){
  if (mul < 1) mul = a[i];
  else mul *= a[i];
  if (sol < mul) sol = mul;
 }
 printf("%.3f", sol);
 return 0;
}
#endif
// 그릇
#if 0
#include <stdio.h>
char a[50 + 10];
int sol;
int main(void)
{
 int i;
 scanf("%s", &a[0]);
 sol = 10;
 for (i = 1; a[i] != '\0'; i++){
  if (a[i] == a[i - 1]) sol += 5;
  else sol += 10;
 }
 printf("%d", sol);
 return 0;
}
#endif
// 행과 열의 큰 값 찾기
#if 0
#include <stdio.h>
int N;
int a[10 + 10][10 + 10];
int max_row, max_col;
int main(void)
{
 int i, j, max, sum;
 scanf("%d", &N);
 for (i = 1; i<=N; i++)
 {
  for (j = 1; j<=N; j++)
  {
   scanf("%d", &a[i][j]);
  }
 }
 max = 0x80000000; // min = 0x7fffffff;
 for (i = 1; i <= N; i++){
  sum = 0;
  for (j = 1; j <= N; j++){
   sum += a[i][j];
  }
  if (max < sum) {
   max = sum, max_row = i;
  }
 }
 max = 0x80000000;
 for (j = 1; j <= N; j++){
  sum = 0;
  for (i = 1; i <= N; i++){
   sum += a[i][j];
  }
  if (max < sum) {
   max = sum, max_col = j;
  }
 }
 printf("%d %d", max_row, max_col);
 return 0;
}
#endif
// 
#if 0
#include <stdio.h>
int main(void)
{
 return 0;
}
#endif
================================================================
정현수  Jung, Hyunsoo  
삼성전자 생산기술연구소 TP기술팀
Test & Package tech. Team, Manufacturing Tech. Center / Samsung Electronics Co.Ltd.
Mobile: +82-10-5069-1891  E-mail : hs2010.jung@samsung.com
================================================================
 
 



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

	if (n > 4) {
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


