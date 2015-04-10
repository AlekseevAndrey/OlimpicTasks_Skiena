#include <iostream>
#include <math.h>
#include <vector>
#define abs(x) (x) < 0 ? -(x) : (x) //why abs from std not founded??
using namespace std;

void readData(vector<float>& data);
float computeMoneyForChange(const vector<float>& data);
float computeMean(const vector<float>& data);

int main(){
  vector<float> data;
  readData(data);
  cout << computeMoneyForChange(data) << endl;
}

void readData(vector<float>& data){
  int N;
  cin >> N;
  data.resize(N);
  for(auto& i: data){
    cin >> i;
  }
}

float computeMoneyForChange(const vector<float>& data){
  float mean = computeMean(data);
  float sum;
  for(const auto& i: data){
    sum += abs(mean - i) ;
  }
  return sum / 2;
}

float computeMean(const vector<float>& data)
{
  float meanSum;
  for(const auto& i: data)
    meanSum += i / data.size();
  return meanSum;
}
