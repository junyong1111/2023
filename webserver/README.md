
```bash
django-admin startapp pybo
```

- 가상환경 디렉토리에서 해당 명령어를 통해 app 생성
    - pybo는 해당 앱 이름으로 자유롭게 설정 가능

```bash
python manage.py runserver
```

- 가상환경 디렉토리에서 해당 명령어를 통해 로컬서버 구동
- 주소창에 [localhost:8000/pybo](http://localhost:8000/pybo) 를 입력하여 접속
    - 현재는 페이지에 해당하는 url을 매핑하지 않아 오류가 나옴

### config/[**urls.py](http://urls.py) 수정**

```python
from pybo import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('pybo/', views.index),
]
```

- pybo url을 매핑

### pybo/views[**.py](http://urls.py) 수정**

```python
from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def index(request):
    return HttpResponse("안녕하세요 pybo에 오신것을 환영합니다.")
```

![스크린샷 2023-03-13 오후 12.21.47.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3c8ed401-39aa-4e01-b128-166cd539dee8/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-03-13_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_12.21.47.png)

### config가 처리하는 일을 pybo가 할 수 있도록 분산처리

![스크린샷 2023-03-13 오후 1.09.44.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5dce8111-1b64-4d55-8293-625f0c46c403/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-03-13_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_1.09.44.png)

- **config/urls.py 수정 하기**

```python
from django.contrib import admin
from django.urls import path, include
from pybo import views

urlpatterns = [
    path('admin/', admin.site.urls),
	  path('pybo/', include('pybo.urls')),
]
```

- **pybo/urls.py 파일 생성**

```python
from django.urls import path

from . import views

urlpatterns = [
	path('', views.index),

]
```

![스크린샷 2023-03-13 오후 1.10.09.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/097ad181-71fc-42ad-8a5b-ffb7c11e75d0/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-03-13_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_1.10.09.png)