/*************************************************************************
    > File Name: mt19937_32bits.h
    > Desc: Mersenne Twister
    > Author: hemingchen
    > Mail: chmkeily@gmail.com 
    > Created Time: 2017-04-11 16:58:33
 ************************************************************************/
#ifndef __MT19937_32BITS_H__
#define __MT19937_32BITS_H__

#include <stblib.h
#include <time.h>

namespace xgrow
{

static int g_index;
static int g_MT[624];  
     
void srand(int seed)
{
    g_index = 0;
    g_MT[0] = seed;
    
    for (int i = 1; i < 624; i ++)
    {
        g_MT[i] = ((g_MT[i - 1] ^ (g_MT[i - 1] >> 30)) * 0x6c078965 + i) & 0xffffffff;
    }
}

void generate()
{
    for (int i = 0; i < 624; i ++)
    {
        int y   = g_MT[i] & 0x80000000) + (g_MT[(i + 1) % 624] & 0x7fffffff);   //取MT[i]的最高位和M[i+1]的低31位合并
        g_MT[i] = g_MT[(i + 397) % 624] ^ (y >> 1);
        
        if (y & 0x01)
        {
            g_MT[i] ^= 0x9908b0df;  //若y是奇数，在做一次异或
        }
    }
}

int64_t rand()
{
    if (0 == g_index)
    {
        generate();
    }
    
    int y = g_MT[g_index];
    y ^= (y >> 11);
    y ^= ((y << 7) & 0x9d2c5680);
    y ^= ((y << 15) & 0xefc60000);
    y ^= (y >> 18);
    
    g_index = (g_index + 1) % 624;
    
    return y;
}

} //end of namespace xgrow

#endif
