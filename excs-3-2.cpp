#include <vector>
using namespace std;

vector<int> reverse (vector<int> vec)
{
	for(int i = 0 ; i < vec.size()/2 ; i++ )
	{
		int tmp = vec[i] ;
		vec[i] = vec[vec.size() -i -1] ;
		vec[vec.size() -i -1] = tmp ;
	}
		
	return vec ;
}
