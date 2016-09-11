#define _NO_CRT_SECURE_WARNINS

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


