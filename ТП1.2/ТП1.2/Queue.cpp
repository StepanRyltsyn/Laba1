#include "Queue.h"


int Queue::getsize()
{
	return this->size;
}

Queue::Queue()
{
	this->q = nullptr;//обнулили очередь 
	this->size = 0;
}

Queue::~Queue()
{
}

void Queue::push(int n)
{
	Node*e = new Node;//создаи экземпл€р структуры
	e->data = n;//заполнили данными элемент
	e->next = nullptr;//иницилизаци€ ссылки
	if (this->q == nullptr)
	{
		this->q = e;//присвоили к очереди новый элемент 
		this->tail = e;//в указатель на последний элем присвоили текущий 
	}
	else
	{
		this->tail->next = e;//к последнему элем сделали ссылку на новый элем
		this->tail = e;//переместиили ссылку на наш элем
	}
	size++;
}

/*void Queue::pushback(int n)
{
	Node*e = new Node;//создаи экземпл€р структуры
	e->data = n;//заполнили данными элемент
	e->next = nullptr;//иницилизаци€ ссылки
	if (this->q == nullptr)
	{
		this->q = e;//присвоили к очереди новый элемент 
		this->tail = e;//в указатель на последний элем присвоили текущий 
	}
	else
	{
		e->next = this->q;//добавление в начало очереди 
		this->q = e;
	}
}*/

int Queue::pop()
{
	int r = q->data;//заполнили данные начала очереди 
	Node*tmp = q;//заполили первый элемент
	this->q = this->q->next;//передвинули указатель начала на один элем вперед
	delete tmp;//освобождаем пам€ть 
	size--;
	return r;
}

void Queue::print()
{
	Node*tmp = this->q; //дл€ того, чтобы не уничтожить всю очередь
	while (tmp != nullptr)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;//смещаем ссылку на один элемент вперед 
	}
}

Queue * Queue::copy()
{
	Queue*queue = new Queue();
	Node*tmp = this->q;
	while (tmp != nullptr)
	{
		queue->push(tmp->data);
		tmp = tmp->next;//смещаем ссылку на один элемент вперед 
	}
	return queue;
}

Queue * Queue::merge(Queue * queue)
{
	Queue*result = new Queue();
	Node*tmp = this->q;
	while (tmp != nullptr)
	{
		result->push(tmp->data);
		tmp = tmp->next;//смещаем ссылку на один элемент вперед 
	}
	Queue*t = queue->copy();//создаЄм копию, чтобы не уничтожать исход очередь 
	while (!t->isempty())
	{
		result->push(t->pop());
	}
	return result;
}

bool Queue::isempty()
{
	return this->q == nullptr;
}

double Queue::getavg()
{
	int sum = 0;
	Node*tmp = this->q;
	while (tmp != nullptr)
	{
		sum += tmp->data;
		tmp = tmp->next;
	}
	return (double)sum/size;
}

int Queue::countOver(double value)
{
	Node*tmp = this->q;
	int result = 0;
	
	while (tmp != nullptr)
	{
		if (tmp->data > value)
			result++;
		tmp = tmp->next;
	}
	return 0;
}


