/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2020. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "List.h"

template <typename T> void List<T>::traverse (void ( *visit ) (T& ) ) //借助函数指针机制遍历
{  for ( ListNodePosi<T> p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  }

template <typename T> template <typename VST> //元素类型、操作器
void List<T>::traverse ( VST& visit ) //借助函数对象机制遍历
{  for ( ListNodePosi<T> p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  }

template <typename T>
void List<T>::traverse()
{
    if (_size == 0)
    {
        std::cout << "no element" << std::endl;

        return;
    }

    ListNodePosi<T> p = header;

    while (trailer != (p = p->succ))
    {
        cout << p->data << "  ";
    }

    std::cout << std::endl;
}
