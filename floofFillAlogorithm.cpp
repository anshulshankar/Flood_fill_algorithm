#include<iostream> 
using namespace std; 
  
// Dimentions of paint screen 
#define M 8 
#define N 8 
  
// A recursive function to replace previous color 'prevC' at  '(x, y)'  
// and all surrounding pixels of (x, y) with new color 'newC' and 
void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC) 
{ 
    // Base cases 
    if (x < 0 || x >= M || y < 0 || y >= N) 
        return; 
    if (screen[x][y] != prevC) 
        return; 
  
    // Replace the color at (x, y) 
    screen[x][y] = newC; 
  
    // Recur for north, east, south and west 
    floodFillUtil(screen, x+1, y, prevC, newC); 
    floodFillUtil(screen, x-1, y, prevC, newC); 
    floodFillUtil(screen, x, y+1, prevC, newC); 
    floodFillUtil(screen, x, y-1, prevC, newC); 
} 
  
// It mainly finds the previous color on (x, y) and 
// calls floodFillUtil() 
void floodFill(int screen[][N], int x, int y, int newC) 
{ 
    int prevC = screen[x][y]; 
    floodFillUtil(screen, x, y, prevC, newC); 
} 
  
// Driver program to test above function 
int main() 
{ 
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
    int x = 4, y = 4, newC = 3; 
    floodFill(screen, x, y, newC); 
  
    cout << "Updated screen after call to floodFill: n"; 
    for (int i = 0; i < M; i++) 
    { 
        for (int j = 0; j < N; j++) 
           cout << screen[i][j] << " "; 
        cout << endl; 
    } 
}

/* Running in Microsoft Visual Studio :-

If you want to build a sample with Microsoft Visual Studio, then you need to create a project and copy the sample into that project by your own.
In order to build each sample, simply cd to its directory and run make to build the required executable. 
Run make clean to clean-up your directory. Also make full, first cleans and then rebuilds each sample. */
/*
Running on Linux/Unix System :-
step 1 :- Open Terminal.
step 2 :- Go to directory where file is saved
step 3 :- Command for compile g++ filename.cpp
step 4 :- Command to run ./a.out.
/*
