#include <stdio.h>
int getMaxInt(){ //01111111  00000001
  /* return ((1 << 31) - 1); */
  /* return ~(1 << 31); */
  return ((unsigned int) - 1) >> 1;
  /*由于优先级的关系，()不可以省略*/
}

int getMinInt(){ //10000000
  return 1 << 31;
}

int absbit(int n){
  return n + (n >> 31) ^ n >> 31;
  /* (x+y)^y */
  /* return (n ^ (n >> 31)) - (n >> 31); //(x^y)-y */
}

int max(int a,int b){
  return (a ^ ((a ^ b) & -(a < b)));
  /* a^b^b=a,0,-1 */
  return (b & ((a - b) >> 31)) |(a & (~(a - b) >> 31));
  /* 如果a>=b,(a-b)>>31为0，否则为-1 */
}

int main(void)
{
  int a;
  int n;
  int b;
  int c;
  b = 3;
  c = 9;
  n = -2;
  /* a = getMaxInt(); */
  /* a = getMinInt(); */
  /* a = absbit(n); */
  a = max(b,c);
  printf("%d %d\n",n, ~n);
  printf("int 的max-num is : %d\n", a);
  printf("%d %d max is : %d\n",b, c, a);
}
