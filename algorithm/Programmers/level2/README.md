## Programmers School Algorithm Level_2

### 1. 최댓값과 최솟값
- 문제 설명 :  문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.
예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.

- 해결 방법 : string to integer와 integer to string 함수를 알고 있다면 어렵지 않게 해결이 가능한 기본적인 문자열 문제이다.
- string to integer -> stoi(string)
- integer to string -> to_string(int)