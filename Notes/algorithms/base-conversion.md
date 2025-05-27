# 진법 변환
## 1. 10진수 -> 3진수 문자열 변환 (Java)
```java
public static String decimalToTernary(int decimal) {
	if (decimal == 0)  return "0";
	
	StringBuilder ternary = new StringBuilder();
	while (decimal > 0) {
	  ternary.append(decimal % 3);
	  decimal /= 3;
	}
	
	return ternary.reverse().toString();
}
```
- `tenrary.insert(0, decimal % 3)`을 한 다음 그냥 `toString()`을 반환해도 된다.
## 2. 3진수 문자열 -> 10진수 변환 (Java)
```java
public static int ternaryToDecimal(String ternary) {
	int decimal = 0;
	int length = ternary.length();
	
	for (int i = 0; i < length; i++) {
		char c = ternary.charAt(i);
		// 방어 로직
		if (c < '0' || c > '2') {
			throw new IllegalArgumentException("Invalid ternary digit: " + c);
		}
		
		decimal = decimal * 3 + (c - '0');
	}
	
	return decimal;
}
```