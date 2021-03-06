// heapsort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Heap {
private:
	int *data;
	void buildHeap(int data, int length);
	void ajust(int index);
	int len;
public:
	Heap();
	void init(int *arr, int length);
	int *sort();
	void show();


};
void Heap::show() {
	int *temp = data;
	int c = len;
	while (c--){
		cout << *temp++ << " ";
	}
	cout << endl;
}
Heap::Heap() {
	data = new int[100];
	len = 0;
}
void Heap::init( int *arr , int length) {
	delete[]data;
	this->len = length;
	data = new int[length];
	for (int i = 0; i < length; i++) {
		this->buildHeap(arr[i], i);
	}

}
void Heap::buildHeap(int item , int length) {
	if (length == 0) {
		data[0] = item;
		return;
	}
	int index = length;
	int p = (index-1) / 2;
	while (index != 0&&data[p] < item  ) {
		data[index] = data[p];
		index = (index-1) / 2;
		p = (index-1) / 2;
	}
	data[index] = item;
	 
}
int *Heap::sort() {
	int *result = new int[len];
	int temp = len; 
	for (int i = len-1; i >= 0; i--) {
		*result++ = this->data[0];
		this->data[0] = this->data[len-1];
		this->data[len - 1] = *(result-1);
		len--;
		this->ajust(0);
	}
	len = temp;
	//this->init(data, len);
	return result;
}
void Heap::ajust(int index) {
	int item = data[index];
	int left = index * 2+1;
	if (left >= len) {
		return;
	}
	int right = left + 1;
	int max = data[left];
	int exchangeIndex = left;
	if (right >= len) {
		right = -1;
	}
	else {
		if (max < data[right]) {
			exchangeIndex = right;
			max = data[right];
		}
	}
	while (left < len && item < max) {
		data[index] = data[exchangeIndex];
		index = exchangeIndex;
		left = index * 2+1;
		exchangeIndex = left;
		right = left + 1;
		if (left < len) {
			max = data[left];
		}
		if (right < len) {
			if (max < data[right]) {
				max = data[right];
				exchangeIndex = right;
			}
		}

	}
	data[index] = item;

}
int main()
{
	int arr[]= { 11,2,3,4,5,6,7,8,9,10 ,23,556,344,356};
	Heap Heap;
	Heap.init(arr, 13);
	Heap.show();
	int *result = Heap.sort();
	int i = 10;

	Heap.show();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
