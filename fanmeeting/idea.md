### 종만씨의 생각

```cpp
string num1;
string num2;
string num3 = num1 * num2;

// carryout을 고려하지 않을 때,
num3[i] = num1[0] * num2[i] +
          num1[1] * num2[i - 1] +
          num1[2] * num2[i - 2] +
          ...
          num1[i] * num2[0];
```

멤버와 팬의 성별 M을 1로, F를 0으로 하는 2진수 수라고 생각하면

```cpp
// member: MMFFMM
string member = 110011;

// fan: FFM
string fan = 001;
```

여기서 fan을 역으로 하고 서로 곱하면

```cpp
string reverseFan = 100;

string temp = member * reverseFan;
/*
temp[2] == member[0] * reverseFan[2]
        + member[1] * reverseFan[1]
        + member[2] * reverseFan[0]

        == member[0] * fan[0]
        + member[1] * fan[1]
        + member[2] * fan[2]
*/
```

즉, 자릿수의 숫자는 남자쌍의 수를 의미한다. 포옹을 하는 경우에는 남자쌍이 0이어야 하므로, 결과에서 0인 자리의 수를 구하면 되겠다.
