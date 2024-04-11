#include "ternary.h"

int main() {
   static_assert( 0_ter == 0, "failed");
   static_assert( 1_ter == 1, "failed");
   static_assert( 2_ter == 2, "failed");
   static_assert( 10_ter == 3, "failed");
   static_assert( 11_ter == 4, "failed");
   static_assert( 12_ter == 5, "failed");
   static_assert( 20_ter == 6, "failed");
   static_assert( 21_ter == 7, "failed");
   static_assert( +22_ter == 8, "failed");
   static_assert( 100_ter == 9, "failed");
   static_assert( 10001_ter == 82, "failed");
   static_assert( -10001_ter == -82, "failed");

   /* illegal begin */
   //3_ter;
   //0x0_ter;
   //1.2_ter;
   //1e2_ter;
   /* illegal end */

   return 0;
}
