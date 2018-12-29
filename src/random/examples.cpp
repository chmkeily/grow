/*************************************************************************
    > File Name: exampls.cpp
    > Author: hemingchen
    > Mail: chmkeily@gmail.com 
    > Created Time: 2017-04-29 16:17:08
 ************************************************************************/

#include <iostream>
#include <time.h>
#include <map>
#include "mt19937_32bits.h"
using namespace std;

#define SIZE 20

int main(int argc, char ** argv)
{
    int N = 100;
    if (argc > 1)
    {
        N = atoi(argv[1]);
        if (N < 0)
        {
            N = 100;
        }
    }

    int occurance[SIZE];
    memset(occurance, 0, sizeof(occurance));

    xgrow::srand(time(NULL));
    for (int i = 0; i < N; i ++)
    {
        occurance[xgrow::rand() % SIZE] ++;
    }

    for (int i = 0; i < SIZE; i ++)
    {
        cout << i << ":" << occurance[i] << endl;
    }

    return 0;
}
