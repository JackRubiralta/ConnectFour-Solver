## Time Log
### Specs
Depth: 15<br/>
Benchmark: Slow Computer<br/>
CPU: Intel(R) Core(TM) i5-7200U CPU @ 2.50Ghz<br/>
GPU: Intel(R) HD Graphics 620<br/>
RAM: 8GB SODIMM @ 2133MHz<br/>

### Connect Four bitboard based class
Created a connect four class making use of bitboards and bitwise operations which are very fast, with unit tests to make development easier which would check for a expected result.<br/>
Date: March 18 to 22

### Negamax with alpha beta pruning
Created a negamax function using alpha beta pruning and implementing a heuristic move ordering function.<br/>
Time: 14949 ms<br/>
Date: March 23<br/>

### Move sorting from middle out
Added heuristic move ordering from middle out because the middle is the best as it creates more possibilities, this inturn helps with alpha beta pruning<br/>
Time: 4521 ms<br/>
Date: March 23 to 24<br/>


### Anticipating loosing moves
Made the algorithm anticipate and avoid exploring very bad moves which allow the opponent to win directly at the next turn. This way we can reduce the amount of nodes explored.<br/>
Time: 527 ms<br/>
Date: March 24<br/>

### added -Ofast flag
Added -Ofast flag when compiling which optimizes code during compiling.<br/>
Time: 91 ms<br/>
Date: March 25<br/>
