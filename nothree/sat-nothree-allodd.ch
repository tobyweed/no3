@x
  @<Generate clauses to ensure at most $r$ queens@>;
@y
  @<Generate clauses to ensure at most $r$ queens@>;
  @<Generate clauses to force all non-odd cells zero@>;
@z
@x
printf("~ sat-nothree %d %d %d\n",m,n,r);
@y
printf("~ sat-nothree-allodd %d %d %d\n",m,n,r);
@z
@x
@*Index.
@y
@ @<Generate clauses to force all non-odd cells zero@>=
for (i=1;i<=m;i++) for (j=1;j<=n;j++) if ((i&1)==0 || (j&1)==0)
  printf("~%d.%d\n",
                    i,j);

@*Index.
@z
