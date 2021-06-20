/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2020. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of PQ_ComplHeap & PQ_LeftHeap
 ******************************************************************************************/
#include <rand.h>
#include <print.h>
#include <PQ_List.h>
#include <PQ_ComplHeap.h>

/******************************************************************************************
 * ��Ի����б��������Լ���ʽ��ʵ�ֵ����ȼ����У�������ͳһ�Ĳ���
 ******************************************************************************************/
template <typename PQ, typename T> //�����͡���������
void  testHeap ( int n ) {
   T* A = new T[2*n/3]; //��������Ϊ2*n/3�����飬��
   for ( int i = 0; i < 2 * n / 3; i++ ) A[i] = dice ( ( T ) 3 * n ); //�������������2*n/3������
   /*DSA*/printf ( "%d random keys created:\n", 2 * n / 3 );
   /*DSA*/for ( int i = 0; i < 2 * n / 3; i++ ) printf (" %d ", A[i] ); printf ( "\n" );
//   PQ heap ( A + n / 6, n / 3 ); //�������ѣ�PQ_ComplHeapʵ����Robert Floyd�㷨��
//   delete [] A;
//   /*DSA*/print ( heap );
//   while ( heap.size() < n ) { //�������
//      if ( dice ( 100 ) < 70 ) { //70%���ʲ����´���
//         T e = dice ( ( T ) 3 * n ); /*DSA*/printf ( "Inserting" ); print ( e ); printf ( " ...\n" );
//         heap.insert ( e ); /*DSA*/printf ( "Insertion done\n" );
//      } else { //30%����ժ��������
//         if ( !heap.empty() ) {
//            /*DSA*/printf ( "Deleting max ...\n" );
//            T e = heap.delMax();/*DSA*/printf ( "Deletion done with" ); print ( e ); printf ( "\n" );
//         }
//      }
//      /*DSA*/print ( heap );
//   }
//   while ( !heap.empty() ) { //���
//      T e = heap.delMax();/*DSA*/printf ( "Deletion done with" ); print ( e ); printf ( "\n" );
//      /*DSA*/print ( heap );
//   }
}

#if 0

/******************************************************************************************
 * ���ȼ����в���
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) );

   char *type = argv[1];
   //srand( 1234567 );
//#if defined(DSA_PQ_LEFTHEAP)
//   testHeap<PQ_LeftHeap<int>, int> ( atoi ( argv[1] ) ); //�������Ϳ�������������ѡ��
//#elif defined(DSA_PQ_COMPLHEAP)
   testHeap<PQ_ComplHeap<int>, int> ( atoi ( argv[1] ) ); //�������Ϳ�������������ѡ��
//#elif defined(DSA_PQ_LIST)
//   testHeap<PQ_List<int>, int> ( 5 ); //�������Ϳ�������������ѡ��
//#else
//   printf ( "PQ type not defined yet\n" );
//#endif
   return 0;
}


#endif