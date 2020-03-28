//Diffie Hellman Key exchange algorithm

#include<stdio.h>
#include<math.h>
int main()
{
 int q,p,x,a,y,b,S1,S2,m,n;
 // both the persons will be agreed upon the common p(prime no.) and q(premitive root)
 printf("Enter the value of p and q : ");
 scanf("%d%d",&p,&q);
 
 // first person's private data
 printf("Enter the value of x for the first person : ");
 scanf("%d",&x);
 m=pow(q,x);
 a= m%p;
 
 // second person's private data
 printf("Enter the value of y for the second person : ");
 scanf("%d",&y);
 n=pow(q,y);
 b= n%p;

 // Calculating key for sender
 m=pow(b,x);
 S1=m%p;
 // Calculating key for reciever
 n=pow(a,y);
 S2=n%p;
 printf("key for the first person is : %lld\n",S1);
 printf("key for the second person is : %lld\n",S2);
 // both of the keys will same : it means this algo is a symmetric key algo.
 return 0;
}
