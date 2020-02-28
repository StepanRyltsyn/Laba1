#pragma once
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node*next; //ссылка на след элемент
};
class Queue
{
private:
	Node*q; //сама очередь
	Node*tail;
	int size; //размер очереди 
public:
	int getsize();
	Queue();
	~Queue();
	void push(int n);
	/*void pushback(int n);*/
	int pop();
	void print();
	Queue*copy();
	Queue*merge(Queue*queue);//функция для слияния двух очередей 
	bool isempty();//проверяем пустая очередь или нет
	double getavg();//среднее арифм
	int countOver(double value);//считает кол-во элментов, больше зн
};

