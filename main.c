#include <stdio.h>

void main () {
    unsigned int a, na, b, nb, i=0, j, k, temp, niza[16], nizb[16], nizc[16];
    
    printf("Broj A?: ");
    scanf("%u", &a);
    printf("Broj B?: ");
    scanf("%u", &b);
    
    while (b != (b|1))
        b=b>>1;
    printf("%u \n", b);                                 //brisanje poslednjih nula kod B
    
    while (a!=0){
        niza[i++]= a%2 ? 1 : 0;                         //A u niz od najnizeg do najveceg bita
        a/=2;
    }
    na=i;                                               //broj bitova od A
    
    for (j=0; j<=na/2; j++){                            //NizA se obrne da bude od najvece do najmanjeg bita
        temp=niza[j];
        niza[j]=niza[na-1-j];
        niza[na-1-j]=temp;
    }
    
    i=0;
    while (b!=0){
        nizb[i++]= b%2 ? 1 : 0;                         //B u niz od najnizeg do najveceg bita
        b/=2;
    }
    nb=i;                                               //broj bitova od A
    
    for (j=0; j<=nb/2; j++){                            //NizB se obrne da bude od najvece do najmanjeg bita
        temp=nizb[j];
        nizb[j]=nizb[nb-1-j];
        nizb[nb-1-j]=temp;
    }
    
    temp=0;                                             //pocetak nizaC gde idu pozicije javljanja sekvence
    
    for (j=0; j<=na-nb; j++){                           //proverava se prvih (na-nb) bitova jer posle nmz ceo nizB da se javi
        i=0;
        k=j;
        while (i<nb && nizb[i]==niza[k]) {              //dokle god se nizovi podudaraju
            i++;                                        //povecava se i
            k++;
        }
        if (i==nb) nizc[temp++]=na-1-j;                 //ako se i podudari s nb onda se cela sekvenca podudarila pa imamo res
    }
    
    for (i=0; i<temp; i++){
        printf("%u  ", nizc[i]);
    }
    
}
