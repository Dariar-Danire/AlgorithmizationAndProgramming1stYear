#include <iostream>
#include <vector>
#include <string>

bool is_can_exit_from_maze(std::vector<std::string> maze, int row, int col){  
    int count=1;  
    maze[row][col]='*';  
    while(count>0){  
        count=0;  
        for(int i=1;i<maze.size()-1;i++){  
            for(int j=1;j<maze[i].length()-1;j++){  
                if(maze[i][j]=='*'){  
                    if(maze[i-1][j]==' ') maze[i-1][j]='*';  
                    if(maze[i+1][j]==' ') maze[i+1][j]='*';  
                    if(maze[i][j-1]==' ') maze[i][j-1]='*';  
                    if(maze[i][j+1]==' ') maze[i][j+1]='*';  
                    if(maze[i-1][j]=='E') return true;  
                    if(maze[i+1][j]=='E') return true;  
                    if(maze[i][j-1]=='E') return true;  
                    if(maze[i][j+1]=='E') return true;  
                    maze[i][j]='#';  
                    count++;  
                }  
            }  
        }  
    }  
    return false;  
}

int main(){
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода
    
    std::vector<std::string> maze(rows);
    for(auto& line : maze) std::getline(std::cin, line);
    
    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}
