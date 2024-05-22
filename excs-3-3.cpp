#include <vector>
#include <iostream>
#include <chrono>
using namespace std;


vector<int> reverse1 (vector<int> vec)
{
	vector<int> reversed_vec ;
	
	for(auto it = vec.rbegin() ; it != vec.rend() ; it++ )
		reversed_vec.push_back(*it) ;
		
	return reversed_vec ;
}

vector<int> reverse2 (vector<int> vec)
{
	for(int i = 0 ; i < vec.size()/2 ; i++ )
	{
		int tmp = vec[i] ;
		vec[i] = vec[vec.size() -i -1] ;
		vec[vec.size() -i -1] = tmp ;
	}
		
	return vec ;
}

int main ()
{
	auto t1 = std::chrono::high_resolution_clock::now() ;
	
	vector<int> test1 (1000000) ;
	for(int i = 0 ; i < 100 ; i++ )
		reverse1(test1) ;
		
	auto t2 = std::chrono::high_resolution_clock::now() ;
	cout << "it took "
	<<std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
	<<" milliseconds for reverse1() \n" ;
	
	//**********************************************************
	
	t1 = std::chrono::high_resolution_clock::now() ;
	
	vector<int> test2 (1000000) ;
	for(int i = 0 ; i < 100 ; i++ )
		reverse2(test2) ;
		
	t2 = std::chrono::high_resolution_clock::now() ;
	cout << "it took "
	<<std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
	<<" milliseconds for reverse2() \n" ;
}

























