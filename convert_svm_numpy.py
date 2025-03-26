from micromlgen import port
from sklearn.svm import SVC
from sklearn.datasets import load_svmlight_file as LD
import numpy as np

classifier = SVC(kernel = 'linear', gamma = 0.001)
#training_points = [[1,1,1], [1,2,1], [2,3,1], [3,1,2], [3,2,2], [4,3,2]]
#labels = [0,0,0,1,1,1]

##use .csv dataset file name
filename = 'data.csv' 
##load dataset
datafile = np.loadtxt(filename, delimiter = ',', dtype=np.float32)
##delete first column : first col is label.(not data)
training_points = datafile[:,1:]
##load only first col data : label
labels = np.loadtxt(filename, delimiter = ',', usecols=0, dtype=np.int32)

classmap = {}
classifier.fit(training_points, labels)
classmap[0] = 'class1'
classmap[1] = 'class2'

##you can skip under three line : just view in python.
data2 = np.loadtxt('predict.csv', delimiter=',', dtype=np.float32)
sample = data2[:,1:]
#sample = [5,5,5]
print(classifier.predict(sample))

c_code = port(classifier, classmap=classmap)
print(c_code)
with open("model_3d.h", "w") as f:
    f.write(c_code)
