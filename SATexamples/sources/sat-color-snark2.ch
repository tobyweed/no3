@x
int c;
@y
int c;
int n; /* order of flower snark line graph (a command-line parameter) */
char buf[20];
@z
@x
@ @<Process the command line@>=
if (argc!=3 || sscanf(argv[2],"%d",&c)!=1) {
  fprintf(stderr,"Usage: %s foo.gb c\n",argv[0]);
  exit(-1);
}
g=restore_graph(argv[1]);
if (!g) {
  fprintf(stderr,"I couldn't reconstruct graph %s!\n",argv[1]);
  exit(-2);
}
if (c<=0) {
  fprintf(stderr,"c must be positive!\n");
  exit(-3);
}
printf("~ sat-color %s %d\n",argv[1],c);
@y
@ @<Process the command line@>=
if (argc!=2 || sscanf(argv[1],"%d",&n)!=1) {
  fprintf(stderr,"Usage: %s n\n",argv[0]);
  exit(-1);
}
sprintf(buf,"fsnarkline%d.gb",n);
g=restore_graph(buf);
if (!g) {
  fprintf(stderr,"I couldn't reconstruct graph %s!\n",buf);
  exit(-2);
}
c=3;
printf("~ sat-color-snark2 %d\n",n);
printf("b1.1\n"); /* start with three unary clauses to break symmetry */
printf("c1.2\n");
printf("d1.3\n");
@z
@x
@*Index.
@y
@ In this variant we also generate negative clauses to ensure that
no vertex gets more than one color. We use the fact that |c=3|.

@<Generate the negative clauses@>=
for (v=g->vertices;v<g->vertices+g->n;v++) {
  printf("~%s.1 ~%s.2\n",v->name,v->name);
  printf("~%s.2 ~%s.3\n",v->name,v->name);
  printf("~%s.3 ~%s.1\n",v->name,v->name);
}

@*Index.
@z
