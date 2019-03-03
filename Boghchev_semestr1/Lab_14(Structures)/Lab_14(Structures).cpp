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
#include <stack> // подключаем библиотеку для использования стека 
#include <queue> // подключили библиотеку для использования очереди 
#include <deque> // подключили библиотеку для использования дека 


#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива


int main()
{
	setlocale(LC_ALL, "rus");
	/*
	Стек — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).

	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.

	Достоинство: операции удаления и добавления элемента делаются за const время.

	*/
	/*
std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека
int i = 0, a = 0;
std::cout << "Введите 5 целых чисел: " << std::endl;
while (i != 5) {
	std::cin >> a;
	stackInt.push(a); // добавляем введенное число
	i++;
}

if (stackInt.empty()) // проверяем пуст ли стек (нет)
	std::cout << "Стек не пуст";

std::cout << "Верхний элемент стека: " << stackInt.top() << std::endl;
stackInt.pop(); // удаляем верхний элемент

std::cout << "Новый верхний элемент: " << stackInt.top()<< std::endl;
			*/
			// ЗАДАНИЕ 1 
			/*
			Проверить правильность расстановки скобок (,),[,],{,}
			в введенном пользователем выражении за линейное время
			(один просмотр выражения).
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
	

	//решение 
	/*
	Считываем элемент.
	Если это (,[ или {, то помещаем ее в стек.
	Если это ),] или }, то сравниваем с верхним элементом стека.
	Если образовалась пара, то верхний элемент стека удаляем.
	Иначе - выражение неправильное.

	Когда все элементы считали, то проверяем стек на пустоту.
	Если стек пуст, то выражение правильное.
	Иначе - выражение неправильное.
	*/

	/*
	Очередь — это структура данных, которая построена по принципу
	LILO (last in — last out: последним пришел — последним вышел).
	*/
	/*
std::queue <int> MyQueue; // создали очередь
std::cout << "Введите 7 чисел: " << std::endl;
for (i = 0; i < 7; i++) {
	std::cin >> a;
	MyQueue.push(a); // добавляем в очередь элементы
}
std::cout << std::endl;
std::cout << "Первый элемент в очереди: " << MyQueue.front() << std::endl;
MyQueue.pop(); // удаляем элемент из очереди
std::cout << "Первый элемент (после удаления): " << MyQueue.front() << std::endl;

if (!MyQueue.empty()) // проверяем пуста ли очередь (нет)
	std::cout << "Очередь не пуста!";
			*/
			/*
			Очередь с приоритетом (priority_queue) — это обычная очередь,
			но в ней новый элемент добавляется в такое место,
			чтобы очередь была отсортирована по убыванию.
			*/

			//std::priority_queue <int> priority_q; // объявляем приоритетную очередь 

			//std::cout << "Введите 7 чисел: " << std::endl;
			//for (i = 0; i < 7; i++) {
				//std::cin >> a;
				//priority_q.push(a); // добавляем элементы в очередь 
				//std::copy(MyQueue.front(), MyQueue.back(), std::ostream_iterator<int>(cout, " "));
			//}
			// выводим первый 
			//std::cout << "Первый элемент очереди: " << priority_q.top();

			// ЗАДАНИЕ 2 
			/*
			Программа на вход получает список школьников.
			В каждой строке сначала записан номер класса (число, равное 9, 10 или 11),
			затем (через пробел) – фамилия.
			Необходимо вывести список по классам:
			сначала всех учащихся 9 класса, затем – 10, затем – 11.
			Внутри одного класса порядок вывода должен быть таким же, как на входе.
			*/

			/*
			Создаем 3 очереди (свою для каждого класса).

			Считываем очередную строку. В зависимости от класса
			добавляем фамилию в соответствующую очередь

			Когда все считали, выводим очереди последовательно:

			сначала для 9 класса, затем очередь 10 класса,
			а в самом конце очередь 11 класса.
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
			Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь)
			называется структура данных, в которую можно
			*/
			//ЗАДАЧА 3 
		/*
		Проверить, является ли введенная строка палиндромом
		(читается одинаково слева направо и справа налево). Использовать дек.
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

		Считываем строку посимвольно. каждый символ добавляем в хвост дека.
		Далее сравниваем первый и последний символ дека.
		*/

		//ЗАДАЧА 4 
		/*
		Описать структуру данных List.
		Продемонстрировать работу с этой структурой:
		ввод, вывод,
		добавление элемента и удаление,
		сортировка.
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
		//ЗАДАЧА 5 
		/*
		Описать структуру данных Set.
		Продемонстрировать работу с этой структурой:
		ввод, вывод,
		добавление элемента и удаление.
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

		//ЗАДАЧА 6 
		/*
		Описать структуру данных map.
		Продемонстрировать работу с этой структурой:
		ввод, вывод,
		добавление элемента и удаление.
		*/
	std::map<char, int> sixth;
	std::cout << "Input" << std::endl;
	std::cin >> sixth['a'];
	std::cout << "Output " << sixth['a'] << std::endl;
	sixth['b'] = 20;
	sixth.erase('a');
		// ЗАДАЧА 7 
		/*
		Составить таблицу сравнения по времени выполнения операций
		для дека, стека, очереди, списка, множества, массива из n элементов.
		Список операций:
		добавление в начало
		добавление в конец
		добавление в середину
		удаление из начала
		удаление с конца
		удаление из середины
		значение элемента из начала
		значение элемента с конца
		значение элемента из середины
		*/
	system("pause");
	return 0;
}