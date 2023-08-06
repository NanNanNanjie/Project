#include <iostream>

using namespace std;

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

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == NULL) {
//		printf("malloc is failed\n");
//	}
//
//	// 1. 申请堆上的空间
//	// 2. 调用析构函数
//	A* p2 = new A(0);
//	// 也可以自己进行初始化
//	A* p3 = new A(10);
//
//	// 1. 调用析构函数清理对象中的资源
//	// 2. 释放p2指向的空间
//	delete p2;
//	delete p3;
//
//	A* p4 = new A[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	delete[] p4;
//
//	// 结论： new/delete是为自定义类型准备的：
//	// 不仅在堆上申请出来，还会调用构造和析构进行对应的初始化和清理
//
//	// new/delete 和 new[]/delete[] 一定要匹配，否则可能就会编译报错
//	// 自定义类型大概率出问题，内置类型不一定
//}

//int main()
//{
//	// malloc失败返回NULL
//	char* p1 = (char*)malloc(1024u * 1024u * 1024u * 2 - 1);
//	printf("%p\n", p1);
//	
//	// new失败，需要检查返回值，失败是抛异常
//	try {
//		size_t n = 0;
//		while (1) {
//			char* p2 = new char[1024 * 1024];
//			n++;
//			printf("%p->[%d]\n", p2, n);
//
//		}
//	} catch (const exception& e) {
//		cout << e.what() << endl;
//	}
//	
//
//	return 0;
// }

// operator new 与 operator delete函数
// 作用：在堆上开空间（底层实现还是malloc）
// 为什么不直接用malloc？答：封装malloc，如果失败了，可以给程序抛异常，但是malloc失败会返回空指针

// new Type
//   ||
// call operator new -> malloc(失败抛异常)
// call Type(构造函数)


// 重载一个类专属的operator new
struct ListNode
{
	int _val;
	ListNode* _next;
	// 内存池
	static allocator<ListNode> _alloc;

	// 默认条件下 operator new 使用全局库里面的
	// ListNode类专属的 operator new，new这个类对象，就会调用自己实现的operator new
	// 因为频繁申请，要调高效率
	void* operator new(size_t n) {
		// 内存池...
		cout << "void* operator new -> 内存池申请" << endl;
		void* obj = _alloc.allocate(1);
		return obj;

	}

	void operator delete(void* ptr) {
		cout << "void* operator new -> 内存池释放" << endl;
		_alloc.deallocate((ListNode*)ptr, 1);
	}

	struct ListNode(int val)
		:_val(val)
		,_next(nullptr)
	{}
};

// 现在会用即可
allocator<ListNode> ListNode:: _alloc;

int main()
{
	// 频繁申请ListNode
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);

	delete node1;
	delete node2;
	delete node3;
	delete node4;

	return 0;
}

