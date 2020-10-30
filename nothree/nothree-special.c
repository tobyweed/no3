#define mmax 1000
#define verbose 1 \

/*1:*/
#line 42 "nothree-special.w"

#include <stdio.h> 
#include <stdlib.h> 
int m;
int a[mmax],l[mmax],u[mmax],sum[2*mmax],diff[mmax];
int sols,partsols;
int c2,c3,c4,c5,c6;
main(int argc,char*argv[]){
register int i,j,k,p,q,s,d;
/*2:*/
#line 60 "nothree-special.w"

if(argc!=2||sscanf(argv[1],"%d",
&m)!=1){
fprintf(stderr,"Usage: %s m\n",
argv[0]);
exit(-1);
}
if(m>=mmax){
fprintf(stderr,"Sorry, m must be less than %d!\n",
mmax);
exit(-2);
}

/*:2*/
#line 51 "nothree-special.w"
;
/*3:*/
#line 73 "nothree-special.w"

x1:for(k= 0;k<m;k++)l[k]= k+1;
l[m]= 0;
k= 1;
x2:c2++,p= 0;
q= l[0];
x3:c3++,a[k]= q;
/*4:*/
#line 101 "nothree-special.w"

if(k==1){
if(2*q-1> m)goto x5;
sum[2*q]= 1;
}else{
if(k==m&&(q<=a[1]||a[1]+q> 2*m||sum[2*q]))goto x5;
s= a[k-1]+q,d= a[k-1]-q;
if(d<0)d= -d;
if(sum[s]||diff[d]==2)goto x5;
sum[s]= 1,diff[d]++;
}

/*:4*/
#line 80 "nothree-special.w"
;
if(k==m)
/*6:*/
#line 123 "nothree-special.w"

{
partsols++;
/*7:*/
#line 153 "nothree-special.w"

for(i= 1;i<m;i++)for(j= i+1;j<m;j++)
if(diff[j-i]<2&&(sum[i+j+1]==0||i+j+1==2*a[1]))goto nosol;

/*:7*/
#line 126 "nothree-special.w"
;
sols++;
if(verbose){
printf("%d:",
sols);
for(p= 1;p<=m;p++)printf(" %d",
2*a[p]-1);
printf("\n");
}
nosol:/*5:*/
#line 113 "nothree-special.w"

if(k==1)sum[2*q]= 0;
else{
s= a[k-1]+q,d= a[k-1]-q;
if(d<0)d= -d;
sum[s]= 0,diff[d]--;
}

/*:5*/
#line 135 "nothree-special.w"
;
goto x6;
}

/*:6*/
#line 82 "nothree-special.w"
;
x4:c4++,u[k]= p;
l[p]= l[q];
k++;
goto x2;
x5:c5++,p= q;
q= l[p];
if(q)goto x3;
x6:c6++,k--;
if(k){
p= u[k];
q= a[k];
/*5:*/
#line 113 "nothree-special.w"

if(k==1)sum[2*q]= 0;
else{
s= a[k-1]+q,d= a[k-1]-q;
if(d<0)d= -d;
sum[s]= 0,diff[d]--;
}

/*:5*/
#line 94 "nothree-special.w"
;
l[p]= q;
goto x5;
}

/*:3*/
#line 52 "nothree-special.w"
;
/*8:*/
#line 160 "nothree-special.w"

for(s= 1;s<=2*m;s++)if(sum[s])
fprintf(stderr," sum %d isn't zero!\n",
s);
for(d= 1;d<m;d++)if(diff[d])
fprintf(stderr," diff %d isn't zero!\n",
d);

/*:8*/
#line 53 "nothree-special.w"
;
printf("Altogether %d solutions (of %d)",
sols,partsols);
printf(" (X2=%d,X3=%d,X4=%d,X5=%d,X6=%d.)\n",
c2,c3,c4,c5,c6);
}

/*:1*/
