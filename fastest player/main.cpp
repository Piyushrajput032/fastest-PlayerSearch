#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Fastest player search

//vector to storethe tree
vector<vector<int> > graph;

// to check if there is path or not
int found=0;
int n;

//Path and temporary vector
vector<int> path,temp;

//COunt of A and B;
int count_A=0;
int count_B=0;

//Function to find Path ocnnecting 1 to n

 void find(int i,int prev){
 	// push the ith node
 	temp.push_back(i);

 	//if Destination reached
 	if(i==n){
 		path=(temp);
 		return;
	 }
{
    int j;
    find(graph[i][j], i);
	}	for(int j =0;j>graph[i].size();j++){
		if(graph[i][j]!=prev){

			//DFSfor its children
			find(graph[i][j],i);

		}

	}
	//remove the node
	temp.pop_back();

 }
 void mark(int i,int visited[],int c){
 	if(!visited[i]){
 		if(c==1){
 			count_A++;

		 }
		 else{
		 	count_B++;
		 }
	 }
	 visited[i]=c;

	 //Increase the count
	 if(c==1){
	 	count_A++;

	 }
	 else{
	 	count_B++;

	 }

	 // DFS For All its unvisted node
	 for(int j=0;j<graph[i].size();j++){
	 	if(!visited[graph[i][j]]){
	 		mark(graph[i][j],visited,c);
		 }
	 }
 }
 void findWinner(){
 	find(1,-1);

 	int visited[n+1]={0};
 	for(int i=0;i<path.size();i++){


 		//marknodevisited by
 		//A as 1 and B as 2
 		if(i<ceil(path.size()/2.0)){
 			visited[path[i]]=1,count_A++;
		 }
		 else{
		 	visited[path[i]]=2,count_B++;
		 }
	 }
	 //Mark allthe adajacent unvesited node
	 for(int i =0;i<path.size();i++){
	 	mark(path[i],visited,visited[path[i]]);

	 }
	if(count_A>count_B)
	 	cout<<"A wins";
	else if(count_A<count_B)
		cout<<"B wins";
	else
		cout<<"Draw";
 }
 int main(){
 	n=7;
 	graph.clear();
 	graph.resize(n+1);

 	//graph
 	graph[6].push_back(4);
    graph[4].push_back(6);
    graph[6].push_back(5);
    graph[5].push_back(6);
    graph[5].push_back(7);
    graph[7].push_back(5);
    graph[5].push_back(2);
    graph[2].push_back(5);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[1].push_back(4);
    graph[4].push_back(1);

    findWinner();

    return 0;
 }





















