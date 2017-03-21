/*************************************************************************
    > File Name: rand64.h
    > Author: hemingchen
    > Mail: chmkeily@gmail.com 
    > Created Time: 2017-03-20 22:02:23
 ************************************************************************/
#include <stblib.h>

typedef unsigned long long uint64_t;

#ifdef _DIRECT_LCG_
//线性同余算法生成随机数
//Rn+1 = (214013 * Rn + 2531011) % MAX, 一般MAX是2的幂, 以获得2进制整数位
static uint64_t __holdrand = 1;

void srand64(uint64_t seed)
{
	__holdrand = seed;
}

uint64_t rand64()
{
	return (__holdrand = (__holdrand * 214013L + 2531011L) & 0x7fffffffffffffffL);
}

#else

//通过随机两次32bit整数合成一个64bit整数
//不过这种方法有个潜在问题：每次的两个32bit数总是rand()连续的伪随机数-_-
uint64_t rand64()
{
	uint64_t _r = rand();
	return ((_r << 32) | rand());
}

#endif
