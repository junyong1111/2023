## 2주차

- 강의자료(PDF)
    
    [ìì¹í´ì-2ì£¼ì°¨_ê°ì.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/68e3f327-3d7f-46f8-a326-79444c51773f/iiii-2ii_ei.pdf)
    
    [ìì¹í´ì_2ì£¼ì°¨_2ì°¨ì_ê°ì.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0f45d2dd-16e9-4d34-ac2b-d6acd3f91aa6/iiii_2ii_2ii_ei.pdf)
    

| 해석미분 | 수치미분 |
| --- | --- |
| 치환,변형들을 통해 기존에 존재하는 공식과 비교해야하므로 식을 찾기까지 상당히 힘들지만 식을 찾고나면 정답을 찾는것은 빠름 | 치환,변형등을 사용하지 않고(오일러 방식…)근사화 작업을 통해 규칙을 찾으므로 규칙 생성 복잡도가 낮지만 정답에 근접하도록 반복해야 하므로 계산 복잡도가 높다. |
| Rule Generation Complexity(규칙 생성 복잡도)가 높음 | Rule Generation Complexity(규칙 생성 복잡도)가 낮음 |
| Computational Complexity(계산 복잡도)가 낮음 | Computational Complexity(계산 복잡도)가 높음 |
| 개발자 입장 : 손실 함수의 미분방정식 풀기 쉬울 때 사용 | 개발자 입장 : 손실 함수의 미분방정식 풀기가 어려울 때 사용 |

```python
#-- https://github.com/SCKIMOSU/Numerical-Analysis/blob/master/euler.py\
#-- 수치미분,해석미분 
import numpy as np
import matplotlib.pyplot as plt

# this code is designed for the difference comparison 
# between euler and original method 

g=9.8 #-- 중력가속도
cd=0.25 #-- 공기저항
m=68 #-- 무게

v0=0
v1=(1-0)*(g-cd/m*v0**2)+v0
v2=(2-1)*(g-cd/m*v1**2)+v1
v3=(3-2)*(g-cd/m*v2**2)+v2
v4=(4-3)*(g-cd/m*v3**2)+v3

time=np.arange(0, 5)
vel=np.array([v0, v1, v2, v3, v4])

#  original method (수치미분)

vel_o=np.sqrt(g*m/cd)*np.tanh(np.sqrt(g*cd/m)*time)

plt.figure(1)
plt.plot(time, vel, '-b1', label='euler')
plt.plot(time,  vel_o, '-ro', label='differential')
plt.legend(bbox_to_anchor=(1.05, 1), loc=2, borderaxespad=0.)
plt.grid(True)
plt.xlabel('time')
plt.ylabel('velocity by euler and differential')
plt.show()
```

![다운로드](https://user-images.githubusercontent.com/79856225/224893688-2dc2edda-69b9-4153-8134-4580c4fab0fd.png)


**문제 (해석미분으로 접근)**

- 번지 점프 회사에서 문제가 발생했다.
    - 번지 점프를 하는 사람들 중에 심각한 척추 부상을 당하는 경우가 다수 발생
    - 번지 점프 회사는 개발자를 회사의 신입사원으로 입사시켜 이러한 문제를 해결하도록 업무를 지시
    
    —# 첫 번째 확인된 사항은 번지점프 후 4초 대 36m/s의 속도를 가지는 사람들이 척추부상을 당하는 것으로 확인 되었다.
    
    기존에는 몸무게가 고정되어 있던 사람의 t = x일 때 속도를 구하는 문제
    
    현재 문제는 t = 4로 고정되어 있을 때 속도가 36m/s인 사람의 몸무게(x)를 구하는 문제
    

```python
import numpy as np
import matplotlib.pyplot as plt

plt.rc('font', family='NanumBarunGothic') 
g=9.8; cd=0.25; t=4

m=np.linspace(40, 200, 100)
#-- linear space 
#-- 40 ~ 200까지는 모두 동일한 간격으로 100개를 만들겠다는 의미이며 현재 코드에서는 몸무게를 의미

#--해석미분에서 사용한 속도를 이용
v=np.sqrt(g*m/cd)*np.tanh(np.sqrt(g*cd/m)*t)
v1=np.sqrt(g*m/cd)*np.tanh(np.sqrt(g*cd/m)*t)-36

k=np.linspace(0, 0, 100)

plt.figure(1)
plt.plot(m, v, 'r.')
plt.grid()
plt.title('t = 4일때 몸무게별 속도')
plt.xlabel('몸무게')
plt.ylabel('속도')
plt.show()

plt.figure(2)
plt.title('t = 4일때 몸무게별 속도')
plt.xlabel('몸무게')
#plt.plot(m, v1, 'b.')
plt.plot(m, v1, m, k)
plt.grid()
plt.show()
```

![다운로드](https://user-images.githubusercontent.com/79856225/224893780-00f2dd4c-b9e3-477c-9ada-2ee9aa111b57.png)

![다운로드 (1)](https://user-images.githubusercontent.com/79856225/224893791-1637cdd5-7924-4561-934b-ebe7b74b29c3.png)