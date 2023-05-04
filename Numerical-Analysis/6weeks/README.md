## 6주차(손실함수, 경사하강법)

```python
import numpy as np
import matplotlib.pyplot as plt
#import tensorflow as tf
import tensorflow.compat.v1 as tf
tf.disable_v2_behavior()
# print(tf.__version__)

X = np.array([1., 2., 3.])
Y = np.array([1., 2., 3.])
m = len(X)

W = tf.placeholder(tf.float32)

#hypothesis = tf.mul(W, X)
hypothesis = W*X
cost = tf.reduce_sum(tf.pow(hypothesis-Y, 2)) / m

init = tf.initialize_all_variables()

sess = tf.Session()
sess.run(init)

# 그래프로 표시하기 위해 데이터를 누적할 리스트
W_val, cost_val = [], []

# 0.1 단위로 증가할 수 없어서 -30부터 시작. 그래프에는 -3에서 5까지 표시됨.
for i in range(-30, 50):
    xPos = i*0.1                                    # x 좌표. -3에서 5까지 0.1씩 증가
    yPos = sess.run(cost, feed_dict={W: xPos})      # x 좌표에 따른 y 값

    print('{:3.1f}, {:3.1f}'.format(xPos, yPos))

    # 그래프에 표시할 데이터 누적. 단순히 리스트에 갯수를 늘려나감
    W_val.append(xPos)
    cost_val.append(yPos)

sess.close()

#np.where(np.round(cost_val, 2) == 0.0)
#W_val[40]

plt.plot(W_val, cost_val)
plt.xlabel('W')
plt.ylabel('cost')
plt.grid()
plt.show()
```

![1](https://user-images.githubusercontent.com/79856225/236125371-63dfd25d-e882-4840-9ac1-61df392964f7.png)

**최소 제곱 회귀**

- 에러의 합이 최소화 되도록 하는 것
- 두 개의 변수가 있을 때, 최대, 최소를 찾는 편미분 방법 적용

규칙 + 오차함수 

```python
def f1(x):
    return (x - 2) ** 2 + 2

def f1d(x):
    """f1(x)의 도함수"""
    return 2 * (x - 2.0)
```

```python
xx = np.linspace(-1, 4, 100)
plt.plot(xx, f1(xx))
plt.plot(2, 2, 'ro', markersize=10)
plt.ylim(0, 10)
plt.xlabel("x")
plt.ylabel("$f_1(x)$")
plt.title("1차원 목적함수")
plt.show()
```

![2](https://user-images.githubusercontent.com/79856225/236125375-ad163d47-6f05-4c5e-8256-a8c00d99bd67.png)

```python
#-- -1 ~ 4 까지 100개 샘플
xx = np.linspace(-1, 4, 100)

plt.plot(xx, f1(xx), 'k-')
# step size
mu = 0.4

# k = 0
x = 0

plt.plot(xx, f1(xx))
plt.plot(2, 2, 'ro', markersize=10)
plt.ylim(0, 10)
plt.plot(x, f1(x), 'go', markersize=10)
plt.text(x + 0.1, f1(x) + 0.1, "1차 시도")
plt.plot(xx, f1d(x) * (xx - x) + f1(x), 'b--')

# f1(x)에서 접선 긋기
# plt.plot(xx, f1d(x)*xx, 'r--') 직선을 평행이동한 것
# x축으로 0 만큼, y축으로 6 만큼 평행이동한 직선이 접선이 됨
# f1d(x) * (xx[0] - x) + f1(x)   : 10
# f1d(x) * (xx[1] - x) + f1(x)  : 9.8
# f1d(x) * (xx[2] - x) + f1(x)  : 9.6
# f1d(x) * (xx[99] - x) + f1(x) : -10
print("1차 시도: x_1 = {:.2f}, g_1 = {:.2f}".format(x, f1d(x)))
```

![3](https://user-images.githubusercontent.com/79856225/236125377-6c0dc65c-3d21-484c-b0d8-a951923af7e5.png)

```python
# k = 1
x = x - mu * f1d(x)
plt.plot(xx, f1(xx))
plt.plot(2, 2, 'ro', markersize=10)
plt.ylim(0, 10)

plt.plot(x, f1(x), 'go', markersize=10)
plt.text(x - 0.2, f1(x) + 0.4, "2차 시도" )
plt.plot(xx, f1d(x) * (xx - x) + f1(x), 'b--')
# plt.plot(xx, f1d(x)*xx, 'm--') 직선을 평행이동한 것
# x축으로 1.6 만큼, y축으로 2.16 만큼 평행이동한 직선이 접선이 됨

plt.show()
print("2차 시도: x_2 = {:.2f}, g_2 = {:.2f}".format(x, f1d(x)))
```

![4](https://user-images.githubusercontent.com/79856225/236125379-2093cda6-1a1e-4f16-ba7c-30eaf467edd7.png)

```python
# k = 2
x = x - mu * f1d(x)
plt.plot(xx, f1(xx))
plt.plot(2, 2, 'ro', markersize=10)
plt.ylim(0, 10)

plt.plot(x, f1(x), 'go', markersize=10)
plt.text(x - 0.2, f1(x) - 0.7, "3차 시도")
plt.plot(xx, f1d(x) * (xx - x) + f1(x), 'b--')
# plt.plot(xx, f1d(x)*xx, 'c--') 직선을 평행이동한 것
# x축으로 1.92 만큼, y축으로 2.0064 만큼 평행이동한 직선이 접선이 됨

print("3차 시도: x_3 = {:.2f}, g_3 = {:.2f}".format(x, f1d(x)))

plt.xlabel("x")
plt.ylabel("$f_1(x)$")
plt.title("최대경사법을 사용한 1차함수의 최적화")
plt.ylim(0, 10)
plt.show()
```

![5](https://user-images.githubusercontent.com/79856225/236125380-7f0d7cb6-a2ba-4168-b0df-13619325cf66.png)