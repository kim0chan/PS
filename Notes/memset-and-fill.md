# C++ 초기화 memset, fill
## `memset`
```cpp
memset(배열 이름, 초기화 값, 배열 크기);
memset(visited, 0, sizeof(visited));
```
1 바이트 단위로 메모리를 초기화하기 때문에 배열 값을 0으로 초기화 할 때 주로 사용한다.  
bool 형이 아닌 배열을 1로 초기화하는 것은 불가능하다(고 한다).  
또한 바이트 단위기 때문에 char 초기화 할 때도 좋다(고 한다).

## `fill`
```cpp
fill(시작 위치, 끝나는 위치 + 1, 초기화 값);
fill(arr, arr + 10, 5);        // 배열 크기가 10인 경우
fill(&arr[0][0], &arr[ROW - 1][COL], value)        // 2차원 배열에서
```
