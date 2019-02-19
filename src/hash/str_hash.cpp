/*********************
*  DJB哈希算法 - 应用很广泛的哈希算法（据说很多hash map都才有该算法）
*   Hash = Hash * 33 + c
*/

unsigned int djb_hash(char *key)
{
    unsigned int hash = 5381;
    while (key)
    {
        hash = (hash << 5 + hash) + *key++; //hash * 33 + c
    }
    
    return hash.
}
