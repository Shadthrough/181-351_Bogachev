//Stack is better than array 
// To name the stack do: std::stack<DATA_TYPE> STACK_NAME
// stack.push - add an elem
// stack.pop - delete upper elem
//
//	Queue
// naming same as stack
//	Deque - double-ended queue
// naming is same
// as for methods it goes as deque.push_back/push_front



#include <iostream> 

#include <string>
#include <stack> // ���������� ���������� ��� ������������� ����� 
#include <queue> // ���������� ���������� ��� ������������� ������� 
#include <deque> // ���������� ���������� ��� ������������� ���� 


#include <list> // ���������� ���������� ��� ������������� ������
#include <set> // ���������� ���������� ��� ������������� ���������
#include <map> // ���������� ���������� ��� ������������� �������������� �������


int main()
{
	setlocale(LC_ALL, "rus");
	/*
	���� � ��� ��������� ������, ������� ��������
	�� �������� FILO(first in � last out; ������ ������ � ��������� ����).

	� ����� ��� ��������,�.�. ������ ���������� � ������������� ��������.
	������ ������� ����� ��������� �� ��������� �������.
	�������� ������� ��������� �� NULL.

	�����������: �������� �������� � ���������� �������� �������� �� const �����.

	*/
	/*
std::stack<int> stackInt;//stack <��� ������> <���>; -�������� �����
int i = 0, a = 0;
std::cout << "������� 5 ����� �����: " << std::endl;
while (i != 5) {
	std::cin >> a;
	stackInt.push(a); // ��������� ��������� �����
	i++;
}

if (stackInt.empty()) // ��������� ���� �� ���� (���)
	std::cout << "���� �� ����";

std::cout << "������� ������� �����: " << stackInt.top() << std::endl;
stackInt.pop(); // ������� ������� �������

std::cout << "����� ������� �������: " << stackInt.top()<< std::endl;
			*/
			// ������� 1 
			/*
			��������� ������������ ����������� ������ (,),[,],{,}
			� ��������� ������������� ��������� �� �������� �����
			(���� �������� ���������).
			2+4-5(87192479_7348){72648]76823[] -> no
			({}) -> yes
			({)} -> no
			*/
	std::stack <char> first;
	char a;
	while (1)
	{
		std::cin >> a;
		if (a == '0')
		{
			std::cout << "Yes" << std::endl;
			break;
		}
		if (a == '(' || a == '{' || a == '[') first.push(a);
		if (a == ')')
		{
			if ('(' == first.top())
			{
				first.pop();
			}
			else
			{
				std::cout << "No" << std::endl;
				break;
			}
		}
		if (a == '}')
		{
			if ('{' == first.top())
			{
				first.pop();
			}
			else
			{
				std::cout << "No" << std::endl;
				break;
			}
		}
		if (a == ']')
		{
			if ('[' == first.top())
			{
				first.pop();
			}
			else
			{
				std::cout << "No" << std::endl;
				break;
			}
		}
	}
	

	//������� 
	/*
	��������� �������.
	���� ��� (,[ ��� {, �� �������� �� � ����.
	���� ��� ),] ��� }, �� ���������� � ������� ��������� �����.
	���� ������������ ����, �� ������� ������� ����� �������.
	����� - ��������� ������������.

	����� ��� �������� �������, �� ��������� ���� �� �������.
	���� ���� ����, �� ��������� ����������.
	����� - ��������� ������������.
	*/

	/*
	������� � ��� ��������� ������, ������� ��������� �� ��������
	LILO (last in � last out: ��������� ������ � ��������� �����).
	*/
	/*
std::queue <int> MyQueue; // ������� �������
std::cout << "������� 7 �����: " << std::endl;
for (i = 0; i < 7; i++) {
	std::cin >> a;
	MyQueue.push(a); // ��������� � ������� ��������
}
std::cout << std::endl;
std::cout << "������ ������� � �������: " << MyQueue.front() << std::endl;
MyQueue.pop(); // ������� ������� �� �������
std::cout << "������ ������� (����� ��������): " << MyQueue.front() << std::endl;

if (!MyQueue.empty()) // ��������� ����� �� ������� (���)
	std::cout << "������� �� �����!";
			*/
			/*
			������� � ����������� (priority_queue) � ��� ������� �������,
			�� � ��� ����� ������� ����������� � ����� �����,
			����� ������� ���� ������������� �� ��������.
			*/

			//std::priority_queue <int> priority_q; // ��������� ������������ ������� 

			//std::cout << "������� 7 �����: " << std::endl;
			//for (i = 0; i < 7; i++) {
				//std::cin >> a;
				//priority_q.push(a); // ��������� �������� � ������� 
				//std::copy(MyQueue.front(), MyQueue.back(), std::ostream_iterator<int>(cout, " "));
			//}
			// ������� ������ 
			//std::cout << "������ ������� �������: " << priority_q.top();

			// ������� 2 
			/*
			��������� �� ���� �������� ������ ����������.
			� ������ ������ ������� ������� ����� ������ (�����, ������ 9, 10 ��� 11),
			����� (����� ������) � �������.
			���������� ������� ������ �� �������:
			������� ���� �������� 9 ������, ����� � 10, ����� � 11.
			������ ������ ������ ������� ������ ������ ���� ����� ��, ��� �� �����.
			*/

			/*
			������� 3 ������� (���� ��� ������� ������).

			��������� ��������� ������. � ����������� �� ������
			��������� ������� � ��������������� �������

			����� ��� �������, ������� ������� ���������������:

			������� ��� 9 ������, ����� ������� 10 ������,
			� � ����� ����� ������� 11 ������.
			*/
	std::queue <std::string> s9;
	std::queue <std::string> s10;
	std::queue <std::string> s11;
	std::string buf;
	int num;
	std::cin >> num;
	for (;;)
	{
		if (num == 0) break;
		getline(std::cin, buf);
		switch (num)
		{
		case 9:
			s9.push(buf);
			break;
		case 10:
			s10.push(buf);
			break;
		case 11:
			s11.push(buf);
			break;
		}
		std::cin >> num;
	}
	std::cout << '9' << std::endl;
	while (!s9.empty())
	{
		std::cout << s9.front() << std::endl;
		s9.pop();
	}
	std::cout << "10" << std::endl;
	while (!s10.empty())
	{
		std::cout << s10.front() << std::endl;
		s10.pop();
	}
	std::cout << "11" << std::endl;
	while (!s11.empty())
	{
		std::cout << s11.front() << std::endl;
		s11.pop();
	}

			/*
			����� (����. deque � ������������ �� double-ended queue, ������������� �������)
			���������� ��������� ������, � ������� �����
			*/
			//������ 3 
		/*
		���������, �������� �� ��������� ������ �����������
		(�������� ��������� ����� ������� � ������ ������). ������������ ���.
		*/
	std::deque <char> th;
	char sym;
	bool ch = true;
	std::cin >> sym;
	while (true)
	{
		if (sym == '0')
		{
			break;
		}
		th.push_front(sym);
		std::cin >> sym;
	}
	while (!th.empty())
	{
		if (th.front() != th.back())
		{
			std::cout << "Not polyndrom";

			ch = false;
			break;
		}
		th.pop_back();
		if (!th.empty()) th.pop_front();
	}
	if (ch)
	{
		std::cout << "Correct, polyndrom" << std::endl;
	}
		/*

		��������� ������ �����������. ������ ������ ��������� � ����� ����.
		����� ���������� ������ � ��������� ������ ����.
		*/

		//������ 4 
		/*
		������� ��������� ������ List.
		������������������ ������ � ���� ����������:
		����, �����,
		���������� �������� � ��������,
		����������.
		*/

	std::list <int> fourth;
	std::list<int>::iterator it;
	std::cout << "Input" << std::endl;
	fourth.push_front(15);
	std::cin >> fourth.front();
	std::cout << "Output" << fourth.front() << std::endl;
	fourth.push_back(18);
	fourth.pop_front();
	for (int i = 0; i < 5; i++)
	{
		fourth.push_front(rand() % 100);
	}
	fourth.sort();
	for (it = fourth.begin(); it != fourth.end(); ++it) 
	{
		std::cout << *it << ' ';
	}
		//������ 5 
		/*
		������� ��������� ������ Set.
		������������������ ������ � ���� ����������:
		����, �����,
		���������� �������� � ��������.
		*/
	std::set <int> fith;
	std::set<int>::iterator it_set;
	fith.insert(18);
	fith.insert(19);
	fith.insert(20);
	fith.erase(18);
	for (it_set = fith.begin(); it_set != fith.end(); ++it)
	{
		std::cout << *it << ' ';
	}

		//������ 6 
		/*
		������� ��������� ������ map.
		������������������ ������ � ���� ����������:
		����, �����,
		���������� �������� � ��������.
		*/
	std::map<char, int> sixth;
	std::cout << "Input" << std::endl;
	std::cin >> sixth['a'];
	std::cout << "Output " << sixth['a'] << std::endl;
	sixth['b'] = 20;
	sixth.erase('a');
		// ������ 7 
		/*
		��������� ������� ��������� �� ������� ���������� ��������
		��� ����, �����, �������, ������, ���������, ������� �� n ���������.
		������ ��������:
		���������� � ������
		���������� � �����
		���������� � ��������
		�������� �� ������
		�������� � �����
		�������� �� ��������
		�������� �������� �� ������
		�������� �������� � �����
		�������� �������� �� ��������
		*/
	system("pause");
	return 0;
}