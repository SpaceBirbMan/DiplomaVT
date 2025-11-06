#ifndef DYNAMICLIBRARY_H
#define DYNAMICLIBRARY_H

#include <string>

class DynamicLibrary {
public:
    explicit DynamicLibrary(const std::string& path);
    ~DynamicLibrary();

    DynamicLibrary(const DynamicLibrary&) = delete;
    DynamicLibrary& operator=(const DynamicLibrary&) = delete;

    void* getSymbol(const std::string& name);

    bool isOpen() const { return handle_ != nullptr; }

private:
    void* handle_;
};

#endif // DYNAMICLIBRARY_H
