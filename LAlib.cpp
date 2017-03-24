//Programmer: Derek Mandl
//this is the implementation file for LAlib.h
//see LAlib.h for more information.

#include "LAlib.h"



pair<int, int> Matrix::getOrder(){
  return order;
}

void Matrix::setOrder(int n, int m){
  order = make_pair(n, m);
}

void Matrix::fillMatrixu(int n, int m){
  //reset the matrix to empty matrix
 reset();
  //fill the matrix to size with empty values
  //and then add the real value.
  for(int i = 0; i < m; i++){
    //push empty vector onto the data vector's ith place
    data.push_back( vector<double>());
    for(int j = 0; j < n; j++){
      //push an empty double onto that same vector
      data[i].push_back(0);
      //add the actual value using cin
      cin >> data[i][j];
    }//end of for#2
  }//end of for#1
  setOrder(n, m);
}

void Matrix::reset(){
  data.clear();
}


//this is for debugging purposes
//this is where I am testing all functions and classes
int main(){
  Matrix matrix1;
  Matrix matrix2;
  Matrix matrix3;

  matrix1.fillMatrixu(5, 5);

  
  return 0;
}
