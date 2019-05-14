from PythonQt import QtCore, QtGui, example

import pybind_example

import gc


import sys

p = pybind_example.Pet('sonja')
print('ref count:', sys.getrefcount(p))


#p = pybind_example.new_pet()
#print(p.getName())
#p = None
 

res = QtGui.QWidget.myTest(p)
print('ref count:', sys.getrefcount(res))
print(res.getName())
res = None

p = None

print('DONE')
