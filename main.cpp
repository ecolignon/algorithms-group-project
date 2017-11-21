/*********************************************************************
** Author: Bryce Bristow, Evin Colignon, & Romano Garza
** Date: 11/20/17
** Description: This is the main file for a program that takes a .txt
** input file argument when ran. Within the input file, each line has 
** 3 numbers denoting an integer identifier, an x coordinate, and a 
** y coordinate. The file input is stored in a vector. It is then used 
** to determine a solution to the traveling saleman problem given the 
** locations and coordinates.  
*********************************************************************/
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream> 

struct tsp_coordinate 
{
	int identifier; 	// first integer on .txt file line
	int x_coordinate;   // second integer on .txt file line
	int y_coordinate; 	// third integer on .txt file line
}; 

// function prototype for TSP vector generator
void generate_tsp_vector(char* file_name, std::vector<struct tsp_coordinate> &v);


int main(int argc, char **argv)
{
	// store the argument file name that was passed 
	// on the commmand line when the program
	// was run 
	char* argument_file_name = argv[1]; 
	// declare the vector for holding our coordinates
	std::vector<tsp_coordinate> tsp_vector; 

	//generate a tsp vector from the file name
	generate_tsp_vector(argument_file_name, tsp_vector); 

	//test generate_tsp_vector functionality
	/*for(int i= 0; i < tsp_vector.size(); i++)
	{
		std::cout << "ID: " << tsp_vector[i].identifier << std::endl; 
		std::cout << "X: " << tsp_vector[i].x_coordinate << std::endl;
		std::cout << "Y: " << tsp_vector[i].y_coordinate << std::endl;
		std::cout << std::endl << std::endl; 
	}*/

	return 0; 

}

void generate_tsp_vector(char* file_name, std::vector<struct tsp_coordinate> &v)
{
	// declare variable that will hold file & line data 
	std::ifstream file(file_name); 
	std::string line; 
	
	// check for file open errors
	if(!file)
	{
		std::cout << "Error opening file" << file_name << std::endl; 
		return; 
	}

	// get lines and fill out the vector
	while(std::getline(file, line))
	{
		//declare an input string stream so we can move through the line
		std::istringstream iss(line); 
		//declare an integer to hold the current number and one to hold the count; 
		int n, count = 0; 
		//declare a new TSP struct; 
		tsp_coordinate current_coordinate; 

		while(iss >> n)
		{
			if(count == 0) // first number is identifier
			{			   // save as such 
				current_coordinate.identifier = n; 
			}
			else if(count == 1) // second number is x coordinate
			{					// save as such 
				current_coordinate.x_coordinate = n; 
			}
			else if(count == 2)  // third number is y coordinate
			{					 // save as such
				current_coordinate.y_coordinate = n; 
			}
			else
			{
				std::cout << "Error: Too many numbers on a line" << std::endl; 
				return; 
			}
			count++; 
		}

		// now we can save the new struct to the vector we 
		// passed in 
		v.push_back(current_coordinate);  
	}
	//close the file 
	file.close(); 
}