#ifndef QUEENS_H
#define QUEENS_H
#include<iostream>
#include<vector>
#include<deque>

class QueenBoard
{
public: 
  using type = int;
  type const QUEEN = -77;
  using VVQ = std::vector<std::vector<type>>;
private:
  int  rank_size;
  int  file_size;
  std::vector<std::vector<type>> matrix;
  // FUCTIONAL
  int print_board(bool);
  void bezero_matrix(type, type);
  bool put_north_attacks(type, type);
  void get_north_attacks(type, type);
  bool put_south_attacks(type, type);
  void get_south_attacks(type, type);
  bool put_west_attacks(type, type);
  void get_west_attacks(type, type);
  bool put_east_attacks(type, type);
  void get_east_attacks(type, type);
  bool put_north_west_attacks(type, type);
  void get_north_west_attacks(type, type);
  bool put_north_east_attacks(type, type);
  void get_north_east_attacks(type, type);
  bool put_south_west_attacks(type, type);
  void get_south_west_attacks(type, type);
  bool put_south_east_attacks(type, type);
  void get_south_east_attacks(type, type);
  bool put_queen_attacks(type, type);
  void get_queen_attacks(type, type);
  void complete_variants(type, bool flag);
  bool if_queens_complete();
public:
  QueenBoard(type, type);
  QueenBoard(const VVQ&, type, type);
  void set_matrix_params(const VVQ&, type, type);
  void result_initing_board();
  void print_complete_boards();
  void print_complete_variants_count();
 
};


#endif // QUEENS_H
