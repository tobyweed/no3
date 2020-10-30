#define max_m_plus_n 100
#define max_mn 10000 \

#define xbar(k) printf("~%d.%d", \
(((k) -mn+1) /n) +1,(((k) -mn+1) % \
n) +1)  \

/*1:*/
#line 33 "sat-nothree.w"

#include <stdio.h> 
#include <stdlib.h> 
int m,n,r;
char name[max_m_plus_n][8];
int ap[max_m_plus_n],dp[max_m_plus_n];
int count[2*max_mn];
/*4:*/
#line 94 "sat-nothree.w"

void forbid(int i,char t,int n){
register j;
for(j= 1;j<n;j++){
if(j<n-1){
printf("~%d%c%d %d%c%d\n",
i,t,j,i,t,j+1);
printf("~%d%c%d' %d%c%d'\n",
i,t,j,i,t,j+1);
printf("~%s ~%d%c%d'\n",
name[j+1],i,t,j);
}
printf("~%s %d%c%d\n",
name[j-1],i,t,j);
printf("~%d%c%d %s",
i,t,j,name[j-1]);
if(j> 1)printf(" %d%c%d\n",
i,t,j-1);
else printf("\n");
printf("~%s ~%d%c%d %d%c%d'\n",
name[j],i,t,j,i,t,j);
printf("~%d%c%d' %d%c%d\n",
i,t,j,i,t,j);
printf("~%d%c%d' %s",
i,t,j,name[j]);
if(j> 1)printf(" %d%c%d'\n",
i,t,j-1);
else printf("\n");
}
}

/*:4*/
#line 40 "sat-nothree.w"
;
main(int argc,char*argv[]){
register int i,j,k,mn,p,t,tl,tr,jl,jr;
/*2:*/
#line 52 "sat-nothree.w"

if(argc!=4||sscanf(argv[1],"%d",
&m)!=1||
sscanf(argv[2],"%d",
&n)!=1||
sscanf(argv[3],"%d",
&r)!=1){
fprintf(stderr,"Usage: %s m n r\n",argv[0]);
exit(-1);
}
if(m==1||n==1){
fprintf(stderr,"m and n must be 2 or more!\n");
exit(-2);
}
if(m+n>=max_m_plus_n){
fprintf(stderr,"m+n must be less than %d!\n",
max_m_plus_n);
exit(-3);
}
mn= m*n;
if(mn>=max_mn){
fprintf(stderr,"m*n must be less than %d!\n",
max_mn);
exit(-3);
}
#line 11 "sat-nothree-allodd-symm.ch"
printf("~ sat-nothree-allodd-symm %d %d %d\n",m,n,r);
#line 78 "sat-nothree.w"

/*:2*/
#line 43 "sat-nothree.w"
;
for(i= 1;i<=m;i++)/*3:*/
#line 86 "sat-nothree.w"

{
for(j= 1;j<=n;j++)
sprintf(name[j-1],"%d.%d",
i,j);
forbid(i,'R',n);
}

/*:3*/
#line 44 "sat-nothree.w"
;
for(j= 1;j<=n;j++)/*5:*/
#line 125 "sat-nothree.w"

{
for(i= 1;i<=m;i++)
sprintf(name[i-1],"%d.%d",
i,j);
forbid(j,'C',m);
}

/*:5*/
#line 45 "sat-nothree.w"
;
for(k= 1;k<m+n;k++)/*6:*/
#line 133 "sat-nothree.w"

{
p= 0;
for(i= 1;i<=m;i++){
j= k+1-i;
if(j>=1&&j<=n){
sprintf(name[p],"%d.%d",
i,j);
p++;
}
}
forbid(k,'A',p);
ap[k]= p;
}

/*:6*/
#line 46 "sat-nothree.w"
;
for(k= 1;k<m+n;k++)/*7:*/
#line 148 "sat-nothree.w"

{
p= 0;
for(i= 1;i<=m;i++){
j= i+n-k;
if(j>=1&&j<=n){
sprintf(name[p],"%d.%d",
i,j);
p++;
}
}
forbid(k,'D',p);
dp[k]= p;
}

/*:7*/
#line 47 "sat-nothree.w"
;
/*8:*/
#line 163 "sat-nothree.w"

for(i= 1;i<=m;i++)for(j= 1;j<=n;j++){
printf("%d.%d %dR%d' %dC%d'",
i,j,i,n-1,j,m-1);
if(ap[i+j-1]> 1)
printf(" %dA%d'",
i+j-1,ap[i+j-1]-1);
if(dp[i-j+n]> 1)
printf(" %dD%d'",
i-j+n,ap[i-j+n]-1);
printf("\n");
}

/*:8*/
#line 48 "sat-nothree.w"
;
#line 4 "sat-nothree-allodd-symm.ch"
/*9:*/
#line 178 "sat-nothree.w"

/*10:*/
#line 187 "sat-nothree.w"

for(k= mn+mn-2;k>=mn-1;k--)count[k]= 1;
for(;k>=0;k--)
count[k]= count[k+k+1]+count[k+k+2];
if(count[0]!=mn)
fprintf(stderr,"I'm totally confused.\n");

/*:10*/
#line 179 "sat-nothree.w"
;
for(i= mn-2;i;i--)/*11:*/
#line 203 "sat-nothree.w"

{
t= count[i],tl= count[i+i+1],tr= count[i+i+2];
if(t> r+1)t= r+1;
if(tl> r)tl= r;
if(tr> r)tr= r;
for(jl= 0;jl<=tl;jl++)for(jr= 0;jr<=tr;jr++)
if((jl+jr<=t)&&(jl+jr)> 0){
if(jl){
if(i+i+1>=mn-1)xbar(i+i+1);
else printf("~B%d.%d",i+i+2,jl);
}
if(jr){
printf(" ");
if(i+i+2>=mn-1)xbar(i+i+2);
else printf("~B%d.%d",i+i+3,jr);
}
if(jl+jr<=r)printf(" B%d.%d\n",i+1,jl+jr);
else printf("\n");
}
}

/*:11*/
#line 180 "sat-nothree.w"
;
/*12:*/
#line 228 "sat-nothree.w"

tl= count[1],tr= count[2];
if(tl> r)tl= r;
for(jl= 1;jl<=tl;jl++){
jr= r+1-jl;
if(jr<=tr){
if(1>=mn-1)xbar(1);
else printf("~B2.%d",jl);
printf(" ");
if(2>=mn-1)xbar(2);
else printf("~B3.%d",jr);
printf("\n");
}
}

#line 16 "sat-nothree-allodd-symm.ch"
/*:12*/
#line 181 "sat-nothree.w"
;

/*:9*/
#line 4 "sat-nothree-allodd-symm.ch"
;
/*13:*/
#line 16 "sat-nothree-allodd-symm.ch"

for(i= 1;i<=m;i++)for(j= 1;j<=n;j++)if((i&1)==0||(j&1)==0)
printf("~%d.%d\n",
i,j);

/*:13*/
#line 5 "sat-nothree-allodd-symm.ch"
;
/*14:*/
#line 21 "sat-nothree-allodd-symm.ch"

for(i= 1;i<=m;i+= 2)for(j= 1;j<=n;j+= 2)if(i!=j)
printf("~%d.%d %d.%d\n",
i,j,j,i)

/*:14*/
#line 6 "sat-nothree-allodd-symm.ch"
;
#line 50 "sat-nothree.w"
}

/*:1*/
