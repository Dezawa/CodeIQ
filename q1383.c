#include <stdio.h>
#define FMAX  114
#define MTHMAX  31
#define PRIMEMAX 120815L
#define PRIMESIZE 14000
long long f[FMAX]={3,0,2,3 };
int       mth_n_of_fn[MTHMAX] = { 2,2,3};
long      prime[PRIMESIZE] = {27,
                              2,  3,   5,  7, 11, 13, 17,  19,  23,
                              29, 31, 37, 41, 43, 47, 53,  59,  61,
                              67, 71, 73, 79, 83, 89, 97, 101, 103};
long      pprime[PRIMESIZE] = {27,
                               4, 9, 25, 49, 121, 169, 289, 361, 529,
                               841, 961, 1369, 1681, 1849, 2209, 2809,
                               3481, 3721, 4489, 5041, 5329, 6241, 6889,
                               7921, 9409, 10201, 10609};

long long fnc_f(int n){
  int i ;
  if ( f[n] > 0 ) return f[n] ;
  for(i=f[0]+1;i<FMAX;i++) f[i] = f[i-2] + f[i-3];
  return f[n];
}

int mth_n_of_fn_is_multiple_of_n(int m){
  int mm , n;
  if(mth_n_of_fn[m]) return mth_n_of_fn[m];
  mm =  mth_n_of_fn[0];
  n  =  mth_n_of_fn[mm];
  while(mm < m) if( (fnc_f(++n)%n) == 0 )  mth_n_of_fn[++mm] = n;
  mth_n_of_fn[0] = mm ;
  return mth_n_of_fn[mm];
}

/* 全ての自然数に対応しているわけではない
   210i±何某 に対してのチェック.  あらかじめ 2～103の素数のtebleができていること。
   for make_prime
*/
int is_prime(long p){
  int i ;
  for(i=5;p >= pprime[i] ;i++)  if((p%prime[i]) == 0) return 0;
  return 1;
}
/* 6i±1 から 30i±何某 にしたときははっきり早くなったのですが(20%減だもの）
   210±何某 では早くなってるはずですが、CPUの忙しさのばらつきに埋もれて
   しまう程度でした。
*/
void make_prime(){
  long  p;
  int i,j;
  i=prime[0];
  for(j= ((prime[i] +103)/210 ); ++j<576 ;){
    p=j*210-103;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210-101;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 97;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 89;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 83;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 79;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 73;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 71;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 67;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 61;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 59;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 53;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 47;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 43;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 41;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 37;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 31;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 29;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 23;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 19;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 17;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 13;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210- 11;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210-  1;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+  1;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 11;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 13;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 17;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 19;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 23;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 29;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 31;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 37;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 41;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 43;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 47;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 53;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 59;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 61;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 67;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 71;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 73;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 79;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 83;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 89;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+ 97;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+101;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }
    p=j*210+103;if(is_prime(p)){ prime[++i] = p; pprime[i] =  p * p ; }

    prime[0] = i;
  }
}
int largest_prime_division(long long n){
  int i = 0;
  while(++i){
    while((n%prime[i])==0)     n /= prime[i] ;
    if(n <= prime[i]) return (int)prime[i];
  }
}

int sum_of_prime_of_prime(int q){
  int sum = 0;
  int n ;
  long p;
  for(n=1;(p=prime[prime[n]])<= q;n++)  sum += p ;
  return sum;
} 

int test();
int main(int argc,char**argv){
  make_prime();
  if( argc>1)  test();
  
  else {
    long long p = fnc_f(mth_n_of_fn_is_multiple_of_n(30)) ;
    printf("P = %qd\n",p);
    int q = largest_prime_division(p);
    printf("Q = %d\n",q);
    printf("R = %d\n",sum_of_prime_of_prime(q));
  }
  return 1;
}

/* CでのTDDの経験は皆無（というか、Cでこんなに長いのを書いたのは10年以上ぶり)
   なので、test はやっつけ
*/
int test8(){
  printf("H(1000)=15489 ? actual %d ",sum_of_prime_of_prime(1000));
  return sum_of_prime_of_prime(1000)==15489;
}
int test7(){
  printf("H(100)=317 ? actual %d ",sum_of_prime_of_prime(100));
  return sum_of_prime_of_prime(100)==317;
}
int test6(){
  printf("H(5)=8 ? actual %d ",sum_of_prime_of_prime(5));
  return sum_of_prime_of_prime(5)==8;
}

int test1(){
  int i;
  long long fff[9] = {3,0,2,3,2,5,5,7,10};
  printf("フィボナッチもどき 9つ合っているか");
  fnc_f(10);
  for(i=0;i<=8;i++ )
    if( fff[i] != f[i]){
      printf("%d %qd %qd\n",i,f[i],fff[i]);
      return 0 ;
    }
  return 1 ;
}

int test2(){
  int i;
  int mth_n[9] = {8,2,3,5,7,11,13,17,19};
  printf("フィボナッチもどき,割りきれるのは 合っているか");
  /*  for(i=0;i<=8;i++ )printf("%qd ",fff[i]); */
  mth_n_of_fn_is_multiple_of_n(8);
  for(i=0;i<=8;i++ )
  if( mth_n[i] != mth_n_of_fn[i]){
    printf("%d %d %d\n",i,mth_n[i],mth_n_of_fn[i]);
  return 0 ;
  }
  return 1 ;
}

char *true_false[] = { "false" ,"true"};
int test3(){
  int i;  /*      1 2 3 4  5  6  7  8  9 10 11 12 13 14 15 16 17 18*/
  int prm[] = {18,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
  printf("7th prime is 17 ? %s\n", true_false[prime[7] == 17 ]);
  printf("is prime 15 is 0 ? %s\n",true_false[ is_prime(15)==0]);
  printf("is prime 17 is 1 ? %s\n",true_false[ is_prime(17)==1]);
  printf("is prime 25 is 0 ? %s\n",true_false[ is_prime(25)==0]);
  printf("9th prime is 23?  %s\n" ,true_false[ prime[9]==23]);
  printf("10th prime is 29? %s\n",true_false[ prime[10]==29]);
  printf("11th prime is 31? %s\n",true_false[ prime[11]==31]);
  printf("15th prime is 47? %s\n",true_false[ prime[15]==47]);
  printf("28th prime is 107? %s\n",true_false[ prime[28]==107]);

  printf("18番目までの素数は ");
  for(i=1;i<=18;i++ ){
    if( prm[i] != prime[i]){
      printf("%d %d %ld\n",i,prm[i],prime[i]);
      return 0 ;
    }
  }
    return 1 ;
}
int test4(){
  printf("24の素因数分解最大因数は ");
  return 3 == largest_prime_division((long long)24);
}

int test5(){
  printf("123456の素因数分解最大因数は ");
  return 643 == largest_prime_division((long long)123456);
}
int test(){
  int i;
  puts( test1() ? "true" : "false");
  puts( test2() ? "true" : "false");
  puts( test3() ? "true" : "false");
  puts( test4() ? "true" : "false");
  puts( test5() ? "true" : "false");
  puts( test6() ? "true" : "false");
  puts( test7() ? "true" : "false");
  puts( test8() ? "true" : "false");
  return 1;
}
/*
by30
gcc -O2 -lm -Wall -o q1383 q1383.c
real	0m0.109s
user	0m0.052s
sys	0m0.004s

real	0m3.631s
user	0m1.936s
sys	0m0.184s

gcc  -lm  -o q1383 q1383.c 
real	0m0.126s
user	0m0.076s
sys	0m0.008s

real	0m1.315s
user	0m0.856s
sys	0m0.180s
a624c00...

by210
gcc -O2 -lm -Wall -o q1383 q1383.c
real	0m0.124s
user	0m0.044s
sys	0m0.000s

real	0m3.689s
user	0m2.648s
sys	0m0.176s

gcc  -lm  -o q1383 q1383.c 
real	0m0.080s
user	0m0.080s
sys	0m0.004s

real	0m1.732s
user	0m1.076s
sys	0m0.204s

C210 100回
real	0m1.718s
user	0m0.720s
sys	0m0.116s
    return 1;
real	0m1.327s
user	0m0.704s
sys	0m0.108s

*/
