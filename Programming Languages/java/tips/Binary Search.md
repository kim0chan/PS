`contains()`는 Linear Search라서 이진 탐색이 필요할 땐 적절하지 않다.
# 1️⃣ `Collections.binarySearch()`
- 리스트에서 탐색하기
```java
import java.util.*;

List<Integer> list = Arrays.asList(1, 3, 5, 7, 9);
Collections.sort(list);

int index = Collections.binarySearch(list, 5);  // `index` == 2 (인덱스 위치 반환)
```
- 💥인자로 뭐가 들어가는지 잘 봐두기!
- 정렬된 `List<T>`에서 이진 탐색이 수행되는 것을 확인
- 반환값: 찾으면 인덱스 반환, 없으면 음수(-1)
# 2️⃣ `Arrays.binarySearch()`
- 배열에서 탐색하기
```java
import java.util.Arrays;

int[] arr = {1, 3, 5, 7, 9};
Arrays.sort(arr);

int index = Arrays.binarySearch(arr, 5);
```
- 정열된 배열에서 이진 탐색 수행
- 반환값은 `Collections.binarySearch()`와 동일

