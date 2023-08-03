#pragma once
#include <atomic>
#include <iostream>

template <typename T>
class SharedPointer
{
public:
    SharedPointer() = delete;
    SharedPointer(T* ptr) noexcept {
        _rawPtr = ptr;
        _refCount = new std::atomic<int>(0);
        ++(*_refCount);
    }

    ~SharedPointer() noexcept {
        if (!_refCount)
        {
            return;
        }
        --(*_refCount);
        if (_refCount->load() == 0 && _rawPtr)
        {
            delete _rawPtr;
            delete _refCount;
            _rawPtr = nullptr;
            _refCount = nullptr;
        }
    }

    SharedPointer(const SharedPointer& sharedPointer)
    {
        _rawPtr = sharedPointer._rawPtr;
        _refCount = sharedPointer._refCount;
        ++(*_refCount);
    }

    const SharedPointer& operator=(const SharedPointer& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        _rawPtr = rhs._rawPtr;
        _refCount = rhs._refCount;
        ++(*_refCount);
    }
    T& operator*() {
        if (!_rawPtr)
            throw;

        return *_rawPtr;
    }
    T* operator->() {
        if (!_rawPtr)
        {
            throw;
        }
        return _rawPtr;
    }
    void Display()
    {
        std::cout << " Underlying Pointer " << _rawPtr << std::endl;
        std::cout << " RefCount " << _refCount->load() << std::endl;
    }
private:
    T* _rawPtr = nullptr;
    std::atomic<int>* _refCount = nullptr;
};

