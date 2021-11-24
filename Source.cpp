/*Даны два массива A и B размера N, элементы которых упорядочены по
возрастанию1|убыванию2. Объединить эти массивы так, чтобы результирующий
массив остался упорядоченным.*/

#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int chek = 1;
	while (chek == 1)
	{
		cout << "Выберите действие (1 - расчёт, 0 - остановка)" << endl;
		cin >> chek;
		switch (chek)
		{
		case(0):
		{
			cout << "Программа завершена" << endl;
			break;
		}
		case(1):
		{
			int size;
			cout << "Введите количество элементов массивов ";
			cin >> size;
			cout << endl;
			int* arrA = new int[size]; // динамический массив
			int* arrB = new int[size];
			int i;
			srand(time(NULL)); // база, для того чтобы послед. была разной

			cout << "Упорядочение по возрастанию" << endl;

			for (i = 0; i < size; i++)
			{
				arrA[i] = rand() % 100;// заполнение масива рандомными цифрами в промежутке от 0 до 100
			}

			int temp;
			for (int i = 0; i < size - 1; i++) {//упорядочение по возрастанию
				for (int j = 0; j < size - i - 1; j++) {
					if (arrA[j] > arrA[j + 1]) {

						temp = arrA[j];
						arrA[j] = arrA[j + 1];
						arrA[j + 1] = temp;
					}
				}
			}
			cout << "Упорядоченный массив A" << endl;
			for (int i = 0; i < size; i++) { // вывод массива
				cout << arrA[i] << " ";
			}
			cout << endl;
			for (i = 0; i < size; i++)
			{
				arrB[i] = rand() % 100;
			}

			int k;
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (arrB[j] > arrB[j + 1]) {

						k = arrB[j];
						arrB[j] = arrB[j + 1];
						arrB[j + 1] = k;
					}
				}
			}
			cout << "Упорядоченный массив B" << endl;
			for (int i = 0; i < size; i++) {
				cout << arrB[i] << " ";
			}
			cout << endl;
			cout << "Массив С" << endl; // объединение массива А и В с сортировкой
			int s = 2 * size;
			int* arrC = new int[s];
			int l = 0, n = 0, m = 0;
			while (n < size && m < size)
			{
				if (arrA[n] < arrB[m]) {
					arrC[l] = arrA[n];
					l++; n++;
				}
				else {
					arrC[l] = arrB[m];
					l++; m++;
				}
			}

			while (n < size)
				arrC[l++] = arrA[n++];
			while (m < size)
				arrC[l++] = arrB[m++];

			for (int i = 0; i < s; i++) // Вывод объединённого массива
				cout << arrC[i] << " ";
			cout << endl << endl;




			cout << "Упорядочение по убыванию" << endl;

			int k2;
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (arrA[j] < arrA[j + 1]) {

						k2 = arrA[j];
						arrA[j] = arrA[j + 1];
						arrA[j + 1] = k2;
					}
				}
			}
			cout << "Упорядоченный массив A" << endl;
			for (int i = 0; i < size; i++) {
				cout << arrA[i] << " ";
			}
			cout << endl;


			int k4;
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (arrB[j] < arrB[j + 1]) {

						k4 = arrB[j];
						arrB[j] = arrB[j + 1];
						arrB[j + 1] = k4;
					}
				}
			}
			cout << "Упорядоченный массив B" << endl;
			for (int i = 0; i < size; i++) {
				cout << arrB[i] << " ";
			}
			cout << endl;
			cout << "Массив D" << endl;
			int s2 = 2 * size;
			int* arrD = new int[s2];
			int l2 = 0, n2 = 0, m2 = 0;
			while (n2 < size && m2 < size)
			{
				if (arrA[n2] > arrB[m2]) {
					arrD[l2] = arrA[n2];
					l2++; n2++;
				}
				else {
					arrD[l2] = arrB[m2];
					l2++; m2++;
				}
			}
			while (n2 < size)
				arrD[l2++] = arrA[n2++];
			while (m2 < size)
				arrD[l2++] = arrB[m2++];

			for (int i = 0; i < s2; i++)
				cout << arrD[i] << " ";
			cout << endl << endl;

			break;
		}

		default:
		{
			cout << "Неправильно введеные данные" << endl;
			chek = 1;
			continue;
		}

		}

	}
}