# Trie Data Structure

Hey! This is a Trie data structure I wrote that uses the **binary representation** of integers to handle multiple queries efficiently. It's really handy for bitwise operations and competitive programming.

## Supported Compilers
Works perfectly on C++17 and C++20 compilers.

## Functionalities
This Trie structure offers the following functions. I kept the defaults simple so it's easy to drop into your code:

* `insert(x, y)`
  Inserts `y` occurrences of the integer `x`. If you don't provide `y`, it defaults to 1.

* `erase(x, y)`
  Erases `y` occurrences of the integer `x`. The default value of `y` is 1.
    
* `count(x)`
  Returns the exact number of occurrences of the integer `x` currently in the Trie.
    
* `findSmallest(k)`
  Returns the kth smallest integer. The default value of `k` is 1.
    
* `eraseSmallest(k)`
  Erases the kth smallest integer from the Trie. The default value of `k` is 1.
    
* `findGreatest(k)`
  Returns the kth greatest integer. The default value of `k` is 1.
    
* `eraseGreatest(k)`
  Erases the kth greatest integer. The default value of `k` is 1. 
    
* `countSmaller(x, y)`
  Passing `y = 0` (the default) returns the count of integers strictly smaller than `x`. Passing `y = 1` includes integers equal to `x` in the count.

* `countGreater(x, y)`
  Passing `y = 0` (the default) returns the count of integers strictly greater than `x`. Passing `y = 1` includes integers equal to `x` in the count.
    
* `minxor(x)`
  Returns the minimum value of `x XOR y`, where `y` is any integer currently present in the Trie.
    
* `maxxor(x)`
  Returns the maximum value of `x XOR y`, where `y` is any integer currently present in the Trie.
    
* `sorted()`
  Returns a vector containing all integers present in the Trie in non-decreasing order.


  ## Tested On
* [CSES - Maximum Xor Subarray](https://cses.fi/problemset/task/1655)
