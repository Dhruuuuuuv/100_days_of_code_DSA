bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = calloc(roomsSize, sizeof(bool));
    int* queue = malloc(roomsSize * sizeof(int));
    int head = 0, tail = 0;

    visited[0] = true;
    queue[tail++] = 0;

    while (head < tail) {
        int currentRoom = queue[head++];
        for (int i = 0; i < roomsColSize[currentRoom]; i++) {
            int key = rooms[currentRoom][i];
            if (!visited[key]) {
                visited[key] = true;
                queue[tail++] = key;
            }
        }
    }

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            free(queue);
            return false;
        }
    }

    free(visited);
    free(queue);
    return true;
}