#include <stdio.h>
#include <ctype.h>

// Ορισμός σταθεράς
#define megistos_arithmos_eisodou 10

// Δήλωση συναρτήσεων
void adiasma_pinaka_eksodos(void);
void epeksergasia_eisodou(int eisodos, int thesi);
void ektuposi_eksodou(void);

// Δημιουργία πίνακα των αριθμών και των γραμμάτων
const int kommatia_endeikti[13][7] =
       { { 1, 1, 1, 1, 1, 1, 0},   /*αριθμος 0*/
         { 0, 1, 1, 0, 0, 0, 0},   /*αριθμος 1*/
         { 1, 1, 0, 1, 1, 0, 1},   /*αριθμος 2*/
         { 1, 1, 1, 1, 0, 0, 1},   /*αριθμος 3*/
         { 0, 1, 1, 0, 0, 1, 1},   /*αριθμος 4*/
         { 1, 0, 1, 1, 0, 1, 1},   /*αριθμος 5*/
         { 1, 0, 1, 1, 1, 1, 1},   /*αριθμος 6*/
         { 1, 1, 1, 0, 0, 0, 0},   /*αριθμος 7*/
         { 1, 1, 1, 1, 1, 1, 1},   /*αριθμος 8*/
         { 1, 1, 1, 1, 0, 1, 1},   /*αριθμος 9*/
         { 1, 1, 1, 0, 1, 1, 1},   /*γραμμα A*/
         { 1, 0, 0, 1, 1, 1, 0},   /*γραμμα C*/
         { 1, 0, 0, 0, 1, 1, 1}    /*γραμμα F*/
       };

// Δήλωση πίνακα για εκτύπωση των αριθμων και των γραμμάτων 
char eksodos[4][megistos_arithmos_eisodou*4];

// Δημιουργία πίνακα για αντιστοίχηση ενδείκτη
const int thesi_kommation[7][2] = {
       { 0, 1},    /* 0 */
       { 1, 2},    /* 1 */
       { 2, 2},    /* 2 */
       { 2, 1},    /* 3 */
       { 2, 0},    /* 4 */
       { 1, 0},    /* 5 */
       { 1, 1}     /* 6 */
};

/*Συνάρτηση για άδειασμα του πίνακα */
void adiasma_pinaka_eksodos(void) {

   char ch = ' ';
   int i, j;

   for (i = 0; i < 4; i++) {
       for (j = 0; j < megistos_arithmos_eisodou*4; j++) {
           eksodos[i][j] = ch;
       }
   }
}

// Συνάρτηση που ορίζει ανάλογα την είσοδο, την θέση που θα τοποθετηθούνε  _ ή  |
void epeksergasia_eisodou(int eisodos, int thesi) {

   int i, row, col;
   for (i = 0; i < 7; i++) {
       if(kommatia_endeikti[eisodos][i]) {
           row = thesi_kommation[i][0];
           col = thesi_kommation[i][1] + thesi*4;
           eksodos[row][col] = i % 3 == 0 ? '_' : '|';
       }
   }
}

// Συνάρτηση για την εκτύπωση 
void ektuposi_eksodou(void) {

   int i, j;

   for (i = 0; i < 4 ; i++) {
       for (j = 0; j < megistos_arithmos_eisodou*4 ; j++) {
           putchar(eksodos[i][j]);
       }
       printf("\n");
   }
}

int main(void) {

   char c;
   int count = 0;
   int digit;
   adiasma_pinaka_eksodos();

   printf("Eisagete 10 xarakthres apo 0-9 kai A, C, F: \n");

// Βρόχος για έλεγχο μέγιστου αριθμού εισόδου και χαρακτήρων
   while ((c = getchar()) != '\n' && count < megistos_arithmos_eisodou) {
       if (((isdigit(c)) || c == 'A') || (c=='C' || c=='F') ) {
           switch(c){
               case 'A': digit=10;
                   break;
               case 'C': digit=11;
                   break;
               case 'F': digit=12;
                   break;
               default:
                   digit = c - '0';
           }
           epeksergasia_eisodou(digit, count);
           count++;
       }
   }
   ektuposi_eksodou();

   return 0;
}


