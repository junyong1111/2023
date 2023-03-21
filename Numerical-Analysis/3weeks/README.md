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

### 이분법

| 특징 | 장점 | 단점 | 알고리즘 복잡도 |
| --- | --- | --- | --- |
| 주어진 구간을 절반으로 나누어서 근사값을 찾아가는 방식으로 증분법의 변형이다. | - 반복 할때마다 절대 오차가 줄어들기 때문에 계산복잡도가 작다. | -  | - O(logn)의 알고리즘 복잡도를 가진다. |
1. 하한 경계 (x1)과 상한 경계(xu)값을 임의로 정한다.
2. 하한 경계 함수값 f(x1)과 상한 경계 함수값 f(xu)의 부호가 변하면 구간으로 확정한다.
3. 구간이 확정되면, 이분법에 의한 값, xr = (x1 + xu)/2을 계산해서 근이라고 정한다.
4. 하한 경계 함수값 f(x1)과 이분 경계 함수값 f(xr)의 부호 변화를 체크한다.
    - 변하지 않으면 x1 = xr로 대체
    - 변하면 xu = xr로 대체함
5. 단계1 로 가서 반복한다.

—# 증분법 : 해가 존재하는 구간을 찾아줌

이분법 : 해를 찾아줌

```python
import numpy as np

def bisect(func, xl, xu):
    maxit=100
    es=1.0e-4 #-- 절대 오치
    test=func(xl)*func(xu)
    #-- 두 구간의 함수값을 곱했을 때 양수면 구간이 존재 하지 않음

    if test > 0:
        print('No sign change')
        return [], [], [], []

    iter=0; xr=xl; ea=100

    #-- 1단계 : 하한 경계(xl)과 상한 경계(xu)값을 임의로 정한다.
    #-- 2단게 : 하한 경계 함수값 f(xl)과 상한 경계 함수값 f(xu)의 부호가 변하면 구간으로 확정한다.

    while (1):
        xrold=xr
        xr=np.float64((xl+xu)/2)
        #-- 3단계 : 구간이 확정되면, 이분법에 의한 값, xr = (xl +xu) /2을 계산해서 근이라고 정한다.
        iter=iter+1

        if xr != 0:  # 나누기에서 분모가 0이면 안 되죠. 0으로 나누는 것은 ZeroDivisionError: division by zero 가 발생하죠 
            ea=np.float64(np.abs(np.float64(xr)-np.float64(xrold))/np.float64(xr))*100
            #-- 상대 오차 계산

        test=func(xl)*func(xr)
        #-- 4단계 : 하한 경계 함수값 f(x1)과 이분 경계 함수값 f(xr)의 부호 변화를 체크한다.
        
        #-- 두 개의 구간을 곱해도 부호가 변하지 않으면 하한값을 조정 x1 = xr로 대체
        if test > 0:
            xl=xr
        #-- 두 개의 구간을 곱해서 부호가 변하면 상한값을 조정 xu = xr로 대체함
        elif test < 0:
            xu=xr
        else:
            ea=0

        if np.int64(ea<es) | np.int64(iter >= maxit):
            break

    root=xr
    fx=func(xr)

    return root, fx, ea, iter

if __name__ == '__main__':
    
    fm=lambda m: np.sqrt(9.81*m/0.25)*np.tanh(np.sqrt(9.81*0.25/m)*4)-36
    root, fx, ea, iter=bisect(fm, 40, 200)
    print('root = ', root, '(Bisection)')
    print('f(root) = ', fx, '(must be zero, Bisection)')
    print('estimated error= ', ea, '(must be zero error, Bisection)')
    print('iterated number to find root =', iter, '(Bisection)')
```