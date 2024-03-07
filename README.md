# BeeProjects_Push_Swap
<h3>Hive 42 Push Swap</h3>

<p>
This project looks to take in a list of numbers and sort them in order from the smallest to the largest by using a list of commands and two stacks (a and b). My program is designed to take in the arguments either in "" or just after the program name. My program then process the arguments with either ft_split or just straight to argument checkers. It checks for non numeric input, duplicate numbers, symbols, empty, space int max/int min, and if its one '-' or '+'. </p>
  example:
  <p>./push_swap "21 4 67 345 -31"</p>
  <p>or</p>
  <p>./push_swap 21 4 67 345 -31 </p>
It wouldn't take in arguments like [1 56 "7 4 5" 1]
<p>My program uses the Turkish Algorithm to solve the list. For stack that has more than 3 nodes, it will push the nodes from a to b until it has only three nodes left in a. For stack with more nodes than five, it will push the first two nodes from a to b, then after that we will look at each node in stack a and search for it's target node in stack b and calculate it's push cost. When it's going from stack a to b, the target node is the node's closest smaller number. 
  For example, stack a: 3 7 11 9 25 | stack b: 2 4 5 
In this case, the target node for 3 is 2 but if no target node can be found, then we look for the biggest number as the target node. It then moves the target node and the node with the smallest cost to the top then we push the node over. Affter we push all the nodes from a to b until there are three nodes left. It then sorts the three nodes then push from stack b back to a. It now searches the targe node in stack a from b. The target node is now the closest bigger number and if no target node can be found, then it will be the smallest number on the stack. We do the same by moving the target node and node with the cheapest cost to the top and push it over. After stack b is completely empty, we check if the smallest is on the top, if its not, then we move it with either reverse rotate or rotate. </p>
<p>I have included my own tester, which is inspired by the GEMARTIN push_swap tester but I modified it to work with checker_Mac and much shorter. You can update it by putting your own invalid arguments and change how many times it runs 100 inputs or 500 inputs by changing the val=. For memory leaks, you can change the value in while [ $cont2 -lt 175] and on the bottom ((cont2 += 12)), by changing the cont2 incrementer, you are changing the amount of the arguments being run and when it is bigger than 175, 
 the the tester stops.</p>
