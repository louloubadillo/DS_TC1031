# 2. Getting Started 
## 2.1 Insertion Sort
Insertion sort is an algorithm that solves a sorting problem. 

- Input: A sequence of n numbers $\left(a_{1},\ a_{2},\ ...,\ a_{n}\right)$
- Output: A permutation (reordering) $\left(a'_{1},\ a'_{2},\ ...,\ a'_{n}\right)$ of the input sequence such that $a'_{1}\le a'_{2}\le...\le a'_{n}$
  
<br>

The numbers we wish to sort are known as <b>keys</b>. <br><br>
<b>Insertion sort</b> is  an efficient algorithm for sorting a small number of elements. Insertion sort works the way many people sort a hand of playing cards. We start with an empty left hand and the cards face down on the table. We then remove one card at a time from the table and insert it into the correct position in the left hand. To find the correct position for a card, we compare it with each of the cards already in the hand, from right to left.

## 2.2 Analyzing Algorithms
Analyzing an algorithm has come to mean predicting the resources that the algorithm requires. Occasionally, resources such as memory, communication bandwidth, or computer hardware are of primary concern, but most often it is computational time that we want to measure. <br> <br>
Before we can analyze an algorithm, we must have a model of the implementation technology that we will use. In the RAM model, instructions are executed one after another, with no concurrent operations. <br> <br>
### Analysis of insertion sort
The time taken by the insertion sort procedure depends on the input: sorting a thousand numbers takes longer than sorting three numbers. Moreover, insertion sort can take different amounts of time to sort two input sequences of the same size depending on how nearly sorted they already are. In general, the time taken by an algorithm grows with the size of the input, so it is traditional to describe the running time of a program as a function of the size of its input.

### Terminology
- <b>Input size </b> depends on the problem being studied. In some cases, it's the number of items in the input, in other problems, it is the total number of bits needed to represent the input in binary notation. 
- The <b>running time </b> of an algorithm on a particular input is the number of primitive operations or “steps” executed.
