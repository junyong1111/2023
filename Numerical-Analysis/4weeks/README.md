### 가위치법(False Position) f(x) = 0

그래프에서 두 점을 찍고 두 점을 지나는 직선을 그린다.

40에서 만나는 점(p1), 200에서 만나는 점(p2)

2개 점을 지나는 직선이 0이되는 지점을 root로 한다.

<img width="321" alt="스크린샷 2023-03-23 오후 12 21 28" src="https://user-images.githubusercontent.com/79856225/228717718-045cbaaa-1ea7-40e8-9544-0681c304ee77.png">


| 특징 | 장점 | 단점 | 알고리즘 복잡도 |
| --- | --- | --- | --- |
| 시작점과 끝점을 지나는 직선이 0이 되는 지점을 root로 한다.(닮은꼴 삼각형을 원리를 이용) | - 미분계수에 대한개념을 가져올 수 있음 접선은 기울기를 가지게 되고, 이 기울기 값이 접점에서의 미분 계수 | f(x) = 0을 만족하는 x를 구하기가 쉽지 않다. (이분법에 비해 에러가 크고, 반복횟수가 많음) | -  |

```python
import numpy as np
import matplotlib.pyplot as plt

def falseposition(func, xl, xu):
    maxit=100
    es=1.0e-4

    test=func(xl)*func(xu)

    if test > 0:
        print('no sign change')
        return [], [], [], []

    iter=0
    xr=xl

    ea=100

    while(1):
        xrold=xr
        #xr=np.float64((xl+xu)/2)
        # xr - xu - (func(xu) * (xl-xu) / (func(xl) - func(xu)))
        #-- point1과 point2 두 점을 지나는 직선을 만들고 그 직선이 0이 되는 지점을 root로
        xr = np.float64(xu-func(xu)*(xl-xu)/(func(xl)-func(xu)))

        iter=iter+1

        if xr != 0:
            ea=np.float64(np.abs(np.float64(xr)-np.float64(xrold))/np.float64(xr))*100
            #-- 상대오차 계산
        
        test=func(xl)*func(xr)

        if test > 0:

            xl=xr
        elif test < 0:
            xu=xr
        else:
            ea=0

        if np.int64(ea<=es) | np.int64(iter>=maxit):
            break
    root=xr
    plt.show()

    return root, fx, ea, iter
#root= 142.73765563964844
#      142.73763311

if __name__ == '__main__':

    fm=lambda m: np.sqrt(9.81*m/0.25)*np.tanh(np.sqrt(9.81*0.25/m)*4)-36
    root, fx, ea, iter=falseposition(fm, 40, 200)

    print('root=', root)
    print('f(root)=', fx)
    print('ea=', ea)
    print('iter=', iter)
    

'''''''''false position
root= 142.73783844758216
f(root)= 4.20034974979e-06
ea= 7.781013789779357e-05
iter= 29
'''''''''

''''''''' bisection
root= 142.73765563964844
f(root)= 4.60891641552e-07
ea= 5.3450468252827136e-05
iter= 21
'''''''''
```

- 이분법이 더 적은 연산횟수로 루트값을 찾아냄
- 해석 규칙 : A
- 수치 규칙 : B(데이터를 주면 머신이 알아서 규칙을 만들어 내는 방법)
- 해석해 : A(미분방정식)
- 수치해 : B (구간법)
- AA : 해석 규칙 + 해석해
- AB : 해석 규칙 + 수치해
- BA : 수치 규칙 + 해석해(사용 X)
- **BB : 수치 규칙 + 수치해 → 머신러닝**

미분 계수 f’(a)

- 두 개의 점(수치해)으로 보이지만, 멀리서 보면 하나의 점(해석해)같이 보이게 된다.
- 접접은 해석해와 수치해의 개념을 동시에 가진다.

### 뉴튼-랩슨

- 가위치법 : 평균변화율
- 오픈법 : 순간변화율
1. 기준점 

```python
import numpy as np
from scipy.optimize import fsolve

def sech(x):
    return np.cosh(x) ** (-1)

def newton_raphson(func, dfunc, xr, xt):
    maxit = 50
    es = 1.0e-5
    iter = 0

    while (1):
        xrold = xr
        xr = (xr - func(xr) / dfunc(xr))

        iter = iter + 1

        if xr != 0:
            ea = (np.abs(((xr) - (xrold)) / (xr)) * 100)
            et= (np.abs(((xt) - (xr)) / (xt)) * 100)

        if (ea <= es) | (iter >= maxit):
            break

        root = xr
        fx = func(xr)
    return root, fx, ea, iter

if __name__ == '__main__':
    g = 9.81; cd = 0.25; v = 36; t = 4
    fm = lambda m: np.sqrt(9.81 * m / 0.25) * np.tanh(np.sqrt(9.81 * 0.25 / m) * 4) - 36
    xt = fsolve(fm, 1)
    print("Real Root= ", xt)

    fp = lambda m: np.sqrt(g * m / cd) * np.tanh(np.sqrt(g * cd / m) * t) - v
    dfp = lambda m: (1 / 2) * np.sqrt(g / (m * cd)) * np.tanh(np.sqrt(g * cd / m) * t) - g * t / (2 * m) * (
    sech(np.sqrt(g * cd / m) * t)) ** 2

    root, fx, ea, iter = newton_raphson(fp, dfp, 140, xt)
    print('root weight= ', root)
    print('f(root weight, should be zero) =', fx)
    print('ea = should be less than 1.0e-4', ea)
    print('iter =', iter)

"""
Real Root=  [142.73763311]
root weight=  142.7376189663234
f(root weight, should be zero) = -2.8928707251907326e-07
ea = should be less than 1.0e-4 9.907775669827273e-06
iter = 3
"""
```