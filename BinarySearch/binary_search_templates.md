# Binary Search Templates: "Find the First Value That Works"

All examples use the same toy predicate on the range $[1, 8]$:

$$
\text{ok}(k) = (k \ge 4)
$$

So the answer (the smallest $k$ that works) is $4$.

```
k:    1  2  3  4  5  6  7  8
ok:   F  F  F  T  T  T  T  T
                ^ answer
```

---

## Template A: `while (l <= r)`, `r = mid - 1`

```cpp
int l = 1, r = 8;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(mid)) r = mid - 1;   // mid works, but look for something smaller
    else         l = mid + 1;
}
return l;                       // first value that works
```

- **Search range:** $[l, r]$, closed on both ends.
- When `mid` works, it is **dropped** from the range (`mid - 1`).
- **Stops when** $l = r + 1$. At that point $l$ is the first value that works and $r$ is the last value that fails.

| step | l | r | mid | ok(mid) | update    |
|------|---|---|-----|---------|-----------|
| 1    | 1 | 8 | 4   | T       | r = 3     |
| 2    | 1 | 3 | 2   | F       | l = 3     |
| 3    | 3 | 3 | 3   | F       | l = 4     |
| end  | 4 | 3 |     |         | return **4** |

---

## Template B: `while (l < r)`, `r = mid`

```cpp
int l = 1, r = 8;
while (l < r) {
    int mid = l + (r - l) / 2;
    if (ok(mid)) r = mid;       // mid might be the answer, so keep it
    else         l = mid + 1;
}
return l;                       // l == r == answer
```

- **Search range:** $[l, r]$, which always contains the answer.
- When `mid` works, it is **kept** (`r = mid`).
- **Stops when** $l = r$, leaving one candidate: the answer.
- Requires `mid` to round **down**. Since `mid < r` whenever `l < r`, `r = mid` always shrinks the range.

| step | l | r | mid | ok(mid) | update    |
|------|---|---|-----|---------|-----------|
| 1    | 1 | 8 | 4   | T       | r = 4     |
| 2    | 1 | 4 | 2   | F       | l = 3     |
| 3    | 3 | 4 | 3   | F       | l = 4     |
| end  | 4 | 4 |     |         | return **4** |

---

## Side by side

|                         | Template A            | Template B          |
|-------------------------|-----------------------|---------------------|
| Loop condition          | `l <= r`              | `l < r`             |
| When `ok(mid)`          | `r = mid - 1`         | `r = mid`           |
| When `!ok(mid)`         | `l = mid + 1`         | `l = mid + 1`       |
| Ends with               | $l = r + 1$           | $l = r$             |
| Answer                  | `l`                   | `l` (or `r`)        |
| If nothing works        | `l` = hi + 1          | `l` = hi (check it) |

The last row matters when the answer might not exist. In Template A, $l = \text{hi} + 1$ signals "no answer". In Template B, `l` stays at `hi`, so check `ok(hi)` separately. (For Koko, $k = \max(\text{piles})$ always works, so this never comes up.)

---

## Don't mix the parts

**`while (l <= r)` with `r = mid`: infinite loop**

| step | l | r | mid | ok(mid) | update |
|------|---|---|-----|---------|--------|
| 1    | 1 | 8 | 4   | T       | r = 4  |
| 2    | 1 | 4 | 2   | F       | l = 3  |
| 3    | 3 | 4 | 3   | F       | l = 4  |
| 4    | 4 | 4 | 4   | T       | r = 4  |
| 5    | 4 | 4 | 4   | T       | r = 4  ← stuck forever |

**`while (l < r)` with `r = mid - 1`: skips the answer**

| step | l | r | mid | ok(mid) | update |
|------|---|---|-----|---------|--------|
| 1    | 1 | 8 | 4   | T       | r = 3  ← the answer 4 is thrown away |
| 2    | 1 | 3 | 2   | F       | l = 3  |
| end  | 3 | 3 |     |         | returns **3** ✗ |

---

## `l + (r - l) / 2` vs `(l + r) / 2`

For $0 \le l \le r$, the two give the same value:

$$
l + \left\lfloor \frac{r - l}{2} \right\rfloor = \left\lfloor \frac{l + r}{2} \right\rfloor
$$

The first form starts at $l$ and moves halfway across the gap. The difference is overflow. `l + r` is an intermediate value that can exceed `INT_MAX` $= 2^{31} - 1 \approx 2.147 \times 10^9$, but `r - l` never can.

**Example:** $l = 1.5 \times 10^9$, $r = 2.0 \times 10^9$, both valid `int`s.

| expression          | intermediate              | result                          |
|---------------------|---------------------------|---------------------------------|
| `(l + r) / 2`       | $3.5 \times 10^9$, overflows | garbage (undefined behaviour) |
| `l + (r - l) / 2`   | $r - l = 5 \times 10^8$   | $1.75 \times 10^9$ ✓            |

For Koko eating bananas, $r \le 10^9$, so $l + r \le 2 \times 10^9 < \texttt{INT\_MAX}$ and either form works. Using `l + (r - l) / 2` is a habit that costs nothing.