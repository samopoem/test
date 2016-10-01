#include <stdio.h>

int data[10] = {16,1,10,5};
int sel[100];
int selcount = 0;
int N = 4;
int P = 20;

int subset1(int depth,int starti, int sum)
{
    int i;

    if( sum > P ){
        return 0;
    }
    if( sum == P ){
        for(i=0;i<selcount;i++){
            printf("%d ",sel[i]);
        }
        printf("\n");
        return 0;
    }


    for(i=starti;i<N;i++){
        sel[selcount] = data[i];
        sum = sum + data[i];
        selcount++;
        subset1(depth+1,i,sum);
        selcount--;
        sum = sum - data[i];
    }

    return 0;
}

int mincount = 10000;

int subset2(int depth,int starti, int sum)
{
    int i;

    if( sum > P || mincount <= selcount){
        return 0;
    }
    if( sum == P ){
        for(i=0;i<selcount;i++){
            printf("%d ",sel[i]);
        }
        printf("\n");
        mincount = selcount;
        return 0;
    }


    for(i=starti;i<N;i++){
        sel[selcount] = data[i];
        sum = sum + data[i];
        selcount++;
        subset2(depth+1,i,sum);
        selcount--;
        sum = sum - data[i];
    }

    return 0;
}

int main()
{
    printf("subset1\n");
    subset1(0,0,0);
    printf("subset2\n");
    subset2(0,0,0);
    return 0;
}