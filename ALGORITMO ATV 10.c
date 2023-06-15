//implementar o algoritmo de fatorial na forma recursiva e de iteração.

#define interacao
#include <stdio.h>



#ifdef recursiva
int fat(int n)
{
    if (n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*fat(n - 1);
    }
}
void main()
{
    int n;

    printf("DIGITE UM NUMERO: \t");
    scanf("%d", &n);

    fat(n);
    printf("\nFATORIAL: %d", fat(n));
    return 0;
}
#endif //recursiva




#ifdef interacao
int main ()
{
    int n, i, fat=1;

    printf("DIGITE UM NUMERO: \t");
    scanf("%d", &n);

    for(i=n; i>1; i--)
    {
        fat= fat*i;
    }
    printf("FATORIAL: %d", fat);
}
#endif // interação

// algoritimo de fibonacci em recursão e interação

#define ex1
 #include <stdio.h>
 
#ifdef ex1 // interação
 
int main()
 {
 
   int a, b , aux, i;
 
   a=0;
    b=1;
 
   printf("%d\n", a);
    printf("%d\n", b);
    for(i=0; i<30; i++)
    {
        aux= a+b;
        a=b;
        b= aux;
 
       printf("%d\n", aux);
    }
 }
 #endif // ex1
 
#ifdef ex2 // recursao
 
int vetor[30];
 
int calculaFib(int i)
 {
 
    if(i==1 || i==2) {
         vetor[i] = 1;
     }
     else {
         vetor[i] = fib(i-1) + fib(i-2);
     }
 }
 
int fib(int i)
 {
     if(vetor[i]==0) {
         calculaFib(i);
         printf("\n%d ", vetor[i]);
     }
     else {
         return vetor[i];
     }
 }
 
int main()
 {
     int i, N=30;
     int *vetor;
 
    printf("FIBONACCI:\n");
     for(i=1; i<=N; i++)
         fib(i);
 
    return 0;
 }
 #endif // ex2

