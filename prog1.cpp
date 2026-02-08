#include<iostream> 
using namespace std;
void swap(int &n1, int &n2) {
  int temp = n1;
  n1 = n2;
  n2 = n1;
}
int main() {
  int n;
  cin >> n;
  int arr[n];
  if (n <= 0) {
  }
  cout << "Enter the numbers" << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
 
  cout << "The largets and second largets numbers are " << endl;

  for (int j = 0; j < n - 1; j++) {
    if (arr[j] > arr[j + 1]) {
      swap(arr[j], arr[j + 1]);
    }
  }
  cout << arr[n - 1] << endl;
  for (int j = 0; j < n - 1; j++) {
    if (arr[j] > arr[j + 1]) {
      swap(arr[j], arr[j + 1]);
    }
  }
  cout << arr[n - 2] << endl;
  return 0;
}
