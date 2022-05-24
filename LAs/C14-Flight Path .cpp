
#include <iostream>
using namespace std;

int cost[50][50] = {0, 0};
int visited[50] = {0};

void dfs(int start, int m, string cities[]) {
    visited[start] = 1;
    cout << cities[start] << " ";
    for(int i=0; i<m; i++) {
        if(cost[start][i] && !visited[i]) {
            dfs(i, m, cities);
        } 
    }
}

void check_graph(int start, int m, string cities[]) {
    bool ans=true;
    for(int i=0; i<m; i++) {
        int counter=0;
        for(int j=0; j<m; j++) {
            if(!cost[i][j])
                counter++;
            else
                break;
        }
        
        if(counter == m) {
            counter = 0;
            for(int k=0; k<m; k++) {
                if(!cost[k][i])
                    counter++;
                else
                    break;
            }
            
            if(counter == m)
                ans = false;
        }        
    }    
    
    if(ans)
        cout << "Graph is connected" << endl;
    else
        cout << "Graph is not connected" << endl;
}

void print_matrix(int m) {
    cout << "Adjacency matrix: " << endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            cout << cost[i][j] << '\t';
        }
        cout << endl;
    }
}

int main() {
    int m;
    cout << "Enter total number of cities: ";
    cin >> m;
    
    string cities[m];
    for(int i=0; i<m; i++) {
        cout << "City " << i+1 << ": ";
        cin >> cities[i];
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            cout << "Enter cost from city " << cities[i] << " to city " << cities[j] << ": ";
            cin >> cost[i][j];
        }
    }
    
    int start{};
    cout << "Enter starting vertex: ";
    cin >> start;
    
    while(true) {
        int input;
        cout << "===============================" << endl;
        cout << "Menu" << endl;
        cout << "===============================" << endl;
        cout << "1. Matrix" << endl;
        cout << "2. DFS" << endl;
        cout << "3. Check connectivity" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> input;
        if(input == 0)
            break;
        
        switch(input) {
            case 1:
                print_matrix(m);
                break;
            case 2:
                cout << "DFS: ";
                dfs(start, m, cities);
                cout << endl;
                break;
            case 3:
                check_graph(start, m, cities);
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }  
    
    return 0;
}


