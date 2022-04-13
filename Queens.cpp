#include "Queens.h"
//#define DEBAGER

void debager(const std::string & s, const int& l)
{
  #ifdef DEBAGER
  std::cout<< s << "  " << l << std::endl;
  #endif /* DEBAGER */
}

QueenBoard::QueenBoard(type n, type m) : rank_size{n}, file_size{m}
{
  debager(__FUNCTION__, __LINE__);
  matrix.resize(rank_size);
  for(int i{0}; i < rank_size; ++i){
    matrix[i].resize(file_size, 0);
  }
}

QueenBoard::QueenBoard(const VVQ& mat, type n, type m) : rank_size{n}, file_size{m}
{
  matrix = mat;
}

void QueenBoard::set_matrix_params(const VVQ& mat, type n, type m)
{
  rank_size = n;
  file_size = m;
  matrix = mat;
}

int QueenBoard::print_board(bool flag)
{
  debager(__FUNCTION__, __LINE__);
  static int counter = 0;
  if(flag){
    for(int i{0}; i < rank_size; ++i){
      for(int j{0}; j < file_size; ++j){
        if(matrix[i][j] == -77 ){
          std::cout << matrix[i][j] << '\t';
         } else {
           std::cout << 0 << '\t';
         }
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  } else {
    return ++counter;
  }
  return 0;
}

bool QueenBoard::put_north_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  for(int i{i_cord - 1}; i >= 0; --i ){
    if(matrix[i][j_cord] == QUEEN){
      return false;
    }
    ++matrix[i][j_cord];
  }
  return true;
}

void QueenBoard::get_north_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  for(int i{i_cord - 1}; i >= 0; --i){
    if(matrix[i][j_cord] == QUEEN){
      break;
    }
    --matrix[i][j_cord];
  }
}

bool QueenBoard::put_south_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  for(int i{i_cord + 1}; i < rank_size; ++i){
    if(matrix[i][j_cord] == QUEEN){
      return false;
    }
    ++matrix[i][j_cord];
  }
  return true;
}

void QueenBoard::get_south_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  for(int i{i_cord + 1}; i < rank_size; ++i){
    if(matrix[i][j_cord] == QUEEN){
      break;
    }
    --matrix[i][j_cord];
  }
}

bool QueenBoard::put_west_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  for(int j{j_cord - 1}; j >= 0; --j){
    if(matrix[i_cord][j] == QUEEN){
      return false;
    }
    ++matrix[i_cord][j];
  }
  return true;
}

void QueenBoard::get_west_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  for(int j{j_cord - 1}; j >= 0; --j){
    if(matrix[i_cord][j] == QUEEN){
      break;
    }
    --matrix[i_cord][j];
  }
}

bool QueenBoard::put_east_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  for(int j{j_cord + 1}; j < file_size; ++j){
    if(matrix[i_cord][j] == QUEEN){
      return false;
    }
    ++matrix[i_cord][j];
  }
  return true;
}

void QueenBoard::get_east_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  for(int j{j_cord + 1}; j < file_size; ++j){
    if(matrix[i_cord][j] == QUEEN){
      break;
    }
    --matrix[i_cord][j];
  }
}

bool QueenBoard::put_north_west_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  int const count = std::min(i_cord, j_cord);
  int i = i_cord - 1;
  int j = j_cord - 1;
  for(int c = 0 ; c < count; ++c){
    if(matrix[i][j] == QUEEN){
      return false;
    }
    ++matrix[i][j];
    --i;
    --j;
  }
  return true;
}

void QueenBoard::get_north_west_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  int const count = std::min(i_cord, j_cord);
  int i = i_cord - 1;
  int j = j_cord - 1;
  for(int c = 0; c < count; ++c){
    if(matrix[i][j] == QUEEN){
      break;
    }
    --matrix[i][j];
    --i;
    --j;
  }
}

bool QueenBoard::put_north_east_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  int const count = std::min(i_cord, static_cast<int>(matrix[0].size() - 1 - j_cord));
  int i = i_cord - 1;
  int j = j_cord + 1;
  for(int c = 0; c < count; ++c){
    if(matrix[i][j] == QUEEN){
      return false;
    }
    ++matrix[i][j];
    --i;
    ++j;
  }
  return true;
}

void QueenBoard::get_north_east_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  int const count = std::min(i_cord, static_cast<int>(matrix[0].size() - 1 - j_cord));
  int i = i_cord - 1;
  int j = j_cord + 1;
  for(int c = 0; c < count; ++c){
    if(matrix[i][j] == QUEEN){
      break;
    }
    --matrix[i][j];
    --i;
    ++j;
  }
}

bool QueenBoard::put_south_west_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  int const count = std::min(static_cast<int>(matrix.size() - 1 - i_cord), j_cord);
  int i = i_cord + 1;
  int j = j_cord - 1;
  for(int c = 0; c < count; ++c){
    if(matrix[i][j] == QUEEN){
      return false;
    }
    ++matrix[i][j];
    ++i;
    --j;
  }
  return true;
}

void QueenBoard::get_south_west_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  int const count = std::min(static_cast<int>(matrix.size() - 1 - i_cord), j_cord);
  int i = i_cord + 1;
  int j = j_cord - 1;
  for(int c = 0; c < count; ++c){
    if(matrix[i][j] == QUEEN){
      break;
    }
    --matrix[i][j];
    ++i;
    --j;
  }
}

bool QueenBoard::put_south_east_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  int const count = std::min(static_cast<int>(matrix.size() - 1 - i_cord), static_cast<int>(matrix[0].size() - 1 -j_cord));
  int i = i_cord + 1;
  int j = j_cord + 1;
  for(int c = 0; c < count; ++c){
    if(matrix[i][j] == QUEEN){
      return false;
    }
    ++matrix[i][j];
    ++i;
    ++j;
  }
  return true;
}

void QueenBoard::get_south_east_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  int const count = std::min(static_cast<int>(matrix.size() - 1 - i_cord), static_cast<int>(matrix[0].size() - 1 -j_cord));
  int i = i_cord + 1;
  int j = j_cord + 1;
  for(int c = 0; c < count; ++c){
    if(matrix[i][j] == QUEEN){
      break;
    }
    --matrix[i][j];
    ++i;
    ++j;
  }
}

bool QueenBoard::put_queen_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  std::deque<bool> bool_count(8);
  bool_count[0] = put_north_attacks(i_cord, j_cord);
  bool_count[1] = put_south_attacks(i_cord, j_cord);
  bool_count[2] = put_west_attacks(i_cord, j_cord);
  bool_count[3] = put_east_attacks(i_cord, j_cord);
  bool_count[4] = put_north_west_attacks(i_cord, j_cord);
  bool_count[5] = put_north_east_attacks(i_cord, j_cord);
  bool_count[6] = put_south_west_attacks(i_cord, j_cord);
  bool_count[7] = put_south_east_attacks(i_cord, j_cord);
  matrix[i_cord][j_cord] = QUEEN;
  for(int i{0}; i < 8; ++i){
     if(bool_count[i] == 0){
      return false;
    }
  }
  return true;;
}

void QueenBoard::get_queen_attacks(type i_cord, type j_cord)
{
  debager(__FUNCTION__, __LINE__);
  get_north_attacks(i_cord, j_cord);
  get_south_attacks(i_cord, j_cord);
  get_west_attacks(i_cord, j_cord);
  get_east_attacks(i_cord, j_cord);
  get_north_west_attacks(i_cord, j_cord);
  get_north_east_attacks(i_cord, j_cord);
  get_south_west_attacks(i_cord, j_cord);
  get_south_east_attacks(i_cord, j_cord);
  matrix[i_cord][j_cord] = 0;
}

void QueenBoard::complete_variants(type rank_index, bool flag)
{
  debager(__FUNCTION__, __LINE__);
  for(int j{0}; j < matrix[0].size(); ++j){
    if(matrix[rank_index][j] == 0){
      put_queen_attacks(rank_index, j);
      if(rank_index == matrix.size() - 1){
        print_board(flag);
      } else {
        complete_variants(rank_index + 1, flag);
      }
      get_queen_attacks(rank_index, j);
    }
  }
}

void QueenBoard::bezero_matrix(type i_cord, type j_cord)
{
  int k = j_cord;
  for(int j{j_cord}; j < matrix[0].size(); ++j){
    if(matrix[i_cord][j] == QUEEN){
     matrix[i_cord][j] = 0;
   }
  }
  for(int i{i_cord + 1}; i < matrix.size(); ++i){
    for(int j{0}; j < matrix[0].size(); ++j){
      if(matrix[i][j] == QUEEN){
        matrix[i][j] = 0;
      }
    }
  }
}
      
void QueenBoard::print_complete_boards()
{
  debager(__FUNCTION__, __LINE__);
   complete_variants(0, true);
}

void QueenBoard::print_complete_variants_count()
{
  debager(__FUNCTION__, __LINE__);
  complete_variants(0, false);
  std::cout << "COMPLETE VARIANTS COUNT FOR [" << rank_size << ", " << file_size << 
      "] MATRIX IS - " << print_board(false) - 1 << std::endl;
}

bool QueenBoard::if_queens_complete()
{
  for(int i{0}; i < matrix.size(); ++i){
    int line_counter = 0;
    for(int j{0}; j < matrix[0].size(); ++j){
      if(matrix[i][j] == QUEEN){
        ++line_counter;
        if(!(put_queen_attacks(i, j))){
          get_queen_attacks(i, j);
          bezero_matrix(i, j + 1);
          complete_variants(i, true);
          return false;
        }
      }
    }
    if(line_counter == 0){
      bezero_matrix(i, 0);
      complete_variants(i, true);
      return false;
    }
  }
  return true;
}

void QueenBoard::result_initing_board()
{
  if(if_queens_complete()){
    std::cout << "YOUR BOARD COMBINATION IS COMPLETE !!" << std::endl;
  } else {
    std::cout << "YOUR COMBINATION IS WRONG, MOST SAME COMBINATIONS IS UPPER" << std::endl;
  }
}

    

