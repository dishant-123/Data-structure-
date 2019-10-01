#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,vector<int> > Map;
		/*Map.insert({0,3});
		Map.insert({0,2});
		Map.insert({2,3});*/
	Map[0].push_back(3);
	Map[-1].push_back(4);
	Map[0].push_back(3);
	
	//Map.insert(0,push_back(4));
	map<int,vector<int> > :: iterator itr;
	for(itr=Map.begin();itr!=Map.end();itr++)
	{
		cout<<itr->first<<" ";
		
	}
}
