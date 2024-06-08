#include <stdio.h>
#include <stdlib.h>

#define MAX 20
int S[MAX], c=0, n; 

void print();
int Next();

int main(){
    int i;
    char input[MAX];

    system("COLOR F0");
    printf("Nhap cau hinh ban dau: ");
    scanf("%s", input);
    
   
    for (n = 0; input[n] != '\0'; n++);


    for (i = 0; i < n; i++) {
        S[i + 1] = input[i] - '0';
    }

    printf("Cau hinh hien tai: ");
    print();

    if (Next()) {
        printf("Hoan vi ke tiep: ");
        print();
    } else {
        printf("day la hoan vi cuoi cung.\n");
    }

    return 0;
}

void print() {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d", S[i]);
    }
    printf("\n");
}

int Next() {
    int i = n - 1, j, tam, k;

    while (i > 0 && S[i] > S[i + 1]) i--;
    if (i == 0) return 0; 

    j = n;
    while (S[j] < S[i]) j--;
    tam = S[i];
    S[i] = S[j];
    S[j] = tam;

    j = i + 1; k = n;
    while (j < k) {
        tam = S[j];
        S[j] = S[k];
        S[k] = tam;
        j++;
        k--;
    }

    return 1; 
}