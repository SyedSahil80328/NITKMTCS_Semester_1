Yes — here is the **lab-ready pseudocode**, compact enough to revise quickly. I’ll use your terminology: **adjacency list + `visited[]` + stack/queue**.

# 0. DFS / BFS for the whole graph

For a disconnected graph, don't run traversal only from vertex `0`.

```text
DFS_ALL(graph):

    visited[] = false

    for each vertex u:
        if not visited[u]:
            DFS(u)
```

Same idea for BFS:

```text
BFS_ALL(graph):

    visited[] = false

    for each vertex u:
        if not visited[u]:
            BFS(u)
```

---

# 1. DFS — Undirected Graph

```text
DFS(u):

    mark u visited
    process u

    for each v adjacent to u:
        if not visited[v]:
            DFS(v)
```

### Iterative version

```text
DFS(u):

    create empty STACK
    push u

    while STACK not empty:

        u = pop()

        if visited[u]:
            continue

        visited[u] = true
        process u

        for each v adjacent to u:
            if not visited[v]:
                push v
```

---

# 2. BFS — Undirected Graph

```text
BFS(start):

    create empty QUEUE

    visited[start] = true
    enqueue start

    while QUEUE not empty:

        u = dequeue

        process u

        for each v adjacent to u:

            if not visited[v]:

                visited[v] = true
                enqueue v
```

Remember:

```text
DFS → STACK → LIFO
BFS → QUEUE → FIFO
```

---

# 3. DFS — Directed Graph

**The traversal itself is almost identical.**

The only difference is that the adjacency list contains **outgoing edges**.

```text
DFS(u):

    visited[u] = true
    process u

    for each v in outgoing_neighbors(u):

        if not visited[v]:
            DFS(v)
```

For the whole directed graph:

```text
DFS_ALL:

    visited[] = false

    for each u:

        if not visited[u]:
            DFS(u)
```

---

# 4. BFS — Directed Graph

Again, same BFS.

```text
BFS(start):

    visited[start] = true
    enqueue start

    while QUEUE not empty:

        u = dequeue
        process u

        for each v in outgoing_neighbors(u):

            if not visited[v]:
                visited[v] = true
                enqueue v
```

So:

> **Directed vs undirected does NOT fundamentally change DFS/BFS.**

The difference is how you construct/traverse the adjacency list.

---

# 5. Detect Cycle — Undirected Graph 🔥

This is where `parent[]` becomes useful.

```text
DFS(u, parent):

    visited[u] = true

    for each v adjacent to u:

        if not visited[v]:

            if DFS(v, u) == TRUE:
                return TRUE

        else if v != parent:

            return TRUE       ← cycle found

    return FALSE
```

For disconnected graphs:

```text
HAS_CYCLE:

    visited[] = false

    for each u:

        if not visited[u]:

            if DFS(u, -1):
                return TRUE

    return FALSE
```

### Key condition

```text
visited[v] && v != parent
```

means:

> "I found an already-visited vertex that isn't simply the edge I came from."

Therefore → **cycle**.

---

# 6. Directed Cycle Detection 🔥🔥

For directed graphs, `visited[]` alone isn't enough.

Use **3 states**:

```text
0 = UNVISITED
1 = CURRENTLY IN DFS PATH
2 = COMPLETELY FINISHED
```

DFS:

```text
DFS(u):

    state[u] = 1

    for each v adjacent to u:

        if state[v] == 0:

            parent[v] = u

            if DFS(v):
                return TRUE

        else if state[v] == 1:

            return TRUE       ← directed cycle

    state[u] = 2

    return FALSE
```

For the whole graph:

```text
HAS_DIRECTED_CYCLE:

    state[] = 0

    for each u:

        if state[u] == 0:

            if DFS(u):
                return TRUE

    return FALSE
```

### The key idea

If during DFS:

```text
u → v
```

and:

```text
state[v] == 1
```

then `v` is **still in the current DFS chain**.

Therefore:

```text
u → ... → v → ... → u
```

A directed cycle exists.

---

# 7. Output ONE Directed Cycle

Once you detect:

```text
state[v] == 1
```

you know:

```text
u → v
```

is a back edge.

You have:

```text
parent[u]
parent[parent[u]]
...
```

Walk backward from `u` until you reach `v`.

```text
cycle = []

cycle.push(v)

x = u

while x != v:

    cycle.push(x)
    x = parent[x]

cycle.push(v)

reverse(cycle)
```

Example:

```text
0 → 1 → 2 → 3
    ↑       ↓
    └───────┘
```

Suppose:

```text
parent[1] = 0
parent[2] = 1
parent[3] = 2
```

and detect:

```text
3 → 1
```

Then:

```text
3
↓
2
↓
1
```

Reverse + close cycle:

```text
1 → 2 → 3 → 1
```

🔥 That's exactly why your professor had you implement `parent[]`.

---

# 8. Topological Sort

For a **DAG**, use DFS finishing order.

```text
TOPOLOGICAL_SORT:

    visited[] = false
    create empty STACK

    for each vertex u:

        if not visited[u]:
            DFS_TOPO(u)

    output STACK
```

DFS:

```text
DFS_TOPO(u):

    visited[u] = true

    for each v adjacent to u:

        if not visited[v]:
            DFS_TOPO(v)

    PUSH u into STACK
```

Notice the important difference:

```text
visit u
    ↓
visit all children
    ↓
PUSH u
```

**Push after finishing the node.**

Finally:

```text
while STACK not empty:
    print POP(STACK)
```

That's the topological ordering.

### But:

Topological sorting only exists if:

```text
Directed graph + NO directed cycle
```

So your workflow should be:

```text
Directed graph
      ↓
Cycle detection
      ↓
Cycle?
 ┌────┴────┐
YES       NO
 ↓         ↓
Output     DAG
cycle       ↓
           DFS finishing order
                 ↓
           Topological order
```

---

# 9. Bipartite Graph 🔥🔥

Use **BFS/DFS + 2-coloring**.

Maintain:

```text
color[u] = -1   → uncolored
color[u] = 0
color[u] = 1
```

For every unvisited component:

```text
BIPARTITE:

    color[] = -1

    for each vertex u:

        if color[u] == -1:

            color[u] = 0
            enqueue u

            while QUEUE not empty:

                u = dequeue

                for each v adjacent to u:

                    if color[v] == -1:

                        color[v] = 1 - color[u]
                        enqueue v

                    else if color[v] == color[u]:

                        return FALSE

    return TRUE
```

### The rule

Every edge must connect:

```text
color 0 ↔ color 1
```

Never:

```text
0 ↔ 0
1 ↔ 1
```

Example:

```text
      0
     / \
    1   1
```

valid.

But:

```text
    0
   / \
  1---1
```

invalid because the edge between the two `1`s violates the coloring.

---

# 🚨 Ultra-Quick Lab Cheat Sheet

```text
DFS
→ STACK
→ visited[]

BFS
→ QUEUE
→ visited[]

UNDIRECTED CYCLE
→ DFS + parent[]
→ visited neighbor != parent → cycle

DIRECTED CYCLE
→ DFS + 3 states
→ edge to state=1 → cycle

DIRECTED CYCLE OUTPUT
→ parent[]
→ walk backward from u to v

TOPOLOGICAL SORT
→ DAG only
→ DFS
→ push AFTER finishing
→ reverse finishing order

BIPARTITE
→ BFS/DFS + color[]
→ color[v] = 1 - color[u]
→ same color on an edge → NOT bipartite
```

### The five things I'd memorize before entering the lab

```text
1. DFS  = STACK
2. BFS  = QUEUE
3. Undirected cycle = visited + parent
4. Directed cycle   = 3-state DFS
5. Bipartite        = 2-color BFS/DFS
```

And **parent[] is doing double duty**:

```text
DFS parent
   ├── reconstruct paths
   ├── undirected cycle detection
   └── output a directed cycle
```

That's the core of what your professor is asking for today.
