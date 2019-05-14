#include "pybind_example.h"
#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

Pet* new_pet() {
  return new Pet("murphy");
}


PyObject* new_py_pet() {
  Pet* p = new_pet();
  py::object obj = py::cast(p, py::return_value_policy::take_ownership);

  
  //obj.inc_ref();
  //return obj.ptr();

  // release returns a non-ref counted handle
  return obj.release().ptr();
}

Pet* convert_py_pet(PyObject* pet)
{
  py::handle obj(pet);
  return obj.cast<Pet*>();
}


PYBIND11_MODULE(pybind_example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");

    m.def("new_pet", &new_pet, "A function that returns a new Pet");

    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName);

}
