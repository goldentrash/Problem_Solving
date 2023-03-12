# Idea from Youtube

모든 `2*2 블럭`의 xor값을 `0`으로 통일하자.

=> **순차적으로 증가하는 연속된 4수의 xor은 0이다.**

## xor의 성질

1. 한자릿수 xor에서 결과는 **`1`의 개수**가 **홀수**이면 `1`, **짝수**이면 `0`이다.
2. `0 ^ 1 ^ 2 ^ 3 == 0`

## 내 결론

가능한 `Bij`는 64bit 범위이다. 2\*2범위의 **block**을 기준으로 해당 `Bij`를 다음과 같이 분배하자

```
  xxx...xxx | Y-axis (7bits) | X-axis (7bits) | order within block (2bits)
```

위와 같이 하면, 같은 Block 안의 xor은 늘 `0`이 된다.
