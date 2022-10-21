1. findContestant <k>
Find the element with id = <k> in O(1) running time.
The output should be one of the following, as appropriate:
a. “Contestant <k> is in the extended heap with score <s>.”
b. “Contestant <k> is not in the extended heap.”

2. insertContestant <k> <s>
Insert a new contestant with id = <k> and score = <s> into the extended heap.
The output should be one of the following, as appropriate:
a. “Contestant <k> inserted with initial score <s>.”
b. “Contestant <k> could not be inserted because the extended heap is full.”
c. “Contestant <k> is already in the extended heap: cannot insert.”

3. eliminateWeakest
Remove the contestant with the lowest current score.
The output for this operation should be one of the following:
a. “Contestant <k> with current lowest score <s> eliminated.”
b. “No contestant can be eliminated since the extended heap is empty.”

4. earnPoints <k> <p>
Add <p> points to the contestant with id = <k>.
The output should be one of the following:
a. “Contestant <k>’s score increased by <p> points to <s>.”
b. “Contestant <k> is not in the extended heap.”

5. losePoints <k> <p>
Take away <p> points from the contestant with id = <k>.
The output should be one of the following:
a. “Contestant <k>’s score decreased by <p> points to <s>.”
b. “Contestant <k> is not in the extended heap.”

6. showContestants
Print the contents of the extended heap.
The output should be a sequential list of the contestants currently in the extended heap. For each contestant, print
in a single line:
“Contestant <k> in extended heap location <i> with score <s>.”

7. showHandles
Print the contents of the handle array in order, one value per line, formatted as follows:
“Contestant <k> stored in extended heap location <j>.”
Your program should produce n lines of output. If there is no Contestant <k>, you should print
“There is no Contestant <k> in the extended heap: handle[<k>] = -1.”

8. showLocation <k>
Show the location of the contestant with id <k> in the heap, as follows:
“Contestant <k> stored in extended heap location <j>.”
If there is no Contestant <k>, you should print:
“There is no Contestant <k> in the extended heap: handle[<k>] = -1.”

9. crownWinner
Remove all contestants from the extended heap, in order, until only one remains. Then print:
“Contestant <k> wins with score <s>!”
