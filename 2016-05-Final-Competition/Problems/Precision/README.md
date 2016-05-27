# Precision

## Description

I don't know about you, but most programmers hate many mathematical constants. Typically, because they are very long. Fractions, on the other hand, are far easier to remember and give good enough precision. For example isn't it easier to memorize `pi` as the fraction `22/7` instead of `3.14159265358979323846264338327`? The potential problem in this case is the precision is only 2 digts. A better example is `355/133` which has 6 digits of precision.

Working with infinite decimals - not fun. That is why you should think of a good method to find aproximations. Your task is set at a positive decimal **Number** strictly less than 1 and a maximum denominator **MaxDenominator** to find the most accurate fraction:
* We have **Fraction = Nominator / Denominator** where **0 <= Nominator < Denominator**
* Let **Decimal** be the decimal representation of **Fraction**
* Let **Digits** be the number of decimal places in **Number**
* If **Decimal** has more digits than **Digits** they are ignored
* The most precise fraction, is the one that has the most matching digits from the beggining of **Number**. We count to the first differing digit.
  * `3.14286` and `3.14156` have `3.14` in common, so their **Precision** is 3.

You have to find the best (with biggest **Precision**) fraction of **Number**. It's denominator has to be **<= MaxDenominator**. If there are many solutions, choose the one with smallest **Denominator**. If again, there are many solutions, choose the one with smallest **Nominator**.

## Input

* Input is read from the console
  * On the first line is a natural number - **MaxDenominator**
  * On the second line is the number **Number**

## Output

* Output should be printed on the console
  * On the first line print the fraction as **Nominator/Denominator**
  * On the second line output the **Precision** of the fraction

## Constraints

* 1 <= **MaxDenominator** <= 100 000
* **Number** is consisted of 3 to 50 symbols
* **Number** will be given as `0.ddddd...`, where each `d` is a decimal digit
* Time limit: **0.2 seconds**
* Memory limit: **16 MiB**

## Examples

### Example 1

#### Input
```
42
0.141592658
```

#### Output
```
1/7
3
```

### Example 2

#### Input
```
3
0.1337
```

#### Output
```
0/1
1
```

### Example 3

#### Input
```
80000
0.1234567891011121314151617181920
```

#### Output
```
10/81
8
```

### Example 4

#### Input
```
1000
0.42
```

#### Output
```
3/7
3
```

### Example 5

#### Input
```
100
0.420
```

#### Output
```
21/50
4
```

### Example 6

#### Input
```
115
0.141592658
```

#### Output
```
16/113
7
```
