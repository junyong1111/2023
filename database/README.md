# SQL

해당 정리는 김지훈님의 ‘칼퇴족 김대리는 알고 나만 모르는 SQL’  책을 참고하였습니다.

## 1. Database의 정의

- **여러 사람에게 공유되어 사용될 목적을 가지고, 구조적인 방식으로 관리되는 데이터의 집합을 이야기 한다.**
    - **쉽게 말해 정리가 잘 된 캐비닛과 비슷하다.**

### DBMS

- 데이터베이스의 체계적인 관리는 **데이터베이스 관리 시스템**(DBMS : Database Management system)을 통해 이루어진다. DBMS는 데이터를 정리하고 보관하기 위한 용도로 사용된다.
    - 대표적인 DBMS
        - ORACLE
        - MySQL
        - MsSQL
        - Teradata
        - …
- **DBMS의 특성**
    - 실시간 접근성
        - 컴퓨터가 접근할 수 있는 저장 장치에서 관리되는 데이터베이스는 지속적이고 비정형적인 질의에 대하여 실시간 처리가 가능해야 한다.
    - 계속적인 변화
        - 데이터베이스의 상태는 동적이다. 기존의 데이터베이스가 존재한다면 그 데이터베이스에 새로운 데이터 삽입(insert), 기존의 데이터 삭제(delete), 갱신(update)등의 변화를 주어 정확한 데이터를 유지해야한다.
    - 동시 공용
        - 데이터베이스는 다수의 사용자가 동시에 각자 원하는 데이터에 접근하여 이용할 수 있어야 한다.
    - 내용에 의한 참조
        - 데이터에비이스 환경에서 데이터의 참조는 레코드의 주소나 위치에 의해서가 아니라 사용자가 요구하는 데이터의 내용, 즉 데이터가 가지고 있는 값에 따라 참조된다.

### 용어

- **테이블**
    - 구조화된 엑셀 스프레드시트와 같다. 엑셀 하단에 Sheet1이 테이블이라고 생각하면 편하다.
- **스키마**
    - 테이블에 데이터가 저장되는 방식을 정의할 수 있다. 스키마는 데이터베이스에 존재하는 자료의 구조 및 내용과 자료들의 논리적, 물리적 특성에 대한 정보를 표현하는 데이터베이스의 논리적 구조를 지칭한다.
- **열(Column)**
    - 테이블을 구성하는 각각의 **정보를 말한다**
        
        
        | 고객 ID | 성별 | 주소 |
        | --- | --- | --- |
    - 고유한 데이터 형식이 지정된다. 데이터 형식은 다음과 같이 여러가지가 존재하며 지정된 데이터 형식 이외의 값은 입력할 수 없다. ex) 정수 데이터로 지정된 열은 문자 데이터 형식으로 입력할 수 없다.
        - 정수 데이터
        - 문자 데이터
        - 통화 데이터
        - 날자 및 시간 데이터
        - …
- **행(Row)**
    - 테이블의 **데이터는 행에 저장된다.**
    - 위와 같은 테이블의 행은 총 3개이며 **행을 레코드**라고 표현하기도 한다.
    
- **기본 키(Primary key)**
    - 테이블에는 각 행을 **고유하게** 하는 열이 존재하며 이를 기본 키라고 한다.
    - 위와 같은 경우 각 행을 고유하게 하는 키는 고객 ID이다.
        - 성별 또는 주소는 같을 수 있지만 고객 ID는 같을 수 없기 때문이다.
    
- **외래 키(Foreign key)**
    - 다른 테이블과의 연결을 위한 키로, 다른 테이블의 기본 키를 참조한다.
    - 예를 들어 위의 테이블에서 주문 테이블과 연결된다면, 주문 테이블의 고객 ID를 참조하는 외래 키가 생성된다.

## SQL의 개요

- SQL은 **Structured Query Language**의 약자로, 데이터베이스 관리 시스템(DBMS)에서 데이터를 관리하기 위한 표준 언어이다.
- SQL은 **관계형 데이터베이스**에서 데이터를 관리하기 위한 언어로, 데이터베이스에서 데이터를 **조회, 삽입, 삭제, 갱신** 하는 등의 작업을 가능하게 한다.
- SQL은 데이터베이스에 저장된 데이터를 조작하기 위한 언어로, 사용자가 원하는 데이터를 쉽게 가져올 수 있도록 해준다.
- SQL은 대소문자를 구분하지 않는다.
    - ex) SELECT와 select는 같은 의미를 가진다.

### SQL의 종류

- 데이터베이스에 따라 다양한 SQL이 존재하지만, 대표적으로는 **DQL, DML, DDL, DCL**이 있다.

**1) DQL (Data Query Language)**

- 데이터베이스에서 데이터를 **조회**하기 위한 언어
- 대표적인 명령어 : SELECT

**2) DML (Data Manipulation Language)**

- 데이터베이스에서 데이터를 **조작**하기 위한 언어
- 대표적인 명령어 : INSERT, UPDATE, DELETE

**3) DDL (Data Definition Language)**

- 데이터베이스의 **구조를 정의**하기 위한 언어
- 대표적인 명령어 : CREATE, ALTER, DROP

**4) DCL (Data Control Language)**

- 데이터베이스의 **보안, 권한, 무결성 등을 관리**하기 위한 언어
- 대표적인 명령어 : GRANT, REVOKE
## 2. SQL의 기초

## SELECT 문

<aside>
📃 SELECT 열 이름 FROM 테이블 명 ORDER BY 열이름 WHERE 조건절

</aside>

- SELECT 문은 DQL에 속하며, 데이터베이스에서 데이터를 조회하기 위해 가장 많이 사용되는 명령어 중 하나이다.
- SELECT 문의 기본적인 구조는 다음과 같다.

```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```

- column1, column2, ...은 조회하고자 하는 열의 이름이다.
    - 을 사용하면 모든 열을 조회할 수 있다.
- table_name은 조회하고자 하는 테이블의 이름이다.
- WHERE 조건은 조회하고자 하는 데이터에 대한 조건을 정의한다.
    - WHERE 조건을 생략하면 테이블의 모든 데이터를 조회한다.

### SELECT 문의 예시

- employees 테이블에서 모든 열을 조회하는 경우

```sql
SELECT *
FROM employees;
```

- employees 테이블에서 사원의 이름, 부서, 급여를 조회하되, 급여가 5000 이상인 사원만 조회하는 경우

```sql
SELECT name, department, salary
FROM employees
WHERE salary >= 5000;
```

<aside>
❗ SQL은 소문자와 대문자를 구분하지 않는다. 하지만 가독성을 위해 키워드는 대문자를 사용하자!!

</aside>

## 데이터 정렬하기

- 데이터를 정렬할 때에는 **ORDER BY** 키워드를 사용한다.
    - **열 이름을 사용하여 정렬하기**
    - **열 위치를 사용하여 정렬하기**
    
    |  | 장점 | 단점 |
    | --- | --- | --- |
    | 열 이름 지정방식 | - SELECT문 뒤에 선택되지 않은 열에 대해서도 정렬 가능
    - SELECT문 뒤에 출력되는 열 위치가 바뀌어도 ORDER BY절 뒤에 열 위치를 변경할 필요 없다. | - 정렬하려는 열 이름이 길 경우 ORDER BY절 뒤에 열 이름을 잘못 입력할 수 있다. |
    | 열 위치 지정 방식 | - 열 이름을 직접 입력하지 않아도 되기 때문에 정렬하려는 열 이름을 잘못 입력하는 실수를 줄일 수 있다. | - SELECT문 뒤에 선택되지 않은 열에 대해서는 정렬할 수 없다.
    - SELECT문 뒤에 출력되는 열 위치가 바뀌면 ORDER BY절 뒤의 열 위치도 변경해야 한다. |
- 기본적으로는 오름차순(ASC)으로 정렬된다. 내림차순으로 정렬하려면 **DESC** 키워드를 사용한다.
- **ORDER BY 절은 SELECT 문의 마지막에 위치한다.**

### ORDER BY 예시

- employees 테이블에서 급여가 높은 순으로 정렬하는 경우

```sql
SELECT *
FROM employees
ORDER BY salary DESC;
```

## 실습

다음과 같은 A백화점 테이블(PERF)가 있을 때 고객 생년월일을 기준으로 오름차순 정렬해서 고객아이디, 고객 생년월일, 방문횟수를 출력하라.

| CUST_ID | CUST_NM | CUST_BIRTH | VISIT_CNT | SALES_AMT | SALES_CNT |
| --- | --- | --- | --- | --- | --- |
| 56456 | 모형건 | 1982-01-24 | 123 | 3,700,000 | 24 |
| 65412 | 이상훈 | 1984-05-10 | 23 | 467,200 | 14 |
| 23472 | 이상희 | 1978-02-27 | 117 | 2,237,065 | 23 |
| 27896 | 모영길 | 1982-05-11 | 37 | 123,721 | 2 |
| 35478 | 강주혁 | 1983-09-10 | 86 | 830,000 | 30 |

```sql
SELECT CUST_ID, CUST_NM, VISIT_CNT 
FROM PERF 
ORDER BY CUST_BIRTH;
```

| CUST_ID | CUST_BIRTH | VISIT_CNT |
| --- | --- | --- |
| 23472 | 1978-02-27 | 117 |
| 56456 | 1982-01-24 | 123 |
| 27896 | 1982-05-11 | 37 |
| 35478 | 1983-09-10 | 86 |
| 65412 | 1984-05-10 | 23 |

## SELECT문에서 많이 사용되는 키워드

### 1) DISTINCT 키워드

- DISTINCT 키워드는 SELECT 문에서 중복된 값을 제거하여 결과를 출력하는데 사용된다.
    - COUNT라는 함수와  함께 많이 사용된다.
    
    ```sql
    SELECT COUNT(DISTINCT POSITION) FROM EMP:
    ```
    
- 예를 들어, 아래와 같은 employees 테이블에서 모든 부서를 조회하는 경우, 중복된 부서가 존재할 수 있다.
    
    ```sql
    SELECT department
    FROM employees;
    ```
    
- 중복된 부서를 제거하고 싶은 경우, 아래와 같이 DISTINCT 키워드를 사용한다.
    
    ```sql
    SELECT DISTINCT department
    FROM employees;
    ```
    
- 이렇게 하면 중복된 부서가 제거되어 결과가 출력된다.

<aside>
❗ DISTINCT에 반대되는 키워드는 ALL이며 기본값으로 설정되어 있다.

</aside>

### 2) ALIAS(별칭)

- 별칭은 열 이름이나 테이블 이름에 대한 대체 이름을 말한다.
- SQL에서는 AS 키워드를 사용하여 별칭을 정의한다.
    - 또는 다음과 같이 인용부호를 사용할 수 있다 ⇒ “새로운 열 이름”
- 별칭을 사용하면 열 이름이나 테이블 이름을 간단하고 의미있는 이름으로 대체할 수 있어 가독성을 높일 수 있다.
- 아래와 같이 SELECT 문에서 열 이름에 별칭을 붙여 사용할 수 있다.
    
    ```sql
    SELECT column_name AS alias_name
    FROM table_name;
    ```
    
- 아래와 같이 SELECT 문에서 테이블 이름에 별칭을 붙여 사용할 수 있다.

## 실습

다음과 같은 인사고과 테이블 EMP가 있을 때 실제 인사고과를 주는 사람이 누구고, 몇 분인지 알아보기 위한 코드를 작성 (인사고과를 주고 있는 사람 수를 CNT라는 별칭을 사용)

| CLERK_ID | POSITION | PARTY_NM | MANAGER_ID | TEAM_NM | PERF |
| --- | --- | --- | --- | --- | --- |
| 650 | 대리 | 이재훈 | 1270 | 마케팅부 | 1 |
| 540 | 과장 | 장성수 | 3221 | 리스크부 | 2 |
| 210 | 차장 | 문보미 | 3914 | 인사팀 | 3 |
| 347 | 차장 | 정호천 | 3942 | 기획팀 | 3 |
| 970 | 부장 | 김영성 | 3221 | 리스크부 | 2 |
| 345 | 대리 | 오윤경 | 1270 | 마케팅부 | 2 |
| 711 | 과장 | 이재중 | 3914 | 인사팀 | 2 |
- 인사고과를 주는 사람들 구하기
    
    ```sql
    SELECT DISTINCT MANAGER_ID FROM EMP;
    ```
    
- 인사고과를  몇 명이 주고 있는지 구하기
    
    ```sql
    SELECT COUNT(DISTINCT MANAGER_ID) FROM EMP;
    ```
    
- 별칭 사용
    
    ```sql
    SELECT COUNT(DISTINCT MANAGER_ID) AS CNT FROM EMP;
    ```
    

### 3) WHERE 키워드

- WHERE 키워드를 사용하여 **조건에 맞는 행만 조회**할 수 있다.
- WHERE 키워드는 SELECT, UPDATE, DELETE 문에서 모두 사용할 수 있다.

### WHERE 예시

- employees 테이블에서 부서가 'Sales'인 사원들의 정보를 조회하는 경우

```sql
SELECT *
FROM employees
WHERE department = 'Sales';

```

- employees 테이블에서 급여가 5000 이상인 사원들의 이름과 급여를 조회하는 경우

```sql
SELECT name, salary
FROM employees
WHERE salary >= 5000;

```

## 실습

다음과 같은 구매 테이블 PURCHASE_TRAN을 참고하여 다음 문제에 맞게 SQL 쿼리

| ID | PURCHASE_AMT | PURCHASE_CNT | LAST_AMT | LAST_CNT |
| --- | --- | --- | --- | --- |
| 145 | 2,000,000 | 12 | 1,231,000 | 21 |
| 455 | 1,273,100 | 1 | 2,237,230 | 22 |
| 463 | 111,463 | 3 | 214,047 | 1 |
| 324 | 154,769 | 3 | 7,474,663 | 13 |
| 568 | 25,784,652 | 47 | 1,000,047 | 3 |
| 662 | 106,868 | 1 | 277,763 | 1 |
| 871 | 9,694,470 | 123 | 798,874 | 2 |
| 460 | 65,650,000 | 1200 | 6,557,741 | 320 |
| 277 | 57,663,000 | 470 | 57,663,000 | 444 |
| 309 | 5,579,800 | 415 | 2,333,000 | 135 |
1. **PURCHASE_TRAN 테이블에서 올해 구입금액이 1백만원 이상인 고객의 고객번호와 올해 구입금액을 표시**

```sql
SELECT ID, PURCHAS_AMT FROM PURCHASE_TRAN WHERE PURCHASE_AMT >= 1000000;
```

1. **PURCHASE_TRAN 테이블에서 작년 구입금액이 1백만원 이상 5천만원 이하인 고객의 고객번호와 작년 구입금액을 표시**

```sql
SELECT ID, LAST_AMT FROM PURCHASE_TRAN WHERE 1000000 <= LAST_AMT <= 50000000;
```

1. **PURCHASE_TRAN 테이블에서 올해 구입건수가 작년도 구입건수보다 많은 고객들의 고객번호, 올해 구입건수, 작년도 구입건수를 나타내고 고객번호를 기준으로 오름차순으로 정렬**

```sql
SELECT ID, PURCHASE_CNT, LAST_CNT
FROM PURCHASE_TRAN 
WHERE PURCHASE_CNT > LAST_CNT
ORDER BY ID ASC;
```

1. **올해 판매가격의 순 매출마진이 10%라고 가정하자. PURCHASE_TRAN 테이블에서 순이익의 별칭을 INCOME_AMT라고 사용하여 올해 고객별 순이익을 계산**
    - 순 매출마진 : 순이익/총 매출액

```sql
SELECT ID, PURCHASE_AMT * 0.10
AS INCOME_AMT
FROM PURCHASE_TRAN 
```

1. **올해 고객의 건당 구입금액을 구하고, 별칭은 TICKET_SIZE로 설정**

```sql
SELECT ID, PURCHASE_AMT / PURCHASE_CNT
AS TICKET_SIZE
FROM PURCHASE_TRAN;
```

1. **보험원장 테이블(INS_INFO 테이블)에서 실제 살아있는 계약만 추출하여 고객번호, 계약번호 및 가입금액을 출력**
    - 해지일이 없으면 현재 살아있는 계약으로 인식할 수 있다.

```sql
SELECT ID, CNTR_NO, CNRT_AMT
FROM INS_INFO
WHERE CNCL_DT IS NULL;
```

1. **보험원장 테이블(INS_INFO 테이블)에서 해지된 계약만 추출하여 고객번호, 계약번호 및 가입금액을 출력**

```sql
SELECT ID, CNTR_NO, CNRT_AMT
FROM INS_INFO
WHERE CNCL_DT IS NOT NULL;
```

**비즈니스 세계에서 유용한 ‘티켓 사이즈(Ticket size)’라는 개념이 존재**

티켓 사이즈는 직관적으로 고객당 수익이나 가입금액이 얼마인지 알려주는 아주 유용한 개념이 존재한다. 구입 금액이 가장 커도 실제 티켓 사이즈가 작을 수 있다.

- 인당 구매 금액
- 인당 가입금액
- …

**NULL값인 행을 찾을 때는 IS NULL, NULL값이 아닌 행을 찾을 때는 IS NOT NULL을 사용한다.**

이 때 NULL은 데이터가 존재하지 않는다는 것을 의미하며, SPACE 또는 숫자 0과 개념이 다르다.

- NULL을 사용할 때는 연산 ‘=’를 사용할 수 없다.

**NULL값은 오름차순 혹은 내림차순으로 정렬 시 가장 큰 값으로 분류된다.**

보험원장 테이블 INS_INFO에서 해약일을 기준으로 오름차순 정렬하면 NULL값이 가장 아래쪽에 위치하게 된다.

**NULL값의 처리**

**COALESCE 함수 문법**

```sql
COALESCE(EXPRESSION 1, EXPRESSION 2, ..., EXPRESSION N)
```

EXPRESSION 1이 NULL값이 아니면 EXPRESSION 1을 리턴하고, EXPRESSION 1이 NULL값이고 EXPRESSION 2 NULL이 아니면 EXPRESSION 2 값을 리턴

- **해당 함수는 NULL값을 0으로 치환할 때 많이 사용함**

**NULL값과 0은 다른 의미이다. NULL값이 포함된 사칙연산을 할 때 결과값은 NULL값이다.**

- COALESCE(’A’, ‘B’) → ‘A’리턴
- COALESCE(NULL, ’B’, ‘C’) → ‘B’리턴
- ZEROIFNULL(열 이름) : 해당 열에 NULL값이 포함되면 숫자 0으로 바꾸는 함수
- NVL2(열 이름, 표현식1, 표현식2) : 해당 열이 NULL이면 ‘표현식 2’의 값을 나타내고, NULL이 아니면 ‘표현식 1’의 값을 나타냄
    - **MYSQL에서는 IFNULL 키워드를 사용한다(열이름, “바꾸고자 하느 값”)**

### 3) LIKE 키워드

- LIKE 키워드는 WHERE 조건절에서 문자열 패턴을 비교하여 해당 패턴을 포함하는 데이터를 조회할 때 사용된다.
- LIKE 키워드는 %와 _를 사용하여 패턴을 지정한다.
    - % : 0개 이상의 임의의 문자열을 의미한다.
    - _ : 한 개의 임의의 문자를 의미한다.

### LIKE 예시

- employees 테이블에서 이름이 'J'로 시작하는 사원들의 정보를 조회하는 경우

```sql
SELECT *
FROM employees
WHERE name LIKE 'J%';
```

- employees 테이블에서 이름이 'John'으로 시작하는 사원들의 정보를 조회하는 경우

```sql
SELECT *
FROM employees
WHERE name LIKE 'John%';
```

- employees 테이블에서 이름이 5글자인 사원들의 정보를 조회하는 경우

```sql
SELECT *
FROM employees
WHERE name LIKE '_____';
```

### 4) IN 키워드

- IN 키워드는 WHERE 조건절에서 여러 개의 조건을 지정하여 해당 조건 중 하나에 해당하는 데이터를 조회할 때 사용된다.

### IN 예시

- employees 테이블에서 부서가 'Sales'이거나 'Marketing'인 사원들의 정보를 조회하는 경우

```sql
SELECT *
FROM employees
WHERE department IN ('Sales', 'Marketing');
```

### 5) BETWEEN 키워드

- BETWEEN 키워드는 WHERE 조건절에서 범위를 지정하여 해당 범위에 속하는 데이터를 조회할 때 사용된다.

### BETWEEN 예시

- employees 테이블에서 급여가 3000에서 5000 사이인 사원들의 정보를 조회하는 경우

```sql
SELECT *
FROM employees
WHERE salary BETWEEN 3000 AND 5000;
```

## 결론

- SQL은 데이터베이스에 저장된 데이터를 조작하기 위한 언어로, 대표적으로 DQL, DML, DDL, DCL이 있다.
- SELECT 문은 가장 많이 사용되는 DQL 중 하나로, 데이터를 조회하기 위해 사용된다.
- WHERE 조건절을 사용하여 조회할 데이터를 지정할 수 있다.
- DISTINCT, LIKE, IN, BETWEEN 등 다양한 키워드를 사용하여 데이터를 원하는 대로 조회할 수 있다.

## 기본적인 데이터 조작

### 1) 데이터 삽입

- 데이터베이스에 새로운 데이터를 삽입하기 위해서는 **INSERT** 문을 사용한다.
- INSERT 문의 기본적인 구조는 다음과 같다.

```sql
INSERT INTO table_name (column1, column2, column3, ...)
VALUES (value1, value2, value3, ...);
```

- table_name은 데이터를 삽입하고자 하는 테이블의 이름이다.
- column1, column2, column3, ...은 삽입하고자 하는 열의 이름이다.
- value1, value2, value3, ...은 삽입하고자 하는 값을 의미한다.

### INSERT 예시

- employees 테이블에 새로운 데이터를 삽입하는 경우

```sql
INSERT INTO employees (name, department, salary)
VALUES ('John Doe', 'Sales', 5000);
```

### 2) 데이터 갱신

- 데이터베이스에 저장된 데이터를 갱신하기 위해서는 **UPDATE** 문을 사용한다.
- UPDATE 문의 기본적인 구조는 다음과 같다.

```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```

- table_name은 갱신하고자 하는 테이블의 이름이다.
- column1 = value1, column2 = value2, ...은 갱신하고자 하는 열과 값을 의미한다.
- WHERE 조건은 갱신하고자 하는 데이터에 대한 조건을 정의한다.

### UPDATE 예시

- employees 테이블에서 이름이 'John Doe'인 사원의 급여를 6000으로 업데이트하는 경우

```sql
UPDATE employees
SET salary = 6000
WHERE name = 'John Doe';
```

### 3) 데이터 삭제

- 데이터베이스에서 데이터를 삭제하기 위해서는 **DELETE** 문을 사용한다.
- DELETE 문의 기본적인 구조는 다음과 같다.

```sql
DELETE FROM table_name
WHERE condition;
```

- table_name은 삭제하고자 하는 테이블의 이름이다.
- WHERE 조건은 삭제하고자 하는 데이터에 대한 조건을 정의한다.

### DELETE 예시

- employees 테이블에서 이름이 'John Doe'인 사원의 데이터를 삭제하는 경우

```sql
DELETE FROM employees
WHERE name = 'John Doe';
```