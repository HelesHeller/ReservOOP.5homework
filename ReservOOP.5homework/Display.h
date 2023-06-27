#pragma once
#include "Res.h"


void DisplayMenu(const char* menu[], int row, int select);

void DisplayAdd(Res*& res, int& size);
void DisplayPrint(const Res* res, int size);
void DisplayRemove(Res*& res, int& size);
void DisplayEdit(Res*& res, int size);