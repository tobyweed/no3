@*Intro. I'm searching for permutations that have a special form, from which
I think I can construct solutions to a problem suggested indirectly by
Martin Gardner in 1978 (namely to place $n+1$ queens on an $n\times n$
board in such a way that no three queens are on a line, but the addition
of a queen in any other cell would break this condition). In the special
case considered here, $n$ is the odd number $2m-1$, and I impose lots
of other conditions that aren't necessary but may well be sufficient.

The actual problem I'm solving is to find permutations $p_1p_2\ldots p_m$
of the odd numbers $\{1,3,\ldots,2m-1\}$ with the following properties:
(i)~the $m+1$ sums
 $\{2p_1,p_1+p_2,p_2+p_3,\ldots,p_{m-1}+p_m,2p_m\}$ are distinct;
(ii)~the $m-1$ differences
 $\{\vert p_1-p_2\vert, \vert p_2-p_3\vert, \ldots, \vert p_{m-1}-p_m\vert\}$
don't include anything more than twice;
(iii)~moreover, the sums and differences satisfy a technical condition
that leads to a queen solution.

For example, solutions when $m=4$ and $m=5$ are 3175 and 13759. In the
first case the sums are 6, 4, 8, 12, 10 and the differences are 2, 6, 2;
in the second case the sums are 2, 4, 10, 12, 14, 18, and the differences
are 2, 4, 2, 4.

I suspect that the problem has many solutions. Before writing this
program, I'd seen numerous solutions as special cases of the output
of {\mc SAT-NOTHREE-ALLODD-SYMM}. However, I was unable to find any
pattern in those solutions that was obviously generalizable to infinitely
many values of $m$.

The left-right reflection of any solution is also a solution. So is the
permutation $(2m-p_1)\ldots(2m-p_m)$. Therefore
we can assume without loss of generality that $p_1\le m$,
$p_1\le p_m$, and $p_1+p_m\le2m$.

Apology: I wrote this program in a huge hurry and there was no time to
apply spit and polish. I began with a more or less generic implementation
of Algorithm 7.2.1.2X.

@d mmax 1000
@d verbose 1

@c
#include <stdio.h>
#include <stdlib.h>
int m; /* command-line parameter */
int a[mmax],l[mmax],u[mmax],sum[2*mmax],diff[mmax];
int sols, partsols;
int c2,c3,c4,c5,c6; /* step counters */
main (int argc, char*argv[]) {
  register int i,j,k,p,q,s,d;
  @<Process the command line@>;
  @<Do the algorithm@>;
  @<Check that the data structures are sane@>;
  printf("Altogether %d solutions (of %d)",
                           sols,partsols);
  printf(" (X2=%d,X3=%d,X4=%d,X5=%d,X6=%d.)\n",
              c2,c3,c4,c5,c6);
}

@ @<Process the command line@>=
if (argc!=2 || sscanf(argv[1],"%d",
                             &m)!=1) {
  fprintf(stderr,"Usage: %s m\n",
                             argv[0]);
  exit(-1);
}
if (m>=mmax) {
  fprintf(stderr,"Sorry, m must be less than %d!\n",
                                mmax);
  exit(-2);
}

@ @<Do the algorithm@>=
x1:@+ for (k=0;k<m;k++) l[k]=k+1;
 l[m]=0;
 k=1;
x2: c2++,p=0;
 q=l[0];
x3: c3++,a[k]=q;
 @<Test $a_1\ldots a_k$ and |goto x5| if no good@>;
 if (k==m)
   @<Print solution and |goto x6|@>;
x4: c4++,u[k]=p;
 l[p]=l[q];
 k++;
 goto x2;
x5: c5++,p=q;
 q=l[p];
 if (q) goto x3;
x6: c6++,k--;
 if (k) {
   p=u[k];
   q=a[k];
   @<Undo the move to |a[k]=q|@>;
   l[p]=q;
   goto x5;
 }

@ In the following steps I use the fact that |q=a[k]|.

@<Test $a_1\ldots a_k$ and |goto x5| if no good@>=
if (k==1) {
  if (2*q-1>m) goto x5;
  sum[2*q]=1;
}@+else {
  if (k==m && (q<=a[1] || a[1]+q>2*m || sum[2*q])) goto x5;
  s=a[k-1]+q, d=a[k-1]-q;
  if (d<0) d=-d;
  if (sum[s] || diff[d]==2) goto x5;
  sum[s]=1, diff[d]++;
}

@ @<Undo the move to |a[k]=q|@>=
if (k==1) sum[2*q]=0;
else {
  s=a[k-1]+q, d=a[k-1]-q;
  if (d<0) d=-d;
  sum[s]=0, diff[d]--;
}

@ We still have to check the ``technical condition'' (iii).

@<Print solution and |goto x6|@>=
{
  partsols++;
  @<If we don't have a queens solution, |goto nosol|@>;
  sols++;
  if (verbose) {
    printf("%d:",
                      sols);
    for (p=1;p<=m;p++) printf(" %d",
                             2*a[p]-1);
    printf("\n");
  }
nosol:@+ @<Undo the move to |a[k]=q|@>;
  goto x6;
}

@ Call the upper left corner white.
When there are two queens on white squares in every odd-numbered row and every
odd-numbered column, we have a queens solution if and only if every black square
that is in an even-numbered row and an even-numbered column lies on a diagonal
occupied by two queens.

The |sum| data tells us which of the southwest-to-northeast diagonals are
covered; the |diff| data tells us about the northwest-to-southeast diagonals.
For example, |diff[0]| corresponds to the main diagonal, and |diff[1]| to
the diagonals just above and below it. The antidiagonal corresponds to
|sum[m+1]|, and its neighbors correspond to |sum[m]| and |sum[m+2]|.
Although |sum[2*a[1]]=1| at this point, we must treat it as zero,
because the corresponding diagonal doesn't actually contain two queens.

@<If we don't have a queens solution, |goto nosol|@>=
for (i=1;i<m;i++) for (j=i+1;j<m;j++)
  if (diff[j-i]<2 && (sum[i+j+1]==0 || i+j+1==2*a[1])) goto nosol;

@ If the algorithm hasn't properly undone its updates,
this test ought to detect the problem.

@<Check that the data structures are sane@>=
for (s=1;s<=2*m;s++) if (sum[s])
  fprintf(stderr," sum %d isn't zero!\n",
                                 s);
for (d=1;d<m;d++) if (diff[d])
  fprintf(stderr," diff %d isn't zero!\n",
                                 d);

@*Index.
