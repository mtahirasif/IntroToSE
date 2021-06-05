#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include<cmath>

using namespace std;



void SearchGrid()  //if user presses S, this function is called
{
	string InFile; //Stores name of file that has grid
	cout<<"Enter name of Grid File: ";
	cin>>InFile;
	
	string InFile2; //Stores name of file that has words
	cout<<"Enter name of File that has Words: ";
	cin>>InFile2;
	ifstream WORDS(InFile2);
	int rows; 
	int cols;
	int NoOfWords; //Stores the number of words user will enter
	
	
	WORDS>>rows;
	WORDS>>cols;
	WORDS>>NoOfWords;



	string WordsToSearch[NoOfWords]; //String array to store the words
	
	for(int i=0; i<NoOfWords; i++)
	{
		WORDS>>WordsToSearch[i];
	}
		
	char grid[18][19];

	string OutName;
	cout<<"Enter name of the Output file: ";
	cin>>OutName;
			
		ifstream INPUT(InFile); 
		ofstream OUTPUT(OutName); //Creating a new file
		 
		 //Loading the grid in the the 2-D Array named grid		 		 
		 for( int i = 0 ; i < rows ; i++)
			{
				for(int j = 0 ; j < cols ; j++)
				{
					INPUT>>grid[i][j] ; 
				}
			}
			
		INPUT.close();		
	
//--------------------------------------------------------- 
	
    bool found = false; //It is true when a word has been found
	int count = 0;    	   
	bool present = false; //Tells if the word to be searched is present in the grid or not
	
	while(count < NoOfWords)
	{

		bool mycheck = false;	
		bool Found_Word = false; 
		int Length = WordsToSearch[count].length(); 
		
		for(int i = 0 ; i < rows ; i++ ) //Search Right to Left
		{
			for(int j = rows ; j>=0 ; j--)  
			{
				if(grid[i][j] == WordsToSearch[count][0]) //Compares the first character of the WordsToSearch with the alphabet in grid
				{
					for(int k = 1 ; k < Length ; k++) 
					{
						if(grid[i][j-k] != WordsToSearch[count][k])
						{
							Found_Word = false;
							break;	//breaks the loop if character of WordsToSearch and the character in the grid differ
						}
						else
						{
							Found_Word = true;
						}
					}
					
					if(Found_Word != false)
					{
						OUTPUT << endl  << "(" << i << ", " << j << ")  (" << i << ", " << j - Length + 1 << ")\n";
						cout << endl  << "(" << i << ", " << j << ")  (" << i << ", " << j - Length + 1 << ")\n";
						mycheck = true;
					}
				}
			}
		}
	
		for(int i = 0 ; i < rows ; i++) //Search Left to Right
		{
			for(int j = 0 ; j < cols ; j++)
			{                                       
				if(grid[i][j] == WordsToSearch[count][0])
				{
					for(int k = 1 ; k < Length ; k++)
					{
						if(grid[i][j+k] != WordsToSearch[count][k]) 
						{
							Found_Word = false;
							break;
						}
						else
						{
							Found_Word = true;
						}
					}
					
					if(Found_Word != false)
					{
						OUTPUT << endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						cout << endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						mycheck = true;
					}
				}
			}
		}	
	
		for(int i = 0 ; i < cols ; i++) //Search Up to Down
		{
			for(int j = 0 ; j < rows ; j++)
			{
				if(grid[i][j] == WordsToSearch[count][0])
				{
					for(int k = 1 ; k < Length ; k++)
					{
						if(grid[i + k][j] != WordsToSearch[count][k])  
						{
							Found_Word = false;
							break;
						}
						else
						{
							Found_Word = true;
						}
					}
					
					if(Found_Word != false)
					{
						OUTPUT << endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						cout<< endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						mycheck = true;
					}
				}
			}
		}
	
		for(int i = 0 ; i < cols ; i++) //Search Down to Up
		{
			for(int j = rows - 1 ; j >= 0 ; j--)
			{
				if(grid[i][j] == WordsToSearch[count][0])
				{
					for(int k = 1 ; k < Length ; k++)
					{
						if(grid[i - k][j] != WordsToSearch[count][k]) 
						{
							Found_Word = false;
							break;
						}
						else
						{
							Found_Word = true;
						}
					}
					
					if(Found_Word != false)
					{
						OUTPUT << endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						cout<<endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						mycheck = true;
					}
				}
			}
		}
	
		for(int i = 0 ; i < cols ; i++) //Search Right Diagonally
		{
			for(int j = 0 ; j < rows ; j++)
			{
				if(grid[i][j] == WordsToSearch[count][0])
				{
					for(int k = 1 ; k < Length ; k++)
					{
						if(grid[i + k][j + k] != WordsToSearch[count][k]) 
						{
							Found_Word = false;
							break;
						}
						else
						{
							Found_Word = true;
						}
					}
					
					if(Found_Word != false) // if WordsToSearch matches then print on console and in the created file
					{
						OUTPUT << endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						cout<<endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						mycheck = true;
					}
				}
			}
		}
	
		for(int i = 0 ; i < cols ; i++) //Search Left Diagonally
		{
			for(int j = 0 ; j < rows ; j++)
			{
				if(grid[i][j] == WordsToSearch[count][0])
				{
					for(int k = 1 ; k < Length ; k++)
					{
						if(grid[i - k][j - k] != WordsToSearch[count][k])  
						{
							Found_Word = false;
							break;
						}
						else
						{
							Found_Word = true;
						}
					}
					
					if(Found_Word != false) 
					{
						OUTPUT << endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						cout<<endl  << "(" << i << ", " << j << ")  (" << i << ", " << Length - 1 << ")\n";
						mycheck = true;
					}
				}
			}
		}
	
	
		if(mycheck == false && Found_Word == false)
		{
			OUTPUT<< "\nNot Found";
			cout<< "\nNot Found\n";
		}
		    count++;
	}
	
	OUTPUT.close();  	
	
}

void StoreInFile(char grid[][10], string OutFileName, int Rows, int Cols)
{	//Stores the grid in a file
	ofstream OUTPUT (OutFileName);
	
	for (int i=0; i<Rows; i++) 
	{
		for (int j=0; j<Cols; j++) 
		{
			OUTPUT << grid[i][j] << " ";
		}
		OUTPUT<<endl;
	}
	
	OUTPUT.close();
	
	cout<<"The grid has been saved in the File `"<<OutFileName<<"'"<<endl<<endl;
}

bool UpDiagonalPlacement(char grid[][10], string word)	
{	//Places the word in up diagonal position in the grid
	bool check = false;
	int temp = (11 - word.length());
	int RowNo = rand()%temp;
	int ColNo = rand()%temp;
				        
	for (int i=RowNo, j=0, k=ColNo; j<word.length(); i--, j++, k++)
	{
	    if (grid[i][k]==' ' || word[j]==grid[i][k])
	    {
	 		check=true;
	    }
	    else
	    {
	    	check=false;
	    	break;
		}
	}
				        
	if (check==true)
	{
		for (int i=0; word[i]!='\0'; i++, RowNo--, ColNo++)	
	    {////Placing the word in up diagonal position
	        grid[RowNo][ColNo] = word[i];
	    }
	}
	
	return check;
}

bool DownDiagonalPlacement(char grid[][10], string word)	
{	//Places the word in down diagonal position in the grid
	bool check = false;
	int temp = (11 - word.length());
	int RowNo = rand()%temp;	
	int ColNo = rand()%temp;
				        
	for (int i=RowNo, j=0, k=ColNo; j<word.length(); i++, j++, k++)
	{
	    if (grid[i][k]==' ' || word[j]==grid[i][k])
	    {
	 		check = true;
	    }
	    else
	    {
	    	check = false;
	    	break;
		}
	}
				        
	if (check == true)
	{//Placing the word in down diagonal position
		for (int i = 0; word[i] !='\0'; i++, RowNo++, ColNo++)	
	    {
	        grid[RowNo][ColNo] = word[i];
	    }
	}
	
	return check;
}

bool UpAndDownPlacement(char grid[][10], string word)	
{	//Places the word vertically in the grid
	bool check = false;
	int temp = (11 - word.length());
	int RowNo = rand()%temp;
	int ColNo = rand()%10;	
			        
	for (int i=RowNo, j=0; j<word.length(); i++, j++)
	{
	    if (grid[i][ColNo]==' ' || word[j]==grid[i][ColNo])
	    {
	 		check=true;
	    }
	    else
	    {
	    	check=false;
	    	break;
		}
	}
			        
	if (check==true)
	{
		for (int i = 0; word[i]!='\0'; i++, RowNo++)	// Only RowNo number increases when placing vertically
	    {
	        grid[RowNo][ColNo]=word[i];
	    }
	}
	
	return check;
}

bool LeftAndRightPlacement(char grid[][10], string word)	
{	//Places the word horizontally in the grid
	
	bool check = false;		
	int temp= (11 - word.length());
	
	// Random number generated to place the word
	int RowNo = rand()%10;
	int ColNo = rand()%temp;
	
	//Loop to check the availability of empty space to place the word on the grid		       
  	for (int i = ColNo, j = 0; j < word.length(); i++, j++)
    {	
	    if (grid[RowNo][i] == ' ' || word[j] == grid[RowNo][i])	
	    {//Checks if it is possible to overlap an alphabet
			check = true;
		}
		else
		{
			check = false;
		   	break;
		}
	}
			        
	if (check == true)
	{
		for (int i=0; word[i]!='\0'; i++, ColNo++)	
	    {
		    grid[RowNo][ColNo] = word[i];
		}
	}
	
	return check;
}

void PuttingWordsInGrid(char grid[][10], string words[], int WordsCount)	
{	//Randomly Places a word in the grid
	int RandNum;
	//i is incremented everytime a word is placed in the grid
	for (int i=0; i<WordsCount; )
	{
		RandNum = rand()%4;	//Generates and stores Random number
		
		if (RandNum==0)
		{
			if (LeftAndRightPlacement(grid, words[i]))
			{
				i++;
			}
		}
		if (RandNum==1)
		{
			if (UpAndDownPlacement(grid, words[i])) 
			{
				i++;
			}
		}
		if (RandNum==2)
		{
			if (DownDiagonalPlacement(grid, words[i])) 
			{
				i++;
			}
		}
		if (RandNum==3)
		{
			if (UpDiagonalPlacement(grid, words[i]) ) 
			{
				i++;
			}
		}
	}
}

void SortWords(string words[], int WordsCount)	
{	//Arranges words from bigger to smaller lengths(Descending order)
	string TempStr;
	
	for(int i = 0; i< (WordsCount - 1); i++)
	{
		for(int j = i + 1; j < WordsCount; j++)
		{
			int String1 = words[i].length();
			int String2 = words[j].length();
			
			if(String2>String1)
			{
				TempStr = words[i];
				words[i] = words[j];
				words[j] = TempStr;
			}
		}
	}
}

bool CreateGrid()
{

	bool flag = true;
//---------------------------------------
	string InFileName; //Stores Name of Input File
	string OutFileName; //Stores Name of Output File
	int NoOfWords;
	int Rows = 0, Cols = 0;
	cout<<"\n\nName of the Input File: ";
	cin>>InFileName;
	
	cout<<"\n\nNo. of Words in the file: ";
	cin>>NoOfWords;
	
	cout<<"\n\nNumber of Rows: ";
	cin>>Rows;
	
	cout<<"\n\nNumber of Cols: ";
	cin>>Cols;
	
	cout<<"\n\nName of the output file: ";
	cin>> OutFileName;
	
	int total = (Rows*Rows) + (Cols * Cols);
	int diagonal = sqrt(total);
			
	char grid[10][10];	
	int WordsCount = 0;
	string words[10];	
	
	ifstream INPUT (InFileName);
	
	//This loop stores all the words in an array
	for (int i = 0; i<NoOfWords; i++)
	{
		INPUT >> words[i];	
		WordsCount++;	
	}
	INPUT.close(); 		
	
	for(int i=0; i<NoOfWords; i++)
	{
		if(words[i].length() > diagonal)
		{
			flag = false;
			return flag;
		}	
	}
	
	//Initializing the grid with spaces so that later unused spaces can easily be made alphabets
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			grid[i][j] = ' ';
		}
	}	
	
	SortWords(words, WordsCount); //Sorts the words in descending order according to their lengths	
	PuttingWordsInGrid(grid, words, WordsCount);	 


	//Filling the empty spaces in the grid
	 for(int i=0; i<Rows; i++)
	 {
	 	for(int j=0; j<Cols; j++)
	 	{
	 		if(grid[i][j]==' ')
			 {
			 	do
				{
					grid[i][j]=rand();
					
				}while(!(grid[i][j]>=65 && grid[i][j]<=90));
			 }	
		}
	 }

	StoreInFile(grid, OutFileName, Rows, Cols); //Stores the grid in a file

	
	return flag;
}

int main()
{
	char choice;
	
	while(choice != 'Q' && choice != 'q')
	{	
		//system("CLS");
		
		cout<<"\n1) Create Grid"<<endl;
		cout<<"2) Search Words from Grid"<<endl;	
		cout<<"3) Quit"<<endl;	
		
		cout<<"\nEnter your choice: ";
		cin>>choice;
		
		if(choice != 'C' && choice != 'S' && choice != 'Q' && choice != 'c' && choice != 's' && choice != 'q')
		{
			cout<<"\nInvalid Choice!";
			Sleep(1500);
			
		}
		
		if(choice == 'C' || choice =='c')
		{
			bool check = CreateGrid();
			if(check == false)
			{
				cout<<"\nGrid cannot be formed, Press any key to reurn to the Homescreen: ";
				string temp;
				cin>>temp;
				cout<<"\n\n\n";
			}
			
			Sleep(2000);
		}
		
		if (choice == 'S' || choice == 's')
		{
			SearchGrid();
			cout<<"\n\n\n";			
		}
		

	}
	
	cout<<endl<<endl;
	system("pause");
	return 0;
}
