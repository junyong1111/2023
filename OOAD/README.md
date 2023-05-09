# Object-Oriented Analysis and Design(OOAD)


### OOAD - 01  Introduction

<details>
<summary> OOAD - 01  Introduction </summary>
<div markdown="1">   

**객체 지향적 분석과 디자인은 무엇인가?**

- 객체지향적 분석 : Concept를 넣어주는 것
- 객체지향적 디자인 : 소프트웨어 객체를 설계하는 것(문제 잡기)

**객체지향은 객체의 표현을 강조한다.**

- 책을 예제로 한다면 책은 보는사람마다 책에 대한 트겅을 다르게 볼 수 있다.
    - 서점에서는 보는 책에 대한 관점과 운송업체에서 보는 책에 대한 관점은 다르다.
- 같은 비행기(고유넘버)가 존재하더라도 비행을 끝내면 승무원 ,운항정보 등을 모두 교체

</div>
</details>

### OOAD - 02  OOAD-Example

<details>
<summary> OOAD - 02  OOAD-Example </summary>
<div markdown="1">   

**Use Cases 정의**

- **메인 기능과 연관된 설명**
- 주사위를 던지는 게임
    - 주사위 2개를 굴려 합이 7이 되면 이기는 게임

**Domain Model 정의**

**시스템의 도메인(영역)을 표현하는 개념적인 모델**

- 객체별 분류 관점에서 도메인에 대한 설명 만들기
- 도메인을 분해하려면 개념, 속성 및 연관성을 식별
- 객체의 도메인 개념들을  보여준다.

**상호작용 다이어그램 정의**

**실제로 어떻게 돌아갈지 계획(설계)**

- 각각의 소프트웨어 객체들이 어떻게 서로 상호작용해야 하는지 설계

**클래스 다이어그램 정의**

**클래스와 클래스 간의 관계를 시각적으로 표현하는 다이어그램**

- 콘셉과는 다르게 될 수 있음
- 소프트웨어적 설계 시 필요한 클래스만 설계

</div>
</details>



### OOAD - 03  Iterative Evolutionary

<details>
<summary>OOAD - 03  Iterative Evolutionary </summary>
<div markdown="1">   

**UP(Unified Process) 개발 방법론**

**UP개발 방법론은 객체지향 시스템을 building하기 위한 대중적인 소프트웨어 개발 방법이다**

—# 또 다른 표현으로는 Rational UP or RUP

**UP-1**

- UP의 아이디어 : **반복적인 개발**
- 이러한 반복적인 접근은 아래와 같은 과정들이 포함되어 있다.
    - 짧은 시리즈
    - 고정된 길이(예를 들어 4주)
    - 미니 프로젝트라고 불리는 반복들
- 설계를 하면서 코드를 만들어 간다.

**UP-2**

- **각각의 반복은 자신만의 요구사항들, 분석, 디자인, 구현 그리고 테스트과정을 포함하고 있다.**
- 반복에의해 시간이 지남에 따라 점진적으로 개발된다.
    - **ierative and incremental development**
    

**Iterative Development**

- Development : 짧은 시리즈와 고정된 길이, 미니프로젝트라고 불리는 과정의 반복
- 각각의 반복은 자신만의 요구사항들, 분석, 디자인, 구현 그리고 테스트과정을 포함하고 있다.

**UP의 Iterative Developmentdm의 장점**

- 초기위험을 미리 발견 가능
- 반복을 통해 점진적으로 개발 가능

❗️ UP는 **고정된 길이의(예를 들면 4주)짧은 개발의 연속이며 미니프로젝트라고 불리는 작업의 반복이다. 이 반복적인 과정을 통해서 시스템은 시간이 지남에 따라 점진적으로 자라며, 이러한 과정은 iterative and incremental developemnet라고 잘 알려져 있다.**

</div>
</details>


### OOAD - 04  UP

<details>
<summary> OOAD - 04  UP </summary>
<div markdown="1">   

**SW 개발 과정(방법론)**

**Waterfall Model**

**폭포수가 떨어지듯 연결된 활동으로 일련의 과정들이 구성되어 있다.**

| 장점 | 단점 |
| --- | --- |
| - 초기에 요구사항을 잘 정의하고 계획 가능
- 프로젝트의 전체 진행 상황을 문서로 추적하기 쉬움 | - 변경에 대한 유연성이 낮음
- 프로젝트 초기에 요구사항을 완벽하게 정의하기 어려움 |
- **한 번 계획되면 그 상태로 끝임**
- **작은 사이즈 프로그램을 계획할 때 사용하기 좋음**
    - feedback이 있는 경우에는 사용하기 힘듬

**Waterfall Model**

**반복적으로 개발하는 방법으로 가장 잘 알려져 있는 모델로는 UP가 존재한다.**

**각각 반복할 때마다 가장 중요한 일 먼저 한다.**

**UP**

| UP 방법론 장점 | UP 방법론 단점 |
| --- | --- |
| 상세한 계획을 통해 개발 방향성 명확 | 초기 계획에 대한 요구사항 변화에 대응 어려움 |
| 엄격한 품질 관리 절차로 품질 보장 | 높은 비용 및 시간 소요 |
| 대규모 프로젝트에 적합 | 엄격한 절차로 인한 개발 프로세스 무거움 |
| 문서화와 검증에 중점, 후속 유지보수 용이 | 고객과의 지속적인 협력과 빠른 변화에 대응 어려움 |

![IMG_52FFB45E2B65-1.jpeg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6d12396e-7819-430c-873c-d7a8f358052b/IMG_52FFB45E2B65-1.jpeg)

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

</div>
</details>



### OOAD - 05  UP Phases

<details>
<summary> OOAD - 05  UP Phases </summary>
<div markdown="1">   

**UP 개발 과정(방법론)**

![IMG_52FFB45E2B65-1.jpeg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6d12396e-7819-430c-873c-d7a8f358052b/IMG_52FFB45E2B65-1.jpeg)

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

![스크린샷 2023-04-24 오후 7.33.49.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1222411c-9814-43de-996c-92e1643ed3bd/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_7.33.49.png)

</div>
</details>




<!-- 
<details>
<summary>  </summary>
<div markdown="1">   

</div>
</details> -->



### OOAD - 06  Inception-Requirements

<details>
<summary> 06  Inception-Requirements </summary>
<div markdown="1">   

**Inception**

**Inception은 요구 사항 단계만은 아니다**

**Inception단계에서 고려해야 할 이슈**

- What is the vision and business case for this project
    
    →이 프로젝트를 위한 비지니스 케이스와 비전이 무엇인지  
    
- Feasible
    
    →실현 가능성
    
- Buy and / or Build?
    
    → **소프트웨어 시스템을 구축할 때 구매할지 만들지 결정**
    
- Rough estimate of cost
    
    →대략적인 금액을 계산해야 함
    

**Envision the product scope, vision, and business case.**

**Inception Atifact**

- Inception단게는 공통된 vision을 만들어가는 단계이며, 실현가능성에 맞게 결정해야 한다.

—#Atifact(소프트웨어 산출물)의 정의

만질 수 있는것 뿐만 아니라 과정자체도 산출물이다.

ex) use cases, class diagrams, UNL models…

![IMG_52FFB45E2B65-1.jpeg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6d12396e-7819-430c-873c-d7a8f358052b/IMG_52FFB45E2B65-1.jpeg)

- **Inception(개시)**
    - **이번 프로젝트를 무엇을 할지, 어느만큼 할지 정하는 단계**
    
    <aside>
    ❗ Inception단계는 개발자가 해당 문제를 정해진 자원(시간, 비용, 인원 등등…)으로 해결할 수 있는지 확인하는 단계이며 프로젝트에 대해서 진행, 협상 또는 중단을 하는 단계이다.
    
    </aside>
    

![스크린샷 2023-04-24 오후 7.33.49.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1222411c-9814-43de-996c-92e1643ed3bd/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_7.33.49.png)

**Inception Focuses**

**기능적인 요구사항과 비기능적인 요구사항으로 분리**

- **Use cases + Quality Attribues (Use case Modeling)**

**Requirements(요구 사항)**

- 무엇을 해야하는지 찾음
- 소통
- 산출몰로서 기억

**Requirements -1**

**기능적인 요구사항**

- 시스템이 원이 제공해야만 하는 서비스에 대한 정의
- 특정 input에 대해서 시스템이 어떻게 반응해야하는지(카드와, 현금)
- 특정 상황에서 시스템이 어떻게 행동해야 하는지(서버가 다운된 경우)

**비기능적인 요구사항**

- 제한된 일들에 대해서 생각
- 품질에 대한 요구사항

**Requirements -2**

**기능적인 요구사항**

- **Use Cases**

**비기능적인 요구사항**

- 기능적 요구사항에 표현되지 않은 모든 것
- 때로는 Quality가 System을 만들 때 아주 중요할 수 있음

**FURPS Model**

![스크린샷 2023-04-24 오후 8.02.44.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3f13be89-e39c-4b8d-9d81-32a7ef793287/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.02.44.png)

</div>
</details>

### OOAD - 07  Inception-Quality

<details>
<summary> OOAD - 07  Inception-Quality </summary>
<div markdown="1">  

**Inception Quality**

**Quality Attribute(측정이 가능해야 함)**

- Functional Suitablity(기능적으로 맞아야함)
- Performance Efficiency(효율적인 성능)
- Compatatibility(호환성)
- Usablility(사용성)
    - 어떤 상황에 따라 적절하게 사용가능 해야함
- Realiablity(신뢰성)
    - 매우 중요한 기능
- Security(보안성)
- Maintainability(유지관리성)
- Portability(이식성)
    - 다른 환경에서도 잘 적응

![스크린샷 2023-04-24 오후 8.05.50.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/148b9f9b-dcb4-4591-93b7-f3dc12b550f9/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.05.50.png)

![스크린샷 2023-04-24 오후 8.09.28.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f92244d8-28b4-4181-afe3-daccd9c08411/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.09.28.png)

</div>
</details>


### OOAD - 08  Inception-UseCase(⭐️)

<details>
<summary> OOAD - 08  Inception-UseCase(⭐️) </summary>
<div markdown="1">   

**Inception UseCase**

**Use cases : 기능적인 요구사항**

- (기능적으로)요구사항을 발견하고 기록
- 시스템을 사용하는것에 대한 스토리

**Use Case**

- **사용자가 대상 시스템을 이용하는 목표에 대해서 스토리텔링**

**Use Cases and the Use-Case Model**

UP에서 Use-case mode은 요구사항안에 있다고 정의한다.

- Text + image
- 항상 다이어그램은 아니지만 보통 같이 있음

**Use Cases**

- use case : 시스템을 사용하는것에 대한 스토리
- 이 시스템이 해야하는 계약

**Actor**

- 역할에 따라서 생각해야 함
- 외부조직 또는 외부시스템 가능성

**Scenario with Actor**

- Actor + System → scenario
- Actor와 시스템 둘 사이에서의 행동과 상호작용에 대한 특정한 연속성

**Use case**

**성공사례와 실패사례와 관련된 모음**

- 성공사례
- 실패사례

**Use Case Model**

- Requirement artifact in the UP
- Supplementary specification
- Glossary
- Vision
- Business Rules
- All useful for requirements analysis

**Kinds of Actors**

- 주 사용자
- 매니저
- 주사용자 외 사용자

**Use Cases를 찾는 방법**

- 시스템 바운더리 설정
- 주 사용자 설정
- 시스템 주 목표 설정
    - 사용자의 목표 리스트 작성
- Use Cases 정의
    - Use cases의 이름은 동사

![스크린샷 2023-04-24 오후 8.25.38.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c48f1d2f-044d-41ea-81a7-fe2b1defa25a/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.25.38.png)

![스크린샷 2023-04-24 오후 8.23.56.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ff45849d-59bd-4444-a1a8-1284fb172a4d/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.23.56.png)

![스크린샷 2023-04-24 오후 8.27.08.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9cfee3d5-9b50-4ef6-932f-3a04c9cae047/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.27.08.png)

**Requiremetnt 도출 과정**

![스크린샷 2023-04-24 오후 8.26.33.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fd2cf7de-8554-4e9f-a10e-fcf7d83131ad/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.26.33.png)

</div>
</details>


### OOAD - 09  UML-UseCase(⭐️)

<details>
<summary> OOAD - 09  UML-UseCase(⭐️) </summary>
<div markdown="1">   

**UML UseCase**

**UML(Unfied Modeling Language)**

![스크린샷 2023-04-24 오후 8.32.14.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3425d1ee-a2a6-45b4-ace2-b40b359b3439/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.32.14.png)

![스크린샷 2023-04-24 오후 8.32.58.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/42040b0f-7cfa-4c5a-91b0-1060e555feb1/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.32.58.png)

**Use Case Diagram**

시스템 : Use case를 둘러싸는 사각형으로 표현

행위자는 대개 시스템 외부에 잇는 반면 Use case는 시스템의 내부에 있다.

![스크린샷 2023-04-24 오후 8.37.54.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c1c1de7d-079b-4b98-b98a-213bd81d5195/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.37.54.png)

**Extend(추가)**

- 추가적인 행동

![스크린샷 2023-04-24 오후 8.40.13.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f5a27ae2-32eb-4d18-81d5-aba28535371f/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.40.13.png)

**Include(포함)**

- 공통된 부분들

![스크린샷 2023-04-24 오후 8.39.44.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9778ea32-61c1-4e3c-bc80-19daaad69d2d/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.39.44.png)

![스크린샷 2023-04-24 오후 8.41.20.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6edd13f2-a27f-4888-b821-2c7a74b5b9c0/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.41.20.png)

</div>
</details>


### OOAD - 10  UML-ClassDiagram

<details>
<summary> OOAD - 10  UML-ClassDiagram </summary>
<div markdown="1">   

**Class Diagram**

Class Diagram은 설계 시 가장 많이 사용되며 그 모델링 개념의 폭이 넓다.

- 객체 타입인 클래스를 표현하는 다이어그램
- 클래스의 속성, 기능, 연관관계, 일반화 등의 다른 클래스와 다양한 정적인 관계를 표현
- 정적 관계에 대한 제약 등을 표현
- **클래스 다이어그램은 클래스, 인터페이스 그리고 그들의 연관성을 보여준다.**

![스크린샷 2023-04-24 오후 8.44.14.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b330025b-7173-42db-8aa6-080f5f38f306/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.44.14.png)

![스크린샷 2023-04-24 오후 8.45.18.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2e8743d9-e38b-4a6a-9aa8-e14f5bd88f39/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.45.18.png)

![스크린샷 2023-04-24 오후 8.46.29.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fc36893e-a48d-495b-992e-eb9f4f9f3866/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.46.29.png)

**바운더리 클래스**

- 경게선에 있는 클래스
- 장점 : 바운더리만 수정하여 내부 시스템을 재활용 하기 편하다.
- Content를 배달하는 중간 관게이다.

**엔터티 클래스**

- 컨셉이라는 개념이 들어간다.
- 시스템 관점에서의 주요 추상개념이다.

**컨트롤 클래스**

- 행위에 대해 논리적으로 작동한다.
- 가장 어려운 부분으로 특히 규모에 따라 전략이 매우 다양화될 수 잇다.

![스크린샷 2023-04-24 오후 8.48.50.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/969cbc8f-382b-4df1-a4ff-ff448216292a/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.48.50.png)

**정적 오퍼레이션**

![스크린샷 2023-04-24 오후 8.51.49.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/541c8cc6-22b1-4737-bf98-f21b56380ca6/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.51.49.png)

**관계(Relationship)**

![스크린샷 2023-04-24 오후 8.52.16.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/46c336da-8b8c-4065-a922-11ab0f60e70e/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.52.16.png)

**Dependency(의존성)**

![스크린샷 2023-04-24 오후 8.53.06.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5d8e5067-b023-4129-b40f-bb922407b0df/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.53.06.png)

**Association(연관)**

![스크린샷 2023-04-24 오후 8.53.43.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/045cde0d-81f7-474d-9518-7e2defce17fd/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.53.43.png)

![스크린샷 2023-04-24 오후 8.54.13.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4a0577d4-9642-426a-be52-82e3f7e697e8/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.54.13.png)

![스크린샷 2023-04-24 오후 8.54.27.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ca1b4aaf-85bf-4846-8171-35de314b00d7/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.54.27.png)

**집합관계**

![스크린샷 2023-04-24 오후 8.55.21.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2237a613-1305-4bb0-a2fe-3308ecede107/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.55.21.png)

**구성 관계**

- 키보드는 컴퓨터위 한 부분이다.
- 차는 엔진을 반드시 포함한다.
- 물리적인 결합되어 있어 분리되어 생각되어 질 수 없다.

![스크린샷 2023-04-24 오후 8.55.47.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b03fa71d-5572-4996-91ac-7cd325e04f76/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.55.47.png)

**상속 관계**

- 장미는 꽃이다.
- 개는 동물이다.

![스크린샷 2023-04-24 오후 8.57.52.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/172e17f9-de66-4472-a955-3db5e125356b/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_8.57.52.png)

**추상 클래스**

- 직접 인스턴스를 생성할 수 없음
- 객체만 못만들 뿐 클래스와 같다
- 구현이 없이 순수한 정의만을 가진 오퍼레이션

**인터페이스**

- 다른 그룹(외부)와 서로 소통하기 때문에 계약관계로 API 개념
- 어떤 구현도 가지지 않는 클래스
- 모든 특성이 추상이다.
- 클래스내에 구현 로직이 없으며 선언만 가능하다.

![스크린샷 2023-04-24 오후 9.00.23.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2e3a3eca-b810-4844-b85a-1a6f32a72e6d/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2023-04-24_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_9.00.23.png)

</div>
</details>