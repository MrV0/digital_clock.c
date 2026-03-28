#include <stdio.h>
#include <ctype.h>

// Maximum number of input characters
#define MAX_INPUT_COUNT 10

// Function declarations
void clear_output_buffer(void);
void process_input(int value, int position);
void print_output(void);

// 7‑segment mapping for digits and letters
const int segment_map[13][7] =
       { { 1, 1, 1, 1, 1, 1, 0},   /* number 0 */
         { 0, 1, 1, 0, 0, 0, 0},   /* number 1 */
         { 1, 1, 0, 1, 1, 0, 1},   /* number 2 */
         { 1, 1, 1, 1, 0, 0, 1},   /* number 3 */
         { 0, 1, 1, 0, 0, 1, 1},   /* number 4 */
         { 1, 0, 1, 1, 0, 1, 1},   /* number 5 */
         { 1, 0, 1, 1, 1, 1, 1},   /* number 6 */
         { 1, 1, 1, 0, 0, 0, 0},   /* number 7 */
         { 1, 1, 1, 1, 1, 1, 1},   /* number 8 */
         { 1, 1, 1, 1, 0, 1, 1},   /* number 9 */
         { 1, 1, 1, 0, 1, 1, 1},   /* letter A */
         { 1, 0, 0, 1, 1, 1, 0},   /* letter C */
         { 1, 0, 0, 0, 1, 1, 1}    /* letter F */
       };

// Output buffer for printing
char output[4][MAX_INPUT_COUNT * 4];

// Segment positions (row, col)
const int segment_position[7][2] = {
       { 0, 1},    /* segment 0 */
       { 1, 2},    /* segment 1 */
       { 2, 2},    /* segment 2 */
       { 2, 1},    /* segment 3 */
       { 2, 0},    /* segment 4 */
       { 1, 0},    /* segment 5 */
       { 1, 1}     /* segment 6 */
};

/* Clears the output buffer */
void clear_output_buffer(void) {

   char ch = ' ';
   int i, j;

   for (i = 0; i < 4; i++) {
       for (j = 0; j < MAX_INPUT_COUNT * 4; j++) {
           output[i][j] = ch;
       }
   }
}

/* Processes a single input character and sets the correct segments */
void process_input(int value, int position) {

   int i, row, col;
   for (i = 0; i < 7; i++) {
       if(segment_map[value][i]) {
           row = segment_position[i][0];
           col = segment_position[i][1] + position * 4;
           output[row][col] = i % 3 == 0 ? '_' : '|';
       }
   }
}

/* Prints the final 7‑segment output */
void print_output(void) {

   int i, j;

   for (i = 0; i < 4 ; i++) {
       for (j = 0; j < MAX_INPUT_COUNT * 4 ; j++) {
           putchar(output[i][j]);
       }
       printf("\n");
   }
}

int main(void) {

   char c;
   int count = 0;
   int value;
   clear_output_buffer();

   printf("Enter 10 characters from 0-9 and A, C, F: \n");

   // Loop to check max input count and valid characters
   while ((c = getchar()) != '\n' && count < MAX_INPUT_COUNT) {
       if (isdigit(c) || c == 'A' || c == 'C' || c == 'F') {
           switch(c){
               case 'A': value = 10;
                   break;
               case 'C': value = 11;
                   break;
               case 'F': value = 12;
                   break;
               default:
                   value = c - '0';
           }
           process_input(value, count);
           count++;
       }
   }
   print_output();

   return 0;
}


