#include <stdio.h>
#include <string.h>
#include <iostream>
#include <conio.h>

typedef struct {
    char npm [10];
    char nama [20];
    char alamat [30];
    int angkatan;
    float ipk;
} mhs ;

int main() {
    mhs student[100];
    char lagi = 'y'; int i;
    for( i = 0; lagi == 'y'; i++){
        printf("nNPM = "); 
			gets(student[i].npm);
        printf("Nama = "); 
			gets(student[i].nama);
        printf("Alamat = "); 
			gets(student[i].alamat);
        printf("Angkatan = "); 
			scanf("%i", &student[i].angkatan);
        printf("IPK = "); 
			scanf("%f", &student[i].ipk);
        printf("nMasukkan Lagi (y/t) ? "); 
//		lagi = getche(); 
//		flushall();
    }
    printf("nnData yang sudah dimasukkan adalah:n");
    for( int j = 0; j < i; j++){
        printf("nNPM : %s", student[j].npm);
        printf("nNama : %s", student[j].nama);
        printf("nAlamat : %s", student[j].alamat);
        printf("nAngkatan : %i", student[j].angkatan);
        printf("nIPK : %f n", student[j].ipk);
    }
//	return 1;
//	getch();
}
//https://gakpaketelor.wordpress.com/2009/03/06/struct-dalam-c/
