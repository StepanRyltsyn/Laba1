#include "Queue1.h"
using namespace std;
void main()
{   
	//�������� ������ � ����������� 
	Queue1*q = new Queue1();//������ ���������� �������
	Queue*qcpy = new Queue1();//������ ���������� �������
	


	/*Queue*q1=new Queue();//������ �������
	Queue*q2 = new Queue();
	q->push(1);
	q->push(2);
	q->push(3);
	q1 = q->copy();
	q2 = q1->merge(q);
	q2->print();
	//->print();
	q->print();*/
	int n;
	int count=0;
	float sum=0;
	setlocale(LC_ALL, "Russian");
	bool isrun = true;
	int action;
	while (isrun)
	{
		cout << "1-��������� �������� �������" << endl;
		cout << "2-���������� �������� �� �������" << endl;
		cout << "3-����� ������� �� �����" << endl;
		cout << "4-���������� ��������" << endl;
		cout << "5-�������� ����� �������" << endl;
		cout << "6-������� ������������ ������� � ������ � ����� ���������� �� �����" << endl;
		cout << "7-����� �� ���������" << endl;
		cin >> action;
		switch (action)
		{
		case 1:
			cout << "������� ���������� ��������� �������: ";
			cin >> n;
			cout << "������� �������: " << endl;
			for (int i = 0; i < n; i++)
			{
				int a;
				cin >> a;
				q->push(a);
			}
				break;
		case 2:
			cout<<q->pop()<<endl;
			break;
		case 3:
			q->print();
			cout << endl;
			break;
		case 4:
			q->function();
			cout << endl;
			break;
		case 5:
			qcpy=q->copy();
			cout <<"������� �����������"<< endl;
			break;
		case 6:
			(q->merge(q))->print();
			cout << endl;
			break;
		case 7:
			isrun=0;
			break;
		}
	}
	system("pause");
}
