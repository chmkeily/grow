/*************************************************************************
    > File Name: randi64.h
    > Author: hemingchen
    > Mail: chmkeily@gmail.com 
    > Created Time: 2017-03-20 22:02:23
 ************************************************************************/

typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;
typedef unsigned char uint8_t;

//线性同余算法生成随机数
//Rn+1 = (214013 * Rn + 2531011) % MAX, 一般MAX是2的幂, 以获得2进制整数位
class _Rand
{
	
}
