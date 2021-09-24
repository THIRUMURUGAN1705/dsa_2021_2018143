#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define INF 9999999


int main() {
    int tot=0;
	int G[20][20], i, j, V, u;
  printf("enter no. of vertices: ");
	scanf("%d", &V);


	printf("enter dist in matrix form:\n");
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++)
			scanf("%d", &G[i][j]);
	}


  int no_edge;  // number of edge

  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[V];

  // set selected false initially
  for(int i = 0; i < V; i++) {
		selected[i] = false;
	}

  // set number of edge to 0
  no_edge = 0;

  // the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph

  // choose 0th vertex and make it true
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  // print for edge and weight
  printf("Edge : Weight\n");

  while (no_edge < V - 1) {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    tot=tot+G[x][y];
    selected[y] = true;
    no_edge++;
  }
  printf("total cost of minimum heap tree:%d",tot);

  return 0;
}
