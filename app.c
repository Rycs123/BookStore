#include <stdio.h>

void tambahBuku(char namaBuku[100][100], int stock[100], int *choose){
    printf("Masukkan nama buku : ");
    scanf("%s",&namaBuku[*choose]);
    printf("Masukkan Stock Buku : ");
    scanf("%d",&stock[*choose]);
    (*choose)++;
}

void tampilBuku(char namaBuku[100][100], int stock[100], int choose){
    for(int i=0;i<choose;i++){
        printf("Judul buku ke-%d adalah %s , stock : %d \n ",i+1,namaBuku[i],stock[i]);
    }
}

void beliBuku(char namaBuku[100][100],int stock[100],int choose){
    int pilihan,jumlahBeli;
    for(int i=0;i<choose;i++){
        printf("%d. %s => : %d \n",i+1,namaBuku[i],stock[i]);
    }
    printf("Masukkan Pilihan : ");
    scanf("%d",&pilihan);

    if(pilihan > 0 && pilihan <= jumlahBeli){
        printf("Masukkan jumlah buku yang ingin di beli : ");
        scanf("%d",&jumlahBeli);
        if(jumlahBeli <= stock[pilihan-1]){
            stock[pilihan-1] -= jumlahBeli;
            printf("Pembelian buku %s sebanyak %d berhasil..",namaBuku[pilihan-1],jumlahBeli);
        }else{
            printf("Stock buku tidak cukup...");
        }
    }else{
        printf("Pilihan tidak valid");
    }
}

int main(){
    char namaBuku[100][100];
    int stock[100];
    int choose = 0;
    int pilihan;

    do{
        printf("Selamat Datang di Book Store Staditek\n");
        printf("1. Tambah Buku \n");
        printf("2. Tampil Buku \n");
        printf("3. Beli Buku \n");
        printf("4. Keluar Aplikasi \n");
        printf("Pilih menu : ");
        scanf("%d",&pilihan);
        switch(pilihan){
            case 1 : 
                tambahBuku(namaBuku,stock,&choose);
                break;
            case 2 :
                tampilBuku(namaBuku,stock,choose);
                break;
            case 3 :
                beliBuku(namaBuku,stock,choose);
                break;
            case 4 :
                printf("Terima kasih telah berbelanja di book store staditek");
                break;
            default : 
                printf("Pilian anda tidak ada..!!!");
                break;
        }
    }while(pilihan != 4);

    return 0;
}