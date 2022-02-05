#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void infectStudents(vector<vector<int>> & matrix ,
                      int& height,
                      int& width,
                      int row,
                      int col ,
                      int& movieLenth,
                      int timeAtInfection,
                      int& infectedStudents){
        if(row < 0 || row > height - 1 || col < 0 || col > width - 1 ||
            timeAtInfection > movieLenth ||
            (matrix[row][col] != -1 && timeAtInfection >= matrix[row][col])){
                return ;
        }
        if(matrix[row][col] == -1 || matrix[row][col] > timeAtInfection){
            if(matrix[row][col] == -1){
                infectedStudents++;
            }
            matrix[row][col] = timeAtInfection;
            infectStudents(matrix , height , width , row - 1 , col, movieLenth,
                             timeAtInfection + 1 , infectedStudents);
            infectStudents(matrix , height , width, row, col + 1, movieLenth,
                             timeAtInfection + 1, infectedStudents);
            infectStudents(matrix, height, width, row + 1, col, movieLenth,
                             timeAtInfection + 1, infectedStudents);
            infectStudents(matrix, height , width , row, col - 1, movieLenth,
                             timeAtInfection + 1, infectedStudents);
        }
}

 int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int height , width;
    cin >> height >> width;

    const int HEALTHY_STUDENTS = -1;
    vector<vector<int>> matrix(height , vector<int>(width, HEALTHY_STUDENTS));

    int movieLength , firstInfectedStudents;
    cin >> movieLength >> firstInfectedStudents;

    int allStudentsCount = height * width;
    int infectedStudents = 0;
    int timeAtinfection = 0;

    int startPosRow , startPosCol;
    for(int i = 0 ; i < firstInfectedStudents ; i++){
        cin >> startPosRow >> startPosCol;
        startPosRow = height - startPosRow;
        startPosCol = startPosCol - 1;
        infectStudents(matrix , height , width , startPosRow , startPosCol,
                         movieLength , timeAtinfection , infectedStudents);
    }
    printf("%d" , (allStudentsCount - infectedStudents));
    return 0;
 }
