#include <vector> 
#include <iostream> 
using namespace std;


int main()
{
	vector<vector<int>> MyVec (3 , vector<int> (1)) ;
	
	MyVec[0][0] = 2 ;
	MyVec[1][0] = 4 ;
	MyVec[2][0] = 6 ;
	
	
	MyVec[0].push_back(4) ;
	MyVec[0].push_back(3) ;
	MyVec[2].push_back(9) ;
	
//	for(int i = 0 ; i < MyVec.size() ; i++)
//	{
//		for(int j = 0 ; j < MyVec[i].size() ; j++)
//			cout << MyVec[i][j] <<"  " ;
//		cout << "\n\n" ;
//	}
	
	
	return 0;
}