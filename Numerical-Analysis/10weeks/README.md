# 10주차(수치해, 데이터생성)

나이 : X , 키 : Y ⇒ modeling

—# modeling :  X,Y를 가장 잘 설명하는 하나의 직선을 찾는 것

- **Data graph** : 16명의 나이, 키 데이터 쌍
    - x = 나이
    - y = 키

<img width="249" alt="1" src="https://user-images.githubusercontent.com/79856225/236112141-605ca3c8-3dfd-4f82-b376-b318a160b7c6.png">

- **Cost Function Graph : 가설 직선(h)와 실제 데이터와의 차이 값**
    - x = 기울기
    - y = 오차 값
    
    —# bias 는 일단 무시
    
    <img width="210" alt="2" src="https://user-images.githubusercontent.com/79856225/236112147-9c2adbe3-d29e-4d74-929e-1a132175c337.png">

    
- **수치해 방법을 이용하여 weigt 값 갱신**
    - Gradient Descent(경사 하강법 이용)

**X, Y** **데이터 생성**

```python
import matplotlib.pyplot as plt
import numpy as np

#-- X data 생성(나이)
np.random.seed(seed=1) # 난수를 고정
number_of_data = 16
X = 5 + 25 * np.random.rand(number_of_data)
#-- randomr.rand함수는 [0,1]사이의 데이터만 나옴 여기에 25를 곱하면 -> [0,25] -> [5, 30]
#-- X는 5에서 30세에 100% 가 나타나는 균등 분포
print("=====================X Data ===================")
print("Number of X data is :", len(X))
print("X data is :", X)

print("=====================Y Data ===================")
#-- Y(T) data 생성(키)
Prm_c = [170, 108, 0.2, 4] # 생성 매개 변수
T = Prm_c[0] - Prm_c[1] * np.exp(-Prm_c[2] * X) + Prm_c[3] * np.random.randn(number_of_data) # (A)
#-- [126.269, 173.73]@ 68% 정규분포
print("Number of Y data is :", len(T))
print("Y data is :", T)

'''
=====================X Data ===================
Number of X data is : 16
X data is : [15.42555012 23.00811234  5.00285937 12.55831432  8.66889727  7.30846487
  9.65650528 13.63901818 14.91918686 18.47041835 15.47986286 22.13048751
 10.11130624 26.95293591  5.68468983 21.76168775]
=====================Y Data ===================
Number of Y data is : 16
Y data is : [170.91013145 160.67559882 129.00206616 159.70139552 155.46058905
 140.56134369 153.65466385 159.42939554 164.70423898 169.64527574
 160.71257522 173.28709855 159.31193249 171.51757345 138.9570433
 165.8744074 ]
'''
```