int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        inDegree[course]++;
        adjSize[pre]++;
    }

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; 
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        adj[pre][adjSize[pre]++] = course;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    while (head < tail) {
        int curr = queue[head++];
        result[count++] = curr;

        for (int i = 0; i < adjSize[curr]; i++) {
            int nextCourse = adj[curr][i];
            inDegree[nextCourse]--;
            if (inDegree[nextCourse] == 0) {
                queue[tail++] = nextCourse;
            }
        }
    }

    for (int i = 0; i < numCourses; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    free(inDegree);
    free(queue);

    if (count == numCourses) {
        *returnSize = numCourses;
        return result;
    } else {
        *returnSize = 0;
        free(result);
        return NULL;
    }
}