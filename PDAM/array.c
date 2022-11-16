//Pande Komang Indah Triroshanti
//2205551053

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//#define Administrasi 5000
const int Administrasi = 5000;
#define denda 0.1*biaya


int BPM[2] = {1000,2000}; // BPM untuk kelompok rumah tangga = 1000
                            // BPM untuk kelompok niaga = 2000
float tarif[32][3]= {{1780, 2060, 5880},     //D1 - 1 
                    {2060, 2340, 5940},      //D1 - 2
                    {2340, 2620, 6000},      //D2 - 1
                    {2620, 2900, 6060},      //D2 - 2
                    {2900, 3180, 6120},      //D3 - 1
                    {3180, 3460, 6180},      //D3 - 2
                    {3460, 3740, 6240},      //D4 - 1
                    {3740, 4020, 6300},      //D4 - 2 
                    {6340, 9200, 9600},      //D1 - 3
                    {6420, 9350, 9650},      //D1 - 4
                    {6490, 9500, 9800},      //D2 - 3
                    {6570, 9650, 9950},      //D2 - 4
                    {6640, 9800, 10100},     //D3 - 3
                    {6720, 9950, 10250},     //D3 - 4
                    {6790, 10100, 10400},    //D4 - 3
                    {6870, 10250, 10550},    //D4 - 4
                    {6940, 10400, 10700},    //D5 - 1
                    {7020, 10550, 10850},    //D5 - 2
                    {7090, 10700, 11000},    //D5 - 3
                    {7170, 10850, 11150},    //D5 - 4 
                    {9200, 9850, 10950},     //E1 - 1
                    {9500, 10150, 11250},    //E1 - 2
                    {9800, 10450, 11550},    //E1 - 3
                    {10100, 10750, 11850},   //E1 - 4
                    {10400, 11050, 12150},   //E2 - 1
                    {10700, 11350, 12550},   //E2 - 2
                    {11000, 11650, 13150},   //E2 - 3
                    {11300, 11950, 13950},   //E2 - 4
                    {11600, 12250, 14750},   //E3 - 1
                    {11900, 12550, 15050},   //E3 - 2
                    {12200, 12850, 15850},   //E3 - 3
                    {12500, 13150, 16650}};  //E3 - 4

char golongan[32][5] = {"D1-1",  "D1-2", 
                        "D2-1",  "D2-2",
                        "D3-1",  "D3-2",
                        "D4-1",  "D4-2",  
                        "D1-3",  "D1-4", 
                        "D2-3",  "D2-4", 
                        "D3-3",  "D3-4", 
                        "D4-3",  "D4-4", 
                        "D5-1",  "D5-2",  "D5-3",  "D5-4", 
                        "E1-1",  "E1-2",  "E1-3",  "E1-4",
                        "E2-1",  "E2-2",  "E2-3",  "E2-4",
                        "E3-1",  "E3-2",  "E3-3",  "E3-4"};            

int kelompok();
int menu1();
void D1_1 ();
void D1_2 ();
void D2_1 ();
void D2_2 ();
void D3_1 ();
void D3_2 ();
void D4_1 ();
void D4_2 ();
int menu2();
void D1_3 ();
void D1_4 ();
void D2_3 ();
void D2_4 ();
void D3_3 ();
void D3_4 ();
void D4_3 ();
void D4_4 ();
void D5_1 ();
void D5_2 ();
void D5_3 ();
void D5_4 ();
int menu3();
void E1_1 ();
void E1_2 ();
void E1_3 ();
void E1_4 ();
void E2_1 ();
void E2_2 ();
void E2_3 ();
void E2_4 ();
void E3_1 ();
void E3_2 ();
void E3_3 ();
void E3_4 ();
int proses(int index_golongan, int index_tarif, int index_bpm);
int cetak_bukti_pembayaran(char nama [50],float rek, int index_golongan, int tanggal, float pemakaian, int Administrasi, int BPM, float output_tarif, float biaya, float output_denda, float total_bayar);
void ulang();

int main(){
	char username [15];
	char password [8];
	
	system ("clear");
	printf("\n\t==============================================================\n");
	printf("\n\t||               S E L A M A T  D A T A N G                 ||\n");
	printf("\n\t``````````````````````````````````````````````````````````````\n");
	printf("\n\t||            SILAHKAH LOG IN TERLEBIH DAHULU               ||\n");
	printf("\n\t==============================================================\n");
	printf("\n\t  Masukkan username     :");
	scanf("%s", username);
	printf("\n\t  Masukkan password     :");
	fflush(stdin);
	scanf("%s", password);
	if ((strcmp(username, "admin") == 0) && (strcmp(password, "pdam") ==0)){
		kelompok();
		
	}else {
        getchar();
        printf("\n\t```````````````````````````````````\n");
		printf("\n\t PASSWORD atau USERNAME SALAH!");
        printf("\n\n\t [Tekan enter untuk mencoba kembali]");
        getchar();
        main();
		
	}
	return 0;
}

int kelompok(){
	int golongan;
	system ("clear");
	printf("\n\t==================================================");
    printf("\n\t||        PEMBAYARAN PEMAKAIAN AIR PDAM         ||");
    printf("\n\t||----------------------------------------------||");
    printf("\n\t||     K E L O M P O K  P E L A N G G A N       ||");
    printf("\n\t||----------------------------------------------||");
    printf("\n\t|| [1] Rumah Tangga Bersubsidi                  ||");                           
    printf("\n\t|| [2] Rumah Tangga Non Subsidi                 ||");
    printf("\n\t|| [3] Niaga                                    ||");
	printf("\n\t==================================================");
	printf("\n\t Masukkan pilihan anda [1][2][3] : ");
	while (scanf("%d", &golongan)==0 || golongan < 1 || golongan > 3){
		printf("\t\t----------------------------------------------\n");
        printf("\t\tKarakter yang Anda inputkan salah!\n");
        printf("\t\tMohon inputkan pilihan yang benar.\n");
        printf("\t\t----------------------------------------------\n");
        printf("\t\tInputkan pilihan anda:");
        while(getchar()!='\n');
	}
	
	if (golongan==1){
		menu1();
	}else if (golongan==2){
		menu2();
	}else {
		menu3();
	}
	 return 0;
}	

int menu1(){
	int rts;
	system ("clear");
	printf("\n\t==========================================================================");
    printf("\n\t||                     RUMAH TANGGA BERSUBSIDI                          ||");
    printf("\n\t||----------------------------------------------------------------------||");
    printf("\n\t||               I N S T R U K S I  P E L A N G G A N                   ||");
    printf("\n\t||----------------------------------------------------------------------||");
    printf("\n\t||       Pilihlah sesuai dengan kondisi tempat tinggal anda!            ||");
    printf("\n\t||----------------------------------------------------------------------||");
    printf("\n\t||  No	|  Lebar jalan (termasuk got & berm) | Daya listrik |  Golongan ||");
    printf("\n\t||----------------------------------------------------------------------||");
    printf("\n\t||  [1] |             0-3.99 meter           |     450 VA   |    D1-1   ||"); 
	printf("\n\t||  [2] |             0-3.99 meter           |     900 VA   |    D1-2   ||");                           
    printf("\n\t||  [3] |             4-6.99 meter           |     450 VA   |    D2-1   ||");
    printf("\n\t||  [4] |             4-6.99 meter           |     900 VA   |    D2-2   ||");
    printf("\n\t||  [5] |              7-10 meter            |     450 VA   |    D3-1   ||");
    printf("\n\t||  [6] |              7-10 meter            |     900 VA   |    D3-2   ||");
    printf("\n\t||  [7] |              >10 meter             |     450 VA   |    D4-1   ||");
    printf("\n\t||  [8] |              >10 meter             |     900 VA   |    D4-2   ||");
	printf("\n\t==========================================================================");
	printf("\n\t Masukkan pilihan anda [1][2][3][4][5][6][7][8] : ");
		while (scanf("%d", &rts)==0 || rts < 1 || rts > 8){
		printf("\t\t----------------------------------------------\n");
        printf("\t\tKarakter yang Anda inputkan salah!\n");
        printf("\t\tMohon inputkan pilihan yang benar.\n");
        printf("\t\t----------------------------------------------\n");
        printf("\t\tInputkan pilihan anda:");
        while(getchar()!='\n');
	}
    if (rts==1){
		D1_1();
	}else if(rts==2){
		D1_2();
	}else if(rts==3){
		D2_1();
	}else if(rts==4){
		D2_2();
	}else if(rts==5){
		D3_1();
	}else if (rts==6){
		D3_2();
	}else if (rts==7){
		D4_1();
	}else{
		D4_2();
	}
    }
void D1_1 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA BERSUBSIDI              ||");
    printf("\n\t||                  GOLONGAN D1-1                    ||");
    printf("\n\t=======================================================");
    proses(0,0,0);
}
void D1_2 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA BERSUBSIDI              ||");
    printf("\n\t||                  GOLONGAN D1-2                    ||");
    printf("\n\t=======================================================");
    proses(1,1,0);
}
void D2_1 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA BERSUBSIDI              ||");
    printf("\n\t||                  GOLONGAN D2-1                    ||");
    printf("\n\t=======================================================");
    proses(2,2,0);
}
void D2_2 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA BERSUBSIDI              ||");
    printf("\n\t||                  GOLONGAN D2-2                    ||");
    printf("\n\t=======================================================");
    proses(3,3,0);
}
void D3_1 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA BERSUBSIDI              ||");
    printf("\n\t||                  GOLONGAN D3-1                    ||");
    printf("\n\t=======================================================");
    proses(4,4,0);
}
void D3_2 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA BERSUBSIDI              ||");
    printf("\n\t||                  GOLONGAN D3-2                    ||");
    printf("\n\t=======================================================");
    proses(5,5,0);
}
void D4_1 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA BERSUBSIDI              ||");
    printf("\n\t||                  GOLONGAN D4-1                    ||");
    printf("\n\t=======================================================");
    proses(6,6,0);
}
void D4_2 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA BERSUBSIDI              ||");
    printf("\n\t||                  GOLONGAN D4-2                    ||");
    printf("\n\t=======================================================");
    proses(7,7,0);
}

int menu2(){
	int rtn;
	system ("clear");
	printf("\n\t===============================================================================");
    printf("\n\t||                        RUMAH TANGGA NON-SUBSIDI                           ||");
    printf("\n\t||---------------------------------------------------------------------------||");
    printf("\n\t||                  I N S T R U K S I  P E L A N G G A N                     ||");
    printf("\n\t||---------------------------------------------------------------------------||");
    printf("\n\t||          Pilihlah sesuai dengan kondisi tempat tinggal anda!              ||");
    printf("\n\t||---------------------------------------------------------------------------||");
    printf("\n\t||  No	|            Deskripsi golongan           | Daya listrik |  Golongan ||");
    printf("\n\t||---------------------------------------------------------------------------||");
    printf("\n\t||  [1] |terdapat jalan yg lebarnya 0-3.99 meter  |    1300 VA   |    D1-3   ||"); 
	printf("\n\t||  [2] |terdapat jalan yg lebarnya 0-3.99 meter  |   >1300 VA   |    D1-4   ||");                           
    printf("\n\t||  [3] |terdapat jalan yg lebarnya 4-6.99 meter  |    1300 VA   |    D2-3   ||");
    printf("\n\t||  [4] |terdapat jalan yg lebarnya 4-6.99 meter  |   >1300 VA   |    D2_4   ||");
    printf("\n\t||  [5] |terdapat jalan yg lebarnya 7-10 meter    |    1300 VA   |    D3-3   ||");
    printf("\n\t||  [6] |terdapat jalan yg lebarnya 7-10 meter    |   >1300 VA   |    D3-4   ||");
    printf("\n\t||  [7] |terdapat jalan yg lebarnya >10 meter     |    1300 VA   |    D4-3   ||");
    printf("\n\t||  [8] |terdapat jalan yg lebarnya >10 meter     |   >1300 VA   |    D4-4   ||");
    printf("\n\t||  [9] |selain tempat tinggal jg berupa usaha    |     450 VA   |    D5-1   ||");
    printf("\n\t||  [10]|selain tempat tinggal jg berupa usaha    |     900 VA   |    D5-2   ||");
    printf("\n\t||  [11]|selain tempat tinggal jg berupa usaha    |    1300 VA   |    D5-3   ||");
    printf("\n\t||  [12]|selain tempat tinggal jg berupa usaha    |   >1300 VA   |    D5-4   ||");
	printf("\n\t===============================================================================");
	printf("\n\t Masukkan pilihan anda [1][2][3][4][5][6][7][8][9][10][11][12] : ");
	while (scanf("%d", &rtn)==0 || rtn < 1 || rtn > 12){
		printf("\t\t----------------------------------------------\n");
        printf("\t\tKarakter yang Anda inputkan salah!\n");
        printf("\t\tMohon inputkan pilihan yang benar.\n");
        printf("\t\t----------------------------------------------\n");
        printf("\t\tInputkan pilihan anda:");
        while(getchar()!='\n');
	}
	if (rtn==1){
		D1_3();
	}else if(rtn==2){
		D1_4();
	}else if(rtn==3){
		D2_3();
	}else if(rtn==4){
		D2_4();
	}else if(rtn==5){
		D3_3();
	}else if (rtn==6){
		D3_4();
	}else if (rtn==7){
		D4_3();
	}else if (rtn==8){
		D4_4();
	}else if (rtn==9){
		D5_1();
	}else if (rtn==10){
		D5_2();
	}else if (rtn==11){
		D5_3();
	}else {
		D5_4();
	}
}
void D1_3 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D1-3                    ||");
    printf("\n\t=======================================================");
    proses(8,8,0);
}
void D1_4 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D1-4                    ||");
    printf("\n\t=======================================================");
    proses(9,9,0);
}
void D2_3 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D2-3                    ||");
    printf("\n\t=======================================================");
    proses(10,10,0);
}
void D2_4 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D2-4                    ||");
    printf("\n\t=======================================================");
    proses(11,11,0);
}
void D3_3 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D3-3                    ||");
    printf("\n\t=======================================================");
    proses(12,12,0);
}
void D3_4 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D3-4                    ||");
    printf("\n\t=======================================================");
    proses(13,13,0);
}
void D4_3 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D4-3                    ||");
    printf("\n\t=======================================================");
    proses(14,14,0);
}
void D4_4 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D4-4                    ||");
    printf("\n\t=======================================================");
    proses(15,15,0);
}
void D5_1 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D5-1                    ||");
    printf("\n\t=======================================================");
    proses(16,16,0);
}
void D5_2 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D5-2                    ||");
    printf("\n\t=======================================================");
    proses(17,17,0);
}
void D5_3 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D5-3                    ||");
    printf("\n\t=======================================================");
    proses(18,18,0);
}
void D5_4 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||              RUMAH TANGGA NON-SUBSIDI             ||");
    printf("\n\t||                  GOLONGAN D5-4                    ||");
    printf("\n\t=======================================================");
    proses(19,19,0);
}

int menu3(){
    int niaga;
    system ("clear");
	printf("\n\t==============================================================================================================");
    printf("\n\t||                                                 NIAGA                                                    ||");
    printf("\n\t||----------------------------------------------------------------------------------------------------------||");
    printf("\n\t||                               I N S T R U K S I  P E L A N G G A N                                       ||");
    printf("\n\t||----------------------------------------------------------------------------------------------------------||");
    printf("\n\t||                          Pilihlah sesuai dengan kondisi bidang usaha anda!                               ||");
    printf("\n\t||----------------------------------------------------------------------------------------------------------||");
    printf("\n\t||  No	|    Kategori  |                       Deskripsi                         |  Daya listrik | Golongan ||");
    printf("\n\t||----------------------------------------------------------------------------------------------------------||");
    printf("\n\t||  [1] | Niaga Kecil  | Jalan di depan usaha memiliki lebar 0-6.99 meter        |     450 VA    |   E1-1   ||");
	printf("\n\t||  [2] | Niaga Kecil  | Jalan di depan usaha memiliki lebar 0-6.99 meter        |     900 VA    |   E1-2   ||"); 
	printf("\n\t||  [3] | Niaga Kecil  | Jalan di depan usaha memiliki lebar 0-6.99 meter        |    1300 VA    |   E1-3   ||");
	printf("\n\t||  [4] | Niaga Kecil  | Jalan di depan usaha memiliki lebar 0-6.99 meter        |   >1300 VA    |   E1-4   ||");
	printf("\n\t||  [5] | Niaga Sedang | Jalan di depan usaha memiliki lebar 7-10 meter          |     450 VA    |   E2-1   ||"); 
	printf("\n\t||  [6] | Niaga Sedang | Jalan di depan usaha memiliki lebar 7-10 meter          |     900 VA    |   E2-2   ||"); 
	printf("\n\t||  [7] | Niaga Sedang | Jalan di depan usaha memiliki lebar 7-10 meter          |    1300 VA    |   E2-3   ||");
	printf("\n\t||  [8] | Niaga Sedang | Jalan di depan usaha memiliki lebar 7-10 meter          |   >1300 VA    |   E2-4   ||");                            
    printf("\n\t||  [9] | Niaga Besar  | Jalan di depan usaha memiliki lebar >10 meter           |     450 VA    |   E3-1   ||");
    printf("\n\t|| [10] | Niaga Besar  | Jalan di depan usaha memiliki lebar >10 meter           |     900 VA    |   E3-2   ||");
    printf("\n\t|| [11] | Niaga Besar  | Jalan di depan usaha memiliki lebar >10 meter           |   >1300 VA    |   E3-3   ||");
    printf("\n\t|| [12] | Niaga Besar  | Jalan di depan usaha memiliki lebar >10 meter           |    1300 VA    |   E3-4   ||");
	printf("\n\t==============================================================================================================");
	printf("\n\t Masukkan pilihan anda [1][2][3][4][5][6][7][8][9][10][11][12]: ");
	while (scanf("%d", &niaga)==0 || niaga < 1 || niaga > 12){
		printf("\t\t----------------------------------------------\n");
        printf("\t\tKarakter yang Anda inputkan salah!\n");
        printf("\t\tMohon inputkan pilihan yang benar.\n");
        printf("\t\t----------------------------------------------\n");
        printf("\t\tInputkan pilihan anda:");
        while(getchar()!='\n');
	} 
	
	if (niaga==1){
		E1_1();
	}else if(niaga==2){
		E1_2();
	}else if(niaga==3){
		E1_3();
	}else if(niaga==4){
		E1_4();
	}else if(niaga==5){
		E2_1();
	}else if (niaga==6){
		E2_2();
	}else if (niaga==7){
		E2_3();
	}else if (niaga==8){
		E2_4();
	}else if (niaga==9){
		E3_1();
	}else if (niaga==10){
		E3_2();;
	}else if (niaga==11){
		E3_3();
	}else{
		E3_4();
	}
}
void E1_1 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  K E C I L                ||");
    printf("\n\t||                  GOLONGAN E1-1                    ||");
    printf("\n\t=======================================================");
    proses(20,20,1);
}
void E1_2 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  K E C I L                ||");
    printf("\n\t||                  GOLONGAN E1-2                    ||");
    printf("\n\t=======================================================");
    proses(21,21,1);
}
void E1_3 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  K E C I L                ||");
    printf("\n\t||                  GOLONGAN E1-3                    ||");
    printf("\n\t=======================================================");
    proses(22,22,1);
}
void E1_4 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  K E C I L                ||");
    printf("\n\t||                  GOLONGAN E1-4                    ||");
    printf("\n\t=======================================================");
    proses(23,23,1);
}
void E2_1 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  S E D A N G              ||");
    printf("\n\t||                  GOLONGAN E2-1                    ||");
    printf("\n\t=======================================================");
    proses(24,24,1);
}
void E2_2 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  S E D A N G              ||");
    printf("\n\t||                  GOLONGAN E2-2                    ||");
    printf("\n\t=======================================================");
    proses(25,25,1);
}
void E2_3 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  S E D A N G              ||");
    printf("\n\t||                  GOLONGAN E2-3                    ||");
    printf("\n\t=======================================================");
    proses(26,26,1);
}
void E2_4 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  S E D A N G              ||");
    printf("\n\t||                  GOLONGAN E2-4                    ||");
    printf("\n\t=======================================================");
    proses(27,27,1);
}
void E3_1 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  B E S A R                ||");
    printf("\n\t||                  GOLONGAN E3-1                    ||");
    printf("\n\t=======================================================");
    proses(28,28,1);
}
void E3_2 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  B E S A R                ||");
    printf("\n\t||                  GOLONGAN E3-2                    ||");
    printf("\n\t=======================================================");
    proses(29,29,1);
}
void E3_3 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  B E S A R                ||");
    printf("\n\t||                  GOLONGAN E3-3                    ||");
    printf("\n\t=======================================================");
    proses(30,30,1);
}
void E3_4 (){
	system ("clear");
	printf("\n\t=======================================================");
    printf("\n\t||   P E M B A Y A R A N  R E K E N I N G  A I R     ||");
    printf("\n\t||               N I A G A  B E S A R                ||");
    printf("\n\t||                  GOLONGAN E3-4                    ||");
    printf("\n\t=======================================================");
    proses(31,31,1);
}


int proses(int index_golongan, int index_tarif, int index_bpm){
    char nama [50];
    int tanggal;
    float rek, bulan_ini, bulan_lalu, pemakaian, total_bayar, output_tarif, output_denda, biaya;

    printf("\n\t Masukkan nama pelanggan  :");
    scanf("%s", &nama);
    printf("\n\t Masukkan nomor rek. PDAM :");
    while (scanf("%f", &rek)==0 ){
	    printf("\n\t----------------------------------------------\n");
        printf("\n\t       Mohon input hanya berupa angka!        \n");
        printf("\n\t----------------------------------------------\n");
        printf("\n\t Masukan no rekening yang benar :");
        while(rek=getchar() != '\n');
    }
    printf("\n\t Masukkan tanggal pembayaran :");
    while (scanf("%d", &tanggal)==0 || tanggal < 1 || tanggal > 31){
		printf("\n\t----------------------------------------------\n");
        printf("\n\t    Mohon inputkan tanggal yang benar!\n");
        printf("\n\t----------------------------------------------\n");
        printf("\n\tMasukkan tanggal pembayaran :");
        while(tanggal=getchar() != '\n');
    }
    printf("\n\t Masukan Besar Pemakaian Bulan Sebelumnya (m^3) :");
    while (scanf("%f", &bulan_lalu)==0 || bulan_lalu<0){
		printf("\n\t----------------------------------------------\n");
        printf("\n\t       Mohon input hanya berupa angka!        \n");
        printf("\n\t----------------------------------------------\n");
        printf("\n\tMasukan Besar Pemakaian Bulan Sebelumnya (m^3) :");
        while(bulan_lalu=getchar() != '\n');
    }
    printf("\n\t Masukan Besar Pemakaian Saat Ini (m^3) :");
    while (scanf("%f", &bulan_ini)==0 || bulan_ini < bulan_lalu || bulan_lalu<0 ){
		printf("\n\t---------------------------------------------------------------\n");
        printf("\n\t Besar pemakaian bulan ini pasti lebih besar dari bulan lalu! \n");
        printf("\n\t---------------------------------------------------------------\n");
        printf("\n\tMasukan Besar Pemakaian bulan ini (m^3)         :");
        while(bulan_ini=getchar() != '\n');
    }

     pemakaian = bulan_ini - bulan_lalu;

    if(tanggal<=15){
        if(pemakaian>=0 && pemakaian<=10){
            output_tarif=tarif[index_tarif][0];
            biaya=pemakaian*tarif[index_tarif][0];
            output_denda=0;
            total_bayar=Administrasi+BPM[index_bpm]+biaya;          
        }else if(pemakaian>10 && pemakaian<=20){
            output_tarif=tarif[index_tarif][1];
            biaya=pemakaian*tarif[index_tarif][1];
            output_denda=0;
            total_bayar=Administrasi+BPM[index_bpm]+biaya;           
        }else if(pemakaian>20){
            output_tarif=tarif[index_tarif][2];
            biaya=pemakaian*tarif[index_tarif][2];
            output_denda=0;
            total_bayar=Administrasi+BPM[index_bpm]+biaya;
        }
    }else if(tanggal>15){
        //isi denda
        if(pemakaian>=0 && pemakaian<=10){
            output_tarif=tarif[index_tarif][0];
            biaya=pemakaian*tarif[index_tarif][0];
            output_denda=denda;
            total_bayar=Administrasi+BPM[index_bpm]+biaya+denda;           
        }else if(pemakaian>10 && pemakaian<=20){
            output_tarif=tarif[index_tarif][1];
            biaya=pemakaian*tarif[index_tarif][1];
            output_denda=denda;
            total_bayar=Administrasi+BPM[index_bpm]+biaya+denda; 
        }else if(pemakaian>20 && pemakaian<100){
            output_tarif=tarif[index_tarif][2];
            biaya=pemakaian*tarif[index_tarif][2];
            output_denda=denda;
            total_bayar=Administrasi+BPM[index_bpm]+biaya+denda;
        }else if(pemakaian>100){
            output_tarif=tarif[index_tarif][2];
            biaya=pemakaian*tarif[index_tarif][2];
            output_denda=denda;
            total_bayar=Administrasi+BPM[index_bpm]+biaya+denda;
        }
    }
    system("clear");
    printf("\t==============================================");
    printf("\n\t||            RINCIAN TAGIHAN              ||");
    printf("\n\t==============================================");
    printf("\n\tNama Pelanggan           : %s", nama);
    printf("\n\tNo rek. PDAM             : %.0f", rek);
    printf("\n\tGolongan                 : %s", golongan[index_golongan]);
    printf("\n\tTanggal pembayaran       : %d", tanggal);
    printf("\n\tBesar Pemakaian          : %.2f m^3", pemakaian);
    printf("\n\t----------------------------------------------");
    printf("\n\tBiaya Administrasi       : Rp. %d", Administrasi);
    printf("\n\tBiaya Pemeliharaan       : Rp. %d", BPM[index_bpm]);
    printf("\n\tTarif yang Dikenakan     : Rp. %.0f/m^3", output_tarif);
    printf("\n\tBiaya Pemakaian          : Rp. %.0f", biaya);
    printf("\n\tDenda                    : Rp. %.0f", output_denda);
    printf("\n\t==============================================");
    printf("\n\tTOTAL TAGIHAN ANDA ADALAH Rp. %.2f", total_bayar);
    printf("\n\t==============================================");
    getchar();
int cetak;
    getchar();
    system("clear");
    printf("\n\t||===============================================||");
    printf("\n\t|| Apakah anda ingin mencetak bukti pembayaran ? ||");
    printf("\n\t||===============================================||");
    printf("\n\t|| 1. Ya                                         ||");
    printf("\n\t|| 2. Tidak                                      ||");
    printf("\n\t||===============================================||");
    printf("\n\tMasukkan pilihan anda : ");
    while (scanf  ("%d", &cetak)==0 || cetak<0 || cetak>2){
        printf ("\t---------------------------------------");
        printf ("\n\tKarakter yang anda inputkan salah");
        printf ("\n\tSilahkan inputkan ulang");
        printf ("\n\t---------------------------------------");
        printf("\n\tMasukkan pilihan anda : ");
        while (cetak=getchar() != '\n');
    }
    if(cetak==1){
        cetak_bukti_pembayaran(nama,rek, index_golongan, tanggal, pemakaian, Administrasi, BPM[index_bpm], output_tarif, biaya, output_denda, total_bayar);
    }else{
        ulang();
    }
}

int cetak_bukti_pembayaran(char nama [50],float rek, int index_golongan, int tanggal, float pemakaian, int Administrasi, int BPM, float output_tarif, float biaya, float output_denda, float total_bayar){
    FILE *fptr;
    fptr = fopen("Data Pelanggan.txt", "a");

     if (fptr==NULL){
        printf ("\n\tFile tidak ditemukan");
        exit(0);
    }else{
        fprintf(fptr,"\t===============================================");
        fprintf(fptr,"\n\t||      B U K T I  P E M B A Y A R A N     ||");
        fprintf(fptr,"\n\t||              TAGIHAN PDAM               ||");
        fprintf(fptr,"\n\t==============================================");
        fprintf(fptr,"\n\tNama Pelanggan           : %s", nama);
        fprintf(fptr,"\n\tNo rek. PDAM             : %.0f", rek);
        fprintf(fptr,"\n\tGolongan                 : %s", golongan[index_golongan]);
        fprintf(fptr,"\n\tTanggal pembayaran       : %d", tanggal);
        fprintf(fptr,"\n\tBesar Pemakaian          : %.2f m^3", pemakaian);
        fprintf(fptr,"\n\t----------------------------------------------");
        fprintf(fptr,"\n\tBiaya Administrasi       : Rp. %d", Administrasi);
        fprintf(fptr,"\n\tBiaya Pemeliharaan       : Rp. %d", BPM);
        fprintf(fptr,"\n\tTarif yang Dikenakan     : Rp. %.0f/m^3", output_tarif);
        fprintf(fptr,"\n\tBiaya Pemakaian          : Rp. %.0f", biaya);
        fprintf(fptr,"\n\tDenda                    : Rp. %.0f", output_denda);
        fprintf(fptr,"\n\t==============================================");
        fprintf(fptr,"\n\tTOTAL TAGIHAN ANDA ADALAH Rp. %.2f", total_bayar);
        fprintf(fptr,"\n\t==============================================");

        fclose(fptr);//tutup file
        getchar();
        printf("\n\tBukti Pembayaran telah berhasil dicetak!\n");   
        getchar();
        ulang();
    }
}

void ulang(){
    int menu;
    system("clear");
    printf("\n\t==============================================");
    printf("\n\t||                   MENU                   ||");
    printf("\n\t||==========================================||");
    printf("\n\t||Apakah anda ingin mengulang ?             ||");
    printf("\n\t|| 1. Ulangi                                ||");
    printf("\n\t|| 0. Exit                                  ||");
    printf("\n\t==============================================");
    printf("\n\tPilihan : ");
    while(scanf("%d", &menu)==0 || menu < 0 || menu > 1){
        printf("\t----------------------------------------------");
        printf("\n\t     [Mohon masukkan pilihan yang benar]");
        printf("\n\t----------------------------------------------");
        printf("\n\tPilihan : ");
        int c;
        while((c=getchar())!='\n' && c!=EOF);
    }

    if (menu==1){
        main();
    }else if(menu==0){
        system("clear");
        printf("\n\t==============================================");
        printf("\n\t||                                          ||");
        printf("\n\t||TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI||");
        printf("\n\t||           SAMPAI JUMPA KEMBALI           ||");
        printf("\n\t||                                          ||");
        printf("\n\t==============================================");
    }
}
