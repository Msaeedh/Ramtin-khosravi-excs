#include <vector>
using namespace std;

vector<int> reverse (vector<int> vec)
{
	vector<int> reversed_vec ;
	
	for(auto it = vec.rbegin() ; it != vec.rend() ; it++ )
		reversed_vec.push_back(*it) ;
		
	return reversed_vec ;
}

