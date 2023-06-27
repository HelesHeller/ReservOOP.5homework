#pragma once
#include <iostream>

using namespace std;
class Res
{
    char* type;
    int width;
    int length;
    int depth;

public:
    explicit Res();

    Res(const Res& object) = delete;

    ~Res();

    Res& operator=(const Res& object);
    bool operator==(const Res& object) const;

    void SetType(const char* type);
    void SetWidth(int width);
    void SetLength(int length);
    void SetDepth(int depth);

    const char* GetType() const;
    int GetWidth() const;
    int GetLength() const;
    int GetDepth() const;

    int Volume() const;
    int Area() const;
    void Print() const;
};

