

// 샘플
#if 0
#include <stdio.h>
int main()
{
	return 0;
}
#endif


// 2020 Problem  D [TST]고기잡이 
#if 0
#include <stdio.h>
int N, L, M;
typedef struct {
	int y, x;

}Q_T;
Q_T Q[100+10];
int sol;

int main()
{
	scanf("%d %d %d", &N, &L, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &Q[i].y, &Q[i].x);
	}
	int max = -1;


	// 좌표 이동
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= M; j++)
		{

			// 그물 사이즈 변경
			for (int w = 1; w <= L / 2; w++)
			{
				int h = L / 2 - w;


				int cnt = 0;
				// 고기 위치 하나씩 꺼냄
				for (int k = 0; k < M; k++)
				{
					if ((j <= Q[k].x && Q[k].x <= (j + w)) &&
						(i <= Q[k].y && Q[k].y <= (i + h)))
						cnt++;
				}
				if (max < cnt) max = cnt;
			}

		}
	}
	

	printf("%d", max);

	return 0;
}
#endif

// 2139 Problem  C [TST]예산 
#if 0
#include <stdio.h>
int N;
int a[10000 + 10];
int b[10000 + 10];
int T;
int sol;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &T);

	for (int i = 0; i < N-1; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (a[i] < a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	int t=0;
	for (int i = 0; i < N; i++)
	{
		t += a[i];
	}


	if(t<=T) printf("%d", a[0]);
	else
	{
		int total = 0;
		int p = a[0];

		for (;;)
		{
			
			for (int i = 0; i < N; i++){
				if (a[i] > p) a[i] = p;
			}
			p--;

			for (int i = 0; i < N; i++)	total += a[i];
			if (total <= T) break;
			total = 0;
		}
		printf("%d", a[0]);
	}

	return 0;
}
#endif

#if 0
#include <stdio.h>
int N;
int s[6 + 10];

int cnt=0;
void DFS(int n, int i)
{
	if (n >= 3)
	{
		printf("%d  ",cnt++);
		for (int i = 0; i < 3; i++)
		{
			printf("%d ", s[i]);
		}
		printf("\n");
		return;
	}

	for (size_t i = 1; i <= 6; i++)
	{
		s[n] = i;
		DFS(n+1, i);
	}
	
}



int main()
{
	N = 6;
	DFS(0, 0);
	return 0;
}


#endif


#if 0
#include <stdio.h>
int N;
int s[6 + 10];
int data[] = { 1,2,3,4 };
int cnt = 0;

int swap(int i, int j)
{
	int temp;
	if (i == j) return 0;
	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
	return 0;
}

int P(int n, int r)
{
	int i;
	if ( r == 1)
	{		
		for (int i = 0; i < n; i++)
		{
			printf("%d ", data[i]);
		}
		printf("\n");
		return 0;
	}

	for (i = 0; i < r; i++) {
		swap(i, r - 1);
		P(n, r - 1);
		swap(i, r - 1);
	}
}



int main()
{
	N = 4;
	P(N, N);
	return 0;
}



#endif

// PowerSet1
#if 0
#include <stdio.h>

int data[] = { 1,2,3,4 };
int flag[] = { 0,0,0,0 };

void powerset(int n, int depth)
{
	if (n == depth) {
		int i;
		printf("{");
		for (i = 0; i<n; i++) {
			//if (flag[i] == 1)printf("%d ", data[i]);
			printf("%d ", flag[i]);
		}
		printf("}\n");
		return;
	}
	flag[depth] = 1;
	powerset(n, depth + 1);
	flag[depth] = 0;
	powerset(n, depth + 1);
}

int main()
{
	powerset(sizeof(data) / sizeof(int), 0);
	return 0;
}

#endif



// PowerSet2
#if 0
#include <stdio.h>

int data[] = { 1,2,3,4 };

void powerset(int n)
{
	int i, j;
	int max = 1 << n;
	for (int i = 0; i < max; i++)
	{
		printf("{");
		for (int j = 0; j < n; j++)
		{
			//int temp = (i & (1 << j)) > 0 ? 1 : 0;
			//printf("%d ", temp);
			if (i & (1 << j))
			{
				printf("%d ", data[j]);
			}
		}
		printf("}\n");
	}
}

int main()
{
	powerset(sizeof(data) / sizeof(int));
	return 0;
}

#endif

// PowerSet3
#if 1
#include <stdio.h>

int data[10] = { 1,2,3,4 };
int flag[10];
int selected[10];
int N = 3;


void powerset(int depth, int starti)
{
	
}

void powerset2(int depth, int starti)
{
	int i;
	printf("{");
	for (int i = 0; i < depth; i++)
	{
		printf("%d ", selected[i]);
	}
	printf("}\n");
	for (int i = starti; i < N; i++)
	{
		selected[depth] = data[i];
		powerset2(depth + 1, i + 1);
	}
}

int main()
{
	powerset(0, 0);
	powerset2(0, 0);
	return 0;
}

#endif