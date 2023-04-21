# Computer Graphics Midterm exam


### 00. Computer Graphics Overview 

<details>
<summary> 00. Computer Graphics Overview  </summary>
<div markdown="1">

<details>
<summary> Introduction to Computer Graphics </summary>
<div markdown="1">

현재 컴퓨터 그래픽스는 다양한 분야에서 활용되고 있다.

- 컴퓨터 그래픽스 + 컴퓨터 비전
    - 파라노라 사진
    - 3D 맵
- 컴퓨터 그래픽스 + 디지털 이미지
    - 이미지에서 얼굴 탐지, 누끼 따기
    - GAN
- 컴퓨터 그래픽스 + 뉴럴 렌더링
    - NeRF
- 컴퓨터 그래픽스 + 자율주행
    - Video-to-Video Synthesis
    - CARLA
- 컴퓨터 그래픽스 + Mixed Reality
    - QR 코드와 같이 특별한 형식의 마커가 아닌 일반 영상을 마커로 인식
    - 실시간으로 주변호나경에 대한 지도를 작성하고, 지도 내의 현재 위치를 인식
    - 가상현실캐릭터(Anumoji)
    - FaceID
    - Kinect(Microsoft)
- 컴퓨터 그래픽스 + 컴퓨터 게임
    - 물리 엔진
        - 복잡한 물리 연산을 실시간으로 계산
        - 영화와 같은 연출 가능
    - 실시간 렌더링 계산이 용이하도록, 오프라인으로 미리 계산하여 처리
- 컴퓨터 그래픽스 + 예술
    - 사진과 같은 사실적 렌더링 결과가 아닌, 화가가 그린 듯 스타일이 살아 있는 렌더링

### Principles of Computer graphics

**조명화**

- Global Vs Local

Time - Quality tradeoff 존재

- Global
    - Off-line graphics
    - High quality
    - 애니메이션, 시네마틱 효과
- Local
    - Interactive grpahics
    - Low quality
    - 모바일 UI, 게임

**Global Illumination**

- 일반적으로 실시간이 아님
- Direct illumination, Indirect illumination 모두를 고려

**Local Illumination**

- 일반적으로는 실시간
    - 기존에는 Phong reflection model을 사용했지만 현재는PBR과 같은 더 복잡한 모델을 사용
- H/W와 친숙한 local effects만 고려함
    - Direct illumination

**Interactive Computer Graphics**

- **사람들은 실시간을 원했음**
- GPU, OpenGL과 같은 하드웨어들은 그래픽의 발전에 가속을 더함

</div>
</details>


<details>
<summary> OpenGL & OpenGL ES, Computer Graphics Systems  </summary>
<div markdown="1">

### OpenGL

- ~ 1991
    - IRIS GL : 실리콘 그래픽스(SGI)에 의해 만들어진 그래픽스 독점 API
- OpenGL
    - 1992년 배포
    - H/W는 3D 그래픽스에 가속을 더함
    - 관리
        - OpenGL ARB에 의해 관리되었음 (OpenGL Architectural Review Board)
        - 현재는 Khronos Group에 의해 관리되고 있음
- 경쟁자
    - 현재까지 가장 강한 경쟁자는 마이크로소프트
    - microsoft Direct3D(1998 ~ now)
    

<img width="673" alt="1" src="https://user-images.githubusercontent.com/79856225/233635608-007d7822-f273-4071-9ecc-533b0a86395c.png">

<img width="655" alt="2" src="https://user-images.githubusercontent.com/79856225/233635648-ae07cb78-90a3-44db-abad-963182ebd452.png">

OpenGL 2.x 이전 버전까지는 GPU는 단순한 하드웨어에 불가했지만 2.x 버전부터 nvidia가 GPU를 연산 장치로 사용가능하게 발전 시켰고 이 때 부터 컴퓨터 그래픽스는 빠르게 발전한다

### OpenGL ES

<img width="262" alt="3" src="https://user-images.githubusercontent.com/79856225/233635659-56504806-9875-4e66-9e92-d72685c4e135.png">

- A subset of OpenGL for Embedded Systems
- PC시장은 MS의 Direct X가 정렴하여 OpenGL은 점점 사라져 갔지만 모바일 시장이 인기가 생기면서 Apple이 OpenGL를 다시 살림
- 모바일 기기 및 임베디드 시스템에서 사용되는 축소판 OpenGL. OpenGL ES는 OpenGL의 하위 집합으로, 모바일 기기와 같은 작은 화면에서의 그래픽 처리에 최적화

### Computer Graphics Systems

**기본적인 그래픽 시스템**

<img width="1605" alt="4" src="https://user-images.githubusercontent.com/79856225/233635665-ecbd1e6d-668b-4d3d-ab82-4bbc137f7b4f.png">

마우스 또는 키보드와 같은 input devices를 이용하여 computer에 input을 넣어주면 cpu와 메모리를 이용하여 Frame buffer에서 이미지가 생성이 되며 이 이미지를 지우고 그리는 걸 빠르게 반복하여 모니터에 이미지를 출력하는 방식

**초기 컴퓨터 그래픽스 1960 ~ 1970**

**Wireframe graphics**

- 라인만을 이용하여 그림
    - 외형만 그리는 그래픽스
- Oscilloscope cathode ray tube (CRT)
- **1963(Sketchpad)**
    - Ivan Sutherland’s PHD thesis at MIT
        - man-machine interaction의 잠재력을 알아차림
        - **Vector grapjics - “line work’**

Sketchpad은 또한, 최초로 사용자가 그린 그림을 인식하고, 이를 다시 그리거나 변형하는 기능을 제공하여 그래픽스 분야에서의 융합 기술을 선보였다.

컴퓨터 그래픽스의 초기 단계에서는 하드웨어의 한계가 존재했기 때문에 물체를 선으로만 표현할 수 있었다

<img width="370" alt="5" src="https://user-images.githubusercontent.com/79856225/233635672-a38db5e9-f0fd-409f-9f3b-5a657ec755fc.png">

**컴퓨터 그래픽스 1970 ~ 1980**

**Raster Graphics(픽셀들로 이루어진 그래픽스)**

- 이미지를 작은 사각형 블록으로 나누어, 각 블록을 픽셀이라는 작은 단위로 나누어 처리한다. 각 픽셀은 색상 값을 가지며, 모든 픽셀의 색상 값들이 결합하여 전체 이미지가 표현
- 고해상도 이미지를 처리하기에는 적합하지만 Vector와는 다르게 이미지 확대 축소시 노이즈 발생 가능성
- 현재는 Raster Graphics가 기본이다.

**컴퓨터 그래픽스 1980 ~ 1990**

**Realism comes to cimputer graphics**

- 이미지를 효과적으로 표현하는 알고리즘을 개발
- 어떻게 하드웨어로 보내서 Real time으로 렌더링할지 고민

<img width="1199" alt="6" src="https://user-images.githubusercontent.com/79856225/233635677-243b47a2-57d2-4070-9126-0945bbf74eb0.png">

**컴퓨터 그래픽스 1990 ~ 2000**

- OpenGL API
- Toy Story와 같은 컴퓨터 그래픽스 영화가 성공함
- 새로운 하드웨어
    - Texture mapping
    - Blending
    - Accumulation, stencil buffers
    

**컴퓨터 그래픽스 2000 ~ 2010**

- Photorealism
- Graphics cards for Pcs dominate market
    - Nvidia, ATI
- Game boxed and game plyaers determine direction of market
- Computer graphics routine in movie indrstry : Maya, Lightwave
- Prigrannable piplens

**컴퓨터 그래픽스 2010 ~ 2020**

- Stylized rendering
- Precomputed Radiance Transfer(PRT)
    - Textures brcome much more important
- Image/Video processing
- General purpose GPU(GPGPU)

**컴퓨터 그래픽스 2020 ~** 

- GAN(Generative Adversarial Networks)
- Neural 3D Rendering(NeRF)
- Stable Diffusion(SD)

</div>
</details>



</div>
</details>


<!-- 00 Overview-->




<!--
<details>
<summary>  </summary>
<div markdown="1">

</div>
</details>
----------------------
-->
