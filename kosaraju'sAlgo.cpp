#include<bits/stdc++.h>
using namespace std;

//This algo is used to find no. of strongly connected components

void dfs(int node,vector<int>adj[],vector<int>&visited,stack<int>&st){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[node]){
            dfs(it,adj,visited,st);
        }
    }
    st.push(node);
}

void dfs(int node,vector<int>adjR[],vector<int>&visited){
    visited[node]=1;
    for(auto it:adjR[node]){
        if(!visited[it])
        dfs(it,adjR,visited);
    }
}

int kosarajuAlgo(int V,vector<int>adj[]){

    stack<int>st;
    vector<int>visited(V,0);

    //Step1:Sort all the edges according to finishing time
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }


    //Step2:Reverse all the edges
    vector<int>adjR[V];
    for(int i=0;i<V;i++){
        visited[i]=0;
        for(auto it:adj[i]){
            adjR[it].push_back(i);
        }
    }

    //Step3:Do the dfs until the stack is empty
    int noOfScc=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            noOfScc++;
            dfs(node,adjR,visited);
        }
    }

    return noOfScc;

}