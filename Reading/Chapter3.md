# 3. Growth of Functions
When we look at input sizes large enough to make only the order of growth of the running time relevant, we are studying the asymptotic efficiency of algorithms.<br>
That is, we are concerned with how the running time of an algorithm increases with the size of the input in the limit, as the size of the input increases without bound. Usually, an algorithm that is asymptotically more efficient will be the best choice
for all but very small inputs. <br>
### Overview 
- The order of growth of functions provides a simple characterization of efficiency. 
- It allows for comparison of relative performance between alternative algorithms. 
- The best asymptotic efficiency usually is the best choice, except for smaller inputs. 
- There are several standard methods to simplify asymptotic analysis of algorithms. 


## 3.1 Asymptotic Notation
- Applies to functions whose domains are the set of natural numbers. 
- If time resource $T(n)$ is being analyzed, the function's range is usually the set of non-negative real numbers. 
- If space resource $S(n)$ is being analyzed, the function's range is usually the set of natural numbers. 
- Asymptotic categories may be expressed in terms of: 
  - set membership: functions belong to a family of functions that exhibit some property
  - function property 

### Asymptotic notation, functions, and running times
We will use asymptotic notation primarily to describe the running times of algorithms. <br>
Even when we use asymptotic notation to apply to the running time of an algorithm, we need to understand which running time we mean. Sometimes we are interested in the worst-case running time. 
