#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CITIES 5

int dist[CITIES][CITIES] = {
    {0, 10, 15, 20, 25},
    {10, 0, 35, 25, 30},
    {15, 35, 0, 30, 20},
    {20, 25, 30, 0, 15},
    {25, 30, 20, 15, 0}
};

int min_cost = INT_MAX;
int best_path[CITIES + 1];

int get_return_cost(int last_city, int start_city) {
    return dist[last_city][start_city];
}

void tsp_recursive(int *path, int *visited, int level, int current_cost, int start_city) {
    if (level == CITIES) {
        int total_cost = current_cost + get_return_cost(path[level - 1], start_city);

        if (total_cost < min_cost) {
            min_cost = total_cost;

            for (int i=0 ; i<CITIES ; i++) {
                best_path[i] = path[i];
            }

            best_path[CITIES] = start_city;
        }

        return;
    }

    for (int i=0 ; i<CITIES ; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            path[level] = i;

            int next_cost = current_cost + dist[path[level - 1]][i];

            if (next_cost < min_cost) {
                tsp_recursive(path, visited, level + 1, next_cost, start_city);
            }

            visited[i] = 0;
        }
    }
}

int main() {
    int path[CITIES];
    int visited[CITIES] = {0};

    int start_city = 0;
    path[0] = start_city;
    visited[start_city] = 1;

    for (int iter=0 ; iter<2000000 ; iter++) {
        min_cost = INT_MAX;
        tsp_recursive(path, visited, 1, 0, start_city);
    }

    printf("Minimum TSP Tour Cost: %d\n", min_cost);
    printf("Optimal Path: ");

    for (int i=0 ; i<=CITIES ; i++) {
        printf("%d ", best_path[i]);
    }

    printf("\n");

    return 0;
}