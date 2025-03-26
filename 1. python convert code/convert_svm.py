from micromlgen import port
from sklearn.svm import SVC

#kernel tag : 'linear', 'poly', 'rbf', 'sigmoid'
classifier = SVC(kernel = 'linear', gamma = 0.001)
#input data values
training_points = [[1,1], [1,2], [2,3], [3,1], [3,2], [4,3]]
#input data labels
labels = [0,0,0,1,1,1]
classmap = {}
classifier.fit(training_points, labels)
classmap[0] = 0
classmap[1] = 1
#predict output
print(classifier.predict([[5,5]]))

#code covert python to C
c_code = port(classifier, classmap=classmap)
print(c_code)
#save C code
with open("model_linear.h", "w") as f:
    f.write(c_code)


