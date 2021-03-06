//
// Created by mc on 21-5-3.
//

#ifndef DATASTRUCT_LIST_H
#define DATASTRUCT_LIST_H

#include "listnode.h"

template<typename T>
class List { //列表模板类
private:
    int _size;
    ListNodePosi<T> header;
    ListNodePosi<T> trailer; //规模、头哨兵、尾哨兵


protected:
    void init();//列表创建时的初始化




public:
    List() { init(); } //默认

    List(List<T> const &L); //整体复制列表L
    // 析构函数
    ~List(); //释放（包含头、尾哨兵在内的）所有节点
    Rank size(){ return  _size;}

    T &operator[](Rank r) const;

    int clear(); //清除所有节点

    ListNodePosi<T> first() const { return header->succ; } //首节点位置

    ListNodePosi<T> last() const { return trailer->pred; } //末节点位置

    bool empty() const { return _size <= 0; } //判空

    int deduplicate();//剔除无序列表中的重复节点

    ListNodePosi<T> search ( T const& e ) const ;//有序列表查找

    T remove(ListNodePosi<T> p);  //删除合法位置p处的节点,返回被删除节点

    ListNodePosi<T> find ( T const& e, int n, ListNodePosi<T> p ) const; //无序区间查找

    void reverse(); //前后倒置（习题）

    void traverse();

    ListNodePosi<T> search ( T const& e, int n, ListNodePosi<T> p ) const; //有序区间查找
    // 遍历
    void traverse(void (* )(T &)); //遍历，依次实施visit操作（函数指针，只读或局部性修改）

    template<typename VST>
    //操作器
    void traverse(VST &); //遍历，依次实施visit操作（函数对象，可全局性修改）


    ListNodePosi<T> insertAsFirst ( T const& e ); //将e当作首节点插入


    ListNodePosi<T> insertAsLast(T const &e); //e当作末节点插入

    void insertionSort(ListNodePosi<T> p,int n);

    void copyNodes(ListNodePosi<T> p, int n) {
        init(); //创建头，尾哨兵节点并初始化
        while (n--) { //将起自
            insertAsLast(p->data);
            p = p->succ;
        }
    }

    int uniquify();

    ListNodePosi<T> selectMax(ListNodePosi<T> p,int n); // 在p及其n-1个后继中选出最大者

    ListNodePosi<T> selectMax() { return selectMax ( header->succ, _size ); } //整体最大者


    ListNodePosi<T> insertB ( ListNodePosi<T> p, T const& e ); //将e当作p的前驱插入（Before）
    ListNodePosi<T> insertA ( ListNodePosi<T> p, T const& e ); //将e当作p的后继插入（After）

    void selectionSort ( ListNodePosi<T>, int ); //对从p开始连续的n个节点选择排序

};


#endif //DATASTRUCT_LIST_H
