#include <stdio.h>
#include <stdlib.h>

//调整最小堆
void MinHeapAdjust( int heap[], int i, int length )
{
	int value = heap[i];

	int child = 2*i+1;

	while( 2*i+1 < length )
	{
		child = 2*i+1;

		if( child < length-1 && heap[child] > heap[child+1] )
			child++;

		if( value > heap[child] )
			heap[i] = heap[child];
		else
			break;

		heap[child] = value;
		i = child;
	}
}

//调整最大堆
void MaxHeapAdjust( int heap[], int i, int length )
{
	int value = heap[i];

	int child = 2*i+1;

	while( 2*i+1 < length )
	{
		child = 2*i+1;

		if( child < length-1 && heap[child] < heap[child+1] )
			child++;

		if( value < heap[child] )
			heap[i] = heap[child];
		else
			break;

		heap[child] = value;

		i = child;
	}
}

void swap( int *a, int *b )
{
	int tmp = *a;

	*a = *b;

	*b = tmp;
}

void HeapSort( int heap[], int length )
{	int i,j;

	for( i = (length)/2-1;i>=0;i-- )
		MinHeapAdjust(heap, i, length);

	int min;

	int l = length;

	while( l > 0 )
	{
		min = heap[0];

		printf("%d  ", min);

		swap( &heap[0], &heap[l-1] );

		MinHeapAdjust(heap, 0, --l);

	}
}

void KMax( int data[], int length )
{
	printf("前几个最大的数：\n");

	int i,k,index;

	scanf("%d", &k);

	//初始化最小堆
	int * heap = (int *)malloc(k*sizeof(int));

	for(index=0; index<k;index++)
		heap[index] = data[index];

	for( i = k/2-1;i>=0;i-- )
		MinHeapAdjust(heap, i, k);

	//初始化结束，开始计算
	for( index=k; index<length; index++ )
	{
		if( data[index] > heap[0] )
		{
			heap[0] = data[index];

			MinHeapAdjust(heap, 0, k);
		}
	}

	for( index=0; index<k; index++ )
		printf("%d  ", heap[index]);

	printf("\n");
}

void KMin( int data[], int length )
{

	printf("前几个最小的数：\n");

	int i,k,index;

	scanf("%d", &k);

	//初始化最大堆
	int * heap = (int *)malloc(k*sizeof(int));

	for(index=0; index<k;index++)
		heap[index] = data[index];

	for( i = k/2-1;i>=0;i-- )
		MaxHeapAdjust(heap, i, k);
	
	//初始化结束，开始计算
	for( index=k; index<length; index++ )
	{
		if( data[index] < heap[0] )
		{
			heap[0] = data[index];
			MaxHeapAdjust(heap, 0, k);
		}
	}

	for( index=0; index<k; index++ )
		printf("%d  ", heap[index]);
	printf("\n");
}

int main()
{
	int data[] = {5,98,24,57,36,6,2,9,123,59,41,26,75,4,9,65,2,32,12,45,98,32,23};	
	int length = (sizeof(data)/sizeof(int));

	//堆排序
	HeapSort(data, length);

	printf("\n********************************\n");

	//求一些数字中最大的k个数字
	KMax( data, length );

	printf("\n********************************\n");

	//求一些数字中最小的k个数字
	KMin( data, length );

}
