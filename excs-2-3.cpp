#include <iostream>
#include <vector>
using namespace std;

vector<int> most_frequent(vector<int> vec)
{
	vector<int> nums(vec.size()) ;
	
	for(int i = 0 ; i < vec.size() ; i++)
	{
		int frequence = 0 ;
		for(int j = 0 ; j < vec.size() ; j++)
		{
			if(vec[i] == vec[j])
				frequence++ ;
		}
		nums[i] = frequence ;
		//cout<< vec[i] <<": " << nums[i] <<endl ;
	}
	
	int most_frequent = nums[0] ;
	for(int i = 1 ; i < nums.size() ; i++)
	{
		if(nums[i] > most_frequent)
			most_frequent = i ;
	}
	
	vector<int> res ;
	for(int i = 0 ; i < nums.size() ; i++)
	{
		if(nums[most_frequent] == nums[i] )
		{
			res.push_back(vec[nums[i]]) ;
			for(int j = 0 ; j < res.size() ; j++)
			{
				if(res[j] == vec[nums[i]] ) 
					{
						res.erase(std::next(res.begin() , res.size() -1)) ;
						break ; //res.pop_back()
					}
			}
		}
	}
	
	return res ;
}

int main()
{
	vector<int> sample {0,0,0,1,1,1,1,1,1,2,2,3,3,4,5,5,5,5,5,5} ;
	for(int i = 0 ; i < sample.size() ; i++)
		cout << sample [i] ;
	
	cout << endl ;
	
	vector<int> vec = most_frequent(sample) ;
	for(int i = 0 ; i < vec.size() ; i++)
	cout << vec[i] <<endl ;
	
	
	return 0 ;
}


















