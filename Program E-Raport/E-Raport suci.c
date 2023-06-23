 #include <stdio.h>
 #include <conio.h>
 #include <string.h>
 #include <windows.h> 
 #include <stdbool.h>
 #include "backgroud2.c"

 //======================================= VARIABEL GLOBAL ========================================
float satu[100];
char verivikasi[10];
char user[20];
char pass[10];
char verivikasi[10];
char namaranking[][100]={" "};
int a=1;
int jumlah=0;
char jml[30];
int c=0;
int keterangan[40][40];
char anak[40][40];
char jenke[40];
int nilai1;
char nm[100];
char nis2[100];
int jmla;
char nama[30][20];
char nama2[30][20];
char nis[10][20];
char ttl[25][20];
char alamat[25][20];
char jk[20][20];
int anake[20];
char status[15][20];
char pa[15][20];
char ni[20][20];
char na[20][20]; 
char pi[15][20];
int nilai [100][16];
int cek=0;
float jumlahnilai[30];
float ratarata [30];
int ke;
int smt=2;
char kelas[4]={"XII"};  

//================================================== PROTOTYPE ======================================================== 
 void pindahan();
 void registrasi();
 void kotak();
 int menu();
 int rekap2();
 void kepala();
 void daftarmenu();
 void login();
 int rekapbiodata();
 int rekapnilai();
 int peringkat();
 void bingkai();
 void sekul();
///////////////////////////////////////////////////  BACKGROUD ////////////////////////////////////////////////////////
void kotak(int p, int l, int x, int y){
     p-=1;
     l-=1;
     for(int a=0; a<=p; a++){
         set_cursor(x+a,y);
         printf("%c",223);
         set_cursor(x+a,y+l);
         printf("%c",220);
     }
     for(int b=0; b<=l; b++){
         set_cursor(x,y+b);
         printf("%c",219);
         set_cursor(p+x,y+b);
         printf("%c",219);
     }
 }
void bingkai(){
set_background_color(14);
set_text_color(6);
for(int x=0; x<=119; x++){
    for(int y =0; y<=39; y++){
        set_cursor(x,y);
        if(x==0 || x==1 || x==119 || x==118 ||y==0 || y==39){
            printf("%c",219); //Sleep(1);
        }else{
            printf(" ");
        }
    }
}
}
////////////////////////////////////////////////  VALIDASI USERNAME & PASSWORD ///////////////////////////////////////////////////////////////////
char *valusername(char *user){
   char a;
   char b[100];
   char c[100];
   int d=0;
   while((a=getch())!=13 || d<=3){
      if(d<=6 &&(a>='a' && a<='z'  || a>='0' && a<='9' && d>0 )){     
         printf("%c",a);
         b[d]=a;
         d++;
      }
      else if(a==8 && d!=0){
         printf("\b \b");
         d-=1;
      }
   }
for(int s=0; s<d; s++){
   c[s]=b[s];
}
strcpy(user,c);
return user;
}
/////////////////////////////////////////////////  VALIDASI   NAMA ////////////////////////////////////////////////////
char*val(char*nm){
    char ca;
    char data1[100];
    char data2[100];
    int a=0;
    while((ca=getch())!=13 || a<2){
        if(a<30 && (ca>='A' && ca<='Z' || ca==' ' && a!=0 && data1[a-1]!=' ')){
            printf("%c",ca);
            data1[a]=ca;
            a++;
        }else if(ca==8 && a!=0){
            printf("\b \b");
            a--;
        }
    }
    for(int z=0; z<a; z++){
        data2[z]=data1[z];
    }
    strcpy(nm, data2);
    return nm;
}
////////////////////////////////////////////////////  VALIDASI NIS  ////////////////////////////////////////////////////
char*valnis(char*nis2){
    char ca;
    char data1[100];
    char data2[100];
    int a=0;
    while((ca=getch())!=13 || a<10){
        if(a<15 && (ca>='1' && ca<='9'|| ca=='0'  && a!=0 )){
            printf("%c",ca);
            data1[a]=ca;
            a++;
        }else if(ca==8 && a!=0){
            printf("\b \b");
            a--;
        }
    }
    for(int z=0; z<a; z++){
        data2[z]=data1[z];
    }
    strcpy(nis2, data2);
    return nis2;
}
////////////////////////////////////////////////////  VALIDASI JUMLAH SISWA ////////////////////////////////////////////
int valjml(int jmla){
    char ca;
    char data1[100];
    char data2[100];
    int a=0;
    while((ca=getch())!=13 || a<1){
        if(a<2 && (ca>='1' && ca<='9'&& a==0 || a==1 &&( data1[a-1]=='1' || data1[a-1]=='2'||data1[a-1]=='3'||data1[a-1]=='4')&&ca>='0'&&ca<='9')){
            printf("%c",ca);
            data1[a]=ca;
            a++;
        }else if(ca==8 && a!=0){
            printf("\b \b");
            a--;
        }
    }
    for(int z=0; z<a; z++){
        data2[z]=data1[z];
    }
    return atoi(data2);
}
///////////////////////////////////////////////////////  VALIDASI NILAI  ///////////////////////////////////////////////
int valnilai(int nilai1){
    char ca;
    char data1[100];
    char data2[100];
    int a=0;
    while((ca=getch())!=13 || a<2){
        if(a<3 && (ca>='1' && ca<='9'&& a==0 || a==1 &&ca>='0'&&ca<='9'|| a==2 && data1[a-1]=='0' && data1[a-1]=='1' && ca=='0')){
            printf("%c",ca);
            data1[a]=ca;
            a++;
        }else if(ca==8 && a!=0){
            printf("\b \b");
            a--;
        }
    }
    for(int z=0; z<a; z++){
        data2[z]=data1[z];
    }
    return atoi(data2);
}
////////////////////////////////////////////////////  VALIDASI JK  /////////////////////////////////////////////////////
char*valjk(char*jenke){
    char ca;
    char data1[100];
    char data2[100];
    int a=0;
    while((ca=getch())!=13 || a<1){
        if(a<1 && (ca=='p' || ca=='l' ||ca=='P' || ca=='L' || ca==' ' && a!=0 && data1[a-1]!=' ')){
            printf("%c",ca);
            data1[a]=ca;
            a++;
        }else if(ca==8 && a!=0){
            printf("\b \b");
            a--;
        }
    }
    for(int z=0; z<a; z++){
        data2[z]=data1[z];
    }
    strcpy(jenke, data2);
    return nm;
}
//========================================================================================================
//====================================== MENU KE 5= KELUAR PROGRAM =======================================
int finish(){
    system("cls");
    char pilih3;
    do{
    kotak(50, 0, 5, 10); set_cursor(5, 8); printf("Anda Yakin Mau Keluar Dari Program?(Y/T) ");
    kotak(62, 0, 13, 15); set_cursor(14, 13); printf("Masukan pilihan anda       : "); pilih3=getche(); 
    if(pilih3=='Y'||pilih3=='y'){
    sekul();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t=================================================\n");Sleep(100);
    printf("\t\t\t\t=                                               =\n");Sleep(100);
	printf("\t\t\t\t=                                               =\n");Sleep(100);
	printf("\t\t\t\t=                                               =\n");Sleep(100);
	printf("\t\t\t\t=                TERIMAKASIH                    =\n");Sleep(100);
	printf("\t\t\t\t=                                               =\n");Sleep(100);
	printf("\t\t\t\t=      ANDA TELAH MENGGGUNAKAN APLIKASI         =\n");Sleep(100);
	printf("\t\t\t\t=                                               =\n");Sleep(100);
	printf("\t\t\t\t=                 E-RAPORT                      =\n");Sleep(100);
	printf("\t\t\t\t=                                               =\n");Sleep(100);
    printf("\t\t\t\t=    SEMOGA DAPAT MEMPERMUDAH PEKERJAAN ANDA    =\n");Sleep(100);
    printf("\t\t\t\t=                                               =\n");Sleep(100);
	printf("\t\t\t\t=                                               =\n");Sleep(100);
	printf("\t\t\t\t=================================================\n");Sleep(10000);
    exit(0);
    }else if(pilih3 == 't' || pilih3 =='T'){
      	system("cls"); registrasi();
    }else{
        kotak(62, 0, 13, 15); set_cursor(43, 13); printf("Inputan yang anda masukan salah"); Sleep(50); system("cls");
    }
    }while(pilih3 !='y' || pilih3 !='Y' || pilih3 != 't' || pilih3 !='T');     
}

//==================================================================================================================
//=============================================== KOTAK NILAI ======================================================
void br(){
    set_cursor(3,13); printf("|===========================================================|============|");Sleep(20);
    set_cursor(3,14); printf("|                   DAFTAR MATA PELAJARAN                   |   NILAI    |");Sleep(20);
    set_cursor(3,15); printf("|===========================================================|============|");Sleep(20);
    set_cursor(3,16); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,17); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,18); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,19); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,20); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,21); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,22); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,23); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,24); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,25); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,26); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,27); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,28); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,29); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,30); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,31); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,32); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,33); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,34); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,35); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,36); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,37); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,38); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,39); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,40); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,41); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,42); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,43); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,44); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,45); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,46); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,47); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,48); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,49); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,50); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,51); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,52); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,53); printf("|-----------------------------------------------------------|------------|");Sleep(20);
    set_cursor(3,54); printf("|                                                           |            |");Sleep(20);
    set_cursor(3,55); printf("|===========================================================|============|");Sleep(20);
    set_cursor(3,56); printf("|                        JUMLAH NILAI                       |            |");Sleep(20);
    set_cursor(3,57); printf("|===========================================================|============|");Sleep(20);
    set_cursor(3,58); printf("|                       RATA-RATA NILAI                     |            |");Sleep(20);
    set_cursor(3,59); printf("|===========================================================|============|");Sleep(20);

    set_cursor(78,16); printf("|==================================|");Sleep(20);
    set_cursor(78,17); printf("|       DATA KEHADIRAN SISWA       |");Sleep(20);
    set_cursor(78,18); printf("|=======================|==========|");Sleep(20);
    set_cursor(78,19); printf("|  SAKIT                |          |");Sleep(20);
    set_cursor(78,20); printf("|=======================|==========|");Sleep(20);
    set_cursor(78,21); printf("|  IZIN                 |          |");Sleep(20);
    set_cursor(78,22); printf("|=======================|==========|");Sleep(20);
    set_cursor(78,23); printf("|  TANPA KETERANGAN     |          |");Sleep(20);
    set_cursor(78,24); printf("|=======================|==========|");Sleep(20);    
}  

//============================================================================================================
//================================ MENU KE 1= TENTANG PROGRAM ================================================

int tentangprogram(){
    char no; 
    do{
    bingkai();
    set_text_color(0);
    kotak(116, 0, 2, 8);
    kepala(); 
    kotak(20, 4,28,12); set_cursor(30,14); printf("  1. PROFIL");
    kotak(20, 4,68,12); set_cursor(70,14); printf("  2. INFORMASI");
    kotak(20, 4,48,20); set_cursor(50,22); printf("  3. KEMBALI");
    set_cursor(30,30);  printf(">>>>>>>>>>>>Masukan Pilihan: "); no= getche();
    if(no=='1'){
       set_cursor(5,10);  printf("----------------------------------------------------------------------------------------------------------------");Sleep(10);
        set_cursor(5, 11); printf("-                                                                                                              -");Sleep(10);
        set_cursor(5, 12); printf("- E-Raport merupakan program untuk mengelompokkan data siswa, berikut dengan kalkulasi nilai                   -");Sleep(10);
        set_cursor(5,13);  printf("- dan pengurutan peringkat. Program ini dibuat untuk memenuhi syarat kelulusan Ujian Akhir Semester            -");Sleep(10);
        set_cursor(5,14);  printf("- pada Pelatihan Pemrograman Bahasa-C, bukan hanya itu saja, program dengan tema E-raport ini sengaja dibuat   -");Sleep(10);
        set_cursor(5,15);  printf("- mempermudah perekapan data siswa, terutama tenaga pendidikan di kelas 12 Akuntansi SMKN 2 KOTA BANJAR.       -");Sleep(10);
        set_cursor(5,16); printf("-                                                                                                              -");Sleep(10); 
        set_cursor(5,17); printf("----------------------------------------------------------------------------------------------------------------");Sleep(10);    
        set_cursor(5,18); printf("----------------------------------------------------------------------------------------------------------------");Sleep(10);
        set_cursor(5,19); printf("-                                                                                                              -");Sleep(10);
        set_cursor(5,20); printf("-                                   >>>       PROFIL   creator      <<<                                        -");Sleep(10);
        set_cursor(5,21); printf("-                                                                                                              -");Sleep(10);
        set_cursor(5,22); printf("-    Nama                      : SUCI AMANAH                                                                   -");Sleep(10);
        set_cursor(5,23); printf("-    Alamat Sekarang           : Banjar, Jawa Barat                                                            -");Sleep(10);
        set_cursor(5,24); printf("-    Prodi                     : D3 MANAJEMEN INFORMATIKA                                                      -");Sleep(10);
        set_cursor(5,25); printf("-    Fakultas                  : Ilmu Komputer                                                                 -");Sleep(10);
        set_cursor(5,26); printf("-    Perguruan Tinggi          : Universitas Nasional Pasim Bandung                                            -");Sleep(10);
        set_cursor(5,27); printf("-    E-mail                    : SUCIAMNH01@GMAIL.COM                                                          -");Sleep(10);
        set_cursor(5,28); printf("-                                                                                                              -");Sleep(10);
        set_cursor(5,29); printf("-                                                                                                              -");Sleep(10);
        set_cursor(5,30); printf("----------------------------------------------------------------------------------------------------------------");Sleep(10);
        set_cursor(40,30);  printf(">>>>>>>>>>>>KLIK SEMBARANG UNTUK KEMBALI KE MENU UTAMA: "); no= getche(); tentangprogram();
    }else if(no=='2'){
        system("cls");
        set_cursor(5,10); printf("--------------------------------------------------------------------------------------------------------");Sleep(30);
        set_cursor(5, 11);printf("-                                                                                                      -");Sleep(30);
        set_cursor(5, 12);printf("- E-Rapor adalah sebuah sistem aplikasi berbasis web yang di harapkan dapat merubah pola kerja guru    -");Sleep(30);
        set_cursor(5,13); printf("- dari pola manual ke pola digital dan juga dapat mempermudah guru dalam                               -");Sleep(30);
        set_cursor(5,14); printf("- melakukan penilaian ke siswa bahkan sampai ke cetak rapor dan evaluasi nilai hasil belajar siswa.    -");Sleep(30);
        set_cursor(5,15); printf("- E-Rapor di harapkan dapat memberikan manfaat untuk dunia pendidikan                                  -");Sleep(30);
        set_cursor(5,16); printf("- dan dapat memberikan efek positif terhadap dunia pendidikan terutama kepada tenaga pengajar.         -");Sleep(30);
        set_cursor(5,17); printf("- Dengan adanya Aplikasi ini Insyaallah dapat meng Efisien kan waktu para wali kelas                   -");Sleep(30);
        set_cursor(5,18); printf("- dalam merekap nilai hasil belajar siswa.                                                             -");Sleep(30);
        set_cursor(5,19); printf("-                                                                                                      -");Sleep(30);
        set_cursor(5,20); printf("-------------------------------------------------------------------------------------------------------");Sleep(30);   
        set_cursor(40,30);  printf(">>>>>>>>>>>>KLIK SEMBARANG UNTUK KEMBALI KE MENU UTAMA: "); no= getche(); tentangprogram();
    }else if(no=='3'){
        menu();
    }else{
        set_cursor(47,30); printf("inputan tidak valid");
        set_cursor(47,30); printf("                        ");   
        tentangprogram;  
    }
}while(true);
}

//====================================================================================================================
//==================================================== MENU UTAMA ====================================================

int menu(){
    system("cls");
    char jml[50];
    char pil;
    char nex;
    int nex1;
    char pilih2; 
    bingkai();
    set_text_color(0);
do{
    kepala();
    kotak(116, 0, 2, 8);
    kotak(30, 0, 73, 15);
    kotak(25, 3, 8, 10);
    kotak(25, 3, 8, 15);
    kotak(25, 3, 8, 20);
    kotak(25, 3, 8, 25);
    kotak(25, 3, 40, 13);
    kotak(25, 3, 40, 18);
    kotak(25, 3, 40, 23);
    kotak(30, 0, 73, 30);
    set_cursor(75,13); printf("DAFTAR MENU");
    set_cursor(10,11); printf("1. Tentang Program");
    set_cursor(10,16); printf("2. Jumlah Siswa");
    set_cursor(10,21); printf("3. Rekap Biodata");
    set_cursor(10,26); printf("4. Rekap Nilai");
    set_cursor(42,14); printf("5. Lihat Peringkat");   
    set_cursor(42,19); printf("6. LIhat Data Siswa");
    set_cursor(42,24); printf("7. Keluar Program");
    set_cursor(75,28); printf("Masukkan Pilihan: "); pil=getche(); 
    switch(pil){
      case '1':
        kepala();
        tentangprogram();
        break;
      case '2':
        system("cls");
        int test = 0;
        kotak(60,4,40,10); Sleep(200);  
            set_cursor(42,27); printf(">>>>>> INPUTAN HARUS MENGGUNAKAN ANGKA 1-40");
            set_cursor(42,28); printf(">>>>>>>> TIDAK MENGGUNAKAN HURUF ATAU KARAKTER LAINNYA");
            set_cursor(42,12); printf("JUMLAH SISWA DALAM SATU KELAS  : "); jumlah=valjml(jmla);
            do{
            system("cls");
            if(jumlah>=1 && jumlah<=40){
            kotak(60,4,40,10); Sleep(200); 
            kotak(60,4,40,14); Sleep(200);
            set_cursor(42,12); printf("JUMLAH SISWA DALAM SATU KELAS  : %d ", jumlah);             
            set_cursor(42,16); printf("JUMLAH SISWA DALAM SATU KELAS ANDA YAITU SEBANYAK = %d", jumlah);
                Sleep(2000); system("cls"); menu();
            }else{
                kotak(60,4,40,10); Sleep(200); 
                kotak(60,4,40,14); Sleep(200);
                set_cursor(42,27); printf(">>>>>> INPUTAN HARUS MENGGUNAKAN ANGKA 1-40");
                set_cursor(42,28); printf(">>>>>>>> TIDAK MENGGUNAKAN HURUF ATAU KARAKTER LAINNYA");
                set_cursor(42,12); printf("JUMLAH SISWA DALAM SATU KELAS  : ");
            }
    }while(jumlah<1  && jumlah >40);
        break;
      case '3':
        system("cls");
     if(jumlah==0){
   	    set_cursor(50,33); printf(">>> ANDA BELUM MENG-INPUT JUMLAH SISWA <<<");
        set_cursor(40,34); printf(">>>> SILAHKAN ISI TERLEBIH DAHULU UNTUK MELANJUTKAN MENU REKAP <<<");
        set_cursor(40,36); printf(">>>>>>>>>> tekan sembarang untuk kembali ke menu utama <<<<<<<<<<<");
   	    getch();
		menu();
     }else{
        kepala();
        set_cursor(30,8);  printf("=================================================================");Sleep(100);
        set_cursor(30,9);  printf("=                                                               =");Sleep(100);
        set_cursor(30,10); printf("=                                                               =");Sleep(100);
        set_cursor(30,11); printf("=              PENGISIAN IDENTITAS WAJIB MENGGUNAKAN            =");Sleep(1000);
        set_cursor(30,12); printf("=           HURUF KAPITAL, TIDAK ANGKA MAUPUN KARAKTER LAIN     =");Sleep(1000);
        set_cursor(30,13); printf("=              SEMENTARA PENGISIAN NOMOR INDUK SISWA            =");Sleep(1000);
        set_cursor(30,14); printf("=                     ANDA BISA MENGGUNAKAN ANGKA               =");Sleep(1000);
        set_cursor(30,15); printf("=               MINIMAL 10 ANGKA DENGAN TIDAK MENGGUNAKAN       =");Sleep(1000);
        set_cursor(30,16); printf("=           ANGKA 0 SEBAGAI AWALAN, SESUAI DENGAN KETENTUAN     =");Sleep(1000);
        set_cursor(30,17); printf("=                      PENDIDIKAN PADA UMUMNYA                  =");Sleep(1000);
        set_cursor(30,18); printf("=                                                               =");Sleep(1000);
        set_cursor(30,19); printf("=                                                               =");Sleep(100);
        set_cursor(30,20); printf("=                                                               =");Sleep(100);
        set_cursor(30,21); printf("=================================================================");Sleep(1000);
        Sleep(5);char inputan;
        set_cursor(1,9);printf("REKAP BIODATA SISWA E-RAPORT\n");
        system("cls");
        for(int a=0; a<jumlah; a++){
            kepala();
            char q[100];
            set_cursor(1,8);   printf("REKAP DATA SISWA");
            set_cursor(1,9);   printf("SISWA KE - %d",a+1);
            fflush(stdin);
            set_cursor(3,12);  printf("Nama Peserta Didik (Lengkap)    : "); val(nm); strcpy(nama[cek], nm);
            set_cursor(3,13);  printf("Nomor Induk Siswa / NIS         : "); valnis(nis2); strcpy(nis[cek], nis2);         
            set_cursor(3,14);  printf("Tempat Tanggal Lahir            : "); val(nm); strcpy(ttl[cek], nm);
            set_cursor(3,15);  printf("Alamat Sekarang                 : "); val(nm); strcpy(alamat[cek], nm);
            set_cursor(3,16);  printf("Jenis Kelamin  ( P/L )          : "); valjk(jenke); strcpy(jk[cek],jenke); 
            do{
            set_cursor(3,17);  printf("Anak Ke-                        : ");for(int x=0;x<1;){if ((inputan=getch())>'0'&&inputan<='9'){anak[cek][x]=inputan;printf("%c",inputan);x++;}else if(x>1&&inputan==8){printf("\b \b");x--;}else if(x>0&&inputan==13){printf ("  "); break;}} 
            anake[cek]=atoi(anak[cek]);
            }while(!(anake[cek]>0 && anake[cek]<15));
            set_cursor(3,18);  printf("Status Dalam Keluarga           : "); val(nm); strcpy(status[cek], nm);
            set_cursor(3,19);  printf("Nama Ayah                       : "); val(nm); strcpy(na[cek], nm);
            set_cursor(3,20);  printf("Pekerjaan Ayah                  : "); val(nm); strcpy(pa[cek], nm);
            set_cursor(3,21);  printf("Nama Ibu                        : "); val(nm); strcpy(ni[cek], nm);
            set_cursor(3,22);  printf("Pekerjaan  Ibu                  : "); val(nm); strcpy(pi[cek], nm);Sleep(400); system("cls");
            cek++;
            c+=1;
        }
         system("cls");
        for(int a=0; a<9; a++){
        set_text_color(a);
        set_cursor(30,8);  printf("=================================================================");Sleep(10);
        set_cursor(30,9);  printf("=                                                               =");Sleep(10);
        set_cursor(30,10); printf("=                                                               =");Sleep(10);
        set_cursor(30,11); printf("=                                                               =");Sleep(70);
        set_cursor(30,12); printf("=                           SELAMAT REKAP                       =");Sleep(70);
        set_cursor(30,13); printf("=                                                               =");Sleep(70);
        set_cursor(30,14); printf("=                           DATA DIRI SISWA                     =");Sleep(70);
        set_cursor(30,15); printf("=                                                               =");Sleep(70);
        set_cursor(30,16); printf("=                         SELESAI ANDA REKAP                    =");Sleep(70);
        set_cursor(30,17); printf("=                                                               =");Sleep(10);
        set_cursor(30,18); printf("=                                                               =");Sleep(10);
        set_cursor(30,19); printf("=                                                               =");Sleep(10);
        set_cursor(30,20); printf("=                                                               =");Sleep(10);
        set_cursor(30,21); printf("=================================================================");Sleep(70);
        //Sleep(5);
        set_text_color(0);
        }
        system("cls");
          break;
     }
        case '4':
        set_text_color(0);
        system("cls");
      if(jumlah==0 || c==0){
   	        set_cursor(50,33); printf(">>>> BELUM ADA DATA YANG ANDA INPUTKAN <<<<");
            set_cursor(35,34); printf(">>>> SILAHKAN ISI TERLEBIH DAHULU UNTUK MELANJUTKAN KE MENU REKAP NILAI SISWA <<<");
            set_cursor(50,36); printf(">>>>>>>>>>>>> tekan sembarang untuk kembali ke menu utama");
   	        getch();
		    menu();
      }else{
        for(int a=0; a<jumlah; a++){
            kepala();
            kotak(116, 0, 2, 8);Sleep(50);
            set_cursor(2,5); printf("\nRekap nilai siswa ke-%d\n", a+1); Sleep(1000);
            set_cursor(4,9); printf("NAMA LENGKAP      : %s",nama[a]);
            set_cursor(4,10); printf("NIS               : %s",nis[a]);
            set_cursor(4,11); printf("KELAS             : %s",kelas);
            set_cursor(4,12); printf("SEMESTER          : %d",smt);
            br();
            set_cursor(4,16); printf("Muatan Nasional\n");
            set_cursor(4,18); printf("1. Penddikan Agama dan budi pekerti            "); 
            set_cursor(4,20); printf("2. Pendidikan Pancasila dan Kewarganegaraan    "); 
            set_cursor(4,22); printf("3. Bahasa Indonesia                            "); 
            set_cursor(4,24); printf("4. Matematika                                  "); 
            set_cursor(4,26); printf("5. Bahasa Inggris                              "); 
            set_cursor(4,28); printf("6. Sejarah Indonesia                           "); 
            set_cursor(4,30); printf("7. Bahasa Jerman                               "); 
            set_cursor(4,32); printf("Muatan Kewilayahan");
            set_cursor(4,34); printf("1. Seni Budaya                                 "); 
            set_cursor(4,36); printf("2. Pendidikan Jasmani, Olahraga dan Kesehatan  "); 
            set_cursor(4,38); printf("3. Muatan Lokal");
            set_cursor(4,40); printf("   -Bahasa Sunda                               "); 
            set_cursor(4,42); printf("Muatan Peminatan Kejuruan");
            set_cursor(4,44); printf("1. Akuntansi Jasa Perusahaan Jasa, Dagang dan manufaktur  "); 
            set_cursor(4,46); printf("2. Akuntansi Lembaga / Instansi Pemerintahan   "); 
            set_cursor(4,48); printf("3. Akuntansi Keuangan                          "); 
            set_cursor(4,50); printf("4. Komputer Akuntansi                          "); 
            set_cursor(4,52); printf("5. Administrasi Pajak                          "); 
            set_cursor(4,54); printf("6. Produk Kreatif dan Kewirausahaan            "); 

            set_cursor(68,18); nilai[a][0]=valnilai(nilai1);
            set_cursor(68,20); nilai[a][1]=valnilai(nilai1);
            set_cursor(68,22); nilai[a][2]=valnilai(nilai1);
            set_cursor(68,24); nilai[a][3]=valnilai(nilai1);
            set_cursor(68,26); nilai[a][4]=valnilai(nilai1);
            set_cursor(68,28); nilai[a][5]=valnilai(nilai1);
            set_cursor(68,30); nilai[a][6]=valnilai(nilai1);
            set_cursor(68,34); nilai[a][7]=valnilai(nilai1);
            set_cursor(68,36); nilai[a][8]=valnilai(nilai1);
            set_cursor(68,40); nilai[a][9]=valnilai(nilai1);
            set_cursor(68,44); nilai[a][10]=valnilai(nilai1);
            set_cursor(68,46); nilai[a][11]=valnilai(nilai1);
            set_cursor(68,48); nilai[a][12]=valnilai(nilai1);
            set_cursor(68,50); nilai[a][13]=valnilai(nilai1);
            set_cursor(68,52); nilai[a][14]=valnilai(nilai1);
            set_cursor(68,54); nilai[a][15]=valnilai(nilai1);
            jumlahnilai[a]  = (nilai[a][1])+nilai[a][0]+nilai[a][2]+nilai[a][3]+nilai[a][4]+nilai[a][5]+nilai[a][6]+nilai[a][7]+nilai[a][8]+nilai[a][9]+nilai[a][10]+nilai[a][11]+nilai[a][12]+nilai[a][13]+nilai[a][14]+nilai[a][15];
            ratarata[a]     = jumlahnilai[a]/16;  
            set_cursor(66,56); printf(" %.1f",jumlahnilai[a]);
            set_cursor(67,58); printf(" %.1f",ratarata[a]);
            set_cursor(107,19); printf(" "); scanf("%d",&keterangan[0][0]);
            set_cursor(107,21); printf(" "); scanf("%d",&keterangan[0][1]);
            set_cursor(107,23); printf(" "); scanf("%d",&keterangan[0][2]);
            Sleep(2000); system("cls"); 
            for(int a=0; a<9; a++){
      set_text_color(a);
        }
        for(int a=0; a<9; a++){
            set_text_color(a);
            set_cursor(30,8);  printf("=================================================");Sleep(10);
            set_cursor(30,9);  printf("=                                               =");Sleep(10);
            set_cursor(30,10); printf("=                                               =");Sleep(10);
            set_cursor(30,11); printf("=                                               =");Sleep(100);
            set_cursor(30,12); printf("=                 SELAMAT REKAP                 =");Sleep(10);
            set_cursor(30,13); printf("=                                               =");Sleep(10);
            set_cursor(30,14); printf("=            NILAI HASIL BELAJAR SISWA          =");Sleep(10);
            set_cursor(30,15); printf("=                                               =");Sleep(10);
            set_cursor(30,16); printf("=              SELESAI ANDA INPUTKAN            =");Sleep(10);
            set_cursor(30,17); printf("=                                               =");Sleep(10);
            set_cursor(30,18); printf("=                                               =");Sleep(10);
            set_cursor(30,19); printf("=                                               =");Sleep(10);
            set_cursor(30,20); printf("=                                               =");Sleep(10);
            set_cursor(30,21); printf("=================================================");Sleep(10); system("cls");
            set_text_color(0);
        }
      }
        break;       
    case '5': 
    float tamp;
    int c=0;
    system("cls");
    if(jumlah==0){
   	    set_cursor(45,33); printf(">>>>> BELUM ADA DATA YANG TER INPUT");
        set_cursor(40,34); printf(">>>> SILAHKAN ANDA INPUTKAN NILAI SISWA TERLEBIH DAHULU <<<<");
        set_cursor(40,36); printf(">>>>>>>>>>>>>tekan sembarang untuk kembali ke menu utama");
   	    getch();
		menu();
   }else{
    kotak(60, 4, 2, 2); Sleep(10);
    kotak(55, 4, 63,2); Sleep(10);
        set_cursor(4,3);  printf("BERIKUT ADALAH URUTAN DATA NILAI DI KELAS 12 AKUNTANSI");
        set_cursor(4,4);  printf("SEKOLAH MENENGAH KEJURUAN 2 KOTA BANJAR");
        for(int i=0; i<jumlah; i++){ 
        set_cursor(3,6+i);  printf("%d.  %s\t\t%.1f\t %.1f\n", i+1, nama[i], jumlahnilai[i], ratarata[i]);
        }
        for(int b=0; b<jumlah-1; b++){
            for(int a=b+1; a<jumlah; a++){
                if(ratarata[b] < ratarata[a]){
                    tamp= ratarata[b];
                    ratarata[b]=ratarata[a];
                    ratarata[a]=tamp;
                    strcpy(nama2[a], nama[a+1]);
                }
            }
        }
         set_cursor(65, 3); printf("BERIKUT ADALAH URUTAN DATA PERINGKAT DARI TERATAS");
         set_cursor(65, 4); printf("DI KELAS 12 AKUNTANSI");
         for(int x=0; x<jumlah; x++){
         set_cursor(64, 6+x);  printf("%d.  %s\t  %.1f\n", x+1, nama[x], ratarata[x]); //Sleep(10000);
         }
   }
        Sleep(4000); system("cls");
        break;
    case '6':
        system("cls");
        kotak(50, 0, 5, 5); set_cursor(6, 3); printf("PILIH DATA YANG INGIN ANDA LIHAT");
        kotak(50, 0, 13, 10); set_cursor(14, 8); printf("1. Rekap data diri Saswa ");
        kotak(50, 0, 13, 15); set_cursor(14, 13); printf("2. Rekap data Nilai Siswa"); 
        kotak(50, 0, 5, 20); set_cursor(6, 18); printf("MASUKAN PILIHAN     :"); nex=getche();
      if(jumlah==0){
        set_cursor(23, 18); printf("INPUTAN TIDAK SESUAI"); Sleep(1000);system("cls");
   	    set_cursor(40,35); printf(">>>>>BELUM ADA DATA YANG TER INPUT, SILAHKAN INPUT DATA TERLEBIH DAHULU");
        set_cursor(40,36); printf(">>>>>>>>>>>>>tekan sembarang untuk kembali ke menu utama");
   	    getch();
		menu();
      }else{
        system("cls");
        if(nex=='1'){
            if(jumlah==0 || c==0 || nex>'0' && nex<=c){
                set_cursor(2,3); printf(" Lihat data anak ke: "); scanf("%d",&ke);
                set_cursor(2,8); printf("KETERANGAN TENTANG DATA DIRI PESERTA DIDIK");
                set_cursor(3,12); printf("Nama Peserta Didik (Lengkap)        :%s\n",nama[ke-1]);
                set_cursor(3,13); printf("Nomor Induk Siswa /NISN             :%s\n",nis[ke-1]);
                set_cursor(3,14); printf("Tempat Tanggal Lahir                :%s\n",ttl[ke-1]);
                set_cursor(3,15); printf("Alamat sekarang                     :%s\n",alamat[ke-1]);
                set_cursor(3,16); printf("Jenis Kelamin                       :%s\n",jk[ke-1]);
                set_cursor(3,17); printf("Anak Ke-                            :%d\n",anake[ke-1]);
                set_cursor(3,18); printf("Status Dalam Keluarga               :%s\n",status[ke-1]);
                set_cursor(3,19); printf("Nama Ayah                           :%s\n",na[ke-1]);
                set_cursor(3,20); printf("Nama Ibu                            :%s\n",ni[ke-1]);
                set_cursor(3,21); printf("Pekerjaan Ayah                      :%s\n",pa[ke-1]);
                set_cursor(3,22); printf("Pekerjaan Ibu                       :%s\n",pi[ke-1]); 
                Sleep(4000);system("cls");
            }else{
                set_cursor(37,27); printf(">>>>>> MOHON MAAF DATA YANG INGIN ANDA LIHAT MELEBIHI DATA YANG ANDA INPUTKAN");
                set_cursor(37,28); printf(">>>>>>>>> SILAHKAN KEMBALI UNTUK MELIHAT DATA SISWA LAINNYA");
                set_cursor(37,30); printf(">>>>>>>>> Tekan sembarang untuk kembali ke menu awal"); getch(); menu();
            }
        }else if(nex=='2'){
            

            if(jumlah==0 || c==0 || nex>'0' && nex<=c){
                set_cursor(2,5); printf(" Lihat data anak ke: "); scanf("%d",&ke);
                kepala();
                br();
                set_cursor(4,9); printf("NAMA LENGKAP        : %s", nama[ke-1]);
                set_cursor(4,10); printf("NIS                 : %s", nis[ke-1]);
                set_cursor(4,11); printf("KELAS               : %s", kelas);
                set_cursor(4,12); printf("SEMESTER            : %d", smt);
                set_cursor(4,16); printf("Muatan Nasional\n");
                set_cursor(4,18); printf("1. Penddikan Agama dan budi pekerti                          %d ", nilai[ke-1][0]); 
                set_cursor(4,20); printf("2. Pendidikan Pancasila dan Kewarganegaraan                  %d", nilai[ke-1][1]); 
                set_cursor(4,22); printf("3. Bahasa Indonesia                                          %d", nilai[ke-1][2]); 
                set_cursor(4,24); printf("4. Matematika                                                %d", nilai[ke-1][3]); 
                set_cursor(4,26); printf("5. Bahasa Inggris                                            %d", nilai[ke-1][4]); 
                set_cursor(4,28); printf("6. Sejarah Indonesia                                         %d", nilai[ke-1][5]); 
                set_cursor(4,30); printf("7. Bahasa Jerman                                             %d", nilai[ke-1][6]); 
                set_cursor(4,32); printf("Muatan Kewilayahan");
                set_cursor(4,34); printf("1. Seni Budaya                                               %d", nilai[ke-1][7]); 
                set_cursor(4,36); printf("2. Pendidikan Jasmani, Olahraga dan Kesehatan                %d", nilai[ke-1][8]); 
                set_cursor(4,38); printf("3. Muatan Lokal");
                set_cursor(4,40); printf("   -Bahasa Sunda                                             %d", nilai[ke-1][9]); 
                set_cursor(4,42); printf("Muatan Peminatan Kejuruan");
                set_cursor(4,44); printf("1. Akuntansi Jasa Perusahaan Jasa, Dagang dan manufaktur     %d", nilai[ke-1][10]); 
                set_cursor(4,46); printf("2. Akuntansi Lembaga / Instansi Pemerintahan                 %d", nilai[ke-1][11]); 
                set_cursor(4,48); printf("3. Akuntansi Keuangan                                        %d", nilai[ke-1][12]); 
                set_cursor(4,50); printf("4. Komputer Akuntansi                                        %d", nilai[ke-1][13]); 
                set_cursor(4,52); printf("5. Administrasi Pajak                                        %d", nilai[ke-1][14]); 
                set_cursor(4,54); printf("6. Produk Kreatif dan Kewirausahaan                          %d", nilai[ke-1][15]);    
                jumlahnilai[ke-1]  = (nilai[ke-1][1])+nilai[ke-1][2]+nilai[ke-1][3]+nilai[ke-1][4]+nilai[ke-1][5]+nilai[ke-1][6]+nilai[ke-1][7]+nilai[ke-1][8]+nilai[ke-1][9]+nilai[ke-1][10]+nilai[ke-1][11]+nilai[ke-1][12]+nilai[ke-1][13]+nilai[ke-1][14]+nilai[ke-1][15]+nilai[ke-1][0];
                ratarata[ke-1]     = jumlahnilai[ke-1]/16; 
                set_cursor(66,56); printf(" %.1f",jumlahnilai[cek]);
                set_cursor(67,58); printf(" %.1f",ratarata[cek]);
                set_cursor(107,19); printf(" %d",keterangan[ke-1][0]);
                set_cursor(107,21); printf(" %d",keterangan[ke=1][1]);
                set_cursor(107,23); printf(" %d",keterangan[ke-1][2]);
                    cek++;
                    Sleep(4000); system("cls");
            }else{
                set_cursor(37,27); printf(">>>>>> MOHON MAAF DATA YANG INGIN ANDA LIHAT MELEBIHI DATA YANG ANDA INPUTKAN");
                set_cursor(37,28); printf(">>>>>>>>> SILAHKAN KEMBALI UNTUK MELIHAT DATA SISWA LAINNYA");
                set_cursor(37,30); printf(">>>>>>>>> Tekan sembarang untuk kembali ke menu awal"); getch(); menu();
            }
        }else{
            set_cursor(21, 18); printf("INPUTAN TIDAK SESUAI"); Sleep(500);system("cls");
        }
    }
        break;   
    case '7':
    system("cls");
    char pilih3;
    do{
        kotak(50, 0, 5, 10); set_cursor(5, 8); printf("Anda Yakin Mau Keluar Dari Program?(Y/T) ");
        kotak(62, 0, 13, 15); set_cursor(14, 13); printf("Masukan pilihan anda       : "); pilih3=getche(); 
    if(pilih3=='Y'||pilih3=='y'){
        registrasi();
    }else if(pilih3 == 't' || pilih3 =='T'){
      	system("cls"); menu();
    }else{
        kotak(62, 0, 13, 15); set_cursor(43, 13); printf("Inputan yang anda masukan salah"); Sleep(50); system("cls");
    }
    }while(pilih3 !='y' || pilih3 !='Y' || pilih3 != 't' || pilih3 !='T');   
        break;
    default:
        set_cursor(92,28); printf("          ");
        set_cursor(65,31); printf("Anda hanya dapat menginputkan angka 1,2,3,4,5,6 dan 7");
    }
}
}while(true);
}

void pindahan(){
    sekul();
    bingkai();
    set_text_color(0);
    registrasi();
}
//================================================= REGISTRASI =====================================================
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void registrasi(){
char pilih2;
char pilih3;
int ps;
bingkai();
set_text_color(0);
do{
set_text_color(0);
kotak(40, 4, 40, 12);
kotak(25, 4, 10, 20);
kotak(25, 3, 8, 20);
kotak(25, 4, 47, 20);
kotak(25, 3, 45, 20);
kotak(25, 4, 85, 20);
kotak(25, 3, 83, 20);
kotak(26, 0, 80, 35);
set_text_color(0);
set_cursor(55,14); printf("MENU AWAL");
set_cursor(12,21); printf("1.Registrasi");Sleep(10);
set_cursor(49,21); printf("2.login");Sleep(10);
set_cursor(87,21); printf("3.Log Out");Sleep(10);
set_cursor(85,33); printf("Masukan Pilihan:"); pilih2=getche(); 
if(pilih2=='1'){
    bingkai();
    set_text_color(0);
    system("cls");
    set_cursor(2,15);   printf(">>> Pembuatan akun bisa menggunakan huruf kecil dan angka,"); Sleep(1000);
    set_cursor(2,16);   printf(">>> namun tidak dapat menggunakan angka di awal nama maupun password anda,"); Sleep(1000);
    set_cursor(2,17);   printf(">>>>> penggunaan minimal 4 karakter  dan maksimal 6 karakter tanpa spasi"); Sleep(3000);
    system("cls");
    for(int a=0; a<10; a++){
    kotak(35, 8, 10, 10);
    kotak(35, 5, 15, 10);
    kotak(40, 10, 68, 7);
    kotak(40, 15, 68, 7);
    kotak(40, 5, 68, 7); 
	set_cursor(19, 12); printf("BUAT AKUN ");
	set_cursor(70, 9);  printf("Username    = "); valusername(user);
    set_cursor(70, 14); printf("Password    = "); valusername(pass);
	set_cursor(70, 19); printf("Verifikasi  = "); valusername(verivikasi);
    getchar();
    if(strcmp(pass,verivikasi)==0){
        system("cls");
      for(int a=0; a<5; a++){
        set_text_color(a);
        set_cursor(19, 8); printf("============================================");Sleep(30);
		set_cursor(19, 9); printf("=                                          =");Sleep(30);
		set_cursor(19, 10); printf("=                                          =");Sleep(30);
		set_cursor(19, 11); printf("              SELAMAT %s                ",user);Sleep(10);
		set_cursor(19, 12); printf("=                                          =");Sleep(10);
		set_cursor(19, 13); printf("=                                          =");Sleep(10);
		set_cursor(19, 14); printf("        REGISTRASI ANDA BERHASIL            ");Sleep(50);
        set_cursor(19, 15); printf("                                            ");Sleep(50);
		set_cursor(19, 16); printf("=   SILAHKAN KEMBALI KE MENU AWAL UNTUK    =");Sleep(10);
		set_cursor(19, 17); printf("=                                          =");Sleep(10);
	    set_cursor(19, 18); printf("         MELANJUTKAN KE MENU LOGIN          ");Sleep(10);
		set_cursor(19, 19); printf("=                                          =");Sleep(10);
	    set_cursor(19, 20); printf("=                                          =");Sleep(10);
	    set_cursor(19, 21); printf("============================================");Sleep(10);
      Sleep(1);
      }
        for(int a=1; a<=100;a++){
			set_cursor(19,23); printf("MOHON TUNGGU SEBENTAR %d %%",a);Sleep(55);
        }   system("cls");
            registrasi();
    }else{
        set_cursor(10, 20); printf("=====================================");Sleep(50);
        set_cursor(10, 21); printf("-                                   -");Sleep(50);
   		set_cursor(10, 22); printf("-       Inputan Password            -");Sleep(50);
      	set_cursor(10, 23); printf("-   dan Verivikasi yang Anda        -");Sleep(50);
      	set_cursor(10, 24); printf("-       Masukan Harus Sama          -");Sleep(50);
        set_cursor(10, 25); printf("-                                   -");Sleep(50);
      	set_cursor(10, 26); printf("=====================================");Sleep(50);
        kotak(43, 0, 68, 27); set_cursor(68, 25); printf("KEMBALI KE MENU AWAL? (Y/T)   : ");
        set_cursor(100, 25); pilih3=getche(); 
        if(pilih3=='y' || pilih3== 'Y'){
            system("cls"); registrasi(); 
        }else if(pilih3=='t' || pilih3== 'T'){
            system("cls");
        }else{
            kotak(43, 0, 68, 27); set_cursor(100, 25); printf("Pilihan salah"); Sleep(50);
                set_cursor(100, 25); printf("                 ");
                set_cursor(83, 9); printf("                         ");
                set_cursor(80, 14); printf("                        ");
                set_cursor(84, 19); printf("                        ");
        }
    }
}
}else if(pilih2 =='2'){
    system("cls"); login();
}else if(pilih2 == '3'){
    finish();   
}else{
    set_text_color(0);
    set_cursor(85,33); printf("INPUTAN INVALID    "); Sleep(10); 
}
}while(true);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//========================================  KATA SANDI/PIN  ==============================================

void login(){
char user2[10];
char pass2[10];
char pilih3;
char nex;
kotak(80, 4, 20, 8); set_cursor(27,10); printf("ISI DATA DIBAWAH INI DENGAN BENAR UNTUK MASUK KE MENU BERIKUTANYA\n");
kotak(30, 0, 20, 17); set_cursor(20,15); printf("USERNAME    : "); valusername(user2);
kotak(30, 0, 20, 21); set_cursor(20,19); printf("PASSWORD    : "); valusername(pass2);
if((strcmp(user,user2)==0) &&  (strcmp(pass,pass2)==0)){
    system("cls");
    set_cursor(30,10);  printf("============================================");Sleep(10);
    set_cursor(30,11);  printf("=                                          =");Sleep(10);
	set_cursor(30,12); printf("=                                          =");Sleep(10);
	set_cursor(30,13); printf("=           SELAMAT ANDA                   =");Sleep(10);
	set_cursor(30,14); printf("=                                          =");Sleep(10);
	set_cursor(30,15); printf("=                                          =");Sleep(10);
	set_cursor(30,16); printf("=       BERHASIL LOGIN DI E-RAPORT         =");Sleep(10);
	set_cursor(30,17); printf("=                                          =");Sleep(10);
    set_cursor(30,18); printf("=                                          =");Sleep(10);
	set_cursor(30,19); printf("=                                          =");Sleep(10);
    set_cursor(30,20); printf("=   SELAMAT MENGGUNAKAN PROGRAM INI        =");Sleep(10);
	set_cursor(30,21); printf("=                                          =");Sleep(10);
	set_cursor(30,22); printf("=                                          =");Sleep(10);
	set_cursor(30,23); printf("============================================\n");Sleep(2000); system("cls");
for(int a=1; a<=6; a++){
    set_text_color(a);
    set_cursor(18,4);printf("---------------------------------------------------------------------------------------");  Sleep(1);
    set_cursor(18,5);printf("    																			        "); Sleep(1);
    set_cursor(18,6);printf("-                                          %c%c                                         -",219,219);  Sleep(1);
    set_cursor(18,7);printf("-                                       %c%c%c%c%c%c%c%c                                      -" ,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,8);printf("-                                    %c%c%c%c%c%c%c%c%c%c%c%c%c%c                                   -",219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,9);printf("-                                  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                                -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,10);printf("-                               %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                             -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,11);printf("-                            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                          -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,12);printf("-                         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                       -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,13);printf("-                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,14);printf("-                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,15);printf("-                         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                       -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,16);printf("-                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                        -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,17);printf("-                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                         -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,18);printf("-                            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                          -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,19);printf("-                             %c%c%c%c====================%c%c%c%c%c                           -",219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,20);printf("-                              %c%c  TUT WURI HANDAYANI  %c%c%c                            -",219,219,219,219,219);  Sleep(1);
    set_cursor(18,21);printf("-                               %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                             -",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);  Sleep(1);
    set_cursor(18,22);printf("-                               =======================                               -");  Sleep(1);
    set_cursor(18,23);printf("-                                                                                     -");  Sleep(1);
    set_cursor(18,24);printf("-                      KEMENTERIAN AGAMA REPUBLIK INDONESIA                           -");  Sleep(1);
    set_cursor(18,25);printf("-                               PROGRAM E - RAPORT                                    -");  Sleep(1);
    set_cursor(18,26);printf("-                  Tingkat Sekolah Menengah Kejuruan Negeri(SMKN)                     -");  Sleep(1);
    set_cursor(18,27);printf("-                                   Tahun 2022                                        -");  Sleep(1);
    set_cursor(18,28);printf("                    CREATED SUCI AMANAH || SUCIIAMNH01@GMAIL.COM                       ");  Sleep(1);
    set_cursor(18,29);printf("---------------------------------------------------------------------------------------");  Sleep(1);
        Sleep(1);
}
for(int a=1; a<=100;a++){
	set_cursor(27,31); printf("MOHON TUNGGU SEBENTAR %d %%",a);Sleep(30);
}   system("cls"); menu();
}else{
    system("cls");
	set_cursor(27,10); printf("============================================");Sleep(300);
	set_cursor(27,11); printf("=                                          =");Sleep(300);
	set_cursor(27,12); printf("=                                          =");Sleep(300);
	set_cursor(27,13); printf("=               MOHON MAAF                 =");Sleep(50);
	set_cursor(27,14); printf("=                                          =");Sleep(50);
	set_cursor(27,15); printf("=          USERNAME ATAU PASSWORD          =");Sleep(50);
	set_cursor(27,16); printf("=                                          =");Sleep(50);
	set_cursor(27,17); printf("=               ANDA SALAH                 =");Sleep(50);
    set_cursor(27,18); printf("=                                          =");Sleep(50);
	set_cursor(27,19); printf("=        ATAU ANDA BELUM TERDAFTAR         =");Sleep(100);
    set_cursor(27,20); printf("=                                          =");Sleep(300);
    set_cursor(27,21); printf("=           HARAP COBA LAGI....            =");Sleep(500);
    set_cursor(27,22); printf("=                                          =");Sleep(1000);
	set_cursor(27,23); printf("============================================");Sleep(1000);
}system("cls");
  do{
      set_text_color(0);
    kotak(60, 4, 18, 8); set_cursor(23,10); printf("1. Tekan 1 untuk kembali ke menu login");
    kotak(60, 4, 18, 14); set_cursor(23,16); printf("2. Tekan 2 untuk registrasi ulang");
    kotak(60, 4, 18, 19); set_cursor(23,21); printf("3. Tekan 3 untuk keluar dari program");
    kotak(60, 4, 18, 24); set_cursor(23,26); printf("MASUKAN PILIHAN        : "); pilih3=getche(); 
    if(pilih3 =='1'){
        system("cls");
        login();
    }else if(pilih3 =='2'){
        system("cls"); registrasi();
    }else if(pilih3 == '3'){
        system("cls"); finish();
    }else{
        set_cursor(48, 26); printf("Pilihan salah"); Sleep(50); 
        set_cursor(48, 26); printf("                           ");
    }
  }while(pilih3!='1' || pilih3!='2' || pilih3!='3');    
 }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//==============================================JUDUL BESAR==================================================

void kepala(){
    set_cursor(51,2); printf("SELAMAT DATANG DI\n");
    set_cursor(51,3); printf("APLIKASI E-RAPORT\n");
    set_cursor(42,4); printf("TINGKAT SEKOLAH SD/SMP/SMA SEDERAJAT\n");
    set_cursor(23,5); printf("Diharapkan Dapat Membantu dan Mempermudah Pencatatan dan Rekap Nilai Siswa\n");   
}
//===========================================================================================================
void sekul(){
    for(int a=0; a<10; a++){
 set_text_color(a);
 set_cursor(3,10); printf("                      88                                  88                     ;-;             "); Sleep(10);
 set_cursor(3,11); printf("                      88                                  88                     |#|             "); Sleep(10);
 set_cursor(3,12); printf("                      88                                  88        =====       |===|            "); Sleep(10);
 set_cursor(3,13); printf(" ,adPPYba,  ,adPPYba, 88,dPPYba,   ,adPPYba,   ,adPPYba,  88         |Q|         |0|             "); Sleep(10);
 set_cursor(3,14); printf(" I8[    '' a8'     '' 88P'    '8a a8'     '8a a8'     '8a 88   .-----' '-----.   | |                  __   "); Sleep(10);
 set_cursor(3,15); printf(" `'Y8ba,   8b         88       88 8b       d8 8b       d8 88  '____[SCHOOL]___'.=====                ()))  "); Sleep(10);
 set_cursor(3,16); printf(" aa    ]8I '8a,   ,aa 88       88 '8a,   ,a8' '8a,   ,a8' 88   | [] .-.-. [] | _||_||_              (((()) "); Sleep(10);
 set_cursor(3,17); printf(" `'YbbdP''  `'Ybbd8'' 88       88  `'YbbdP''   `'YbbdP''  88 ..|____|_|_|____|.|......|...............)(..."); Sleep(10);
 Sleep(100);
 system("cls");
}
}
//=====================================================================================================================
//====================================================  FUNGSI MAIN  ==================================================

void main(){
    //pindahan();
    //menu();
    login();
getch();
}
