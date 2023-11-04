# 26000 ~ 26999


## 26215 : 눈 치우기
정렬을 유지해야할 필요가 있다고 생각하여 `priority_queue`를 이용했다.  
문제는 가능하면 두 집 앞의 눈을 한 번에 치우도록 해야 한다는 것이다.  
`N=5`이고 입력이 `9 8 7 6 6`인 경우를 생각해보자.  
```
9 8 7 6 6  elapsed time : 0
6 6 6 6 0  elapsed time : 9
6 6 0 0 0  elapsed time : 15
0 0 0 0 0  elapsed time : 21
```
언뜻 보면 이게 최소 시간을 들이는 것처럼 보이지만,
```
9 8 7 6 6  elapsed time : 0
8 7 7 6 6  elapsed time : 1
7 7 6 6 6  elapsed time : 2
6 6 6 6 6  elapsed time : 3
6 6 6 5 5  elapsed time : 4
6 5 5 5 5  elapsed time : 5
5 5 5 5 4  elapsed time : 6
5 5 4 4 4  elapsed time : 7
4 4 4 4 4  elapsed time : 8
4 4 4 3 3  elapsed time : 9
4 3 3 3 3  elapsed time : 10
3 3 3 3 2  elapsed time : 11
3 3 2 2 2  elapsed time : 12
2 2 2 2 2  elapsed time : 13
2 2 2 1 1  elapsed time : 14
2 1 1 1 1  elapsed time : 15
1 1 1 1 0  elapsed time : 16
1 1 0 0 0  elapsed time : 17
0 0 0 0 0  elapsed time : 18
```
이렇게 하면 더 짧은 시간에 눈을 모두 치울 수 있다.