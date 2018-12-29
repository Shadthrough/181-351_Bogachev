#include <iostream>
/*
int max(int * arr)
{
	int res;
	int temp = arr[0];
	int len = sizeof(arr);
	for (int i = 0; i <= len; i++)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
		}
	}
	res = temp;
	return res;
}
char max(char * arr)
{
	char res;
	char temp = arr[0];
	int len = sizeof(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
		}
	}
	res = temp;
	return res;
}
double max(double arr[])
{
	double res;
	double temp = arr[0];
	int len = sizeof(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
		}
	}
	res = temp;
	return res;
}
*/
/*
template<typename TT>
class myList
{
public:
	TT element;
	myList * prev;
	myList * next;

	myList();
	myList(TT el);
	~myList();

	void push_back(TT new_elem);
	void print();
};

template<typename TT>
void myList<TT>::push_back(TT new_elem)
{
	myList<TT> *tmp = new myList<TT>;//ptr on a new elem
	myList<TT> *tmp1 = new myList<TT>;//ptr on a current elem
	this->next = tmp;// changing ptr on next elem
	*tmp1 = *this;

	tmp->element = new_elem;	//
	tmp->prev = tmp1;			//	ASK A QESTION HERE!!!!!!!!!!!!!!!!!!!!!
	tmp->next = NULL;			//

	this->element = tmp->element;
	this->prev = tmp->prev;
	this->next = NULL;
}

template<typename TT>
void myList<TT>::print()
{
	myList<TT> *tmp = new myList<TT>;
	*tmp = *this;
	while (tmp->prev != NULL)
	{
		*tmp = *tmp->prev;
	}
	while (tmp->next != NULL)
	{
		std::cout << tmp.element << '\t';
		*tmp = *tmp->next;
	}
	std::cout << tmp->element << '\t';
}
*/
/*
template<typename TT>
myList<TT>::myList()
{
	prev = NULL;
	next = NULL;
}

template<typename TT>
myList<TT>::myList(TT el)
{
	prev = NULL;
	next = NULL;
	element = el;
}

template<typename TT>
myList<TT>::~myList()
{
	delete next;
	delete prev;
}*/

//				Trees
class tree
{
private:
	char *elem;
	tree * rptr;
	tree * lbptr;
	tree * root;
public:
	tree();
	tree(bool r);
	tree(char * el, bool r);
	~tree();
	//void write(char * el);
	//void add_here(tree * son);
	void add_bot(char* el);
	void print();
	void print(tree * ptr, int i);
};


tree::tree()
{
	rptr = NULL;
	lbptr = NULL;
}
tree::tree(bool r)
{
	rptr = NULL;
	lbptr = NULL;
	if (r) root = NULL;
}
tree::tree(char * el, bool r)
{
	rptr = NULL;
	lbptr = NULL;
	elem = el;
	if (r) root = NULL;
}
tree::~tree()
{
	//delete rptr;
	//delete lbptr;
}
/*
void tree::write(char * el)
{
	this->elem = el;
}

void tree::add_here(tree * son)
{
	son->root = NULL;
	if (this->lbptr != NULL)
	{
		tree * temp = nullptr;
		temp = this->lbptr;
		while (temp->rptr != NULL)
		{
			temp = temp->rptr;
		}
		temp->rptr = son;
	}
	else
	{
		this->lbptr = son;
	}
}
*/
void tree::add_bot(char* el)
{
	tree * tmp = new tree;//next
	tree * tmp1 = new tree;//curr
	this->lbptr = tmp;
	*tmp1 = *this;

	tmp->elem = el;
	tmp->root = tmp1;
	
	//this->lbptr = NULL;
	//this->rptr = NULL;
	this->root = tmp->root;
	this->elem = tmp->elem;
}

void tree::print()
{
	//tree * tmp;
	//*tmp = *this;// remove tmp afterwords
	std::cout << root->elem << "\n|\nv\n";
	if (root->lbptr != NULL) print(root->lbptr, 0);
}

void tree::print(tree * ptr, int i)
{
	std::cout << ptr->elem;
	if (ptr->rptr != NULL)
	{
		std::cout << "\t->\t";
		print(ptr->rptr, i + 1);
	}
	if (ptr->lbptr != NULL)
	{
		//for (int j = 0; j <= i; j++)
		//{
			//std::cout << ""
		//}	
		std::cout << "\n";
		for (int j = 0; j < i * 2; j++) std::cout << '\t';
		std::cout << "|\n";
		for (int j = 0; j < i * 2; j++) std::cout << '\t';
		std::cout << "v\n";
		for (int j = 0; j < i * 2; j++) std::cout << '\t';
		print(ptr->lbptr, i);
	}
}

int main()
{
	//int a[10] = {5, 2, 3, 4, 5, 6, 7, 8, 9, 8};
	//std::cout << max(a);

	//myList<int> li(5);
	//li.push_back(4);
	//li.push_back(7); 
	//li.print();
	
	tree rt((char *) "root", 1);
	/*
	rt.write((char*)"root");
	tree lv1_1((char*)"lv1_1");
	tree lv1_2((char*)"lv1_2");
	tree lv1_3((char*)"lv1_3");
	rt.add_here(&lv1_1);
	rt.add_here(&lv1_2);
	rt.add_here(&lv1_3);
	tree lvl2_1((char*)"lvl2_1");
	lv1_3.add_here(&lvl2_1);
	rt.print();
	*/
	rt.add_bot((char*)"lv1_1");
	rt.add_bot((char*)"?");
	rt.add_bot((char*)"??");
	rt.print();
	getchar();
	return 0;
}
