#include<stdio.h>

int jangkauan(int awal, int akhir)
{
	int i;
	for(i=awal;i<=akhir;i++)
    {
    	if(prima(i) == 1) printf("%d ", i);
	}
}

int prima(int n)
{
    if (n == 2 || n == 3)
        return 1;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return 0;

	int i;
    for (i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }

    return 1;
}

long pangkat(int a, int n)
{
	long hasil = 1;
	while (n != 0) {
        hasil *= a;
        --n;
    }
    return hasil;
}
      
long faktorial(int n)  
{  
    if (n == 0)  
    	return 1;  
    else  
        return(n * faktorial(n-1));  
}
       
int main()
{  
    int angka, pang, awal, akhir, i;
    long fakt, hsl_pang;
    printf("Angka: ");
    scanf("%d", &angka);
    printf("Pangkat: ");
    scanf("%d", &pang);
    printf("Jangkauan awal: ");
    scanf("%d", &awal);
    printf("Jangkauan akhir: ");
    scanf("%d", &akhir);
       
    fakt = faktorial(angka);
    printf("%d! = %ld\n", angka, fakt);
    
    hsl_pang = pangkat(angka, pang);
    printf("%d^%d = %ld\n", angka, pang, hsl_pang);
    
    if(prima(angka)) printf("%d prima\n", angka);
    else printf("%d bukan prima\n", angka);
    
    jangkauan(awal, akhir);
    return 0;  
}  
