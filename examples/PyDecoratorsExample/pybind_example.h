#pragma once

#include "Python.h"

#include <string>
#include <iostream>

#define DLL_PUBLIC __attribute__ ((visibility ("default")))
#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))


DLL_PUBLIC int add(int i, int j);

class DLL_PUBLIC Pet {
public:
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

    ~Pet() { std::cout << "~Pet: " << name << std::endl; }
    std::string name;
};

DLL_PUBLIC Pet* new_pet();

DLL_PUBLIC PyObject* new_py_pet();

DLL_PUBLIC Pet* convert_py_pet(PyObject* pet);
