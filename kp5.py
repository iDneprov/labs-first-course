import random
import numpy as np
from sklearn import datasets
import matplotlib.pyplot as plt

INPUT_NEU = 4
OUT_NEU = 3
HID_NEU = 10
ALPHA = 0.002
EPOCH = 100
BATCH_SIZE = 50

iris = datasets.load_iris()
dataset = [(iris.data[i][None, ...], iris.target[i]) for i in range(len(iris.target))]
lossArr = []
probArr = []


w1 = np.random.randn(INPUT_NEU, HID_NEU)
b1 = np.random.randn(1, HID_NEU)
w2 = np.random.randn(HID_NEU, OUT_NEU)
b2 = np.random.randn(1, OUT_NEU)

def SoftmaxButch(t):
    out = np.exp(t)
    return out / np.sum(out, axis = 1, keepdims=True)

def ReluDeriv(t):
    return (t >= 0).astype(float)

def Full(y, numСlasses):
    yFull = np.zeros((1, numСlasses))
    yFull[0,y] = 1
    return yFull

def Sce(z,y):
    return -np.log(z[0,y])

def SceButch(z,y):
    return -np.log(np.array([z[j, y[j]] for j in range(len(y))]))


def Relu(t):
    return np.maximum(t, 0)

def Softmax(t):
    out = np.exp(t)
    return out / np.sum(out)

def FullBatch(y, numClasses):
    yFull = np.zeros((len(y), numClasses))
    for j, yj in enumerate(y):
        yFull[j,yj] = 1
    return yFull


counter = 0
k = 1

for ep in range(EPOCH):
    random.shuffle(dataset)
    for i in range(len(dataset) // BATCH_SIZE):

        # разбиение датасета на кортеж входных данных и кортеж выходных данных размером в батч сайз
        batchX, batchY = zip(*dataset[i * BATCH_SIZE : i * BATCH_SIZE + BATCH_SIZE]) 

        # склейка кортежей значений иксов в матрицу
        x = np.concatenate(batchX, axis = 0)

        # склейка кортежа выходных значений в вектор
        y = np.array(batchY)


        t1 = x @ w1 + b1
        h1 = Relu(t1)
        t2 = h1 @ w2 + b2
        z = SoftmaxButch(t2)
        e = np.sum(SceButch(z, y))


        for i in range(len(z)):
            maxi = np.argmax(z[i])
            if (maxi == y[i]):
                counter += 1
            k += 1
            if (k > 250):
                probArr.append((counter / k) * 100)
        

        yFull = FullBatch(y, OUT_NEU)
        de_dt2 = z - yFull
        de_dw2 = h1.T @ de_dt2
        de_db2 = np.sum(de_dt2, axis=0, keepdims=True)
        de_dh1 = de_dt2 @ w2.T
        de_dt1 = de_dh1 * ReluDeriv(t1)
        de_dw1 = x.T @ de_dt1
        de_db1 = np.sum(de_dt1, axis=0, keepdims=True)

        w1 = w1 - ALPHA * de_dw1
        b1 = b1 - ALPHA * de_db1
        w2 = w2 - ALPHA * de_dw2
        b2 = b2 - ALPHA * de_db2

        lossArr.append(e)
def Predict(x):
    t1 = x @ w1 + b1
    h1 = Relu(t1)
    t2 = h1 @ w2 + b2
    z = Softmax(t2)
    return z

def CalcAccuracy():
    correct = 0
    for x, y in dataset:
        z = Predict(x)
        pred = np.argmax(z)
        if y == pred:
            correct += 1
    acc = correct / len(dataset)
    return acc

accuracy = CalcAccuracy()
print("Accuracy: ", accuracy)

fig = plt.figure()


ax1 = fig.add_subplot(1,2,1)
ax2 = fig.add_subplot(1,2,2)
ax1.grid(True)
ax2.grid(True)
ax1.set(title = 'Mistake cross entropy')
ax2.set(title = 'Probability of guessing')
ax1.plot(lossArr)
ax2.plot(probArr)


plt.show()


