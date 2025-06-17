#include <iostream>
using namespace std;

void towerofhanoi(int n, char from_rod, char aux_rod, char to_rod)
{
  if (n == 0)
    return;

  towerofhanoi(n - 1, from_rod, to_rod, aux_rod);

  cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;

  towerofhanoi(n - 1, aux_rod, from_rod, to_rod);
}

int main()
{
  int N = 3;
  towerofhanoi(N, 'A', 'B', 'C');
  return 0;
}