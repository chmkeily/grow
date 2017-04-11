/*************************************************************************
    > File Name: tiny_mt19937_32bits.h
    > Desc: Mersenne Twister
    > Author: hemingchen
    > Mail: chmkeily@gmail.com 
    > Created Time: 2017-04-11
 ************************************************************************/

#ifndef __TINY_MT19937_32BITS_H__
#define __TINY_MT19937_32BITS_H__

namespace xgrow
{

static int g_MT_curr;
static int g_MT_next;
static int g_MT_next397;

void srand(int seed)
{
    g_MT_curr = seed;
    g_MT_next = ((g_MT_curr ^ (g_MT_curr >> 30)) * 0x6c078965 + i) & 0xffffffff;
    g_MT_next397 = g_MT_curr;
    for (int i = 0; i < 397; i ++)
    {
        g_MT_next397 = ((g_MT_next397 ^ (g_MT_next397 >> 30)) * 0x6c078965 + i) & 0xffffffff;
    }
    
    ///
    int y     = g_MT_curr & 0x80000000) + (g_MT_next & 0x7fffffff);
    g_MT_curr = g_MT_next397 ^ (y >> 1);
    if (y & 0x01)
    {
        g_MT_curr ^= 0x9908b0df;
    }
}

int rand()
{
    
    return 0;
}

}

#endif
