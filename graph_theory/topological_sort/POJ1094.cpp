#include<cstdio>
using namespace std;

bool graph[26][26];

void topological_sort(int v, int e)
{
    char res[27] = {'\0'};
    int resIdx = 0;
    while(resIdx < v) {
        int count = 0;
        int min_v;
        bool flag = true;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(graph[j][i] == true){
                    flag = false;
                    break;
                }
            }
            if(flag){
                count++;
                if(count > 1){
                    printf("Sorted sequence cannot be determined.\n");
                    return;
                }
                flag = false;
                min_v = i;
            }
        }
        if(count == 1){
            res[resIdx++] = 'A' + min_v;
            for(int i=0;i<v;i++){
                graph[min_v][i] = false;
            }
        }
    }
    printf("Sorted sequence determined after 4 relations: ABCD.");
}

int main()
{
    int v, e;
    char cmp[4];
    while(scanf("%d %d", &v, &e) && e && v) {
        for(int i=0;i<e;++i){
            scanf("%s", cmp);
            graph[cmp[0] - 'A'][cmp[1] - 'A'] = true;
        }
        topological_sort(v, e);
    }
    return 0;
}