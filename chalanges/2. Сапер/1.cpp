#include <iostream>
#include <string>
#define byte int8_t
using namespace std;

class Field
{
private:
  string name;
  int rows,cols; 
  byte** data; 
  
  void setBomb(const int& r, const int& c){
    if(r > 0)
      data[r - 1][c]++;
    if(r < rows - 1)
      data[r + 1][c]++;
    
    if(c > 0)
      data[r][c - 1]++;
    if(c < cols - 1)
      data[r][c + 1]++;
    data[r][c] = -10;
  }
public:
  Field(const int& _rows, const int& _cols){
    static int count = 0;
    name = "Field #" + to_string(++count);
    rows = _rows;
    cols = _cols;
    data = new byte*[rows];
    for( int i = 0; i < rows; i++)
      data[i] = new byte[cols];
  }
  
  void print(){
    cout << name << endl;
    cout << rows << ":"<< cols << endl;
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
	if(data[i][j] <0)
	  cout << '*';
	 else 
	  cout << to_string(data[i][j]);
     
      }
      cout << endl;
    }
  }
  
  void readBombs(){
    string row;
    for(int i = 0; i < rows; i++){
      cin >> row;
      for(int j = 0; j < row.size() && j < cols; j++)
	if(row[j] == '*')
	  setBomb(i,j);
    }
  }
   
};


int main(){
  int N,M;
  cin >> N >> M;
  Field field(N,M);
  field.print();
}