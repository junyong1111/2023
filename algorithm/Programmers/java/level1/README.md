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

## Java 알고리즘 연습 Programmers Level_1

### 1. 가장 가까운 같은 글자
- 문제 설명 :  문자열 s가 주어졌을 때, s의 각 위치마다 자신보다 앞에 나왔으면서, 자신과 가장 가까운 곳에 있는 같은 글자가 어디 있는지 알고 싶습니다.


- 해결 방법 : 문자열의 중복을 체크하는 check 배열을 만들어 해당 배열에 문자가 나온 마지막 index를 저장하는 방식으로 해결가능하며 이러한 방법은 중복은 체크할 때 유용하게 사용할 수 있는 방법이다. 

```java
// 자바 배열의 원소를 특정한 값으로 전부 초기화 하는 함수
Arrays.fill(arr, value);
```

