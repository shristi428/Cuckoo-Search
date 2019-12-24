// Program to solve Job Shop Scheduling problem 
#include <bits/stdc++.h> 
using namespace std; 
#define N 4 
  
// state space tree node 
struct Node 
{ 
    // stores parent node of current node 
    // helps in tracing path when answer is found 
    Node* parent; 
  
    // contains time for ancestors nodes 
    // including current node 
    int pathTime; 
  
    // contains least promising time
    int time; 
  
    // contains machine number 
    int machineID; 
  
    // contains Job ID 
    int jobID; 
  
    // Boolean array assigned will contain
    // info about available jobs 
    bool assigned[N]; 
}; 
  
// Function to allocate a new search tree node 
// Here Machine x is assigned to job y 
Node* newNode(int x, int y, bool assigned[], 
              Node* parent) //new nest
{ 
    Node* node = new Node; 
  
    for (int j = 0; j < N; j++) 
        node->assigned[j] = assigned[j]; 
    node->assigned[y] = true; 
  
    node->parent = parent; 
    node->machineID = x; 
    node->jobID = y; 
  
    return node; 
} 
  
// Function to calculate the least promising time 
// of node after machine x is assigned to job y. 
// i.e. minimizing the makespan.
int calculateTime(int timeMatrix[N][N], int x, 
                  int y, bool assigned[]) 
{ 
    int time = 0; 
  
    // to store unavailable jobs 
    bool available[N] = {true}; 
  
    // start from next machine 
    for (int i = x + 1; i < N; i++) 
    { 
        int min = INT_MAX, minIndex = -1; 
  
        // do for each job 
        for (int j = 0; j < N; j++) 
        { 
            // if job is unassigned 
            if (!assigned[j] && available[j] && 
                timeMatrix[i][j] < min) 
            { 
                // store job number 
                minIndex = j; 
  
                // store time 
                min = timeMatrix[i][j]; 
            } 
        } 
  
        // add time of next machine
        time += min; 
  
        // job becomes unavailable 
        available[minIndex] = false; 
    } 
  
    return time; 
} 
  
// Comparison object to be used to order the heap 
struct comp 
{ 
    bool operator()(const Node* lhs, 
                   const Node* rhs) const
    { 
        return lhs->time > rhs->time; 
    } 
}; 
  
// print Assignments 
void printAssignments(Node *min) 
{ 
    if(min->parent==NULL) 
        return; 
  
    printAssignments(min->parent); 
    cout << "Assign Machine " << char(min->machineID + 'A') 
         << " to Job " << min->jobID << endl; 
  
} 
  
// Finds minimum time using Branch and Bound. 
int findMinTime(int timeMatrix[N][N]) 
{ 
    // Create a priority queue to store live nodes of 
    // search tree; 
    priority_queue<Node*, std::vector<Node*>, comp> pq; 
  
    // initailize heap to dummy node with time 0 
    bool assigned[N] = {false}; 
    Node* root = newNode(-1, -1, assigned, NULL); 
    root->pathTime = root->time = 0; 
    root->machineID = -1; 
  
    // Add dummy node to list of live nodes; 
    pq.push(root); 
  
    // Finds a live node with least time, 
    // add its childrens to list of live nodes and 
    // finally deletes it from the list. 
    while (!pq.empty()) 
    { 
      // Find a live node with least estimated time
      Node* min = pq.top(); 
  
      // The found node is deleted from the list of 
      // live nodes 
      pq.pop(); 
  
      // i stores next machine 
      int i = min->machineID + 1; 
  
      // if all machines are assigned a job 
      if (i == N) 
      { 
          printAssignments(min); 
          return min->time; 
      } 
  
      // do for each job 
      for (int j = 0; j < N; j++) 
      { 
        // If unassigned 
        if (!min->assigned[j]) 
        { 
          // create a new tree node 
          Node* child = newNode(i, j, min->assigned, min); 
  
          // time for ancestors nodes including current node 
          child->pathTime = min->pathTime + timeMatrix[i][j]; 
  
          // calculate its lower bound 
          child->time = child->pathTime + 
            calculateTime(timeMatrix, i, j, child->assigned); 
  
          // Add child to list of live nodes; 
          pq.push(child); 
        } 
      } 
    } 
} 
  
// Driver Function to obtain optimum time
int main() 
{ 
    // x-cordinate represents a machine 
    // y-cordinate represents a Job 
    int timeMatrix[N][N] = 
    { 
        {9, 2, 7, 8}, 
        {6, 4, 3, 7}, 
        {5, 8, 1, 8}, 
        {7, 6, 9, 4} 
    }; 
  
    cout << "\nOptimal Time is "
        << findMinTime(timeMatrix); 
  
    return 0; 
} 
