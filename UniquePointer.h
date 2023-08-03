#pragma once

template <typename T>
class UniquePointer
{
public:
    UniquePointer() {}
    ~UniquePointer() {}

    UniquePointer& operator=(const UniquePointer&) = delete;
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&&) = delete;
    UniquePointer(const UniquePointer&&) = delete;

private:
    T* ptr;


};

