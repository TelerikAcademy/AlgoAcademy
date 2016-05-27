# Bad Cat

## Description

I had a **number** (with distinct digits) written on a sheet of paper.
My cat (Sid) ate it (she loves to eat paper)!
Now I can only remember that some digits were before or after others. My memory is good and the order of digits I remember are always correct.
Please help me **find the smallest possible number that corresponds to the digits order I remember**.
The number was valid integer number with no leading zeroes.
There is always a possible solution.

## Input

- The input data should be read from the console.
- On the first line there will be the number **N**.
- On each of the next N lines there will be a string in the format “**X is before Y**” or “**X is after Y**”. **X** and **Y** will be valid digits (‘0’ – ‘9’).
- The input data will always be valid and in the format described. There is no need to check it explicitly.

## Output

- The output data should be printed on the console.
- On the only output line write the smallest possible number that corresponds to the rules described in the input.

## Constraints

- **N** will be between 1 and 20.
* Time limit: **0.05 seconds**
* Memory limit: **16 MiB**

## Examples

### Example 1

#### Input
```
5
1 is before 2
4 is after 2
3 is before 4
6 is after 4
6 is before 8
```

#### Output
```
123468
```

### Example 2

#### Input
```
6
8 is before 7
6 is before 5
3 is after 4
1 is after 2
2 is before 1
1 is after 2
```

#### Output
```
21436587
```
