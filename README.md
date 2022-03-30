# no3
SAT solvers and scripts to find solutions to [Martin Gardner's minimum no-3-in-a-line problem](https://arxiv.org/abs/1206.5350). 

Using this software we were able to find good placements of `n+1` queens on only odd rows and columns for odd `n` up to `n = 41`. Previously there were only upper bounds established for up to `n=18`.

Additionally, we found exhaustive lists of good placements of up to `n+1` queens for odd `n` up to 19. These findings are summarized in the following table:

Board Size (n)   | 5 | 7 | 9 | 11 | 13 | 15 | 17 | 19 |  
-----------------+---+---+---+----+----+----+----+-----   
\# of Placements | 1 | 2 | 2 | 6  | 15 | 23 | 44 | 65 |

The number of placements are up to listed symmetry; e.g. placements which differed only by a reflection or a rotation were not counted multiple times.

Based on these results, we suggest an upper bound of `n+1` for odd `n`. With [Cooper, Pikhurko, Schmitt, and Warrington's result](https://arxiv.org/abs/1206.5350), this would confine the problem solution to `{n,n+1}` except when `n` is congruent to 3 modulo 4, where one less may suffice.
