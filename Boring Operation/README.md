You are given an array A with N elements: A1,A2,...,An​​, (1≤Ai≤10^9​​). You can perform the following operation as many times as you wish:
```
Choose an element Ai​​, and replace it with 10^9 − Ai​​.
```

Let Vmin​​ be the minimum value in the resulting array, and Vmax​​ the maximum value. Your task is to perform the operation above as many times as you wish, in order to minimize Vmax − Vmin​​.

## Standard input

In the first line of the input there will be the number N, representing the size of the array. On the second line there will be n integers, denoting the elements in the array.

## Standard output

You should output a single line with the minimal value of Vmax − Vmin​​ that can be obtained using the operation above as many times as you wish.