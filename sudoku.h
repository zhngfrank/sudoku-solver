#ifndef SUDOKU_H
#define SUDOKU_H


/*	1) check if original puzzle is okay
	2) set initial values to special
	3) starting at row 1 column 1, input test_value, starting at 1
	4) test if valid: first row, then column, then block.
	5) if false test_value++
	7) call function to move onto next (if current x = 9, then x = 1, y =2)
	8) if no test value is valid restart, where previous value at 1,1 
		is also invalid
	9) this is sloooowwwww
	
*/


class Sudoku
{
private: 
	int x_coordinate = 0;
	int y_coordinate = 0;
	int test_value = 0;
	vector<int> row;
	vector<int> column;
	bool test = true;
public:

	//basic setters and getters for each private member
	void setXCoordinate(int x_position) { x_coordinate = x_position; }
	void setYCoordinate(int y_position) { y_coordinate = y_position; }
	void setTestValue(int test) { test_value = test; }
	void setX(vector<int> row_test) { setX = row_test; }
	void setY(vector<int column_test) { setY = column_test; }
	void setTest(bool evaluate) { test = evaluate; }
	
	int getXCoordinate() const { return x_coordinate; }
	int getYCoordinate() const { return y_coordinate; }
	int getTestValue() const { return test_value; }
	int getrow() const { return row; }
	int getcolumn() const { return column; }
	int getTest() const { return test; }
	
	//advanced functions
	
	//menu/houskeeping
	int menu();
	void menuChoice( int choice );
	void inputOriginal();
	void beginTest();
	
	//check if original puzzle is valid, need only return 
	//if puzzle is valid or not
	bool checkOriginalXRow();
	bool checkOriginalYColumn();
	bool checkOriginalBlock();
	bool returnIfValid();
	
	//basic movement along the vectors and stuff
	int navigateX(int current_x);
	int navigateY(int current_y);
	int chooseTestValue(); //start with 1, keep adding until true
	void setInitialVector(); //initial puzzle set up
	bool testCurrent(); //test row, column, block
	
	//test if valid, if not valid return conflict location
	int xRowTest();
	int yColumnTest();
	int xBlockTest();
	int yBlockTest
	
	//check if value is from puzzle or testvalue e.g.
	//can it be modified?
	int forbiddenX();
	int forbiddenY();
	
};

#endif
