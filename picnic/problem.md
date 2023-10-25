# Problem

N개의 node와 M개의 edge가 주어진다. node를 2개씩 묶는 경우의 수는 몇 개인가?

(단, 묶는 두 노드는 연결된 상태여야 한다.)

### Input

- C: test case의 수 (C <= 50)
- N: node의 수 (2 <= N <= 10, N % 2 == 0)
- M: edge의 수 (0 <= M <= N \* (N - 1) / 2)
- (n1, n2): edge (0 <= n <= N - 1)

### Output

각 test case마다 가능한 경우의 수를 출력한다.
