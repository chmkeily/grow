#ifndef _SORTED_OBJECT_POOL_H_
#define _SORTED_OBJECT_POOL_H_

#include <iostream>
using namespace std;

namespace xgrow
{

struct tagObjBase
{
	
};

struct tagSortedObjPoolHead
{
	char *m_pcDataHead;
	char *m_pszData;
};

template <typename _KeyType, typename _DataType>
class CSortedObjectPool
{
public:
	typedef typename int PointerType;
	typedef typename _KeyType KeyType;
	typedef typename _DataType DataType;
	
public:
	int Init();
	int Resume();
	int Reclaim();

	int Insert(const DataType &stData);

	int DeleteByKey(const KeyType &stKey);

	int DeleteByIndex(int iIdx);

protected:
	

private:
	DataType *m_pDataHead;
	
	
private:
	
};

}

#endif
