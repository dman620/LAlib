//Programmer: Derek Mandl
//this is the implementation file for LAlib.h
//see LAlib.h for more information.
//it houses a main only for debugging purposes

#include "LAlib.h"


//GETTERS:
pair<int, int> Matrix::getOrder(){
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

//this is for debugging purposes
//this is where I am testing all functions and classes
int main(){
  Matrix matrix1;
  Matrix matrix2;
  Matrix matrix3;

  matrix1.fillMatrixI(5, 5, cin);
  matrix2.fillMatrixI(2, 4, cin);
  matrix3.fillMatrixI(4, 1, cin);

  matrix1.print(cout);
  cout << '\n';
  matrix2.print(cout);
  cout << '\n';
  matrix3.print(cout);
  cout << '\n';
  //it works!

  
  return 0;
}
