# Task solution

Check shop shelf

```text
command > print shop

Shop shelf:
----------------------------------------
1. bread - 100 x $0.9 = $90
2. white bread - 100 x $1.1 = $110
3. milk - 100 x $1.3 = $130
4. butter - 100 x $3.6 = $360
5. sour cream - 100 x $1.8 = $180
6. meat - 100 x $16 = $1600
7. orange - 100 x $3 = $300
8. apple - 100 x $2.5 = $250
9. sugar - 100 x $2.05 = $205
10. pasta - 100 x $1.29 = $129
11. whisky - 1 x $45 = $45
12. cola - 1 x $5 = $5
....................
Subtotal: $3404
```

Get products like in example

- 5 x bread
- 1 x butter
- 2 x pasta

```text
command > add 1 5
command > add 4 1
command > add 10 2
```

Check your cart (optional)

```text
command > print cart

Client cart:
----------------------------------------
1. bread - 5 x $0.9 = $4.5
4. butter - 1 x $3.6 = $3.6
10. pasta - 2 x $1.29 = $2.58
....................
Subtotal: $10.68
```

Ok! Let's checkout!

```text
command > checkout

Client cart:
----------------------------------------
1. bread - 5 x $0.9 = $4.5
4. butter - 1 x $3.6 = $3.6
10. pasta - 2 x $1.29 = $2.58
....................
Subtotal: $10.68
checkout
total: $8.43
discount used: Most valued position - 50%
```

## Other solutions

```text
command > checkout

Client cart:
----------------------------------------
1. bread - 5 x $0.9 = $4.5
4. butter - 1 x $3.6 = $3.6
10. pasta - 3 x $1.29 = $3.87
2. white bread - 1 x $1.1 = $1.1
....................
Subtotal: $13.07
checkout
total: $10.7972
discount used: Flour discount - 24%
```

```text
command > checkout

Client cart:
----------------------------------------
1. bread - 5 x $0.9 = $4.5
4. butter - 1 x $3.6 = $3.6
10. pasta - 3 x $1.29 = $3.87
2. white bread - 1 x $1.1 = $1.1
3. milk - 5 x $1.3 = $6.5
....................
Subtotal: $19.57
checkout
total: $16.237
discount used: Milk discount - 33%
```

```text
command > checkout

Client cart:
----------------------------------------
1. bread - 5 x $0.9 = $4.5
10. pasta - 3 x $1.29 = $3.87
2. white bread - 1 x $1.1 = $1.1
3. milk - 5 x $1.3 = $6.5
....................
Subtotal: $15.97
checkout
total: $12.72
discount used: Most valued position - 50%
```
