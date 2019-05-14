project(example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

qt4_add_resources(resource_srcs PyDecoratorsExample.qrc)

qt4_wrap_cpp(moc_srcs PyExampleDecorators.h)

add_executable(PyDecoratorsExample main.cpp PyExampleDecorators.cpp ${resource_srcs} ${moc_srcs})
target_link_libraries(PyDecoratorsExample PythonQt)


add_subdirectory(pybind11)
pybind11_add_module(pybind_example SHARED pybind_example.cpp)
#add_library(pybind_example pybind_example.cpp)

target_link_libraries(PyDecoratorsExample pybind_example)
