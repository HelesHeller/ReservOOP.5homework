#include "Display.h"
#include "Log.h"
#include <iostream>

using namespace std;

void DisplayMenu(const char* menu[], int row, int select) {

	char marker = 149;
	system("cls");

	for (int i = 0; i < row; i++) {

		if (i == select) {

			cout << " " << marker << " ";
			cout << menu[i] << endl;
		}

		else {

			cout << "   ";
			cout << menu[i] << endl;
		}
	}
}

void DisplayAdd(Res*& res, int& size) {

	system("cls");

	LogicCleanBuffer();
	LogicAdd(res, size);

	system("pause");
}

void DisplayPrint(const Res* res, int size) {

	system("cls");

	if (size != 0) {

		for (int i = 0; i < size; i++) {

			cout << "-- ВОДОЙМА №[" << i + 1 << "] --" << endl;
			res[i].Print();
			cout << "___________________" << endl;
		}
	}

	else
		cout << "список пустий.." << endl << endl;

	system("pause");
}

void DisplayRemove(Res*& res, int& size) {

	system("cls");

	if (size != 0) {

		DisplayPrint(res, size);

		system("cls");
		int index;
		cout << "введіть номер водойми для видалення: ";
		LogicSafeInput(index, 1, size);
		index -= 1;

		LogicRemove(res, size, index);
	}

	else
		cout << "список пустий.." << endl << endl;

	system("pause");
}

void DisplayEdit(Res*& res, int size) {

	system("cls");

	if (size != 0) {

		DisplayPrint(res, size);

		system("cls");
		int index;
		cout << "введіть номер водойми для редагування: ";
		LogicSafeInput(index, 1, size);
		index -= 1;

		LogicCleanBuffer();
		LogicInputData(res, index);
	}

	else
		cout << "список пустий.." << endl << endl;

	system("pause");
}