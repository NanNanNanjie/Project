#include <iostream>

using std::cout;
using std::cin;
using std::endl;
//
//static int Day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//bool isLeapYear(int year)
//{
//    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
//}
//
//int main()
//{
//    int year, month, day;
//    cin >> year >> month >> day;
//
//    if (isLeapYear(year)) Day[2] = 29;
//
//    int count = 0;
//    for (int i = 1; i < month; i++) {
//        count += Day[i];
//    }
//
//    count += day;
//
//
//    
//    cout << count << endl;
//}

//static int Day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//int globalVar = 1;
//static int staticGlobalVar = 1;
//
// C C C A A
// A A A D A B
//
// 40 5 4 8 4 8
//
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//
//	cout << sizeof(num1) << endl;
//	cout << sizeof(char2) << endl;
//	cout << strlen(char2) << endl;
//	cout << sizeof(pChar3) << endl;
//	cout << strlen(pChar3) << endl;
//	cout << sizeof(ptr1) << endl;
//} 
//
//int main()
//{
//	Test();
//}

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	int* p3 = new int[5]; // 5个int的空间
//	int* p4 = new int(10);
//	
//	int* p5 = new int[5] {1, 2, 3, 4, 5}; // C++11
//
//	free(p1);
//	delete p2;
//	delete[] p3; // 用 [] 进行匹配
//	delete p4;
//	delete[] p5;
//
//	 // 针对内置类型，new/delete 和 malloc/free 没有本质的区别，只有用法的区别（用法更简单）
//
//}
//
//int main()
//{
//	Test();
//	
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

int main()
{
	A* p1 = (A*)malloc(sizeof(A));
	if (p1 == NULL) {
		printf("malloc is failed\n");
	}

	// 1. 申请堆上的空间
	// 2. 调用析构函数
	A* p2 = new A;
	// 也可以自己进行初始化
	A* p3 = new A(10);

	// 1. 调用析构函数清理对象中的资源
	// 2. 释放p2指向的空间
	delete p2;
	delete p3;

	A* p4 = new A[10];
	delete[] p4;

	// 结论： new/delete是为自定义类型准备的：
	// 不仅在堆上申请出来，还会调用构造和析构进行对应的初始化和清理
}