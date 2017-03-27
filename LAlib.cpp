//Programmer: Derek Mandl
//this is the implementation file for LAlib.h
//see LAlib.h for more information.
//it houses a main only for debugging purposes

#include "LAlib.h"

//CONSTRUCTORS:
Matrix::Matrix(int n, int m){
  fillMatrixE(n, m);
}

//GETTERS:
pair<int, int> Matrix::getOrder()const{
  return order;
}//end func


//SETTERS:
void Matrix::setOrder(int n, int m){
  order = make_pair(n, m);
}//end func

void Matrix::fillMatrixE(int n, int m){
  //reset the matrix to empty
  reset();

  //fill the matrix to size with empty values
  for(int i = 0; i < m; i++)
    data.push_back(vector<double>(n, 0.0));
  //this vector constructor fills the vectors with n values, all set to 0.0

  setOrder(n, m);
}//end func

void Matrix::fillMatrixI(int n, int m, istream& in){
  //fill matrix to size with empty values first
  fillMatrixE(n, m);

  //j is first because I want to fill by row rather than by collumn.
  //this will make it easier to fill using filestreams
  for(int j = 0; j < n; j++){
    for(int i = 0; i < m; i++){
      in >> data[i][j];
    }//end for#2
  }//end for#1
}//end func

void Matrix::reset(){
  data.clear();
}//end func

void Matrix::print(ostream& out){
  order = getOrder();
  int n = order.first;
  int m = order.second;
  for(int j = 0; j < n; j++){
    for(int i = 0; i < m; i++){
      out << data[i][j]<< " ";
    }//end for#2
    cout << '\n';
  }//end for#1
}//end func

/*
void Matrix::fillMatrixF(int n, int m, string filename){

}*/

Matrix Matrix::operator* (const Matrix& m1){
  Matrix product;
  //this is the order of the product matrix
  int n = this->order.first; int m =  m1.order.second;
  product.fillMatrixE(n, m);

  //int t is used for iteration, it is equal to the number of collumns
  //of the first matrix, and the number of rows of the second matrix.
  //otherwise the multiplication would not be possible.
  int t = this->order.second;

  if (t != m1.order.first) {
    cout << "ERROR 01 - ORDER MISMATCH\n";
    return product;
  }

  //the k is on the outside because according to my CS professor,
  //"IT CAUSES FASTER CACHE" (in large matrices)
  //but it works exactly the same as if
  //the k was on the inside, so visualize it that way if you wish
  for(int k = 0; k < t; k++){
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
	product.data[i][j] += data[k][j]*m1.data[i][k];
      }//end for#3
    }//end for#2
  }//end for#2
  
return product;
}//end func








//this is for debugging purposes
//this is where I am testing all functions and classes
int main(){
  Matrix matrix1;
  Matrix matrix2;
  Matrix matrix3;
  /*multiplication test
  matrix1.fillMatrixI(2, 2, cin);
  matrix2.fillMatrixI(2, 2, cin);
  matrix3 = matrix1*matrix2;
  */

  
  matrix1.print(cout);
  cout << '\n';
  matrix2.print(cout);
  cout << '\n';
  matrix3.print(cout);
  cout << '\n';
  
  
  return 0;
}
