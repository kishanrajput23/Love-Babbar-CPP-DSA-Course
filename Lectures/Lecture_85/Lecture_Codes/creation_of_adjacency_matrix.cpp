#include<iostream>

using namespace std;

int arr[20][20]; //the adjacency matrix initially 0

void displayMatrix(int n) {
   for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
}

void add_edge(int u, int v) {       //function to add edge into the matrix
   arr[u][v] = 1;
   arr[v][u] = 1;
}

int main() {
   int n = 6;    //there are 6 vertices in the graph

   add_edge(0, 4);
   add_edge(0, 3);
   add_edge(1, 2);
   add_edge(1, 4);
   add_edge(1, 5);
   add_edge(2, 3);
   add_edge(2, 5);
   add_edge(5, 3);
   add_edge(5, 4);

   displayMatrix(n);
}