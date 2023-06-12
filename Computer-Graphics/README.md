# Computer Graphics


<aside>
❗ 현재 컴퓨터 그래픽스는 다양한 분야에서 활용되고 있다. 컴퓨터 그래픽스는 컴퓨터 비전, 디지털 이미지, 뉴럴 렌더링, 자율주행, Mixed Reality, 컴퓨터 게임, 예술 분야에서 다양하게 사용된다. 또한, 컴퓨터 그래픽스의 조명화에는 Global Vs Local, Global Illumination, Local Illumination이 있다. Interactive Computer Graphics 분야에서는 GPU, OpenGL과 같은 하드웨어들이 그래픽의 발전을 가속화하였다. OpenGL은 1992년 배포된 그래픽스 독점 API이며, 현재는 Khronos Group에 의해 관리되고 있다. Microsoft Direct3D는 OpenGL의 경쟁자이다.

</aside>

<details>
<summary> Overview </summary>
<div markdown="1">

### Overview

**Rendering PipeLine**

| 단계 | 설명 |
| --- | --- |
| Vertex Processor | 입력된 객체의 모든 점에 대해 처리하고, 좌표를 바탕으로 색상과 빛, 투영 등의 속성을 계산한다. |
| Clipper and Primitive Assembler | Vertex Processor에서 출력된 객체를 화면의 크기에 맞게 자르는 작업을 수행하고, 점과 선, 삼각형과 같은 기본 도형으로 변환한다. |
| Rasterizer | 객체의 기본 도형을 화면의 픽셀 단위로 분해하고, 객체의 모든 부분을 채우는 작업을 수행한다. |
| Fragment Processing | 화면에 그려진 모든 픽셀에 대해 계산하고, 색상, 빛, 그림자, 반사 등의 효과를 추가하며, 최종적으로 픽셀 값을 계산하여 화면에 출력한다. |

**Vertex Processor** ⇒ Clipper and Primitive Assembler ⇒ Rasterizer ⇒ **Fragment Processing** 
위 순서는 바꿀 수 없으며  **Vertex Processor와 Fragment Processing은 코딩이 가능하다.**

<aside>
❗ input : vertex 데이터, 각 vertex의 위치, 색상, 법선 벡터, 텍스처 좌표 등의 정보가 포함될 수 있다.

</aside>

이미지 위치에 대한 4가지 요소들이 있다.

| 요소 | 설명 |
| --- | --- |
| View | 카메라나 눈과 같은 시점에서 본 관찰 대상의 위치와 방향을 나타내는 요소이다. 
관찰 대상과 시점 간의 상대적인 위치와 방향에 따라 이미지가 달라진다. |
| Objects | 이미지를 구성하는 대상인 물체이다. 물체는 정점(vertex)과 면(face)으로 이루어져 있으며,
정점의 위치와 면의 형태에 따라 물체의 모양이 결정된다. |
| Light Source | 물체에 비춰지는 조명이다. 빛의 종류(빨간색, 파란색 등), 밝기, 방향, 위치 등에 따라 
물체의 색상과 입체감이 달라진다. |
| Attributes | 물체의 속성으로 색상, 반사율, 반사도 등을 포함한다. 이러한 속성에 따라 
물체가 어떤 색으로 보이고, 빛을 얼마나 반사하느냐 등이 결정된다. |

</div>
</details>


<details>
<summary> View(Camera)  </summary>
<div markdown="1">

### View(Camera)

카메라에 빛이 투사되는 2가지 타입이 존재한다.

**Perspective projection**

- 실제 세계에서 눈으로 볼 때의 시점각을 모방하여 물체를 투사
- 물체가 멀어질수록 작아지는 것을 모방하여 물체를 투사
- 물체의 가까이와 멀리 떨어진 곳을 강조하기 위해 주로 사용
- 상대적으로 자연스러운 3차원감을 제공하며, 원근감을 표현할 때 사용

**Orthographic projection**

- 물체를 일정한 크기로 유지하면서 투사
- 물체가 멀어질수록 작아지지 않다.
- 주로 2D 또는 3D 모델링 도구에서 사용되며, 보통 3D 공간에서 오브젝트를 다룰 때 사용.
- 오브젝트를 고정 크기로 보여줄 때 사용.

**Clipping**

물리적으로 카메라는 세상 전부를 볼 수 없다. OpenGL에서는 기본적으로 4개의 Clipping Planes + 2개의 추가적인 Clipping Planes를 사용한다.  Front + Back(너무 앞에 있거나, 넘어가는 물체는 그리지 않는다)

**외부 파라메터**

6개의 방향을 바꾸면서 상을 바꿀 수 있다. → 카메라 움직임

- Position : 3DOF → **X, Y, Z 방향으로 카메라를 움직임**
- Orientation : 3DOF → 고개를 끄덕, 도리, 갸웃거려 카메라를 움직임

```java
void gluLookAt(
GLdouble eyex, GLdouble eyey, GLdouble eyez, 
GLdouble centerx, GLdouble centery, GLdouble centerz, 
GLdouble upx, GLdouble upy, GLdouble upz
)
```

1. 카메라 위치(eye) : (eyex, eyey, eyez)
2. 카메라가 바라보는 점(center) : (centerx, centery, centerz)
    - 객체의 위치
3. 카메라의 방향(up) : (upx, upy, upz)
    - 카메라의 수직 방향
    - (객체 - 카메라의 방향) → 카메라가 바라보는 방향
        
        **→ 카메라가 바라보는 방향 X 0.0f, 1.0f, 0.0f(외적) ⇒ 두 벡터의 수직인 방향 Up 벡터 반환**
        

```java
glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
**glm::vec3 up = glm::normalize(
																glm::cross(cameraTarget - cameraPosition, 
																glm::vec3(0.0f, 1.0f, 0.0f))
);**
```

**내부 파라메터**

**Field of view(FOV) → Fovy**

Fovy는 화각이라고 이해하면 된다. 

- Foby를 줄인다 → Zoom In
- Foby를 키운다 → Zoom out

```java
const glm::mat4 Camera::get_projection_matrix() const
{
  if (mode_ == kPerspective)
    return glm::perspective(glm::radians(fovy_), aspect_, near_, far_);
  else
  {
      float ortho_left = -ortho_scale_ * aspect_ / 2.0f;
      float ortho_right = ortho_scale_ * aspect_ / 2.0f;
      float ortho_bottom = -ortho_scale_ / 2.0f;
      float ortho_top = ortho_scale_ / 2.0f;
      return glm::ortho(ortho_left, ortho_right, ortho_bottom, ortho_top, near_, far_);
  }
}
```

|  | Perspective Projection | Orthographic Projection |
| --- | --- | --- |
| Constructor Parameters | fovy, aspect, near, far | ortho_scale, aspect, near, far |
| Matrix Calculation | glm::perspective() | glm::ortho() |
| Projection Matrix Type | Frustum | Parallel |
| Effect on Depth | Non-linear | Linear |
| Use Case | 3D Rendering | 2D Rendering |

<aside>
❗ 이 글에서는 **카메라의 뷰와 관련된 내용**을 다룬다. 카메라의 뷰는 **perspective** projection과 **orthographic** projection 두 가지가 있다. perspective projection은 실제 세계에서 눈으로 볼 때의 시점각을 모방하여 물체를 투사하고 물체가 멀어질수록 작아지는 것을 모방한다. 반면, orthographic projection은 물체를 일정한 크기로 유지하면서 투사하며 물체가 멀어질수록 작아지지 않는다. 이외에도 clipping과 카메라의 내부 파라메터인 field of view(FOV)에 대해서도 다루고 있다. FOV는 화각이며 **fovy를 줄이면 zoom in**하고 **fovy를 키우면 zoom out**한다.

</aside>

</div>
</details>

<details>
<summary> Objects </summary>
<div markdown="1">

### Objects

| 특징 | Polygon Soup 방식 | Vertex List & Polygons 방식 |
| --- | --- | --- |
| 구성 요소 | 삼각형 메시(Mesh) 형태 | 정점(Vertex) 리스트와 다각형(Polygon) 리스트 |
| 정점의 중복성 | 중복된 정점을 사용 | 중복된 정점을 사용하지 않음 |
| 저장되는 데이터 | 정점 좌표와 삼각형의 인덱스 | 정점 좌표와 다각형을 이루는 정점 인덱스 |
| 3D 모델링 도구와 호환성 | 대부분의 3D 모델링 도구와 호환 | 일부 3D 모델링 도구와 호환되지 않을 수 있음 |
| 메모리 사용량 | 메모리 사용량이 상대적으로 높음 | 메모리 사용량이 낮음 |
| 계산량과 속도 | 계산량이 적어 속도가 빠름 | 계산량이 많아 속도가 상대적으로 느림 |
| 빌딩 높이 제한과 유연성 | 빌딩 높이에 제한이 있을 수 있음 | 높은 빌딩 또한 쉽게 처리 가능 |

| 특징 | 설명 |
| --- | --- |
| 성능 개선 | VBO는 GPU에 데이터를 캐시하여 렌더링 성능을 크게 향상시킵니다. CPU와 GPU간의 대역폭 사용량을 최소화하고 메모리 효율을 최적화하기 때문입니다. |
| 유연성 | VBO는 다양한 데이터 타입을 지원하기 때문에 이전에는 불가능했던 다양한 렌더링 기술을 구현할 수 있습니다. |
| 재사용성 | VBO는 다른 메시나 렌더링 상태와 함께 여러 번 재사용할 수 있습니다. 이는 동일한 데이터를 여러 번 복사하지 않아도 되므로 메모리 효율을 높이고 성능을 향상시킵니다. |
| 유지보수 용이성 | VBO를 사용하면 변경할 데이터가 저장된 버퍼만 업데이트하여 렌더링을 업데이트 할 수 있습니다. 이는 메모리 효율을 높이고 CPU와 GPU 간의 데이터 전송을 최소화합니다. |
| 인덱스 처리 | IBO를 사용하면 인덱스 버퍼를 처리할 수 있습니다. 이는 메모리 사용량을 줄이고 다양한 렌더링 기술을 구현하는 데 유용합니다. |

**물체를 모델링하는 방식**은 Soup방식과 Vertex List 방식으로 나뉜다. 

임베디드 또는 핸드폰에서는 모든 물체를 폴리곤이 아닌 삼각형으로 표현하는 **Triangle Meshes**를 사용한다.

- Soup
    - 중복된 정점을 사용
    - 중복된 데이터를 사용하기 때문에 메모리 사용량이 상대적으로 높음
    - 메모리 사용량이 높은 대신 속도가 빠름
    - 현재는 이 방법을 사용
- Vertext List
    - 중복된 정점을 사용하지 않음
    - Vertex에 대한 Index정보를 이용하므로 메모리 사용량이 상대적으로 낮음
    - 정점에 대한 데이터를 찾으므로 상대적으로 속도가 느림
    - 시작은 상관없이 반시계 방향으로 폴리곤 또는 삼각형이 형성된다.

**렌더링**

- **Vertex Arrays** 방식은 모델을 렌더링하기 전에 모든 데이터를 CPU로 가져온다. 이는 모델이 크고 복잡할수록 CPU에 대한 부하가 증가할 수 있다. 또한, 데이터를 가져온 후에는 매번 렌더링할 때마다 CPU에서 GPU로 데이터를 전송해야 하기 때문에 성능 문제가 발생할 가능성이 있다.
- **Vertex/Index Buffer Objects(VBOs + IBO)** 방식은 데이터를 GPU의 버퍼로 먼저 전송한다. 이렇게 하면 CPU에서 GPU로 데이터를 전송하는 빈도가 줄어들기 때문에 **전송 속도가 빨라지고**, **CPU의 부하가 감소한**다. 또한, GPU의 버퍼에 데이터가 저장되어 있기 때문에 매번 렌더링할 때마다 데이터를 **CPU에서 GPU로 전송할 필요가 없으므로 성능 문제도 크게 줄어든다.**

</div>
</details>

<details>
<summary> Objects → Transformations(중요⭐️) </summary>
<div markdown="1">

### **Affine Space & Homogeneous Coordinates**

Affine Space는 선형 변환에 대한 일반화된 개념으로, 상대적인 위치와 관계에 초점을 두는 공간입니다. 이 공간에서는 절대적인 좌표 시스템이나 원점이 없습니다.

Homogeneous Coordinates는 Affine Space에서 점을 표현하기 위한 방법 중 하나로**, 추가된 한 요소를 사용하**여 점의 위치를 다차원 벡터로 표현합니다. 이 좌표 체계를 사용하면 선형 변환을 행렬 연산으로 간단하게 표현할 수 있으며, 원근 효과를 나타내는 데에도 유용합니다.

Affine Space와 Homogeneous Coordinates는 컴퓨터 그래픽스, 컴퓨터 비전, 로봇 공학 등 다양한 분야에서 활용되며, Affine Space는 상대적인 위치와 관계를 다루는 데에 유용하고, Homogeneous Coordinates는 선형 변환을 표현하고 계산하는 데에 효과적으로 사용됩니다.

**Homogeneous coordinates**

그래픽 카드는 homogeneous coordinates를 지원한다 

N차원의 벡터와 포인터를 N+1차원으로 표현한다.

Vector는 0으로 Point는 1로 표현한다.

**Affine Space**

- Scalars
- Vectors
- Points

위 3개를 하나의 연산체계로 통합한 것이다.

### **Linear Transformations(선형 변환)**

**Transformations(변환)**

- 입력에서 직선은 변환을 거쳐도 직선이다.
- 가장 기본적인 변환은 다음과 같이 3가지가 존재한다.
    - Trnslation
    - Rotation
    - Scaling

**Transloation(이동)**

- 이동은 객체를 주어진 벡터만큼 평행이동하는 것을 의미한다. 이동 변환은 2D 공간에서는 2차원 벡터 (tx, ty)로 표현되고, 3D 공간에서는 3차원 벡터 (tx, ty, tz)로 표현된다. 이동 변환을 적용하기 위해선 변환 행렬에 이동 벡터를 추가하면 된다.
- glTranslate(dx, dy, dx)

```sql
[ 1   0   0   tx ]
[ 0   1   0   ty ]
[ 0   0   1   tz ]
[ 0   0   0   1  ]
```

**Rotation(회전)**

- 회전은 객체를 기준점을 중심으로 주어진 각도만큼 회전시키는 것을 의미한다. 2D 공간에서는 회전 변환을 위해 회전 각도를 사용하며, 3D 공간에서는 회전 축과 회전 각도를 사용한다. 회전 변환을 적용하기 위해서는 회전 행렬을 사용하며, 각각의 축에 대한 회전 행렬이 정의되어 있다.
- glRotate(각도, ux,uy, uz)

![1](https://github.com/junyong1111/Computer-Graphics/assets/79856225/75cc568f-0466-49df-b7cb-df4fa7b09f4e)


**Scaling(확대/축소)**

- 확대/축소는 객체의 크기를 변화시키는 것을 의미한다. 2D 공간에서는 x축과 y축 방향으로 각각 다른 비율로 확대 또는 축소할 수 있다. 3D 공간에서는 x축, y축, z축에 대한 확대/축소 비율을 사용한다다. 확대/축소 변환을 적용하기 위해선 변환 행렬에 확대/축소 비율을 포함시키면 된다.
- glScale(sx, sy, sz)

<img width="935" alt="2" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/b05dc565-5312-4e26-b874-d68a71a019be">

### **Model Transformations**

**합성 변환(Composite transformations)**

여러 개의 기본 변환(이동, 회전, 확대/축소 등)을 조합하여 물체에 순차적으로 적용하는 것을 말한다. 이를 통해 복잡한 변환을 표현하거나 객체의 위치, 크기, 방향 등을 조작할 수 있다.

- TRS

```cpp
// mat 4x4 mat_model T,R,S

T = translate(2, 1, 0);
R = rotate(-30, 0, 0, 1);
S = scale(2, 2, 2);

mat_model = T*R*S;
glDrawArrays(); 
```

일반적으로, 주어진 점 p를 중심으로 회전하는 회전 변환을 수행하기 위해서는 다음과 같은 과정을 거친다.

1. 점 p를 원점으로 이동한다  이를 위해 이동 변환을 적용하여 p를 원점으로 옮긴다.
2. 회전 변환을 원점을 기준으로 수행합다. 즉, 회전 변환 행렬을 사용하여 객체를 회전시킨다.
3. 이동 변환을 다시 적용하여 원래의 점 p의 위치로 되돌린다. 이로써 회전 변환의 결과가 점 p를 중심으로 이루어진다.

```cpp
// mat 4x4 mat_model T1,T2, R
// 고정 점 pf

T1 = translate(-pf_x,-pf_y, -pf_z); // 원점으로 가져감 
R = rotate(-30, 0, 0, 1); // 각도 회전
T2 = translate(pf_x, pf_x, pf_x); //원래 위치로 이동 

mat_model = T2*R*T1 // 원점이동 -> 회전 -> 원래 위치의 역순으로 곱해줌
glDrawArrays(); 
```

—# 스케일 변환도 마찬자지 이다.

**Instancing**

그래픽스에서 인스턴싱(Instancing)은 동일한 모델을 여러 개의 인스턴스로 생성하여 효율적으로 렌더링하는 기술이다. 이를 통해 동일한 모델을 여러 위치에 배치하거나 다양한 매개변수를 사용하여 다른 모양의 인스턴스를 생성할 수 있다.

예를 들어, 나무 모델을 여러 개 배치해야 한다고 가정하면, 기존의 방식으로는 각각의 나무를 독립적인 개체로 처리해야 하지만, 인스턴싱을 사용하면 하나의 나무 모델을 여러 인스턴스로 생성하여 효율적으로 처리할 수 있다.

### Transformations for Hierarchical Objects

**Solar System**

태양계는 Sun - Earth - Moon으로 구성되어 있고 지구와 달은 각각 다음과 같은 특징이 존재

- 지구
    - 자전
    - 태양 주위를  공전
- 달
    - 자전
    - 지구 주위를 공전
    

태양계를 예시로 계층적 객체의 변환에 대한 이해

**달**

X_달 모델링

<img width="348" alt="3" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/7b37b678-db79-4834-bd2c-fb1ecfbb83ec">

X_달에 R회전 연산 적용

<img width="358" alt="4" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/212a22de-4fd2-40a3-be58-a2c92ba392da">

**지구 - 달** 

- 달은 지구 주위를 회전한다.

<img width="675" alt="5" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/a8653041-d30e-4f97-a1dc-ae6360f4ac58">

#— 달은 자신의 좌표 입장에서는 자전하고 있지만 지구 좌표에서는 공전하고 있음

달의 공전은 지구의 좌표에서 봤을 때이므로 다음과 같은 수식 형성

- 지구의 원점과 달의 원점 즉, 두 행성 사이의 거리 계산
    - distance(earth - moon)
- 지구의 기준에서 달의 회전
    - **Θ**

<aside>
❗ 지구 좌표에서 해석하면
**지구의 원점에서  distance(earth - moon) *cosΘ , distance(earth - moon) *sinΘ만큼 떨어져 있는 달이 R_moon*X_moon만큼 회전**

</aside>

**태양 - 지구**

- 지구는 태양 주위를 회전한다.

<img width="682" alt="6" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/16766889-c843-4aa2-9084-39a60f675ae5">

#— 지구는 자신의 좌표 입장에서는 자전하고 있지만 태양의 좌표에서는 공전하고 있음

지구의 공전은 태양의 좌표에서 봤을 때이므로 다음과 같은 수식 형성

- 태양의 원점과 지구의 원점과의 거리 게산
    - distance(sun - earth)
- 태양의 기준에서 지구의 회전
    - **Φ**

<aside>
❗ 태양 좌표에서 해석하면

**태양의 원점에서 distance(sun - earth) * cosΦ ,  distance(sun - earth) * sinΦ , 만큼 떨어져 있는 지구가 R_earth *Xearth만큼 회전**

</aside>

**X_sun = TR**

- **X_sun** =  **T_earth( distance(sun - earth) * cosΦ,  distance(sun - earth) * sinΦ) * R_earth * X_earth**

**X_earth = TR**

- **X_earth** =  **T_moon(distance(earth - moon) *cosΘ , distance(earth - moon) *sinΘ) * R_moon * X_moon**

위 X_sun 수식에서  **R_earth * X_earth부분에서  X_earth** **⇒ X_moon 대입**

```cpp
**X_sun** =  **T_earth( distance(sun - earth) * cosΦ,  distance(sun - earth) * sinΦ)*
R_earth * 
T_moon(distance(earth - moon) *cosΘ , distance(earth - moon) *sinΘ) * R_moon * X_moon**
```

**모델링**

1. 달 모델링
    
    ```cpp
    void draw_moon()
    {
    	// Moon을 그리는 함수
    	glBindBuffer(GL_ARRAY_BUFFER, ...); // 타겟에 지정된 버퍼 객체를 바인딩
    	glEnableVertexAttribArray(...); //모델에 필요한 버텍스 데이터를 그래픽스 파이프라인으로 전달
    	glDrawArrays(...); //  Moon 모델의 정점들을 렌더링
    	glDisableVertexAttribArray(...); //파이프라인으로의 데이터 전달이 끝났으므로 비활성화
    } 
    ```
    
2. 달 회전
    
    ```cpp
    mat 4x4  g_mat_model;
    
    void draw_earth_system()
    {
    	mat4x4 R;
    	R = rotate(...); // 달 회전을 위한 회전 변환 행렬 생성
    	g_mat_model *= R; // 전역 모델 행렬에 회전 변환 적용
    	draw_moon(); 
    }
    
    ```
    
3. 지구 - 달
    
    ```cpp
    mat4x4 g_mat_model;
    
    void draw_earth_system()
    {
    	mat4x4 T, R;
    	draw_earth();
    	T = translate(...);  // 달의 공전
    	R = rotate(...);  // 달의 자전
    	
    	g_mat_model *= T;
    	g_mat_model *= R;
    	draw_moon();
    }
    ```
    
4. 태양 - 지구
    
    ```cpp
    mat4x4 g_mat_model;
    
    void draw_sun_system()
    {
    	mat4x4 T, R;
    	g_mat_model.set_identity(); // 전역 모델 행렬 초기화
    
    	draw_sun();
    	T = translate(...);  // 달의 공전
    	R = rotate(...);  // 달의 자전
    	
    	g_mat_model *= T;
    	g_mat_model *= R;
    
    	draw_earth_system();
    }
    ```

</div>
</details>


<details>
<summary> View→ Transformations(중요⭐️) </summary>
<div markdown="1">

### View Transformations

**Coordinate System(Frame)**

좌표 시스템은 일반적으로 3차원 공간에서 사용되며, XYZ 축을 기준으로 정의된다. 일반적으로 오른손 좌표계를 사용하며, X 축은 오른쪽, Y 축은 위쪽, Z 축은 화면 바깥쪽을 가리킨다. 이러한 좌표 시스템은 객체의 위치, 회전, 크기 조정 등을 나타내는 데 사용된다

**OpenGL에서는 직교 정규 프레임에만 관심이 있다.**

- 직교 : 기저 벡터들이 서로 직교 즉, 수직한다.
- 정규 : 각 기저 벡터의 길이가 1이라는 것을 의미한다.
    
    ⇒ 즉, 각 축의 단위 길이가 1인 것을 의미
    

**OpenGL 카메라 좌표계는 다음과 같은 조건을 따른다.**

- Center of projection 는 원점에 배치된다.
- 오른손 좌표계를 이용한다.
    - X 축은 오른쪽 방향을, Y 축은 위쪽 방향을, Z 축은 화면 뒤쪽 방향
    - 위와 같은 방향으로 값이 증가한다.

<img width="222" alt="1" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/532f56d9-1100-4621-bb1b-4699f8788607">


**OpenGL gluLooAt() 함수를 적용 할 때**

- 월드 좌표계에서의 카메라 회전 R_c
- 월드 좌표계에서의 카메라 이동 T_c
- 카메라는 강체이기 때문에 스케일은 없다.

**따라서 월드 좌표계에서의 카메라의 위치는  V(view)= T_c * R_c가 된다.**

<aside>
❗ 카메라 위치를 이용하여 카메라 좌표계 0,0,0을 셋팅

</aside>

하지만 우리가 원하는 것은 월드 좌표계에서의 위치가 아닌 **카메라 좌표계에서의 위치**이다.

- 현재 월드 관점에서의 카메라 위치 : V = T*R
- 카메라의 관점으로 변환하려면 모두 역행렬을 구해준다.
    - **V^-1 = R_c^-1* T_c^-1**

세상의 관점에서 카메라가 놓인 좌표 V = T*R이라면

**카메라 관점에서 본 세상은 V^-1 = R_c^-1* T_c^-1이 된다.**

**이 때 이 역변환을 구해주는 함수가 gluLookAt() 함수이다.**

**ViewMatrix V^-1** 

- 회전행렬의 역행렬은 전치행렬

<img width="933" alt="2" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/378fd2a1-f50d-4641-a542-8bd95e57c07c">

</div>
</details>

<details>
<summary> Vertex Processor - ModelView Matrix(중요⭐️⭐️⭐️) </summary>
<div markdown="1">

### ModelView Matrix

카메라 관점에서 바라본 물체를 그리는 것 (카메라 + 물체)

ModelView Matrix는 모델 변환과 뷰 변환을 결합한 변환 행렬이다. 이 행렬은 객체의 모델 좌표를 월드 좌표로 변환하고, 그리고 월드 좌표를 카메라 좌표로 변환하는 데 사용한다

- 모델 좌표 → 월드 좌표
- 월드 좌표 → 카메라 좌표
- view matrix 와 model matrix로 구성되어 있음
- Model Matrix : 물체가 어떻게 월드에 놓여져 있는지
- View Matrix : 카메라가 어떻게 월드에 놓여져 있는지
- **ModelView 행렬을 객체 좌표에 곱하면 카메라 좌표를 얻을 수 있다.**

X_view = V^-1 * M * X_obj ⇒ 물체의 좌표를 카메라의 관점으로

V^-1 * M 을 ModelView matrix라고 부른다.

**1차원의 경우에서 생각 - Model**

1. **월드의 원점에 오브젝트를 하나 생성**
- X_world = X_obj (객체와 object의 원점은 동일한 상태) ⇒ 두 좌표계가 동일함

<img width="656" alt="1" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/41ad4f0d-0b34-4a96-ba44-d2c94e53b705">

1. **물체를 World에서 분리하기 위해 model Matrix 연산**
- X_world = M*X_obj

<img width="639" alt="2" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/99877425-b0db-4b3c-8e61-4a48145cbe76">

**1차원의 경우에서 생각 - Camera**

1. **월드의 원점에 카메라 하나 생성**
- X_world = X_view  ⇒ 두 좌표계가 동일함

<img width="615" alt="3" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/664d5b0a-1f8e-41c1-b1fc-38471d6f89b5">

1. **카메라를 World에서 분리하기 위해  ViewMatrix 연산**
- X_world = V*X_view

<img width="601" alt="4" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/609cd015-c345-4af7-b35e-000c8bdcfd0a">

**1차원의 경우에서 생각 - ModelView**

- X_world = M * X_obj
- X_world = V * X_view

$$
⇒ M * X_o =  V * X_v
$$

                                                                          

$$
⇒ X_v = V^-1 * M * X_o
$$

<img width="607" alt="5" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/c8526fb8-53df-42f3-a470-cdb4be533430">

**물체에 대한 좌표값을 넣으면 카메라에서 바라본 물체의 좌표값을 알 수 있다.**

**X_view = V^-1 * M * X_obj**  

<img width="864" alt="6" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/c046f249-22fc-473e-a1fb-baee6618f28f">

<aside>
❗ **ModelView Matrix = V^-1 * M**

$$
V^-1 M
$$

</aside>

- GL_MODELVIEW_MATRIX

**위와 같은 ModelView Matric를 이용하면 월드와 독립적인 카메라의 상대적인 물체의 위치에  대한 정보를 얻을 수 있다. 즉, 월드를 고려하지 않고 카메라와 객체와의 관계가 된다.**

</div>
</details>


<details>
<summary> Vertex Processor -Projection Matrix </summary>
<div markdown="1">

### Projection Matrix

3D 장면을 2D 화면에 투영하는 변환 행렬이다. 이는 3D 공간에서의 객체와 카메라의 관계를 2D 화면 좌표로 매핑하는 역할을 수행한다.

1. Perspective Projection (원근 투영):
- 실제 세계에서의 원근감을 모방하여 3D 장면을 2D로 투영한다. 이는 시점에 따라 멀어지는 객체가 작아지고, 가까이 있는 객체가 크게 보이는 시각적 효과를 제공한다. 주로 시뮬레이션, 게임, 가상 현실 등에서 사용됩니다. Perspective Projection은 시야각(Field of View), 종횡비(Aspect Ratio), Near Plane과 Far Plane의 클리핑 범위 등을 고려하여 정의된다
1. Orthographic Projection (직교 투영)
- 원근감 없이 3D 장면을 2D로 투영한다. 이는 객체의 크기와 거리를 변하지 않게 유지하며, 모든 객체를 동일한 크기로 표현한다. 주로 공학 그래픽스, 기하학적 모델링, 텍스쳐 매핑 등에서 사용된다. Orthographic Projection은 간단한 수학적 변환으로 정의된다.

3차원의 무한한 공간의 물체들을 모두 다 그릴 필요도 없고 그릴 수도 없다 .이 때 무한한 공간을 유한한 공간으로 클리핑 해야 한다. 

$$
Xc = P*Xview
=> X = P * V^-1 * M * Xo
$$

—# canonical volume

- Canonical View Volume은 컴퓨터 그래픽스에서 투영 변환(Projection Transformation)을 적용하기 전에 장면을 정의하는 3D 공간이다. 이는 투영 변환을 적용하기 전의 공간으로, 투영 공간(projection space) 또는 클리핑 공간(clipping space)으로도 알려져 있다.
- Canonical View Volㅎume은 일반적으로 정육면체 형태를 가지며, 정규화된 크기와 위치로 정의하며 x, y, z 축은 -1에서 1 사이의 범위를 가진다.

<img width="602" alt="1" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/25f79bba-5707-4e23-bd92-0328d5c0bc1d">

</div>
</details>


<details>
<summary>  Clipper and primitive assembeler, Rasterizer </summary>
<div markdown="1">

### Clipper and primitive assembeler - Clipping

카메라의 시야에 들어오지 않는 영역을 제거하고, 표시되어야 할 부분만을 선택하는 과정이다. 이는 컴퓨터 그래픽스에서 가상의 3D 장면을 실제 화면에 투영할 때 필요한 작업이다.

클리핑은 주로 다음 두 가지 수준에서 수행된다.

- View Frustum Clipping (뷰 프러스텀 클리핑): Clipper 단계에서 이루어지며, 카메라의 시야를 나타내는 뷰 프러스텀(View Frustum) 내부에 있는 객체들을 선택한다. 뷰 프러스텀은 원근 투영에 의해 생성되는 가상의 원뿔 모양의 부피로, 카메라의 시야를 제한하는 영역이다. 뷰 프러스텀에 포함되지 않는 객체는 클리핑되어 제거된다.
- Primitive Level Clipping (원시 레벨 클리핑): Primitive Assembler 단계에서 이루어지며, 여러 개의 기본 도형(primitive)을 구성하는 정점(vertex)들의 클리핑을 처리한다. 예를 들어, 선분의 경우 시작점과 끝점이 시야 범위를 벗어나는 경우 해당 선분을 클리핑하여 제거한다.

**Line - Segment Clipping**

선분 클리핑은 2D 그래픽스에서 주로 사용되며, 선분이 화면을 벗어나거나 부분적으로 겹치는 경우에 유용하다. 이를 통해 화면에 보이는 영역만을 선택하여 렌더링할 수 있다

- 선분이 뷰 볼륨을 통과하는지 확인한다. 선분의 양 끝점이 뷰 볼륨 내부에 있는지 확인하고, 내부에 있는 경우 선분은 클리핑을 거치지 않고 그대로 유지된다.
- 선분이 뷰 볼륨을 벗어나는지 확인합니다. 선분의 양 끝점 중 하나가 뷰 볼륨 밖에 있는 경우, 해당 선분은 뷰 볼륨과의 교차점을 찾아 해당 부분만을 남기고 나머지는 버린다.
- 선분이 뷰 볼륨 내부에서 부분적으로 겹치는 경우, 교차점을 찾아 해당 부분만을 남기고 나머지는 제거한다. 이는 선분이 뷰 볼륨 내부로 들어와서 나가는 경우에 해당한다

**Polygon Clipping**

다각형 클리핑은 2D 그래픽스에서 주로 사용되며, 다각형이 화면을 벗어나거나 부분적으로 겹치는 경우에 유용하다. 이를 통해 화면에 보이는 영역만을 선택하여 렌더링할 수 있다.

클리핑은 일반적으로 다음과 같은 단계로 수행됩니다:

- 다각형의 각 변과 뷰 볼륨 각 면의 교차점을 찾는다. 이를 통해 다각형의 변이 뷰 볼륨과 교차하는 부분을 식별한다
- 교차점을 이용하여 다각형의 새로운 변을 생성한다. 이렇게 생성된 변은 뷰 볼륨 내부에 있는 부분을 나타낸다.
- 다각형의 내부에 있는 영역을 찾아 해당 부분을 남기고, 나머지 부분은 제거한다. 이는 다각형이 뷰 볼륨 내부로 들어와서 나가는 경우에 해당한다.

<img width="516" alt="1" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/bf93be1f-03e8-4a7d-a822-c79c4fa16bb9">


**Bounding Boxed and Volumes**

바운딩 박스나 바운딩 볼륨은 객체의 **복잡한 형태를 단순화**하여 클리핑 작업을 효율적으로 수행할 수 있도록 도와준다. 복잡한 다각형이나 객체에 대해 정확한 클리핑 작업을 수행하는 대신, 바운딩 박스나 볼륨을 사용하여 클리핑의 범위를 제한하고, 불필요한 연산을 줄일 수 있다. 이는 그래픽스 처리를 효율적으로 하고 렌더링 성능을 향상시키는 데 도움을 준다.

- 하드웨어가 아무리 뛰어나더라도 소프트웨어에서도 처리를 해줘야 한다.

<img width="663" alt="2" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/73785961-1e31-44b6-ac7f-c9170db91313">

### Rasterizer - Rasterization

**Rasterization(Scan Conversion)**

3D 장면을 **픽셀 그리드로 변환하는 과정**을 의미한다이 과정은 렌더링되는 객체를 화면에 픽셀 단위로 표현하기 위해 필요하다.

1. Fragment Location (프래그먼트 위치): Rasterization은 기본 도형의 정점들로 지정된 도형 내부에 있는 픽셀들을 결정한다. 이를 위해 프래그먼트(fragment)의 위치를 계산한다. 프래그먼트는 픽셀 그리드에서 렌더링될 수 있는 작은 단위로, 기본 도형 내부에 위치한 픽셀들을 나타낸다
2. Per-Fragment Attributes (프래그먼트 속성): 프래그먼트의 속성은 보통 정점들의 속성을 기반으로 결정된다. **이는 보간(interpolation)을 통해** 정점들의 속성 값을 프래그먼트에 전달하는 과정이다. 예를 들어, 색상이나 텍스처 좌표와 같은 속성은 정점들의 값에서 보간되어 프래그먼트에 적용된다.

**Bilinear interpolation(이중 선형 보간)**

- 선 상의 색상 보간: 이중 선형 보간은 먼저 **선 상의 색상을 보간한다**. 예를 들어, 선분 상에 두 개의 점이 주어진 경우, 이중 선형 보간은 두 점의 색상을 **선 상에서 보간하여 중간 지점의 색상을 결정**한다. 이를 통해 선분 위의 픽셀들에 대한 색상을 부드럽게 변화시킨다.
- 각 스캔 라인에서의 색상 보간: 이중 선형 보간은 두 점 사이의 색상 보간을 각 스캔 라인에 적용한다. 예를 들어, 두 점 사이를 연결하는 선분이 여러 개의 수평 스캔 라인을 가로지르는 경우, 각 스캔 라인에서의 색상을 보간하여 픽셀들의 색상을 결정한다. 이를 통해 수평 방향으로도 색상을 부드럽게 변화시킨다.

**Hidden Surface Removal**

Hidden Surface Removal(가려진 표면 제거)은  화면에 표시될 객체들 중에서 다른 객체에 의해 **가려진 표면을 제거하는 과정**을 말한다. 이를 통해 시야에서 보이지 않는 표면을 제거하여 효율적인 렌더링을 가능하게 한다

- Z-buffering: Z-buffer는 각 픽셀에 대해 가장 가까운 표면의 깊이 값을 저장하는 버퍼이다. 렌더링 과정에서 각 픽셀의 깊이 값을 계산하고, Z-buffer와 비교하여 **현재 픽셀의 깊이가 더 가까운 경우에만 표면을 표시한다**. 이를 통해 **가장 가까운 표면만을 표시**하고, 다른 표면은 가려진다.

- Painter's algorithm : 이 알고리즘은 물체를 그리는 순서를 기반으로 동작하여 가장 먼저 그려지는 물체가 가장 뒤에 있는 물체로 간주되어 가려진 표면을 처리한다. 모든 물체를 그리는 순서를 결정한다. 이는 가장 뒤에 있는 물체가 먼저 그려지고, 그 위에 있는 물체가 그 다음에 그려지도록 순서를 정하는 것을 의미한다. 이를 통해 물체가 겹치는 경우, 가장 뒤에 있는 물체가 가려지지 않고 표시된다. 결정된 그리기 순서에 따라 물체를 그린다. 각 물체는 그림자, 반사 등의 효과를 고려하여 표면을 그리게 된다. 가장 먼저 그려지는 물체는 뒷면에 있는 물체로 간주되어 가려진 표면이 제거된다.
    - 물체들이 서로 교차하는 경우나 투명한 물체를 다루는 경우에는 정확한 결과를 얻을 수 없다

<img width="639" alt="3" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/834e2335-7180-43e8-80de-5bcaf8a2c690">

클리퍼와 프리미티브 어셈블러 - 클리핑:

- 클리핑은 컴퓨터 그래픽스에서 시야에 들어오지 않는 영역을 제거하고 필요한 부분만 선택하는 과정입니다.
- 뷰 프러스텀 클리핑은 카메라 시야를 나타내는 뷰 프러스텀 내부에 있는 객체를 선택합니다.
- 원시 레벨 클리핑은 기본 도형을 구성하는 정점들의 클리핑을 처리합니다.
- 선분 클리핑은 선분이 화면을 벗어나거나 겹치는 경우 해당 부분만 선택하여 렌더링합니다.
- 다각형 클리핑은 다각형이 화면을 벗어나거나 겹치는 경우 해당 부분을 선택합니다.
- 바운딩 박스나 볼륨을 사용하여 복잡한 객체의 클리핑을 단순화하고 연산을 줄여 효율적인 처리를 도와줍니다.

래스터라이저와 래스터화:

- 래스터라이저는 3D 장면을 픽셀 그리드로 변환하는 과정입니다.
- 래스터라이저는 객체의 정점들로 지정된 도형 내부에 있는 픽셀들을 결정합니다.
- 프래그먼트의 위치를 계산하고, 보간을 통해 정점들의 속성 값을 프래그먼트에 전달합니다.
- 이중 선형 보간을 사용하여 선 상의 색상을 보간하고, 각 스캔 라인에서의 색상을 보간합니다.
- 래스터라이저는 프래그먼트의 속성을 계산하여 화면에 픽셀 단위로 표현합니다.
- 가려진 표면 제거는 다른 객체에 의해 가려진 표면을 제거하여 효율적인 렌더링을 가능하게 합니다.
- Z-버퍼링과 Painter's 알고리즘을 사용하여 가려진 표면을 처리합니다.

</div>
</details>

<details>
<summary> ShaderProgramming  </summary>
<div markdown="1">

### Fixed Rendering Pipeline

기존에 프로그래밍 불가능했던 시절 렌더링 과정

Vertex Processor 

- 정해진 정보 이외의 정보를 줄 수 없었다.(만약 주려면 속여서 줘야 했음
- Postion, Normal, Color …

Fragment Processor 

<img width="798" alt="1" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/e661be06-3390-4ec2-98b8-4e47c746412b">

위 과정에서 보는거와 같이  Color는 Vertex processor에서 결정되므로 특정 fragment의 값을 변경할 수 없었다. 만약 특정 fragment값을 변경하려면 Vertex부터 값을 전달해야 했음

**Programmable Rendering Pipeline**

기존에 프로그래밍 불가능했던 시절과 다르게 Vertex와 Fragment 부분을 Shader를 통해 프로그래밍 가능

<img width="776" alt="2" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/f8297d1b-b877-4424-bc23-977fdb1a7736">


### **Limitation on Fixed Rendering Pipeline**

**Per-vertex Lighting vs Per-pixel Lighting**

Per-vertex Lighting과 Per-pixel Lighting은 **조명 계산을 어떤 단계에서 수행**하는지에 따라 다른 방식의 조명 모델링 기법이다.

- Per-vertex Lighting 
**Vertex Shader에서 조명 계산을 수행하는 방식이다.** 이 방법은 각 정점의 조명 정보를 계산하고, 그 결과를 정점 색상에 적용하여 근사적인 조명 효과를 생성한다. Vertex Shader는 3D 모델의 정점마다 한 번씩 실행되기 때문에 **계산 횟수가 적어지고 처리 속도가 빠르지만**, 정점 사이의 보간으로 인해 **조명의 부드러움이 제한될 수 있다.** 특히, 면이 평면이나 곡면과 같은 부드러운 곡선을 가질 경우에는 근사 오차가 발생할 수 있다.
    - 기존 Fixed rendering pipelin에서 사용하는 방법이다.
- Per-pixel Lighting 
**Fragment Shader에서 조명 계산을 수행하는 방식이다.** 이 방법은 **Rasterizer** 단계에서 모든 픽셀에 대해 조명 정보를 계산하고, 픽셀의 정확한 색상을 결정한다. Fragment Shader는 모든 픽셀마다 실행되기 때문에 **더 정확한 조명 효과를 제공할 수 있다**. 그러나 계산 횟수가 많아지므로 **처리 속도가 상대적으로 느릴 수 있다.**
    - Rasterizer단계에서  [**Bilinear interpolation(이중 선형 보간)**](https://www.notion.so/Bilinear-interpolation-31eacbc06dcd4d5cbf7edd9dc19c8e95?pvs=21) 을 통해 fragment마다 normal을 만들 수 있다.
    - Progremmable rendering pipline에서 사용할 수 있는 방법이다.
    
    <img width="629" alt="3" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/7f09b516-0695-40a1-badf-030a7042c3a7">
    

<img width="675" alt="4" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/dffc1fa3-43d9-4c1a-8a1c-a976a5948c0c">

따라서 기존에 Vertex에서 수행해야 하는 로직들을 Fragmet에서 수행할 수 있음

<img width="801" alt="5" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/f13f5e6b-2f4c-4823-a872-9a40de58d4b8">

### Shader Programming at a glance

```cpp
// Vertex Shader
#version 120

uniform mat4 u_PVM; // 전역변수 ModelView Maxtrix(projection)

attribute vec3 a_position; // 각각의 정점에 대한 정보(input)
attribute vec3 a_color; // 각각의 정점에 대한 색상(input)

varying vec3 v_color; // 정점에 대한 색상을 fragment로 보내주는 변수

void main()
{
	gl_Position = u_PVM * vec4(a_position, 1.0f);
	v_color = a_color;
}
```

```cpp
// Fragment Shader
#version 120

varying vec3 v_color; // vertex에서 보낸 색상에 대한 정보를 변환

void main()
{
	gl_FragColor = vec4(v_color, 1.0f);
}
```

ModelView Matrix를 전역변수로 설정하면 vertex마다 만들 필요가 없다.

<img width="737" alt="6" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/20ca281f-1fb6-47c5-a9f1-1cbdc5a7b3e5">

**Vertex Shader, Fragment Shader and Program Obj**

```cpp
void init_shader_program()
{
	GLuint vertex_shader
		= create_shader_from_file("./shader/vertex.glsl", GL_VERTEX_SHADER);
	assert(vertex_shader !=0);

	// Vertex Shader 연결

	GLunit fragment_shader
		= create_shader_from_file("./shader/fragment.glsl", GL_FRAGMENT_SHADER);
	assert(fragment_shader !=0);

	// Fragment Shader 연결

	
	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);
	assert(program != 0);
	// Vertext & Fragment Link

	loc_u_PVM = glGetUniformLocation(program, "u_PVM");
	loc_a_position = glGetAttribLocation(program, "a_position");
	loc_a_color = glgetAttribLocation(program, "a_color");
}
```

```cpp
void render_object()
{
	glUseProgram(program);  // 프로그램 사용
	
	//ModelView setting
	mat_PVM = mat_proj * mat_view * mat_model; 
	glUniformMatrix4fv(loc_u_PVM, 1, GL_FALSE, mat_PVM); 

	// VBO를 사용하여 각각의 정점에 대하 속성 Load
	glBindBuffer(...);
	glEnableVertexAttribArray(...);
	glVertexAttribPointer(...);

	// vertex 그리기
	glDrawArrays(...);
}
```

모던 OpenGL에서는 Vertex Shader 에서 ModelView/Projection변환을 직접 처리해야 하며, **glVertexAttribPointer()** 함수를 사용하여 정점 속성을 정의하고 활성화해야 한다. 버텍스 속성은 정점과 관련된 데이터를 나타내며, 쉐이더 프로그램에서 사용된다. **이를 통해 더 유연하고 강력한 버텍스 처리를 수행할 수 있다.**

### **More About Shader Programming**

현재 OpenGL Rendering Pipeline

<img width="721" alt="7" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/a6aa7481-2a26-4190-908b-a9cb3971c101">

**Uniforms**

<img width="721" alt="8" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/26d55fd0-5e56-45b0-a898-73efe9935ad5">

- 렌더링 중에 **변경되지 않는 값들을 선언**하는데 사용
    - 빛의 위치, 카메라의 위치, 텍스처 유닛 등과 같이 렌더링 동안 변하지 않는 값
- Vertex Shader 와 Fragment Shader에서 모두 사용할 수 잇으며 이는 **동일한 프로그램 내에서 데이터를 전달하는 데 사용**된다.
- 읽기 전용으로 사용된다. 쉐이더 내에서는 해당 값을 **읽을 수만 있고 수정할 수는 없다.**
    - 애플리케이션에서 직접 API 명령을 사용하여 초기화할 수도 있고, OpenGL에서 간접적으로 초기화할 수도 있다.

**Attributes**

<img width="712" alt="9" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/d9e405a4-3d2f-43a7-b7d3-9ea050f0115c">

- 변하는 값을 선언하는데 사용된다
    - 버텍스의 위치, 법선 벡터, 색상 등과 같이 각 버텍스마다 다른 값을 가지는 데이터
- **Vertex Sahder에서만 사용할 수 있다. Fragment Sahder에서는   값을 직접 읽을 수는 없고, Vertex Shader에서 처리된 값을 보간하여 사용한다.**
- 읽기 전용으로 사용된다. 쉐이더 내에서 해당 값을 읽을 수만 있고 수정할 수는 없다. Attributes는 버텍스 데이터의 특성을 나타내는 용도로 사용되며, 렌더링 중에 값이 변경되지 않는다.
    - Attributes는 OpenGL 버텍스 API를 통해 전달되거나, 버텍스 배열의 일부로 전달된다. 즉, Attributes는 버텍스 데이터가 저장된 버퍼에서 값을 읽어와 사용하거나, 애플리케이션이 API를 통해 직접 어트리뷰트 값을 설정할 수 있다.

**Varyings**

<img width="718" alt="10" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/e3058a67-5b30-4665-9e57-0efadbefa296">

- **Varying은** Vertex Shader에서 Fragment Shader로 데이터를 전달하기 위해 사용된다.
    - Vertex Shader에서 계산된 값이 Fragment Shader에 전달되어 픽셀 단위에서 보간(interpolation)되어 사용될 수 있다.
- Varing은 Vertex Shader에서 읽기/쓰기가 모두 가능하며 계산된 값이 Varing에 저장되고, 이후 Fragment Shader에서 읽을 수 있다.
- Varing은 Fragment Shader에서는 읽기 전용으로 사용된다.

**Specifying Uniform / Vertex Attribute Data**

```cpp
// Vertex Shader
#version 120

uniform mat4 u_PVM; // 전역변수 ModelView Maxtrix(projection)

attribute vec3 a_position; // 각각의 정점에 대한 정보(input)
attribute vec3 a_color; // 각각의 정점에 대한 색상(input)

varying vec3 v_color; // 정점에 대한 색상을 fragment로 보내주는 변수

void main()
{
	gl_Position = u_PVM * vec4(a_position, 1.0f);
	v_color = a_color;
}
```

```cpp
// Fragment Shader
#version 120

varying vec3 v_color; // vertex에서 보낸 색상에 대한 정보를 변환

void main()
{
	gl_FragColor = vec4(v_color, 1.0f);
}
```

```cpp
// Modern OpenGl codes
GLint loc_u_PVM, loc_a_position, loc_a_color;

void init_shader_program()
{
	// Vertex Shader 연결
	// Fragment Shader 연결

	
	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);
	assert(program != 0);
	// Vertext & Fragment Link

	loc_u_PVM = glGetUniformLocation(program, "u_PVM");
	loc_a_position = glGetAttribLocation(program, "a_position");
	loc_a_color = glgetAttribLocation(program, "a_color");
}

void render_object()
{
	glUseProgram(program);  // 프로그램 사용
	
	//ModelView setting
	mat_PVM = mat_proj * mat_view * mat_model; 
	glUniformMatrix4fv(loc_u_PVM, 1, GL_FALSE, mat_PVM); 

	// VBO를 사용하여 각각의 정점에 대하 속성 Load
	glBindBuffer(...);
	glEnableVertexAttribArray(...);
	glVertexAttribPointer(...);

	// vertex 그리기
	glDrawArrays(...);
}
```

- **`glGetUniformLocation()`** : 프로그램 내의 uniform 변수의 위치를 가져온다.
- **`glGetUniform()` :**  연결된 쉐이더 프로그램에서 Uniform 변수의 값을 설정하는 데 사용된다.
    
    ```cpp
    // location specify the location of the uniform value to be modified
    // v0, v1, v2, v3  specify the new values to be used for the specified uniform variable
    void glUniform1f(GLint Location, GLfloat v0); 
    void glUniform2f(GLint Location, GLfloat v0, GLfloat v1); 
    void glUniform3f(GLint Location, GLfloat v0, GLfloat v1, GLfloat v2); 
    void glUniform4f(GLint Location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3); 
    
    // Location specify the location of the uniform value to be modified
    // count     specify the number of matrices that are to be modified (usually 1)
    // transpose specify whether it is transpose or not (MUST be GL_FALSE)
    // value     specify a pointer to an array of count values
    void glUniformMatrix2fv(GLint Location,  GLsizei count, GLboolean transpose, const glfloat* value);
    void glUniformMatrix3fv(GLint Location,  GLsizei count, GLboolean transpose, const glfloat* value);
    void glUniformMatrix4fv(GLint Location,  GLsizei count, GLboolean transpose, const glfloat* value)
    ```
    
- **`glGetAttribLocation()` :**  attibute 변수의 위치를 반환한다.
    
    ```cpp
    GLint glGetAttribLocation(GLuint program, const GLchar* name);
    ```
    
- **`glVertexAttribPointer()` :**  OpenGL에게 정점 데이터가 어떻게 구성되어 있는지 알려주는 역할
    
    ```cpp
    void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
    ```
    
- **`glenableVertexAttribArray()gldisablevertexAttribArray()` :**  OpenGL에게 정점 속성 배열을 사용하도록 지시하거나 사용하지 않도록 지시하는 역할
    
    ```cpp
    // index: 활성화 또는 비활성화할 정점 속성의 인덱스를 나타내는 값으로,
    //  glVertexAttribPointer() 함수에서 지정한 인덱스와 일치해야 한다
    void glEnableVertexAttribArray(GLuint index);
    void glDisableVertexAttribArray(GLuint index);
    ```

</div>
</details>

<details>
<summary> ⭐️⭐️⭐️Shading </summary>
<div markdown="1">

### Light

- 하나의 Input → Multipil Output
    - Tree 구조와 비슷하며 깊어짐에 따라 계산부담

- OpenGL에서는 Global Effect를 과감하게 포기
- 대부분의 빛은 난반사(Diffuse)

**Light - Material Interaction**

<img width="593" alt="1" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/bc765459-eb60-438c-8cf3-3aa375311a74">

**Color of the Object**

- 색은 빛이 가지고 있음
- 물체는 재질을 가지고 있음
    - 물체는 색이 아닌 재질을 가지고 있고 빛을 얼마나 흡수하고 튕겨내는지에 따라 색이 달라보임

**Color**

- 실제로 색은 광원만 가질 수 있음
- 태양(백색 광원)에 대한 해당 물체가 얼마나 반응하는지에 따른 변화

**Bidirectional Reflection Distribution Function(BRDF)**

- Physically correct model
    - light direction
    - viewer direction
    - frequency of the light
    
    특정 지점에 대해서 빛이 어떻게 반응하는지 알고싶다면 
    
    카메라의 위치와 광원의 위치를 서로 바꿔가면서 빛이 얼마나 들어가는지에 대한 분포를 측정 
    
    **⇒ 한 지점에 대해서 빛이 관찰자 대비 어떤식으로 컬러로서 반응하는지 알아낼 수 있음 (재질을 알 수 있음)**
    
    <img width="644" alt="2" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/bdd1e804-f617-47b6-ae9b-1b7d3416b1e5">
    

**Rendering Equation**

- Global Effects with BRDF
- 해당 지점을 무슨 컬러로 보는지

<img width="579" alt="3" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/26274a2f-dc4f-4572-8bd7-4d13c07654ed">

- X라는 지점의 W’방향으로 빛이 들어오면 나가는 방향은 수직방향
- 그 중 오메가 방향으로 나가는 것만 (비율)
    
    <img width="589" alt="4" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/108daaf3-cee7-465a-92ff-f3f6eb44371b">
    
- i방향으로 들어온 빛 : Li(실제 컬러가 있음)

비율 * 빛의 세기 

### **⭐️⭐️⭐️** Phong Reflection Model

**Local lighting model**

<img width="647" alt="5" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/ae8542b2-9045-4f10-8531-8c333e61c88c">

**Ambient Redlection(주변광)**

- Ambient reflection accounts for the samll amount of light that is scattered about the entire scene
- Intensity of ambient light = 비율 * illumination of ambient light
    - 각각의 빛 마다 ambient 와 각각의 물체마다 얼마나 튕겨내는 지에 대한 비율
- **빛의 Ambient 요소를 부여 ⇒ La**
- **물체의 Ambient light에 얼마만큼 반응하지를 부여 ⇒ Ka**

<img width="612" alt="6" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/9d66e652-a8ca-4857-b385-fa6673bf7f46">

**Diffuse Reflection(난반사광)**

그래픽스에서 lambertian reflectance를 원함 → 모두 동일한 방향으로 반사가 된다고 가정

1. 빛이 해당 지역을 얼마만큼 강한 빛으로 때렸는지 계산
- light와 normal을 내적 계산 ⇒ Cos(θ)
    - Cos(θ)  == 1 : 바로 위에서 때림
    - 그만큼 튕겨냄
1. 모든 방향으로 동일하게 위와 같은 계산

<img width="646" alt="7" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/d9103e52-1276-4089-aabb-1a385c400780">

- **빛의 D iffuse요소를 부여 ⇒ Ld**
    - RGB, alpha
- **물체의 Diffuse Reflection에 얼마만큼 반응하지를 부여 ⇒ Kd**
    - 1이면 받아들임
    - max((l dot n), 0)
    
    <img width="197" alt="8" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/1ca73119-32b4-4f9b-8d62-9e9def7f5d65">
    
    ```cpp
    float mat_Kd[4] = {0.1f, 0.1f, 0.1f, 0.1f};
    // 얼마나 튕겨 낼지 R, G, B, Alpha
    
    float light_Ld[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    // 백생광
    
    float light_pos[4] = {-2.0f, 2.0f, 2.0f, 1.0f};
    ```
    
    - X = Verext input으로 자동으로 결정
    - N = Verex Attribute
    - L = Light_position - X
        
        Graphics/assets/79856225/7c042bf0-00b5-4780-a25b-bae154791a30">
        
    
    <aside>
    ❗ Light가 물체의 밖에서 물체를 때리기 때문에 값이 음수가 나온다면 물체 안에서 Light가 때리는게 되기 때문에 max값을 취해야 한다.
    
    </aside>
    

**Specular Reflection(정반사광)**

Noraml의 반대만큼 반사되야 함

- 하나의 점 p에  빛l이 반사되면 norml의 반대만큼 즉 r만큼 반사가 된다.
- 이 때 눈의 방향이 v라면 r에 가까울수록 더욱 빛이 잘 보임

<img width="710" alt="9" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/7c042bf0-00b5-4780-a25b-bae154791a30">

- **r dot v가 1에 가까울수록 빛나게 보임**
- **빛의 Specular 요소를 부여 ⇒ Ls**
    - RGB, alpha
- **물체의 Specular Reflection에 얼마만큼 반응하지를 부여 ⇒ Ks**
    - 1이면 튕겨냄

**Shinicess Coefficient in Specular Reflection**

광원 하나의 다음과 같이 각각 RGB가 있음

- ambient ⇒ RGB
    - RGB를 얼마나 튕겨낼지 1이면 그대로 튕겨냄(물체)
    - 0는 안보임
- diffuse ⇒ RGB
    - 그 지점이 light를 얼마나 똑바로 보는지
        - 전체적으로 확인
- specular ⇒ RGB
    - 1이면 튕겨냄
    
    <img width="533" alt="10" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/39010829-ce08-4cb4-80d3-e632c486fe78">
    
    Phong Reflection Model

</div>
</details>


<details>
<summary> Computing Per-vertex Normals </summary>
<div markdown="1">

- **삼각형 mesh가 있다면 어떻게 normal을 계산**
    - 한 점을 기준으로 오른쪽 cross product
    - p0 ⇒ cross_product(p1 - po)
    - corss_product(p2- p0)
    
    <img width="679" alt="1" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/3023d09d-c0b3-4364-a07e-e9e2c6831ffe">
    

- 모든 Polygon단위로 normal을 계산
- 각각의 vcertex에 대해서 인접한 Polygon들의 normal을 합침
- 길이로 나눠서 단위 벡터로
- cpu에서 한 번만 계산/

<img width="720" alt="2" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/f4871728-de90-4574-9707-0948e44c1b90">

<img width="462" alt="3" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/c16adea3-dc5f-4b9c-b832-bbe1d335713e">


</div>
</details>

<details>
<summary> Texture Mapping, Blending  </summary>
<div markdown="1">

### Texture Mapping Basics

복잡한 디테일을 반영하기 힘들다. 

표면 위에 스티커를 붙인다는 개념

![1](https://github.com/junyong1111/Computer-Graphics/assets/79856225/835bbe1e-7dcc-4b49-a549-40e18556a8a6)

- 텍스쳐의 좌표값을 이용하여 mapping
    
    <img width="445" alt="2 오후 7 05 02" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/d86111d2-8e72-40c5-ae87-9f0ad2c809a0">
    

**texture image + textre 좌표값**

### **Sampling Problem**

**Aliasing**

디지털 이미지나 신호를 표현할 때 공간적인 샘플링 문제로 발생하는 현상이다. Aliasing은 연속적인 신호를 이산화된 형태로 표현할 때, 원래 신호에는 없던 추가적인 주기적인 패턴이나 왜곡이 나타나는 것

<img width="425" alt="3" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/0e7e07af-1a7e-4228-b32d-1f5ede06ac64">

<img width="383" alt="4" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/718baae6-86b3-4eac-addc-bc5640e539cc">

내가 가진 정보보다 sampling 횟수가 작기 때문에 정보의 왜곡이 발생

⇒ 빠르게 주행하는 바퀴가 역방향으로 도는것 처럼 보임

⇒ 샘플링 횟수를 증가 하거나, antialiasing을 사용하여 뭉개버림(완화)

**AntiAliasing**

<img width="426" alt="5" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/d2bb593f-0c00-489b-818d-00903fbb4e4b">

**Aliasing - Magnification**

- Texture 이미지가 4픽셀로 작음
- 매핑하려는 이미지가 4픽셀보다 더 큰 경우
- 카메라에 가까운 부분

**Aliasing - Minification**

- Texture 이미지가 40픽셀로 큼
- 매핑하려는 이미지가 40픽셀보다 더 작은 경우
- 카메라에서 먼 부분

<img width="394" alt="6" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/fd59e938-4f4a-4403-9689-b2664c76fbbc">

**해결 방법**

- **Nearest sampling**
    - **픽셀의 중앙지점과 texture의 중앙 지점을 샘플링**
    - ex) 1시간 공부 → 부모님이 들어옴 → 쉬고 있음 ⇒ 계속 쉬고 있다고 판단
    - 정보의 왜곡이 많음
    - 속도 빠름
- **Linear sampling**
    - 픽셀을 서브 픽셀(4개)로 자름 (왼쪽위, 왼쪽아래, 오른쪽 위, 오른쪽 아래)
    - 각각의 서브 픽셀과 매핑되는 서로 다른 텍스쳐를 가져와서 각각 25%만큼  곱함
    - 속도 느림
    - 정보의 왜곡이 적음
        
        <img width="355" alt="7" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/bc8caae0-0974-48ba-a6fb-5938b07e203b">
        
        <img width="434" alt="8" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/fe9f1595-5f81-4c17-9289-a78489816cfc">
        
    

### **Advanced Topics of Texture Mapping**

<img width="616" alt="9" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/5218707f-c481-46e8-a7de-588d3b9a718e">

- **Nearsest - point Filtering**
    - magnification에서 떡이 짐
    - 선명함
- **Linear Filtering**
    - 전반적으로 부드러움
    - 선명하지 못함
- **Mipmap**
    
    <img width="536" alt="10" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/4f4377d2-59a9-44c5-a0c0-958c0873ce03">
    
    다양한 해상도 버전을 포함하는 텍스처의 계층적인 표현 즉, 미리 만들어 놓은 텍스쳐를 이용 Mipmap은 주로 텍스처 매핑에서 텍스처 축소(minification) 단계에서 사용된다.
    
    1. 미리 줄여 놓은 이미지를 텍스쳐로 사용
    2. 적당히 잘 줄여진 이미지에서 가져옴
    
    <img width="190" alt="11" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/2c1a1418-4255-445c-bb1e-5fafce65fb5b">
    
    <img width="603" alt="12" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/75f9bfa5-2ae8-4e20-8c86-dcfa1811c7be">
    
    <img width="573" alt="13" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/4fe8b33a-c534-4d61-8bf9-c129b3c07eb6">
    
    - 그리드 + random = poisson
    - 느림
    
    jitter 
    
    - 구역을 정해서 쏠림 현상 방지
    - 많이 쓰인다.
    

**Environment Mapping**

- 물체의 표면에 텍스쳐에 매핑하는것이 아니라
- 물체를 둘러싸는 가상의 Bounding box가 존재하고
- 물체는 Box 안에 있다고 가정
- 그 박스에 texture를 매핑

**Normal Mapping**

기존의 표면 법선 벡터와 Normal Map에 저장된 법선 벡터를 조합하여 새로운 법선 벡터를 생성한다. 이렇게 생성된 법선 벡터는 빛의 입사 방향과 표면의 기하학적 특성에 따라 조명 계산이 수행되며, 입체감 있는 조명 효과가 생성된다.

<img width="710" alt="14" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/ddf227c3-08eb-4e00-b00b-dd006f50be29">

각 텍스처 유닛은 다른 텍스처에 대한 정보를 가지고 있으며, 이러한 정보는 셰이더 프로그램에서 사용됩니다. 셰이더에서는 여러 개의 텍스처 유닛을 통해 다양한 텍스처를 읽어오고, 이를 조합하여 최종적인 색상 값을 계산합니다. 예를 들어, 한 텍스처 유닛에서는 벽돌 질감을 읽어와서 기본 색상 값을 얻고, 다른 텍스처 유닛에서는 녹슬은 금속 질감을 읽어와서 녹슬은 부분의 색상 값을 얻습니다.

**Multi - Texturing**

- 시트지가 2개
    - 바를 때 2개를 합쳐서 바름

<img width="494" alt="15" src="https://github.com/junyong1111/Computer-Graphics/assets/79856225/596cc36c-664e-4f78-badc-c9a3ca311e56">

Multi-Texturing을 구현하기 위해서는 여러 개의 텍스처 유닛(Texture Unit)을 사용한다. 각각의 텍스처 유닛은 독립적으로 텍스처 매핑에 사용되며, 각각의 텍스처 유닛은 다른 텍스처를 바인딩할 수 있다. 예를 들어, 텍스처 유닛 0에는 벽돌 질감을, 텍스처 유닛 1에는 부식된 금속 질감을 할당할 수 있다

**Blending**

- 2개의 칼러를 섞는 것

Aalpha Blending

이는 텍스처나 객체의 표면에 투명도를 적용하여 다른 객체나 배경과 자연스럽게 혼합되는 효과를 만들어낸다. 알파 블렌딩은 텍스처의 알파 채널이나 객체의 알파 값(투명도)을 사용하여 픽셀의 불투명도를 결정하고, 이를 기반으로 다른 픽셀과의 혼합을 수행한다.

</div>
</details>

<details>
<summary> Code </summary>
<div markdown="1">

<details>
<summary> Assimp를 이용하여 Mesh 데이터 모델 읽어 오기  </summary>
<div markdown="1">

Mesh 구조체는 Vertex & traingle list와 triangle soup 자료 구조를 가지고 있다.

Vetex & triangle list

- position
- color
- tv_indices

Triangle soup

- tv_position
- tv_color
1. Assimp의 scence에서 mesh 수 만큼 읽어오기
    
    ```cpp
    for (unsigned int i =0; i< scence->nMumMeshes; ++i)
    ```
    
2. 각각의 mesh의 구조를 옮겨 담기
    
    ```cpp
    const aiMesh* ai_mesh = scence->mMeshes[i];
    Mesh& mesh = g_model.mesh 
    
    // 정점 position 정보 옮기기
    mesh.position.resize(ai_mesh->nNumVertices)// 정점 갯수만큼 resize
    memcy(mesh.positions[0], ai_mesh->mVertices[0], 
    	sizeof(ai_mesh->mVertices[0] * nNumVertices));
    // 메모리를 통째로 옮김(dst, src, sizeof(정점의 갯수))
    
    // 정점 color 정보 옮기기 
    mesh.colors.resize(ai_mesh->nNumVertices)// 정점 갯수만큼 resize
    memcy(mesh.colors[0], ai_mesh->mVertices[0][0], 
    	sizeof(ai_mesh->mVertices[0][0] * nNumVertices));
    // color는 세트가 있으므로 [0][0] 인덱스로 접근해야 함
    
    // 폴리곤 tv_indices 정보 옮기기 (삼각형으로 자름)
    mesh.tv_indices.clear();
    
    for(unsigned int face = 0; face<ai_mesh->nNumFaces; ++face)//face 갯수만큼
    {
    	aiFace& ai_face = ai_mesh->mFaces[i];
    
    	for(unsigned int idx = 0; idx<ai.face.mNumindices-2 ++idx)// 삼각형만
    	{
    		// mNumindices은 현재 몇 각형으로 이루어진 폴리곤인지에 대한 정보
    		// 우리는 모든 폴리곤을 삼각형으로 만들거임 
    		// 0 1 2 -> 삼각형 1개 필요
    		// 0 1 2 3 -> 사각형은 삼각형 2개 필요
    		// n각형은 n-2만큼 반복 돌면 삼각형으로 표현 가능
    		mesh.tv_indices.push_bac(ai_face.mIndices[0]);
    		mesh.tv_indices.push_bac(ai_face.mIndices[idx+1]);
    		mesh.tv_indices.push_bac(ai_face.mIndices[idx+2]);
    	}
    }
    ```
    
3. vectext & list 자료구조를 triangle soup 자료구조로 Update
    
    ```cpp
    // mesh의 삼각형 정보만큼 반복 tv_indices
    for (std::size)t i=0; i<tv_indices.size(); i+=3)
    {
    	unsigned int idx_0 = tv)indices[i];
    	unsigned int idx_1 = tv)indices[i+1];
    	unsigned int idx_2 = tv)indices[i+2];
    
    	// vertex 구조의 position 정보를 triangle soup position 옮기기
    	mesh.tv_positions.push_back(mesh.positions[idx_0]);
    	mesh.tv_positions.push_back(mesh.positions[idx_1]);
    	mesh.tv_positions.push_back(mesh.positions[idx_2]);
    
    // vertex 구조의 color 정보를 triangle soup color 옮기기
    	mesh.tv_colors.push_back(mesh.colors[idx_0]);
    	mesh.tv_colors.push_back(mesh.colors[idx_1]);
    	mesh.tv_colors.push_back(mesh.colors[idx_2]);
    }
    ```
    
4. 버퍼 데이터 생성 및 셋팅
    
    ```cpp
    // 버퍼 생성
    glGelbuffers(1, mesh.position_buffer);
    glGelbuffers(1, mesh.color_buffer);
    
    // 버퍼 셋팅
    // 배열 형태로 보내야 하므로 GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, mesh.position_bueffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * mesh.tv_positions.size(),
    	&mesh.tv_positions[0], GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, mesh.color_bueffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * mesh.tv_colors.size(),
    	&mesh.tv_colors[0], GL_STATIC_DRAW);
    ```

</div>
</details>

<details>
<summary> Vertex shader ⇒ Fragment shader </summary>
<div markdown="1">

```cpp
// vertext shader

// 1.ambient 
color += (u_obj_ambient * u_light_ambient);

// 2. diffuse
// 모든 오브젝트 정보를 월드 정보로 바꿔야 함

// 원래 빛의 방향을 계산하려면 각각의 vetex마다 계산해야 하지만 간소화 가능
// vec3 light_dir = normalize(u_light_position - a_postion);
vec3 light_dir = normalize(u_light_position);

// 원래 정점마다 노멀의 정보를 월드 노멀로 바꾸려면 모델 매트릭스를 곱해줘야 함
//vec3 normal = M * a_normal

// 하지만 normal의 경우 TRS에서 S와 T는 의미가 없기 때문에 R만 곱하면 된다.
// 그리고 이거를 Normal matrix라고 한다.
vec3 normal_wc = normalize(u_normal_matrix * a_normal);

flot ldotn = max(dot(light_dir, normal_wc), 0.0);
color +=   ldotn * u_obj_diffuse * u_light_diffuse;

// 3. Specular
vec3 position_wc = u_model_matrix * vec4(a_position, 1.0f);
// 카메라 위치 - 월드 좌표
vec3 view_dir = (u_camera_position - position_wc);
vec3 reflect_dir = reflect(-light_position, normal_wc);
float rdotv = max(dot(view_dir, reflect_dir), 0.0);
color += (pow(rdotv, u_obj_shininess) * u_light_specular * u_obj_shininess);
```

</div>
</details>

</div>
</details>

<!--
<details>
<summary>  </summary>
<div markdown="1">

</div>
</details>
----------------------
-->
