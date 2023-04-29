<aside>
💡 JAVA로 백준 풀 시 빠른 입출력을 위한 코드

</aside>

```java
import java.io.*; //입출력 관련 import 
public static void main(String[] args) throws IOException //예외 처리 필수
BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

String s = bf.readLine();//문자열 입력 받을 때
int i = Integer.parseInt(bf.readLine());//정수 입력 받을 때
bw.write(s);
bw.flush();
bw.close();
```

## Java 알고리즘 연습 Programmers Level0

### 1. 두 수의 나눗셈
- 문제 설명 :  정수 num1과 num2가 매개변수로 주어질 때, num1을 num2로 나눈 값에 1,000을 곱한 후 정수 부분을 return 하도록 soltuion 함수를 완성해주세요.


- 해결 방법 : int 자료형을 명시적 형변환을 통해 float 또는 double형으로 변환 후 계산해야 하는 문제이다. 명시적 형변환에 대한 개념을 알고 있다면 어렵지 않게 해결이 가능하다.

### 2. 짝수의 합
- 문제 설명 : 정수 n이 주어질 때, n이하의 짝수를 모두 더한 값을 return 하도록 solution 함수를 작성해주세요


- 해결 방법 : 단순하게 반복문을 해결해도 시간초과가 걸리지 않는다.