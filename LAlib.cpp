//Programmer: Derek Mandl
//this is the implementation file for LAlib.h
//LAlib.h and LAlib.cpp comprise all of the code for this project, not including the make file
//see LAlib.h for more information.
//if you intend to use this file, you must create a main somewhere
//it will not compile by itself

#include "LAlib.h"
using namespace LAlib;

//CONSTRUCTORS:
Matrix::Matrix(unsigned n, unsigned m){
  fillMatrixE(n, m);
}

Matrix::Matrix(unsigned n, unsigned m, istream& in){
  fillMatrixI(n, m, in);
}

Matrix::Matrix(initializer_list<Matrix> matrices){
  fillMatrixL(matrices);
}

Matrix::Matrix(initializer_list<vector<double>> vectors){
  fillMatrixV(vectors);
}

//GETTERS:
pair<unsigned, unsigned> Matrix::getOrder()const{
  return order;
}//end func


//SETTERS:
void Matrix::setOrder(unsigned n, unsigned m){
  order = make_pair(n, m);
}//end func

void Matrix::fillMatrixE(unsigned n, unsigned m){
  //reset the matrix to empty
  reset();

  //fill the matrix to size with empty values
  for(unsigned i = 0; i < m; i++)
    data.push_back(vector<double>(n, 0.0));
  //this vector constructor fills the vectors with n values, all set to 0.0

  setOrder(n, m);
}//end func

void LAlib::Matrix::fillMatrixI(unsigned n, unsigned m, istream& in){
  //fill matrix to size with empty values first
  fillMatrixE(n, m);

  //j is first because I want to fill by row rather than by collumn.
  //this will make it easier to fill using filestreams
  for(unsigned j = 0; j < n; j++){
    for(unsigned i = 0; i < m; i++){
      in >> data[i][j];
    }//end for#2
  }//end for#1
}//end func

void Matrix::reset(){
  data.clear();
}//end func

void Matrix::fillMatrixL(initializer_list<Matrix> matrices){
  unsigned num_of_rows = matrices.begin()->order.first;
  unsigned num_of_collumns = 0;
  for(Matrix args : matrices){ //for all arguments in the init. list
    if(args.order.first != num_of_rows){
      cout << "ERROR 01 - ORDER MISMATCH\n";
      return;
    }//endif
    num_of_collumns += args.order.second;
    //this will add onto the number of collumns by 1 for a 4x1 matrix
    //or 3 for a 4x3 matrix for examples
  }//endfor
  fillMatrixE(num_of_rows, num_of_collumns);

  //this will fill the calling matrix with the initializer matrices:
  unsigned i = 0;
  for(Matrix args : matrices){
    for(unsigned j = 0; j < args.order.second; j++){
      data[i] = args.data[j];
      i++;
    }//end for j
  }//end for args
}//end func

void Matrix::fillMatrixV(initializer_list<vector<double>> vectors){
  unsigned num_of_rows = vectors.begin()->size();
  unsigned num_of_coll = 0;
  for(vector<double> args : vectors){//for all arguments in the init. list
    if(args.size() != num_of_rows){
      cout << "ERROR 01 - ORDER MISMATCH\n";
      return;
    }//endif
    num_of_coll ++;
  }//endfor
  fillMatrixE(num_of_rows, num_of_coll);

  //this will fill the calling matrix with the initializer vectors:
  unsigned i = 0;
  for (vector<double> args: vectors){
    //need to fill a matrix based on a vector here.
    data[i] = args;
    i++;
  }//end for
}//end func

void Matrix::print(ostream& out){
  order = getOrder();
  unsigned n = order.first;
  unsigned m = order.second;
  for(unsigned j = 0; j < n; j++){
    for(unsigned i = 0; i < m; i++){
      out << data[i][j]<< " ";
    }//end for#2
    cout << '\n';
  }//end for#1
}//end func

Matrix Matrix::operator* (const Matrix& m1){
  Matrix product;
  if (this->order.second != m1.order.first) {
    cout << "ERROR 01 - ORDER MISMATCH\n";
    return product;
  }
    
  //n, m is the order of the product matrix
  unsigned n = this->order.first; unsigned m =  m1.order.second;
  //unsigned t is used for iteration, it is equal to the number of collumns
  //of the first matrix, and the number of rows of the second matrix.
  //otherwise the multiplication would not be possible.
  unsigned t = this->order.second;

  product.fillMatrixE(n, m);

  //the k is on the outside because according to my CS professor,
  //"IT CAUSES FASTER CACHE" (in large matrices)
  //but it works exactly the same as if
  //the k was on the inside, so visualize it that way if you wish
  for(unsigned k = 0; k < t; k++){
    for(unsigned i = 0; i < m; i++){
      for(unsigned j = 0; j < n; j++){
	product.data[i][j] += data[k][j]*m1.data[i][k];
      }//end forj
    }//end fori
  }//end fork
  
return product;
}//end func


Matrix Matrix::operator+ (const Matrix& m1){
  Matrix result;//this matrix will store the resulting matrix of the addition

  if(this->order != m1.order){
    cout << "ERROR 01 - ORDER MISMATCH\n";
    return result;
  }
  unsigned n = this->order.first; unsigned m = this->order.second;
  //n and m are the dimensions of all matrices. (since they are the same)
  result.fillMatrixE(n, m);
  
  for(unsigned i = 0; i < m; i++){
    for(unsigned j = 0; j < n; j++){
      result.data[i][j] += data[i][j] + m1.data[i][j];
    }//end forj
  }//end fori
  return result;
}//end func

int main(){return 0;}


/*
this is how to use the fillMatrixL function

int main(){
  
  Matrix a;
  Matrix b;
  Matrix c;
 
  a.fillMatrixV({{1, 2, 3,}, {4, 5, 6}});
  b.fillMatrixV({{7, 8, 9}});
  c.fillMatrixL({a, b});

  c.print(cout);
  
  return 0;
}
this is the output:
1 4 7 
2 5 8 
3 6 9 




this is how to use the fillMatrixV function,

int main(){
  Matrix matrix1;
  Matrix matrix2;
  Matrix matrix3;

  matrix1.fillMatrixV({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  matrix2.fillMatrixV({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  
  matrix3.fillMatrixL({matrix1, matrix2});
  
  matrix1.print(cout);
  cout << '\n';
  matrix2.print(cout);
  cout << '\n';
  matrix3.print(cout);
  cout << '\n';
    
  return 0;
}
output:

1 4 7 
2 5 8 
3 6 9 

1 4 7 
2 5 8 
3 6 9 

1 4 7 1 4 7 
2 5 8 2 5 8 
3 6 9 3 6 9 

*/
