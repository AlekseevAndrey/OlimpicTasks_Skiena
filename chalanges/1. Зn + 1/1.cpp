#include <iostream>

using std::cout;
using std::cin;

int findMaxLoopsLenghtBetween(int a, int b);
inline int computeLoopsLength(int n);
inline bool isEven(const int& n);

int main() 
{
  int a,b;
  cin >> a >> b;
  cout << a << "	" << b << "	" << findMaxLoopsLenghtBetween(a,b) << std::endl;
}

int findMaxLoopsLenghtBetween(int a, int b)
{  
  int maxLoopsLength = 0;
  int step = (a < b) ? 1 : -1;
  
  for( int i = a; i != b; i += step ){ 
    maxLoopsLength = std::max(maxLoopsLength, computeLoopsLength(i));
  }
  
  maxLoopsLength = std::max(maxLoopsLength, computeLoopsLength(b));
  return maxLoopsLength;
}

inline int computeLoopsLength(int n)
{
  if(n == 1)
    return 1; //End of recursion
  
  if(isEven(n)){
    return computeLoopsLength( n / 2 ) + 1;
  } else {
    return computeLoopsLength( n * 3 + 1 ) + 1;
  }
}

inline bool isEven(const int& n) 
{
  return !(n%2);
}