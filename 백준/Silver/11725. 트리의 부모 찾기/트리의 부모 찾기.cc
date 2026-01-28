#include <stdio.h>
#include <vector>

using namespace std; 

int N;
int queue[100001];
int front=0, rear=0;


// graph[i]는 i번 노드와 연결된 애들의 목록만 저장
vector<int> graph[100001]; 

int parent[100001]={0};
int visited[100001]={0};

void bfs(){
    while(front<rear){
        int cur = queue[front++];
        visited[cur]=1; // 부모로써 탐색했다는 표시

        // graph[cur]에 들어있는(연결된) 노드들만 하나씩 꺼내서 i에 담기
        for(int i : graph[cur]) {
            // vector에 들어있다는 것 자체가 이미 연결(graph[cur][i]==1)되었다는 뜻
            // visited[i]==0 인지만 확인하면 됨.
            if(visited[i]==0){ 
                queue[rear++]=i;
                parent[i]=cur;
                // 중복 방문 방지
                visited[i]=1; 
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    for(int i=1; i<N; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue[rear++] = 1;
    visited[1] = 1; // 시작노드 방문 처리
    bfs();

    for(int i=2; i<=N; i++){
        printf("%d\n",parent[i]);
    }

    return 0;
}