```java
public static void main (String[] args) throws IOException {  
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
    int N = Integer.parseInt(br.readLine());  
    List<String> filenames = new ArrayList<>();  
  
    for(int i = 0; i < N; i++) {  
        filenames.add(br.readLine());  
    }  
      
    for(String filename : filenames) {  
        System.out.println("filename = " + filename);  
    }  
}
```