#include "Res.h"


Res::Res()
    : type(nullptr), width(0), length(0), depth(0) {}

//Res::Res(const Reservoir& object)
//    : width(object.width), length(object.length), depth(object.depth) {
//
//    this->type = new char[strlen(object.type) + 1];
//    strcpy_s(this->type, strlen(object.type) + 1, object.type);
//}

Res::~Res() {

    delete[] type;
}

bool Res::operator==(const Res& object) const {

    if (strcmp(this->type, object.type) == 0)
        return true;

    return false;
}

Res& Res::operator=(const Res& object) {

    width = object.width;
    length = object.length;
    depth = object.depth;

    if (this->type != nullptr)
        delete[] this->type;

    type = new char[strlen(object.type) + 1];
    strcpy_s(type, strlen(object.type) + 1, object.type);

    return *this;
}

void Res::SetType(const char* type) {

    if (this->type != nullptr)
        delete[] this->type;

    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, strlen(type) + 1, type);
}

void Res::SetWidth(int width) {

    this->width = width;
}

void Res::SetLength(int length) {

    this->length = length;
}

void Res::SetDepth(int depth) {

    this->depth = depth;
}

const char* Res::GetType() const {

    return type;
}

int Res::GetWidth() const {

    return width;
}

int Res::GetLength() const {

    return length;
}

int Res::GetDepth() const {

    return depth;
}

int Res::Volume() const {

    return width * length * depth;
}

int Res::Area() const {

    return width * length;
}

void Res::Print() const {

    cout << "Тип водойми: " << type << endl;
    cout << "Ширина водойми: " << width << endl;
    cout << "Довжина водойми: " << length << endl;
    cout << "Глибина водойми: " << depth << endl;
    cout << "Об'єм водойми: " << Volume() << endl;
    cout << "Площина водойми: " << Area() << endl;
}
