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
//	int* p3 = new int[5]; // 5��int�Ŀռ�
//	int* p4 = new int(10);
//	
//	int* p5 = new int[5] {1, 2, 3, 4, 5}; // C++11
//
//	free(p1);
//	delete p2;
//	delete[] p3; // �� [] ����ƥ��
//	delete p4;
//	delete[] p5;
//
//	 // ����������ͣ�new/delete �� malloc/free û�б��ʵ�����ֻ���÷��������÷����򵥣�
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
//	// 1. ������ϵĿռ�
//	// 2. ������������
//	A* p2 = new A(0);
//	// Ҳ�����Լ����г�ʼ��
//	A* p3 = new A(10);
//
//	// 1. ��������������������е���Դ
//	// 2. �ͷ�p2ָ��Ŀռ�
//	delete p2;
//	delete p3;
//
//	A* p4 = new A[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	delete[] p4;
//
//	// ���ۣ� new/delete��Ϊ�Զ�������׼���ģ�
//	// �����ڶ������������������ù�����������ж�Ӧ�ĳ�ʼ��������
//
//	// new/delete �� new[]/delete[] һ��Ҫƥ�䣬������ܾͻ���뱨��
//	// �Զ������ʹ���ʳ����⣬�������Ͳ�һ��
//}

//int main()
//{
//	// mallocʧ�ܷ���NULL
//	char* p1 = (char*)malloc(1024u * 1024u * 1024u * 2 - 1);
//	printf("%p\n", p1);
//	
//	// newʧ�ܣ���Ҫ��鷵��ֵ��ʧ�������쳣
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

// operator new �� operator delete����
// ���ã��ڶ��Ͽ��ռ䣨�ײ�ʵ�ֻ���malloc��
// Ϊʲô��ֱ����malloc���𣺷�װmalloc�����ʧ���ˣ����Ը��������쳣������mallocʧ�ܻ᷵�ؿ�ָ��

// new Type
//   ||
// call operator new -> malloc(ʧ�����쳣)
// call Type(���캯��)


// ����һ����ר����operator new
struct ListNode
{
	int _val;
	ListNode* _next;
	// �ڴ��
	static allocator<ListNode> _alloc;

	// Ĭ�������� operator new ʹ��ȫ�ֿ������
	// ListNode��ר���� operator new��new�������󣬾ͻ�����Լ�ʵ�ֵ�operator new
	// ��ΪƵ�����룬Ҫ����Ч��
	void* operator new(size_t n) {
		// �ڴ��...
		cout << "void* operator new -> �ڴ������" << endl;
		void* obj = _alloc.allocate(1);
		return obj;

	}

	void operator delete(void* ptr) {
		cout << "void* operator new -> �ڴ���ͷ�" << endl;
		_alloc.deallocate((ListNode*)ptr, 1);
	}

	struct ListNode(int val)
		:_val(val)
		,_next(nullptr)
	{}
};

// ���ڻ��ü���
allocator<ListNode> ListNode:: _alloc;

int main()
{
	// Ƶ������ListNode
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

