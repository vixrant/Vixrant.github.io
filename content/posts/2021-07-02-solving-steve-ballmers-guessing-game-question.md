---
title: Solving Steve Ballmer's Guessing Game Question
draft: false
date: 2021-07-02T12:19:38.209Z
tags:
  - fp
  - interview
  - haskell
categories:
  - tutorials
---
# The Problem

There's this quite popular interview with Steve Ballmer where he explains a "hard" question that he gives to students in interviews.

{{< youtube svCYbkS0Sjk >}}

Now I'm not a statistics guy, I like algorithms and simulations. So here's my solution to this problem. I'll also upload images on how to do it by hand.

## Reframing the Problem

> There's a small change in this blog post, I believe the starting payoff should be \$4 instead of $5 as per my simulation. Therefore, I will consider the starting profit as \$4.

Let me reframe the question in a style of writing more familiar with competetive coders:

You are given a range of number `[1, N]` and a starting payoff of `K` dollars.

Ballmer will pick any number in this range only. You have to guess the number in his mind. For every number that you guess, Ballmer will tell you if the number is higher or lower than the number in his mind. If you guess the number in 1st guess, you get `$K`. If you guess the number in 2nd guess, you get `$(K - 1)`, and so on. The amount you win keeps decreasing with the number of guesses you make. After a certain number of guesses, you would owe Ballmer instead of gaining money from him.

For example, if the range is `[1,100]` and starting payoff is \$4, the prize you'd win in the game will be as follows:

1 guess = \$4

2 guesses = \$3

3 guesses = \$2

4 guesses = \$1

5 guesses = \$0

6 guesses = -\$1 (You owe Ballmer now)

7 guesses = -\$2

And so on.

Determine for given value of `N` and `K` whether you should play the game or not, depending on the mean value of payoff for all numbers. If mean value is positive, then you should play the game.

# The Intuition

Simply by listening to the words "guess", "high/ low", "1-100", we can infer that we can use **Binary Search** in the solution. The array is sorted in an increasing manner, and we are told whether our guess is either higher or lower than the number we need to find. Therefore, binary search will give us the answer in `lg n + 1` number of operations. You can try running binary search manually, for the number chosen as 2:

*Guess 1:* Checking 1 - 100, we choose 50.5 (floor = 50).

*Guess 2:* Checking 1 - 49, we choose 25.

*Guess 3:* Checking 1 - 24, we choose 12.5 (floor = 12).

*Guess 4:* Checking 1 - 11, we choose 6.

*Guess 5:* Checking 1 - 5, we choose 3.

*Guess 6:* Checking 1 - 2, we choose 1.5 (floor = 1).

*Guess 7:* Checking 2 - 2, we choose 2.

This was the worst case scenario where we make 7 guesses, therefore our payoff decreases to -\$2, meaning we owe Ballmer \$2. This, however, is still the most optimal method to guess numbers. We'll go with this algorithm for figuring out if we can expect profit or not.

# Expected Value by Program

In order to find the expected value of the game, we need to calculate how many operations (guesses) we need to make to reach all 1 - 100 numbers. You can do this manually by splitting the binary tree again and again. I wrote a haskell program to find the expected value as follows:

```haskell
gains :: Int -> Int -> [Int]
gains n maxGain = gains' 0 (n-1) maxGain
    where gains' l h g
            | l > h = []
            | otherwise = gains' l (mid-1) (g-1) ++ [g] ++ gains' (mid+1) h (g-1)
                            where mid = div (l+h) 2
```

The `gains` function accepts the range of numbers (100 in this case) and maximum payoff ($4). It uses a recursive divide-and-conquer algorithm to find number of operations for each number.

Running this function for our given problem statement, we get the per-number operations count as:

```haskell
*Main> gains 100 4
[-1,-2,0,-1,-2,1,-1,-2,0,-1,-2,2,-1,-2,0,-1,-2,1,-1,-2,0,-2,-1,-2,3,-1,-2,0,-1,-2,1,-1,-2,0,-1,-2,2,-1,-2,0,-1,-2,1,-1,-2,0,-2,-1,-2,4,-1,-2,0,-1,-2,1,-1,-2,0,-1,-2,2,-1,-2,0,-1,-2,1,-1,-2,0,-2,-1,-2,3,-1,-2,0,-1,-2,1,-1,-2,0,-2,-1,-2,2,-1,-2,0,-1,-2,1,-1,-2,0,-2,-1,-2]
```

Lets run this through run-length encoding and figure out the count of every payoff!

```haskell
*Main> import Data.List
*Main Data.List> code = map (\x -> (head x, length x)) . group
*Main Data.List> code $ sort $ gains 100 4
[(-2,37),(-1,32),(0,16),(1,8),(2,4),(3,2),(4,1)]
```

Interesting pattern here, 1 -> 2 -> 4 -> 8 -> 16 -> 32 and then since we can't get 64, we get 37. Clearly, there are 69 negative numbers, 16 times zero payoff, and 15 positive numbers. Just looking at this data alone, we can say that we are only 15% likely to gain something in the game!

```haskell
divF :: Int -> Int -> Float
divF a b = (fromIntegral a) / (fromIntegral b)

expectedGain :: Int -> Int -> Float
expectedGain n maxGain = flip divF n $ sum $ gains n maxGain
```

The `divF` function is floating point division for integers (haskell gimmick). The `expectedGain` function calculates mean of all payoffs, and then divides them by the range of numbers (100 in this case). This is mathematically equal to

$$ E(X) = \sum_{i = 1}^n x_i * P(x_i) $$

Calculating the expected value we get:

```haskell
*Main Data.List> expectedGain 100 4
-0.8
```

# Conclusion

Given all this proof, we can safely say that we don't want to play this game at all, provided that then numbers are chosen randomly with each number having a $ \frac{1}{n} $ probability of getting chosen.

Of course, if this was a trick question where the numbers aren't chosen with constant probability but with Ballmer's malicious intent in mind, then our answer should be a straight no 😛