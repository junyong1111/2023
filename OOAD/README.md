# Object-Oriented Analysis and Design(OOAD)


## 총정리

<details>
<summary> OOAD - 총정리 </summary>
<div markdown="1">   


<details>
<summary> 객체지향 분석 및 설계란 ?  </summary>
<div markdown="1">   

**객체지향 분석및 설계**

**분석** : Concept를 넣어 주는 것

→ 예를 들어 도서관 정보 시스템의 경우 도서, 도서관, 후원자 등과 같은 개념이 존재한다.

**디자인** : 소프트웨어 객체를 설계를 하는 것

**객체지향은 객체의 표현을 강조한다.**

- 책을 예제로 한다면 책은 보는사람마다 책에 대한 특성을 다르게 볼 수 있다.
    - 서점에서는 보는 책에 대한 관점과 운송업체에서 보는 책에 대한 관점은 다르다.

**주사위 게임 예시**

1. Use Cases를 정의 
    
    **→ 주사위를 2개를 이용하여 합이 7이 되면이기는 게임**
    
2. Domain Model을 정의
    
    **→ 게임 플레이어, 주사위, 주사위 게임**
    
    - 시스템의 도메인(영역)을 표현하는 개념적인 모델
    - 예를 들어, 은행 업무 시스템의 도메인은 계좌, 거래, 고객, 입출금 등이 될 수 있다.
    - 관련된 객체와 그 객체들 간의 관계를 표현하는 모델이다.
3. 상호작용 다이어그램을 정의
    
    **→ 시스템의 동작을 표현하며 주사위게임의 경우 다음과 같다.**
    
    시퀀스 다이어그램 
    
    **주사위 게임 ⇒ 주사위 굴리기(1번째 주사위) ⇒ 점수 계산(1번째)**
    
    **주사위 게임 ⇒ 주사위 굴리기(2번째 주사위) ⇒ 점수 계산(2번째)**
    
    실제로 어떻게 돌아갈지 계획(설계)
    
    - 대표적으로 시퀀스 다이어그램과 커뮤니케이션 다이어그램
        - 시퀀스 다이어그램 : 시간의 흐름에 따라 객체들 간의 상호작용
        - 커뮤니케이션 다이어그램 : 객체들 간의 상호작용을 객체 간의 연결 관점
4. 디자인 클래스 다이어그램을 정의
    
    → 
    
    | 클래스 명  | 주사위 게임 |  | 클래스 명 | 주사위 |
    | --- | --- | --- | --- | --- |
    | die 1(변수) | 객체 | 1                      2 | faceValue(int) | 총합 변수 |
    | die 2(변수) | 객체 | → | getFaceValue() | 주사위 굴리기 함수 |
    | play() | 메서드 | → |  |  |
    - concept이랑 다르게 구현될 수 있다.
    - SW 설계 시 필요한 클래스만 설계한다.
    

하나의 프로젝트를 객체지향적으로 분석 및 설계를 한다면 위와 같이 객체지향적 분석 및 설계를 할 수 있다.

<aside>
💡 **use cases 정의 ⇒ domain model 정의 ⇒ 상호작용 다이어그램 정의 ⇒ 디자인 클래스 정의**

</aside>


</div>
</details>


<details>
<summary> 개발 방법론 </summary>
<div markdown="1">   

**개발 방법론**

**소프트웨어 개발 과정**

- Waterfall Model
- Iterative Model
    - UP
- Agile Model
- Model-Driven Development

The Unified Process(UP) 개발 방법론

- 특징
    - **반복적으로 개발**
        - 짧은 단계
        - 고정된 길이로
        - 작은 프로젝트로
- 설계를 하면서 코드를 만들어 감

각각의 반복단계는 다음을 포함하고 있다.

⇒ **요구사항 분석, 디자인, 코드 구현, 테스트**

UP의 반복단계에서 점직적으로 개발이 진행된다. UP 개발의 장점으로는 초기의 복잡한것을 미리 처리할 수 있다.

UP의 4단계 시리즈

- **Inception(개시)**
    - **이번 프로젝트를 무엇을 할지, 어느만큼 할지 정하는 단계**
    
    <aside>
    ❗ Inception단계는 개발자가 해당 문제를 정해진 자원(시간, 비용, 인원 등등…)으로 해결할 수 있는지 확인하는 단계이며 프로젝트에 대해서 진행, 협상 또는 중단을 하는 단계이다.
    
    </aside>
    
- **Elaboration(상세화)**
    - **분석 설계에 집중하는 단계**
    - 프로토타입을 통해 시스템의 기능과 성능을 검증하고, **리스크를 식별**하고 **대응 방안을 수립**
    - 끝나면 더이상 중심 구조를 더 이상 수정하지 않음
    
    <aside>
    ❗ 핵심 아키텍처가 반복적으로 구현되며 리스크를 식별하고 대응 방안을 수립하여 High-risk문제들이 완화되는 단계이며 상세화 과정이 끝나면 milestone이 생성되며 중심 구조를 더 이상 수정하지 않는다.
    
    </aside>
    
- **Construction(구축)**
    - Elaboration 단계에서 정의한 상세한 요구사항에 따라 소프트웨어를 실제로 개발하는 단계
    - **반복적으로 구현(코딩)하는 단계**
    
    <aside>
    ❗ 소프트웨어를 개발하여 릴리즈(Release)하는 것이 일반적이다. Construction 단계는 Elaboration 단계에서 정의된 아키텍처에 따라 실제로 소프트웨어를 개발하고 테스트하는 단게
    
    </aside>
    
- **Transition(전환)**
    - **시스템의 최종 품질을 검증하고 프로젝트를 완료하는 단계**
    - Beta tests, deployment.
    
    1. Business Modeling: 비즈니스 모델링은 프로젝트의 비즈니스 요구사항을 이해하고 문제를 해결하기 위해 사용자 요구사항을 수집하고 분석하는 활동을 포함합니다. 비즈니스 프로세스, 데이터 모델링, 사용자 시나리오 등의 기법을 사용하여 비즈니스 요구사항을 도출하고 문서화합니다.
    2. Requirements: 요구사항 관리는 사용자와의 커뮤니케이션을 통해 요구사항을 수집, 분석, 문서화하고 관리하는 활동을 포함합니다. 요구사항의 우선순위 결정, 변경 관리, 검증 및 승인 등의 과정을 통해 요구사항을 관리하고 변경에 대응합니다.
        - FR(Functional Requirments) : 출금 (가장 중요한 요구사항)
            - Use cases와 세트임
        - NFR(None Functional Requirments) : 속도 (돈은 나오더라도 느리게 나오는 경우)
            - 빠르게, 아름답게, 견고하게.. Quality와 세트
    3. Analysis & Design: 분석 및 설계는 시스템 아키텍처와 디자인을 수행하는 활동을 포함합니다. 시스템의 기능, 구조, 동작을 분석하여 상세한 디자인을 수행하고, 시스템의 모델링, 패턴, 아키텍처 등을 설계합니다.
    4. Implementation: 구현은 설계된 시스템을 실제 코드로 구현하는 활동을 포함합니다. 개발자들은 프로그래밍 언어, 개발 환경, 개발 도구 등을 사용하여 소프트웨어를 개발하고, 코드를 작성하고, 테스트를 수행합니다.
    5. Test: 테스트는 개발된 소프트웨어의 품질과 안정성을 검증하는 활동을 포함합니다. 다양한 테스트 기법과 도구를 사용하여 소프트웨어의 기능, 성능, 보안 등을 테스트하고 검증합니다.
    6. Deployment: 배포는 개발된 소프트웨어를 사용자에게 제공하는 과정을 포함합니다. 소프트웨어의 설치, 설정

</div>
</details>

<details>
<summary> UP </summary>
<div markdown="1">   

UP는 4단계 과정을 정해진 주기만큼 반복적으로 실행하여 점진적으로 개발을 하는 방법론이다.

4단계 과정은 다음과 같다.

1번째 inception 단계에서는 프로젝트의 비전과 어디까지 설게하는지 등에 대해 조사하는 단계이다. 

2번째 elaboration 단계를 반복하면서 이 단계에서 객체지향 분석 및 설계를 하며 디자인을 코드로 바꾼다

**Inception 단계에서는 다음과 같은 산출물이 나오기 시작한다.**

- 요구 사항
    - Use Case Model
    - Vision
    - Sumpplementary Specification(추가 사양)
    - 용어집
- 구현 및 프로젝트 관리(애자일 미팅)
    - SW 개발 계획, 구현 모델
- 테스트
    - Test Model
    - Development Case

**Elaboration 단계에서는 다음과 같은 산출물이 나오고 수정된다.**

- 비즈니스 모델 : Domain Model (산출물)
- 요구사항
    - Use Case Model(수정)
    - Vision(수정)
    - Sumpplementary Specification(추가 사양)(수정)
    - 용어집(수정)
- 디자인
    - 모델 디자인(산출물)
    - SW 아키텍쳐 문서(산출물)
    - SW 개발 계획(산출물)
- 구현 및 프로젝트 관리(애자일 미팅)
    - SW 개발 계획, 구현 모델(산출 및 수정)
- 테스트
    - Test Model(산출 및 수정)
    - Development Case(산출 및 수정)

프로젝트를 정하면 **시스템이 원하는 컨셉에** 대해 생각하고 **시스템의 요구사항**에 대해서 생각하자.



</div>
</details>

<details>
<summary> UP-Inception </summary>
<div markdown="1">   

UP는 4단계 과정을 정해진 주기만큼 반복적으로 실행하여 점진적으로 개발을 하는 방법론이다.

1번째 inception 단계에서는 프로젝트의 비전과 어디까지 설게하는지 등에 대해 조사하는 단계이다. 

**Inception 단계에서는 다음과 같은 산출물이 나오기 시작한다.**

- 요구 사항
    - Use Case Model
    - Vision
    - Sumpplementary Specification(추가 사양)
    - 용어집
- 구현 및 프로젝트 관리(애자일 미팅)
    - SW 개발 계획, 구현 모델
- 테스트
    - Test Model
    - Development Case

Inception 단계에서는 기능적인 요구사항(Use cases)와 비기능적인 요구사항으로 분린된다.

- Use Cases
    - 질문 게시판 같은 경우 ⇒ 반드시 필요한 요구사항은 질문과 답변하기 기능이다.
- Quality Attributes
    - 질문 게시판 같은 경우 ⇒ 부가적으로 있으면 데이터 처리 속도 등등이다.

**요구 사항은 시스템이 전반적으로 그 프로젝트에서 반드시 수행해야 하는 수용성과 컨디션이 있다.**

요구사항을 분석 하기위해서는 다음과 같은 과정이 필요하다

→ 무엇을 해야하는지 찾고

→ 소통하고 

→ 산출물로서 기억

ex) FURPS Model

- F : Functional
- U : Usability
- R : Realiability
- P : Performance
- S : Supportability

요구사항의 산출물로는  Use - Case Model, 추가 사양, 용어집, Vision, Business Rule이 있다.

<aside>
❗ Inception 단계에서는 요구사항 분석을 위해 Use Case Model, Vision, Supplementary Specification, 용어집 등의 산출물이 필요하며, 기능적 요구사항과 비기능적 요구사항으로 분리된다. 요구사항 분석을 위해서는 무엇을 해야 하는지 파악하고 소통한 뒤 산출물로서 기록해야 하며, FURPS 모델을 사용하여 Functional, Usability, Reliability, Performance, Supportability 등을 고려해야 한다. Use-Case Model, Supplementary Specification, 용어집, Vision, Business Rule 등이 요구사항의 산출물이 된다.

</aside>

**UP → Inception → Requirement → Use Cases(기능적 요구사항)**

Use - Case 시나리오 도출하기

- 시나리오
    - 시나리오는 순차적으로 스토리텔링 하는 것이다.
    
    ```java
    판매 성공 시나리오 : 고객이 상품과 함께 계산대에 도착하고 캐셔는 POS 시스템을 이용하여 
    각각의 아이템들을 등록하고 아이템을 반환
    
    판매 실패 시나리오 
    - 고객이 결제를 위해 신용카드를 냈지만, 카드결제가 안된 경우 고객에게 현글 결제를 알려야 함
    - 외부 서버와 통신에 오류가 생긴다면 알려야 함
    - 바코드가 문제가 생기면 캐셔에게 알리거나 매뉴얼에 대해 알려줘야 함
    
    ```
    

**UP → Inception → Requirement → Quality & Quality Attribute**

> 품질요구사항
시스템이 제공해야 할 품질속성의 수준이다. **품질 속성은 관찰할 수 있고 측정할 수** 있어야 하기 때문에 가능하면 정확한 수치로 제시되어야 한다.
> 
- Functional Suiatability
- Performance efficiency : 자원의 양에 따라 얼마나 좋은 성능을 보일지
- Compatibility : 서로 호환 가능한지
- Usability : 어떤상황에 따라 적절하게 사용가능한지
- Reliability : 신뢰성(매우 중요한 기능)
- Security : 보안성
- Maintainability : 유지관리(산업에서는 굉장히 높게 친다)
- Portability : 이식성 (다른 환경에서도 잘 적응, 대체 가능성 …)

1. Business Modeling 단계에서 잡음
2. Requirements
    - FR(Functional Requirments) : 출금 (가장 중요한 요구사항)
        - Use cases와 세트임
    - NFR(None Functional Requirments) : 속도 (돈은 나오더라도 느리게 나오는 경우)
        - 빠르게, 아름답게, 견고하게.. Quality와 세트

</div>
</details>

<details>
<summary> UP-Inception → Requirements → UseCases </summary>
<div markdown="1">   

<aside>
❗ **Inception** 단계에서는 **요구사항** 분석을 위해 Use Case Model, Vision, Supplementary Specification, 용어집 등의 산출물이 필요하며, **기능적** 요구사항과 **비기능적** 요구사항으로 분리된다. 요구사항 분석을 위해서는 무엇을 해야 하는지 파악하고 소통한 뒤 산출물로서 기록해야 하며, FURPS 모델을 사용하여 Functional, Usability, Reliability, Performance, Supportability 등을 고려해야 한다. **Use-Case** Model, Supplementary Specification, 용어집, Vision, Business Rule 등이 요구사항의 산출물이 된다.

</aside>

> Use Case 
**-** 사용자가 대상 시스템을 이용하는 목표에 대해서 스토리텔링 한다.
- 시스템이 해야하는 계약이다.
- 성공사례와 실패사례에 대한 시나리오의 모음이다.
> 

**Use Cases**

- **Use Cases는 주로 기능적인 요구 사항이다.**

**Use Cases → Actor, Scenario**

Actor : User, Manager …등등 시스템을 이용하는 사람이다.

Scenario : Actor와 System의 액션에 대한 상호작용에 대한 연속이다.

ex) 현금과 함께 아이템을 성공적으로 구매하는 시나리오, 카드 결제 거부로 인해 아이템 구매를 실패하는 시나리오 …

**Use Cases Model**

- Actor의 종류
    - Primary actor : 대상 시스템의 주된 Actor이다.
        - 사용자
    - Supporting actor : 주사용자에게 서비스를 제공하는 Actor이다.
        - 매니저
    - Offstage actor

**Two - Column Variation**

- Primary Actor : User(질문자)

| Actor | System |
| --- | --- |
| 1. Actor는 게시판에 들어와서 원하는 질문을 찾음 |  |
| 2. 원하는 질문이 없는 경우 게시판에 질문 시작 |  |
| 3. 원하는 카테고리에 맞게 질문 등록 |  |
|  | 4. GPT apI를 이용하여 해당 질문에 대한 답변 반환 |
| 질문자는 원하는 답변이 나올 때까지 질문 생성 |  |

<aside>
❗ Use Cases를 찾는 방법은 Actor-goal List를 만들면 쉽게 찾을 수 있다.

</aside>

**UML : Use Case Diagrams**

- 위에서 작성한 틀로 다이어그램 생성

Use Case Diagrams - Notation

- 시스템 actor와 사용자 actor는 다르게 표시해야 하며 다양하게 표기를 할 수 있다.
- 목표와 문제에 대해 보여줘야 하며  중요한 비기능적 요구사항들은 드러내야 한다.

Use Case Diagrams - System

- Use Case를 둘러싸는 사각형으로 표현
- 행위자는 외부에 있는 반면 Use cases는 시스템의 내부

Use Case Diagrams - Extend(추가)

- 추가적인 행동
- "항공편 예약하기" 기능이 Main Success Scenario로 정의되어 있을 때, "좌석 선택하기"나 "결제하기" 등과 같은 Alternate Scenario들이 Extend이다.
- 화살표로 표시(좌서 선택하기에서 예약하기로 화살표를 표시)

Use Case Diagrams - Include(포함)

- 온라인 쇼핑몰에서 "주문하기" Use Case는 "결제하기" Use Case를 포함할 수 있다. 즉, "주문하기"를 수행하려면 "결제하기"가 반드시 수행되어야 한다 따라서 "결제하기"는 "주문하기"의 Include 관계에 위치한다
- 점선 화살표로 표시

![1](https://github.com/junyong1111/2023/assets/79856225/6498e9f3-a767-4fdf-9268-c505c0f43b8c)


**Use Case Description(명세서)**

- 이름
- Actor 기술
    - 요약
    - 역할
- Usecase 기술
    - 요약
    - 사전 조건
    - 사후 조건
    - 주 사건 흐름
    - 대안 흐름
    - 에외 흐름
    - 시나리오
    - 기타
        - 비기능적 요구사항
        - 비즈니스 룰
        - 사용자 화면

| 산출물 | 내용 |
| --- | --- |
| Use Case Model | 사용자가 시스템을 이용하는 목표를 스토리텔링하여 시스템의 기능적 요구사항을 나열한 것 |
| Vision | 프로젝트의 비전과 목표를 기술함 |
| Supplementary Specification | 기능적 요구사항 이외의 비기능적 요구사항을 포함하는 문서 |
| 용어집 | 시스템에서 사용되는 용어들의 정의를 모아둔 문서 |
| Business Rule | 시스템이 준수해야 하는 비즈니스 규칙을 기술함 |

Use Case

- 다이어그램보다는 텍스트 서술에 집중
- 기능적 요구사항을 획득
- 시작시킨 행위자는 왼쪽, 결과를 받는 행위자는 오른쪽에 표현
    
    
    | Use Case 구성요소 | 내용 |
    | --- | --- |
    | Actor | 시스템과 상호작용하는 역할을 수행하는 인간 또는 시스템 |
    | Scenario | Actor가 시스템을 이용하여 얻고자 하는 목표를 스토리텔링한 것 |
    | Use Case | Actor의 목표를 달성하기 위해 시스템이 제공하는 기능 |
    | Extend와 Include | Use Case를 구성하는 기능들 중에서 추가적인 기능을 포함하거나 기능을 확장하는 것 |

Use Case Diagram

- Use Case들의 목차의 **그래픽적인** 테이블 표현
- 시스템의 사용데 대한 **시나리오의 집합**
    
    
    | Use Case Diagram 내용 | 내용 |
    | --- | --- |
    | Actor | 시스템과 상호작용하는 인간 또는 시스템 |
    | Use Case | Actor의 목표를 달성하기 위해 시스템이 제공하는 기능 |
    | 시스템 actor와 사용자 actor | 다르게 표시함 |
    | Use Case 위치 | 시스템의 내부에 위치함 |
    | Extend와 Include | 화살표로 표시하며, 각각 기능을 구성하는 다른 기능과 점선 화살표로 연결됨 |

Use Case Description

- Use Case의 구체적인 동작을 설명하는 문서
- Use Case에 대한 상세한 정보를 제공하여, 이를 구현하는데 필요한 세부 사항을 명확하게 정의
    
    
    | Use Case Description 구성요소 | 내용 |
    | --- | --- |
    | Use Case의 이름 | Use Case의 이름 |
    | Actor | Use Case와 상호작용하는 Actor |
    | Precondition | Use Case가 실행되기 전에 충족되어야 하는 조건 |
    | Flow of Events | Use Case의 행위 |
    | Post Condition | Use Case 실행 후의 시스템의 상태 |
    | Alternative Flows | Use Case의 예외 상황을 다루는 Alternative Flows의 목록 |



</div>
</details>

<details>
<summary> UP-Inception → Requirements → UseCases → Class Diagram </summary>
<div markdown="1">   

### 클래스 다이어그램

**클래스 다이어그램**

설계 시 가장 많이 사용되며 그 모델링 개념의 폭이 넓다. 

- Class의 속성 (Attribute)
- Operation
- Association
- generalization(일반화)
- Package등의 다른 Class와 사이의 다양한 정적인 관계를 표현한다.

—# 일반적으로 속성은 Private하게 하고 메서드를 public하게 한다.

클래스는 4가지 표현법이 존재한다.

1. 클래스 이름으로 표현
    - Question Class
2. 이름과 속성으로 표현
    - Question class
    - content, subject …
3. 이름과 Operation으로만 표현
    - Question class
    - 질문하기
4. 모든 표현
    - Question class
    - content, subject …
    - 질문하기

**Class Diagram - Boundary 클래스**

- 역할: 시스템과 외부 요소(사용자 또는 외부 시스템) 간의 상호작용을 담당하는 클래스입니다. 주로 사용자 인터페이스(UI)와 관련된 기능을 수행합니다.
- 예시: 사용자가 주문을 생성하고 제품을 선택하는 웹 애플리케이션의 주문 생성 폼이 바운더리 클래스의 예시입니다. 이 클래스는 사용자의 입력을 받아들이고, 주문 정보를 시스템으로 전달합니다.

**Class Diagram - 엔터티 클래스 (Entity Class)**

- 역할: 시스템 내에서 데이터를 나타내고, 해당 데이터를 처리하는 역할을 담당하는 클래스입니다. 데이터의 영속성과 비즈니스 규칙을 포함합니다.
- 예시: 고객 정보를 나타내는 엔터티 클래스의 예시입니다. 이 클래스는 고객의 속성(이름, 이메일, 주소 등)을 포함하고, 고객과 관련된 작업(고객 등록, 정보 업데이트 등)을 수행합니다.

**Class Diagram - 컨트롤 클래스 (Control Class)**

- 역할: 시스템의 비즈니스 로직을 제어하고 조정하는 역할을 담당하는 클래스입니다. 주로 시스템의 흐름과 제어를 다룹니다.
- 예시: 주문 처리를 담당하는 컨트롤 클래스의 예시입니다. 이 클래스는 주문 유효성 검사, 결제 처리, 재고 관리 등 주문 처리의 비즈니스 로직을 수행합니다.

| 클래스 유형 | 역할 | 예시 |
| --- | --- | --- |
| 바운더리 클래스 | 시스템과 외부 요소 간의 상호작용을 관리 | 사용자 인터페이스와의 상호작용, 데이터 변환, 입출력 관리 |
| 엔터티 클래스 | 시스템 내 데이터를 나타내고 처리 | 데이터의 저장, 조회, 변경, 비즈니스 규칙 적용 |
| 컨트롤 클래스 | 시스템의 비즈니스 로직을 제어 및 조정 | 데이터 처리, 비즈니스 규칙 적용, 시스템 흐름 관리 |

**Class** - **접근제어자**

자바에는 다음과 같은 접근 제어자가 있다.

- private(+) : 시스템 내 모든 접근 허용
- protected(#): 상속 트리 내에서 접근 허용
- private(-) : 해당 클래스 내에서만 접근 허용

**Class -연관관계**

어떤 클래스의 인스턴스가 작업을 수행하기 위하여 다른 클래스를 알아야 하는 것

- one to one
- one to many
- many to many

영화관, 매표소, 영화 클래스가 있다고 가정

영화관이 없어지면 매표소도 없어짐 → 합성관계이며 검은색 다이아몬드로 표현

영화관이 없어지더라도 영화도 없어지지 않음 → 집합관계이며 흰색 다이아몬드로 표현

<img width="906" alt="1" src="https://github.com/junyong1111/2023/assets/79856225/22902519-54cb-435e-89eb-6122ec46b161">


**Class - Statc** 

- 속성이 한 Class의 여러 객체에 의해 공유
- 밑줄로 표기

**Class - Method**

Visialility → Name → Parametenrers → return type 순으로 적는다

ex) public setPos(int pos) : int



</div>
</details>

<details>
<summary> UP-Inception → Requirements → UseCases → 액티비티 다이어그램 & 인터랙션 다이어그램  </summary>
<div markdown="1">   

### **액티비티 다이어그램 & 인터랙션 다이어그램**

**액티비티 다이어그램**

- 액티비티 다이어그램은 UML에서 동적인 동작을 시각적으로 표현하는 다이어그램이다.
- 액티비티는 동작의 단위를 나타내며, 액션, 의사 결정, 병합, 분기 등 다양한 유형의 동작을 포함한다.
- 액티비티 간의 흐름은 화살표로 표현되며, 초기 상태와 최종 상태를 나타내는 시작점과 종료점이 있다.
- 액티비티 다이어그램은 시스템 또는 프로세스의 동작을 순차적으로 보여줌으로써 시간의 흐름을 이해하기 쉽다.

</div>
</details>

<details>
<summary> UP-Inception → Requirements → UseCases → Sequence Diagram </summary>
<div markdown="1"> 

### Sequence Diagram

**Sequence Diagram**

- 시퀀스 다이어그램은 UML에서 객체 간 상호작용을 시각적으로 표현하는 다이어그램이다.
- 객체 간의 메시지 교환과 호출 순서를 시간의 흐름에 따라 표현한다.
- 라이프라인과 메시지로 구성되며, 객체 간의 수직적인 시퀀스를 나타낸다.
- 시간 순서에 따라 객체의 흐름을 보여주어 시스템의 동작을 이해하기 쉽게 한다.
- 객체 간의 상호작용과 메시지 교환을 분석하고, 시간적 제약과 조건을 모델링할 수 있다.



</div>
</details>

<details>
<summary> UP-Elaboration </summary>
<div markdown="1">  

### **Elaboration**

비즈니스 모델링, 요구사항들에 대한 산출물이 Inception 단계에서 나오고 난 후에는 **Elaboration**에서 **분석및 디자인 단계에 들어간다.**

Analysis & Design: 분석 및 설계는 시스템 아키텍처와 디자인을 수행하는 활동을 포함한다. 시스템의 기능, 구조, 동작을 분석하여 상세한 디자인을 수행하고, 시스템의 모델링, 패턴, 아키텍처 등을 설계한다.

<img width="648" alt="1" src="https://github.com/junyong1111/2023/assets/79856225/23c2c7b5-571b-4183-8654-3995169924a1">

| Analysis | Design |
| --- | --- |
| 분석 시작(모델의 컨셉) | 구조 디자인 |
| 구조 분석 | Use-Case 디자인 |
| Use-Case 분석 | Subsystem 디자인 |
| - | Class 디자인 |
| - | Database  |

![2](https://github.com/junyong1111/2023/assets/79856225/7d0b78a9-fc6f-4acb-8f3e-93eba2b015d9)



</div>
</details>


<details>
<summary> UP-Elaboration → Use case of Analysis </summary>
<div markdown="1">   

<img width="648" alt="1" src="https://github.com/junyong1111/2023/assets/79856225/41c66fd1-28b7-4938-a54e-1496557a5aa3">

<img width="971" alt="2" src="https://github.com/junyong1111/2023/assets/79856225/c397aa44-edb0-412f-b158-305597e053d0">

**Elaboration → Use Case of Analysis → Define essential Use Cases**

필수적인 Use Cases에 대해 정의하는 부분이며 기존의 Use Cases 포맷을 확장한다.

- 시스템의 핵심 기능을 식별
- 해당 기능을 수행하는 사용자 시나리오를 문서화
- 시스템의 주요 기능을 명확하게 정의하고, 팀 간의 의사소통과 이해

**Elaboration → Use Case of Analysis → Refine Use Case Diagrams**

- 'Business Use Case Diagram'의 유효성 검사 및 수정
- Input : Business Use Case 모델, Essential Use Case 설명
- Output :  Use Case 다이어그램
- Standard applied : UML의 Use Case 다이어그램

**Step**

1. Essential Use Case에 따라 Business Use Case를 리뷰
2. Use cases 와 relationships에 따라 use cases diagrams 재정의

**Elaboration → Use Case of Analysis → Define Domain Model (16)**

**Software System의 Domain에 Concept를 잡아가는 것**

- input 산출물에 대한 리뷰를 하므로 도메인 모델의 개념을 정의
- Input : essential use case descriptions, business concept model
- Ouput : 개념적인 클래스 다이어그램
- Standard applied : UML’s use case diagram

—# Domain Model ?

- **Concepts를 시각화 하는것**
- **실제 세상에서 부터 정의된 개념적인 클래스에 대한 표현**
- Illustrates meaningful conceptual classes in a problem domain
- 개념적인 모델들
- Domain models are not models of software components

**Step**

1. Use Cases나 Business Concept Mode로부터 Concepts를 리스트화
    - Concept Category List를 사용
    - Use Case의 시나리오나 Use Cases descriptions 사용 가능
2. 클래스 이름들을 Concepts에 할당
    - domain에 존재하는 이름을 사용
    - 관련없는 이름은 사용하지 않는다.
3. 연관관게 카테고리에 따라 연관관계를 정의
4. 대표되는 assocation위주로 특성들을 할당
5. 연관관계에 이름을 정의
6. association에 끝에 multiplicity를 추가
7. Reading에 의해 특성들을 정의 → Object간의 구별을 위한 특성

아래와 같이 하나에 몰아넣는것이 아닌 나눠주는것이 더 좋음

<img width="507" alt="3" src="https://github.com/junyong1111/2023/assets/79856225/5dd5fe84-473d-4d87-a7b7-4b4fc1f57b38">



</div>
</details>


</div>
</details>

<!-- 
<details>
<summary>  </summary>
<div markdown="1">   



</div>
</details> -->