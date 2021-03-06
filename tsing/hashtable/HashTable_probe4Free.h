/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2020. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "HashTable.h"
#include "HashTable_hashcode.h"

/******************************************************************************************
 * 沿关键码k的试探链，找到首个可用空桶；实践中有多种试探策略可选，这里仅以线性试探为例
 ******************************************************************************************/
template <typename K, typename V> int Hashtable<K, V>::probe4Free ( const K& k ) {
   int r = hashCode ( k ) % M; //按除余法确定试探链起点
   while ( ht[r] ) r = ( r + 1 ) % M; //线性试探，直到首个空桶（无论是否带有懒惰删除标记）
   return r; //只要有空桶，线性试探迟早能找到
}
