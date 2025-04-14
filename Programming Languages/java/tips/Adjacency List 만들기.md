# 입력 예시
| info                      | edges                                                                   |
| ------------------------- | ----------------------------------------------------------------------- |
| [0,0,1,1,1,0,1,0,1,0,1,1] | [ [0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9] ] |
```java
public int solution(int[] info, int[][] edges) {
	List<Integer>[] adj = new ArrayList[info.length];
	for(int i = 0; i < info.length; i++) {
		adj[i] = new ArrayList<>();
	}
	
	for (int[] edge : edges) {
		int u = edge[0];
		int v = edge[1];
		adj[u].add(v);
	}

	// 체크
	for (int i = 0; i < adj.length; i++) {
		for(Integer v : adj[i]) {
			System.out.printf("There is a link between %d and %d\n", i, v);
		}
	}
	
	// 후략
}
```