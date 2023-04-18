## Programmers School Algorithm Level_1

### 1. 추억 점수
- 문제 설명 :  그리워하는 사람의 이름을 담은 문자열 배열 name, 각 사람별 그리움 점수를 담은 정수 배열 yearning, 각 사진에 찍힌 인물의 이름을 담은 이차원 문자열 배열 photo가 매개변수로 주어질 때, 사진들의 추억 점수를 photo에 주어진 순서대로 배열에 담아 return하는 solution 함수를 완성

- 해결 방법 : 각각의 사람당 그리움 점수를 map 자료구조로 담아준 후 해당 사진에서 등장한 인물들을 map구조에서 seach한 후 값들을 총합해주는 식으로 해결하였다.