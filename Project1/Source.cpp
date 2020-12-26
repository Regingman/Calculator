#include <iostream> 
#include <conio.h> 
#include <cmath> 
#include <cstring>
using namespace std;
//ОПЗ запись с++
struct stack {
	int x;
	stack* next;
};
void dob(stack*& a, int x) {
	if (a == NULL) {
		stack* pv = new stack;
		pv->x = x;
		pv->next = NULL;
		a = pv;
		pv = NULL;
		delete pv;

	}
	else {
		stack* pv = new stack;
		pv->x = x;
		pv->next = a;
		a = pv;
		pv = NULL;
		delete pv;

	}
};
int main()
{
	stack* stock = NULL;
	stack* abb = NULL;
	setlocale(LC_ALL, "Russian");
	int i = 0, s = 0, e = 0, n1 = 0, v = 0, ch, s2 = 0;
	char vr[100], stek[100], exit[100];


	cout << "Введите выражение: \n";
	cin >> vr;

	for (i = 0; vr[i] != '\0'; i++)
		switch (vr[i])
		{
		case '+':
			while ((s != 0) && (stek[s - 1] != '('))
			{
				exit[e] = stek[s - 1]; //на выход 
				e++;
				s--;
			}
			stek[s] = '+'; //в стек 
			s++;
			break;
		case '-':
			if (i == 0) {
				while ((s != 0) && (stek[s - 1] != '('))
				{
					exit[e] = stek[s - 1];
					e++;
					s--;
				}
				stek[s] = '!';
				s++;
			}
			else
				if (vr[i - 1] > 48 && vr[i - 1] < 58 || vr[i - 1] == ')') {
					while ((s != 0) && (stek[s - 1] != '('))
					{
						exit[e] = stek[s - 1];
						e++;
						s--;
					}
					stek[s] = '-';
					s++;
				}
				else {
					while ((s != 0) && (stek[s - 1] != '('))
					{
						exit[e] = stek[s - 1];
						e++;
						s--;
					}
					stek[s] = '!';
					s++;
				}
			break;
		case '*':

			while ((s != 0) && (stek[s - 1] != '(') && (stek[s - 1] != '+') && (stek[s - 1] != '-'))
			{
				exit[e] = stek[s - 1];
				e++;
				s--;
			}
			stek[s] = '*';
			s++;
			break;
		case '/':

			while ((s != 0) && (stek[s - 1] != '(') && (stek[s - 1] != '+') && (stek[s - 1] != '-'))
			{
				exit[e] = stek[s - 1];
				e++;
				s--;
			}
			stek[s] = '/';
			s++;

			break;
		case '(':
		{
			stek[s] = '(';
			s++;
			break; }
		case ')':


			while ((stek[s - 1] != '(') && (s != 0))
			{

				exit[e] = stek[s - 1];
				e++;
				s--;
			}
			stek[s - 1] = ' ';
			s--;
			break;
		default:
		{
			exit[e] = vr[i];
			e++;
			if ((vr[i + 1] == '+') || (vr[i + 1] == '-') || (vr[i + 1] == '*') || (vr[i + 1] == '/') || (vr[i + 1] == '(') || (vr[i + 1] == ')'))
			{
				exit[e] = ' ';
				e++;
			}
		}
		}

	exit[e] = ' ';
	e++;

	int a, b, flag = 0;
	int z = 0, y = 1, q = 10;
	while (s != 0)
	{
		exit[e] = stek[s - 1];
		e++;
		s--;
	}
	for (i = 0; i < e; i++)
	{
		if (exit[i] == ')' || exit[i] == '(')
			e = 0;
	}
	if (e == 0) {
		cout << "Неверно введено выражение" << endl;
	}
	else {
		cout << "Обратно польская нотация(ОПН): ";
		for (i = 0; i < e; i++)
		{
			cout << exit[i];
		}
		cout << endl;
		cout << "Последовательность действий: " << endl;
		for (i = 0; i < e; i++)
		{
			switch (exit[i]) {
			case '*': {
				if (stock->next != NULL) {
					a = stock->next->x;
					b = stock->x;
					cout << "Шаг " << y << ": " << a << " * " << b << " = " << a * b << endl;
					y++;
					stock->x = a * b;
					stock->next = stock->next->next;
				}
				else {
					cout << "Шаг " << y << " Ошибка компиляции, одна из операнд не определена" << endl;
					i = e + 1;
					flag = 1;
				}
				break;
			}
			case '-': {
				if (stock->next != NULL) {
					a = stock->next->x;
					b = stock->x;
					cout << "Шаг " << y << ": " << a << " - " << b << " = " << a - b << endl;
					y++;
					stock->x = a - b;
					stock->next = stock->next->next;
				}
				else {
					cout << "Шаг " << y << "Ошибка компиляции,   одна из операнд не определена" << endl;
					i = e + 1;
					flag = 1;
				}
				break;
			}
			case '/': {
				if (stock->next != NULL) {
					a = stock->next->x;
					b = stock->x;
					cout << "Шаг " << y << ": " << a << " / " << b << " = " << a / b << endl;
					y++;
					stock->x = a / b;
					stock->next = stock->next->next;
				}
				else {
					cout << "Шаг " << y << "Ошибка компиляции, одна из операнд не определена" << endl;
					i = e + 1;
					flag = 1;
				}
				break;
			}
			case '+': {
				if (stock->next != NULL) {
					a = stock->next->x;
					b = stock->x;
					cout << "Шаг " << y << ": " << a << " + " << b << " = " << a + b << endl;
					y++;
					stock->x = a + b;
					stock->next = stock->next->next;
				}
				else {
					cout << "Шаг " << y << "Ошибка компиляции,  одна из операнд не определена" << endl;
					i = e + 1;
					flag = 1;
				}
				break;
			}
			case '!': {
				if (stock != NULL) {
					a = stock->x;
					cout << "Шаг " << y << ": Преобразование числа в отрицательное " << a << " * -1 = " << a * (-1) << endl;
					y++;
					stock->x = a * (-1);
				}
				else {
					cout << "Шаг " << y << "Ошибка компиляции операнд нет вообще" << endl;
					i = e + 1;
					flag = 1;
				}
				break;
			}
			case ' ':
				break;

			default: {
				if (exit[i] > 48 && exit[i] < 58) {
					dob(stock, exit[i] - 48);
					while (exit[i + 1] != ' ') {
						stock->x = stock->x * q + (exit[i + 1] - 48);
						i++;
						q *= 10;
					}
					q = 10;
				}
				else {
					cout << "Шаг " << y << " Ошибка компиляции, неверно введена операнда" << endl;
					i = e + 1;
					flag = 1;
				}

			}

			}
		}
		if (flag == 0)
			cout << "Ответ: " << stock->x << endl;
	}
	system("pause");
	return 0;
}