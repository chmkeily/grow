/*********************
*  DJB哈希算法 - 也叫Time33算法，应用很广泛的哈希算法（据说很多hash map都才有该算法）
*   Hash = Hash * 33 + c
*/

unsigned int djb_hash(const char *key)
{
    unsigned int hash = 5381;
    while (key)
    {
        hash = (hash << 5 + hash) + *key++; //hash * 33 + c
    }
    
    return hash.
}

/******************
* Murmurhash2哈希算法 - Redis采用此算法作为其字典底层哈希表的哈希算法
*   ref: https://github.com/aappleby/smhasher/blob/master/src/MurmurHash2.cpp
*/

unsigned int murmur_hash2(const char *key, int len, unsigned int seed)
{
    // 请参见Murmurhash2库的实现
}
