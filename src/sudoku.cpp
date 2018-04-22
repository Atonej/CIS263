#include <stdlib.h>
#include <iostream>
#include <algorithm> //std::find

#define MAX 9

/**********************************************
 * This class is a Sudoku game using the logic 
 * of backtracking.
 *
 * @author Atone Joryman
 * @version Winter 2018
 **********************************************/
class Sudoku {

	public :
		Sudoku(){
		

		}


		/***********************************
 		* This method will print the board at the 
 		* start of the game and the end
 		*
 		***********************************/
		void printBoard(){
			std::cout << "Sudoku Board: Before" << std::endl;
			std::cout <<  "______________" << std::endl;
			for(int i=0;i<9; i++){
				for(int j = 0; j<9 ; j++){
					if (j==8){
						std::cout <<  board[i][j] << "|" << std::endl;
						if(i == 2 || i == 5 || i == 8)
							//help to make look like an actual board
							std::cout <<  "______________" << std::endl;

					}
					else{
					//catch zeros make them appear blank
					std::cout << board[i][j] ;//<< " " ;
					if(j == 2 || j == 5 || j == 8)
							//separator
							std::cout <<  "||";				
					}
				}
	
			}

			//go through board	
			if(backtrack(board)== true){
				//complete = backtrack(board);
			std::cout << "Sudoku Board: Solved" << std::endl;
			std::cout <<  "______________" << std::endl;
			for(int i=0;i<9; i++){
				for(int j = 0; j<9 ; j++){
						
					//at the end of the line
					if (j==8){
					
						std::cout <<  board[i][j] << "|" << std::endl;
						if(i == 2 || i == 5 || i == 8)
							//help to make look like an actual board
							std::cout <<  "______________" << std::endl;

						}
					else{
					//catch zeros make them appear blank
					std::cout << board[i][j] ;//<< " " ;
					if(j == 2 || j == 5 || j == 8)
							//separator
							std::cout <<  "||";
					
					}
				}
	
			}
		
		}
		}
		
		/**************************************************************
 		* In this method will consist of the solving of the board. Back
 		* tracking will be used in order to completed, which is a brute
 		* force method. 
 		*
 		* @param solve the board given 
 		* @return bool for completeness staturs
 		****************************************************************/

		bool backtrack(int solve[MAX][MAX]){
			int row=0, col=0;		
			int r = getRow();
			int c = getCol();
			
			//keep going through board to begin with empty tile
			while(board[r][c]!= 0){
				r = getRow();
				c = getCol();
			}

			row = r;
			col = c;	
			//may need more temp
					
 
    // check if the board is filled then it is a win
    	//if(std::find(grid[0], grid[row-1]+col,0))
        if (!isFilled(solve, row, col))
       return true; 
                 
    // go through the numbers 1-9 that will insist on what can be inserted
    for (int num = 1; num <= 9; num++){
    // checks valid input, then puts in num
    if (canPlace(solve, row, col, num)){
    	   solve[row][col] = num;
                                                               
    //when true recurse 
    if (backtrack(solve))
    return true;
                                                                                               
    else //otherwise take away the value 
    solve[row][col] = 0;
    				}
    }
    return false; // this triggers backtracking

		}
		//int** getBoard(){
		//	return board;
		//}
		
		/********************************
 		* accessor method to get random
 		* number for row
 		*
 		* @return row of type int
 		********************************/
		int getRow(){
			int row =rand() %9 +1;
			return row;
		}
		/********************************
 		* accessor method to get random
 		* number for col
 		*
 		* @return col of type int
 		********************************/
		int getCol(){
			int col =rand() %9 +1;
			return col;
		}
		/********************************
 		* accessor method to get random
 		* number for row
 		*
 		* @return num of type int
 		********************************/
		int getNum(){
			int num = rand() %9 + 1;

			return num;
		}

 
/************************************************************** 
 * Check the columns in a row to see if the numbers don't repeat
 *
 * @param solve the board for col
 * @param col iterator
 * @param num to find in columns of row
 * @return bool type found for true not there for false
 **************************************************************/
bool checkCol(int solve[MAX][MAX], int col, int num)
{
    for (int row = 0; row < MAX; row++)
        if (solve[row][col] == num)
            return true;
    return false;
}

/************************************************************** 
 * Check the row  in a col to see if the numbers don't repeat
 *
 * @param solve the board for row
 * @param row iterator
 * @param num to find in rows of column
 * @return bool type found for true not there for false
 **************************************************************/
bool checkRow(int solve[MAX][MAX], int row, int num)
{
    for (int col = 0; col < MAX; col++)
        if (solve[row][col] == num)
            return true;
    return false;
}

 /************************************************************** 
 * This method will look through the section of the boxes that 
 * are contained in Sudoku. As they appear is a 3x3 matrix 
 *
 * @param solve the board for the section
 * @param row will use the beginning row of the section
 * @param col will use the beginning col of the section
 * @param num will find the number contained in section
 * @return bool type found for true not there for false
 **************************************************************/
bool checkSection(int solve[MAX][MAX], int row, int col, int num)
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (solve[r+row][c+col] == num)
                return true;
    return false;
}
  /************************************************************** 
 * This method will use the methods above combined to check all 
 * three statuses at the same time
 * 
 * @param solve the board for all three situation
 * @param row will use the current row
 * @param col will use the current col
 * @param num will find the number contained in section
 * @return bool type found for true not there for false
 **************************************************************/
bool canPlace(int grid[MAX][MAX], int row, int col, int num)
{
    return checkRow(grid, row, num) == false &&
           checkCol(grid, col, num) == false &&
           	checkSection(grid, row - row%3 , col - col%3, num)== false;
}

 /************************************************************** 
 * This method will tell the rest of the program if the spot is 
 * already taken.
 *
 * @param solve the board for the section
 * @param row will use the beginning row of the section
 * @param col will use the beginning col of the section
 * @param num will find the number contained in section
 * @return bool type found for true not there for false
 **************************************************************/
bool isFilled(int solve[MAX][MAX], int &row, int &col)
{
    for (row = 0; row < MAX; row++)
        for (col = 0; col < MAX; col++)
            if (solve[row][col] == 0)
                return true;
    return false;
}
	private: 
	
	/** solved board **/
	//int solve[MAX][MAX];

	/** board to play with **/
	int board[MAX][MAX]= {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
                       	      { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
	                      { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
           	              { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                              { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                              { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                              { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                   	      { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
	                      { 0, 7, 0, 0, 0, 0, 0, 3, 0 }

	        };
	/**flag if game done **/ 
	//bool complete=false;

	//int row;

	//int col;



};

		/********************************************
 		* main method to begin program 
 		*********************************************/
		int main(){
			Sudoku s;
			//s.backtrack();	
			s.printBoard();

			return 1;
		}
