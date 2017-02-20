//Gearter NY regional 2000;
//A direct implementation of Huffman tree;
//I am not sure whether using priority queue and vector to implement is a good idea;
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
struct Node{
    int frequency;
    vector<char> ch;
    void init(){
        frequency=0;
        ch.clear();
    }
    bool operator < (const Node& b) const{
        return frequency<b.frequency;
    }
    bool operator > (const Node& b) const{
        return frequency>b.frequency;
    }
}node[30];
string s;
priority_queue<Node, vector<Node>, greater<Node>> q;
int table[30];
int main(){
    while(cin>>s){
        if(s=="END") break;
        int len=s.length(), cur=0;
        for(int i=0; i<len; i++){
            for(int j=0; j<cur; j++){
                if(s.at(i)==node[j].ch[0]){
                    node[j].frequency++;
                    goto label;
                }
            }
            node[cur].init();
            node[cur].ch.push_back(s.at(i));
            node[cur++].frequency++;
            label:;
        }
        if(!q.empty()){
            priority_queue<Node, vector<Node>, greater<Node>> tmp;
            swap(q, tmp);
        }
        memset(table, 0, sizeof(table));
        for(int i=0; i<cur; i++)
            q.push(node[i]);
        bool first=true;
        while(!q.empty()){
            Node tmp1, tmp2;
            tmp1=q.top();
            q.pop();
            if(q.empty()){
                if(first) tmp1.ch[0]=='_'?table[26]++:table[tmp1.ch[0]-'A']++;
                break;
            }
            first=false;
            tmp2=q.top();
            q.pop();
            int sz=tmp2.ch.size();
            for(int i=0; i<sz; i++)
                tmp1.ch.push_back(tmp2.ch[i]);
            tmp1.frequency+=tmp2.frequency;
            sz=tmp1.ch.size();
            for(int i=0; i<sz; i++)
                tmp1.ch[i]=='_'?table[26]++:table[tmp1.ch[i]-'A']++;
            q.push(tmp1);
        }
        int tot1, tot2=0;
        tot1=len*8;
        for(int i=0; i<cur; i++)
            tot2+=node[i].frequency*(node[i].ch[0]=='_'?table[26]:table[node[i].ch[0]-'A']);
        double ratiio=(double)tot1/(double)tot2;
        cout<<tot1<<' '<<tot2<<' ';
        printf("%.1f\n", ratiio);
    }
    return 0;
}
