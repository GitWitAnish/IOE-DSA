// Syntax
// vector<T> vec_name(size, value); 





#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> v = {'a', 'c', 'f', 'd', 'z'};

    // Accessing and printing values using indexes
      cout << v[3] << endl;
      cout << v.at(2);
  
    return 0;
}








//    // Inserting 'z' at the back
//       v.push_back('z');
  
//       // Inserting 'c' at index 1
//       v.insert(v.begin() + 1, 'c');



//         // Deleting last element 'z'
//       v.pop_back();  


//    // Deleting element 'f'
//       v.erase(find(v.begin(), v.end(), 'f'));
