#include"Queens.h"

int main()
{
  QueenBoard board(8, 8);
  board.print_complete_boards();
  board.print_complete_variants_count();

  return 0;
}
