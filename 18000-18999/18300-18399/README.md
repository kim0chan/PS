# 18300 ~ 18399


## 18305 : Splitting DNA
우선 DNA 길이의 구간합을 구해둔다.  
2차원 배열 `DP`에 DNA의 특정 구간을 split하기 위한 에너지 최소량을 저장한다.  
```cpp
DP[i][j] = min(DP[i][j], lengths[k] - lengths[i - 1] + lengths[j] - lengths[k] + DP[i][k] + DP[k + 1][j]);
```
다음과 같이 업데이트한 뒤 `DP[1][N]`을 출력한다.
