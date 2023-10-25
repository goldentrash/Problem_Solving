# 교수님의 IDEA (Greedy)

구간 `[st, en]`에서, `en`을포함하는 최대 부분 순열은
`preSum[en] - minPreSum`
이다.

## 발상의 전환

원소 a(i)를 오른쪽 끝으로 하는 순열의 최대 부분 순열은 무엇일까?

```cpp
long long maxS = pSum[1];
long long minS = pSum[0];
for(int i = 1; i <= N; i++){
  minS = (pSum[i] < minS) ? pSum[i] : minS;
  maxS = (pSum[i] - minS > maxS) ? pSum[i] - minS : maxS;
}
```
