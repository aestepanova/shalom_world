#include <stdio.h>
#define N 100

int getInt(int* a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n == 0) {
            printf("Error, please repeat input: ");
            scanf("%*[^\n]");
        }
    } while (n == 0);
    return n < 0 ? 0 : 1;
}

int fun1(int a){
    int n=a, r=0, q, w=0, w1=0, p=0;
    while(n!=0){
        r++; //Счетчик цифр
        q=n%10; //Берем цифру
        n=n/10;
        if (q==0)
            q=1;
        else if (q==1)
            q=0;
        p=10*p + q;
    }
   for (int i=0; i<r; i++){
       w=w*10+p%10;
       p=p/10;
   }
  /* r=0;
   w1=w;
   if (w==0)
        r++;
   while(w1!=0){
     r++;
     w1=w1/10;
   }
   *b=r;*/
   return (w);
}
int fun2(int a, int*b){
    int k=0, p=a;
    if (p==0)
        k=1;
    while(p!=0){
        k++;
        p=p/10;
    }
    *b=k;
    return p;
}

void Choose(int *a, int*digits, int n){
    int max=0;
    for (int i=0; i<n; i++){ //находим индекс минимального элемента массива
        max=i;
        for (int j=i+1; j<n; j++){
            if (digits[j]>digits[max])
                max=j;
        }
        int tmp = digits[i];
        digits[i]=digits[max];
        digits[max]=tmp;
        tmp = a[i];
        a[i]=a[max];
        a[max]=tmp;
    }
}

int main() {
    int l, y;
    printf("Please, input length of sequence: ");
    do{
        getInt(&l);
        if((l<=0)||(l>N)){
            printf("Error. Incorrect number, repeat, please \n");
        }
    }while ((l<=0)||(l>N));
    int nums[N];
    for (int i=0; i<l; i++){
        do{
            printf("Enter a[%d]: ", i+1);
            getInt(&nums[i]);
           if((nums[i]<=0)||(nums[i]>20000000)) {
               printf("Error. Incorrect number,\nrepeat, please \n");
           }
        }while ((nums[i]<=0)||(nums[i]>20000000));
    }
    
    // Исходная последовательность
    printf("%s", "\nThere's your sequence: \n");
    for (int j = 0; j < l; j++) {
        printf("a[%d]=%d  ", j+1 ,nums[j]);
    }
    printf("\n");

    //Массив для обработанных чисел
    int nums2[N];
    for (int i=0; i<l; i++){
        nums2[i]=fun1(nums[i]);
    }
    y=0;
    int nums3[N]; //вспомогательный массив для хранения количества цифр
    for (int i=0; i<l; i++){
        fun2(nums2[i],&y);
        nums3[i]=y;
    }
    printf("%s", "\nThere's new sequence: \n");
    for (int i = 0; i < l; i++) {
        printf("a[%d]=%d Digits: %d\n", i+1 ,nums2[i], nums3[i]);
    }
    Choose(nums2,nums3,l);
    //Вывод новой последовательности
    printf("%s", "\nThere's sort sequence: \n");
    for (int i = 0; i < l; i++) {
        printf("a[%d]=%d has %d digits\n", i+1 ,nums2[i], nums3[i]);
    }
    return 0;
}

