
from re import T
import tensorflow as tf

import numpy as np
import matplotlib.pyplot as plt
from tensorflow.python.framework.ops import init_scope
from tensorflow.python.ops.control_flow_ops import with_dependencies
from tensorflow.python.ops.gen_array_ops import placeholder
import argparse

tf.compat.v1.disable_v2_behavior()
parser = argparse.ArgumentParser()
parser.add_argument("--epoch", type=int, default=100, required=True, help="train epoches")
args = parser.parse_args()

def loadDataSet(filepath):
    dataMat = []
    labelMat = []
    with open(filepath) as fr:
        for line in fr.readlines():
            lineArr = line.strip().split()
            dataMat.append([float(lineArr[0]), float(lineArr[1])])
            labelMat.append(int(lineArr[2]))
    return dataMat, labelMat

def plotDataMat(dataMat, labelMat, weights):
    
    n = np.shape(dataMat)[0]
    xcord1 = []
    ycord1 = []
    xcord2 = []
    ycord2 = []
    for i in range(n):
        if int(labelMat[i]) == 1:
            xcord1.append(dataMat[i, 0])
            ycord1.append(dataMat[i, 1])
        else:
            xcord2.append(dataMat[i, 0])
            ycord2.append(dataMat[i, 1])
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.scatter(xcord1, ycord1, s=30, c='red', marker='s')
    ax.scatter(xcord2, ycord2, s=30, c='green')

    x = np.arange(-3.0, 3.0, 0.1)
    #y = (-weights[0] - weights[1] * x) / weights[2]
    y = (-1 - weights[0] * x) / weights[1]
    ax.plot(x, y)

    plt.xlabel('X1');
    plt.ylabel('X2');
    plt.show()

def main():
    
    trainMat, labelMat = loadDataSet("data.txt")
    trainMat = np.mat(trainMat).astype(np.float32)
    labelMat = np.mat(labelMat).transpose().astype(np.int32)
    sample_num = trainMat.shape[0]
    print(trainMat)
    threshold = 1e-2

    weight = tf.Variable(tf.zeros([2,1]))
    bias = tf.Variable(tf.zeros([1,1]))

    # x_ = tf.placeholder()
    y_ = tf.compat.v1.placeholder(dtype=tf.float32, shape=(1, 1))
    x_ = tf.compat.v1.placeholder(dtype=tf.float32, shape=(1, 2))
    


    g = tf.matmul(x_, weight) + bias
    hyp = tf.sigmoid(g)
    cost = (y_ * tf.math.log(hyp) + (1-y_)*tf.math.log(1-hyp)) / -sample_num
    print(type(cost))
    
    loss = tf.reduce_sum(cost)

    optimizer = tf.compat.v1.train.GradientDescentOptimizer(1e-2)
    train = optimizer.minimize(loss)

    step = 0
    w = None
    flag = 0
    loss_list = []
    init = tf.compat.v1.initialize_all_variables()
    with tf.compat.v1.Session() as sess:
        sess.run(init)
        for _ in range(args.epoch):
            for data, label in zip(trainMat, labelMat):
                sess.run(train, feed_dict = {x_: data, y_: label})
                step += 1
                if step % 10 == 0:
                    print(step, sess.run(weight).flatten(), sess.run(bias).flatten())
            
            loss_val = sess.run(loss, {x_:data, y_:label})
            print('loss_val = ', loss_val)
            loss_list.append(loss_val)
            if loss_val <= threshold:
                flag = 0
            print('weight = ', weight.eval(sess))
        w = weight.eval(sess)

    # 画出loss曲线
    loss_ndarray = np.array(loss_list)
    loss_size = np.arange(len(loss_ndarray))
    
    plt.plot(loss_size, loss_ndarray, 'b+', label='loss')
    plt.show()
    plotDataMat(trainMat, labelMat, w)


if __name__=="__main__":
    main()