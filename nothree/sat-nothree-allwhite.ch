@x
  @<Generate clauses to ensure at most $r$ queens@>;
@y
  @<Generate clauses to ensure at most $r$ queens@>;
  @<Generate clauses to force all black cells zero@>;
@z
@x
printf("~ sat-nothree %d %d %d\n",m,n,r);
@y
printf("~ sat-nothree-allwhite %d %d %d\n",m,n,r);
@z
@x
@*Index.
@y
@ @<Generate clauses to force all black cells zero@>=
for (i=1;i<=m;i++) for (j=1;j<=n;j++) if ((i+j)&1)
  printf("~%d.%d\n",
                    i,j);

@*Index.
@z
