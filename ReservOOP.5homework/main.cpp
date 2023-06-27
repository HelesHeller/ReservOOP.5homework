#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Res.h"
#include"global.h"
#include "Log.h"
#include "Display.h"

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 0;
	Res* res = new Res[size];

	char filename[MAX_PATH] = "save.bin";
	FILE* file = nullptr;
	LogicReadData(file, res, filename, size);

	char select = 0;

	const char* menu[]
	{
		"Додати водойму     ",
		"Вивести список     ",
		"Видалити водойму   ",
		"Редагувати         ",
		"Вихід              "
	};

	while (true) {

		DisplayMenu(menu, MENU_ROW, select);

		char action = _getch();
		if (action == 0 || action == 224)
			action = _getch();

		switch (action) {

		case UP:
			select = (select - 1 + MENU_ROW) % MENU_ROW;
			break;

		case DOWN:
			select = (select + 1) % MENU_ROW;
			break;

		case ENTER:
			switch (select) {

			case ADD:
				DisplayAdd(res, size);
				break;

			case PRINT:
				DisplayPrint(res, size);
				break;

			case REMOVE:
				DisplayRemove(res, size);
				break;

			case EDIT:
				DisplayEdit(res, size);
				break;

			case EXIT:
				LogicSaveData(file, res, filename, size);
				delete[]res;
				return 0;
			}
			break;

		case ESC:
			LogicSaveData(file, res, filename, size);
			delete[]res;
			return 0;
		}
	}

	return 0;
}