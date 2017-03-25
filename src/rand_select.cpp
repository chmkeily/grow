#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/**
* @brief 获得一个 [M,N] 范围内的随机整数
*/
int randv(int m, int n)
{
    return m + (int)((n - m + 1) * (rand() / (RAND_MAX + 1)));
}

/**
* @brief 等权N选K (K<N), 传说Knuth大神在/The Art of Computer Programming/书中提出的，
*        此方案在K远小于N的时候效率可能就不合算了
* @param aiSelected 返回选择结果
*/
int rand_select_knuth(int N, int K, int *aiSelected)
{
    if (N < K)
    {
        return -1;
    }
    
    int r = K;
    for (int i = 0; i < N && 0 < r; i ++)
    {
        if (randv(0, N - 1 - i) < r)
        {   
            -- r;
            aiSelected[r] = i;
        }
    }
    
    return 0;
}

//输出整型数组内容
void print_arrint(int k, int *arrInt)
{
    for (int i = 0; i < k; i ++)
    {
        cout << "\t" << arrInt[i];
    }
    cout << endl;
}

/////////////////////

#define N 100
#define K 10

int main()
{
    int aiSelected[K];
    unsigned int seed = time(NULL) + getpid();  //timestamp + process id
    srand(seed);
    
    //随机选择
    if (rand_select_knuth(N, K, aiSelected))
    {
        cout << "rand_select_knuth failed" << endl;
        return -1;
    }
    
    //输出随机选择结果
    print_arrint(K, aiSelected);

    return 0;
}
