#pragma once
#include "Res.h"

void LogicCleanBuffer();
void LogicSafeInput(int& value, int min, int max);
void LogicInputData(Res*& res, int index);

void LogicAdd(Res*& res, int& size);
void LogicRemove(Res*& res, int& size, int index);

void LogicSaveData(FILE* file, Res*& res, const char* filename, int size);
void LogicReadData(FILE* file, Res*& res, const char* filename, int& size);