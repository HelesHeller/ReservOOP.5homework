#include "Log.h"


void LogicCleanBuffer() {

    if (cin.rdbuf()->in_avail() != 0) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}

void LogicSafeInput(int& value, int min, int max) {

    while (!(cin >> value) || value < min || value > max) {
        cout << "помилка, невірно задане значення.. спробуйте знову: ";
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
}

void LogicInputData(Res*& res, int index) {

    char type[20];
    int width;
    int length;
    int depth;

    cout << "введіть тип водойми: ";
    cin.getline(type, 20);
    res[index].SetType(type);

    cout << "введіть ширину водойми: ";
    LogicSafeInput(width, 1, 5000);
    res[index].SetWidth(width);

    cout << "введіть довжину водойми: ";
    LogicSafeInput(length, 1, 5000);
    res[index].SetLength(length);

    cout << "введіть глибину водойми: ";
    LogicSafeInput(depth, 1, 5000);
    res[index].SetDepth(depth);
}

void LogicAdd(Res*& res, int& size) {

    Res* temp = new Res[size + 1];

    for (int i = 0; i < size; i++)
        temp[i] = res[i];
    LogicInputData(temp, size);

    delete[] res;
    res = temp;
    size++;
}

void LogicRemove(Res*& res, int& size, int index) {

    Res* temp = new Res[size];
    int j = 0;

    for (int i = 0; i < size; i++)
        if (i != index) {
            temp[j] = res[i];
            j++;
        }

    delete[] res;
    res = temp;
    size--;
}

void LogicSaveData(FILE* file, Res*& res, const char* filename, int size) {

    const int type_size = 20;

    fopen_s(&file, filename, "wb");

    if (file == nullptr) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    fwrite(&size, sizeof(size), 1, file);

    for (int i = 0; i < size; i++) {

        const char* type = res[i].GetType();
        int width = res[i].GetWidth();
        int length = res[i].GetLength();
        int depth = res[i].GetDepth();

        fwrite(type, sizeof(char), type_size, file);
        fwrite(&width, sizeof(width), 1, file);
        fwrite(&length, sizeof(length), 1, file);
        fwrite(&depth, sizeof(depth), 1, file);
    }

    fclose(file);
}


void LogicReadData(FILE* file, Res*& res, const char* filename, int& size) {

    const int type_size = 20;

    fopen_s(&file, filename, "rb");

    if (file == nullptr) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    fread(&size, sizeof(size), 1, file);

    Res* data = new Res[size];

    for (int i = 0; i < size; i++) {
        char type[type_size];
        int width, length, depth;

        fread(type, sizeof(char), type_size, file);
        fread(&width, sizeof(width), 1, file);
        fread(&length, sizeof(length), 1, file);
        fread(&depth, sizeof(depth), 1, file);

        data[i].SetType(type);
        data[i].SetWidth(width);
        data[i].SetLength(length);
        data[i].SetDepth(depth);
    }

    fclose(file);

    res = data;
}
