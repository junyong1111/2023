Grphical 방법에서 나온 f(x1)과 f(xu)의 개념을 사용한다.

- 증분법은 구간법의 조건인 단조함수에 대한 제약을 받지 않는다.

| 특징 | 장점 | 단점 | 알고리즘 복잡도 |
| --- | --- | --- | --- |
| - f(x1)f(xu) < 0 원리를 이용한다. | - 샘플링 수(증분수)가 적당하면 모든 근의 구간을 찾을 수 있다. | - 샘플링 수(증분수)를 잘못 정해지면 모든 근의 구간을 찾을 수 없다.(under fitting, overfitting) | - O(n)의 알고리즘 복잡도를 가진다. |

```python
#-- import library
import numpy as np
import matplotlib.pyplot as plt
#-- np.sign(x)
#-- x값이 양수면 1 음수면 -1 0이면 0

#-- Function Code
def incsearch(func, xmin, xmax):
  x = np.arange(xmin, xmax+1)
  f = func(x)
  nb = 0
  xb = []

  #-- Working Code
  for i in np.arange(np.size(x)-1):
    if np.sign(f[i]) != np.sign(f[i+1]):
      nb = nb + 1
      xb.append(x[i])
      xb.append(x[i+1])
      # print("number of bracket is", nb, "xb is ", xb)
     #-- xb is root interval   
  return nb, xb

g = 9.81; cd = 0.25; v = 36; t = 4;
fp=lambda mp:np.sqrt(g*np.array(mp)/cd)*np.tanh(np.sqrt(g*cd/np.array(mp))*t)-v
#-- 익명함수(일회용 함수) lambda를 사용
nb, xb=incsearch(fp, 1, 200)

print('number of brackets= ',nb)
print('root interval=', xb)
```

**—# 람다 함수**

- Lambda function(in line function)
- 한 줄 함수로 함수 핸들러로 많이 사용된다.

```python
fx = lambda x,y : x**2 + y**2
fx(2,3)
13
```

**—# 샘플링 수 문제에 대한 예제**

```python
import numpy as np
import matplotlib.pyplot as plt

def incsearch(func, xmin, xmax, ns):
    x=np.linspace(xmin, xmax, ns)
    f=func(x)
    nb=0;     xb=[]
    for k in np.arange(np.size(x)-1):
        if np.sign(f[k]) != np.sign(f[k+1]):
            nb=nb+1
            xb.append(x[k])
            xb.append(x[k+1])

    xbt=np.hstack(xb)
    xb=xbt.reshape(nb, 2)
    return nb, xb

def draw(xmin, xmax, inc, func):
    x = np.linspace(xmin, xmax, inc)
    #func = lambda x: np.sin(np.dot(10.0, x)) + np.cos(np.dot(3.0, x))
    f1 = func(x)
    plt.figure(1)
    plt.plot(x, f1, 'ro-')
    plt.grid()
    plt.show()

#-- inc의 값이 너무 작으면 루트 값을 제대로 못 찾는 Underfitting문제가 발생하고
#-- inc의 값이 너무 크다면 루트 값을 너무 많이 찾는 Overfitting문제가 발생한다.

if __name__ == '__main__':

    xmin=3; xmax=6
    inc=100
    func=lambda x: np.sin(np.dot(10.0, x))+np.cos(np.dot(3.0, x))
    nb, xb=incsearch(func, xmin, xmax, inc)
    draw(xmin, xmax, inc, func)
    print('number of brackets= ', nb)
    print('root interval=', xb)
```