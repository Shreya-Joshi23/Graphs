//Disjoint set union
//using rank and size

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
    vector<int>rank,parent,size;

public:
    DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
    }

    int findUparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUparent(parent[node]); 
    }

    void unionbyRank(int u,int v){
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbySize(int u,int v){
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);  
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionbySize(1,2);
    ds.unionbySize(2,3);
    ds.unionbySize(4,5);
    ds.unionbySize(6,7);
    ds.unionbySize(5,6);
    if(ds.findUparent(3)==ds.findUparent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }
    ds.unionbySize(3,7);
    if(ds.findUparent(3)==ds.findUparent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }
}