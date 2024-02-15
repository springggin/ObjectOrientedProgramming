/*
  rec01_start.cpp
  spring 2024
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//
// Function prototypes for tasks 15-17
//

// Task 15. Function to display a vector of ints



// Task 16. Function to modify the vector, using indices



// Task 17. Function to modify the vector, using a ranged for




//
// main

//
int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"
    //std::cout << "Hello world!";



    // Task 2  Printing hello ...  Using "using namespace"
    cout << "Helloworld\n";


    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable
    int x;
    //cout << x << "!\n";

    
    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.
    int y = 17;
    int z = 2000000017;
    double pie =  3.14159;

    cout << sizeof(y) << '\n';
    cout << sizeof(z) << '\n';
    
    
    // Task 5  Attempt to assign the wrong type of thing to a variable
    //x = 'felix';


    //
    // Conditions
    //

    // Task 6  Testing for a range

    if (y>10 && y<20) {
   cout << "True\n";
    } else {
   cout << "False\n";}
    
    

    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop
    for (int i = 10; i <= 20; ++i) {
          cout << i << "\n";
      }
    // Then with a while loop
    int i =10;
    while(i<=20){
      cout << i <<"\n";
      ++i;
    }

    // Finally with a do-while loop
    i = 10;
    do {
      cout << i <<"\n";
      ++i;
    } while ( i<=20 );


    // Task 8  Looping to successfully open a file, asking user for the name
  
    while (true) {
        string filename;
        cout << "Enter filename: ";
        cin >> filename;

        ifstream ifs(filename);

        if (!ifs) {
            cerr << "Failed to open the file. Please try again.\n";
        } else {
            cout << "File opened successfully!\n";
            // Task 9  Looping, reading file word by "word".
            string something;
            while (ifs >> something) {
              cout << something << endl;
            }
            ifs.close();  
            break;
        }

    }
 

    // Task 10 Open a file of integers, read it in, and display the sum.
    ifstream ifs("integers.txt");
    if (!ifs) {
            cerr << "Failed to open the file. Please try again.\n";
        } else {
          int num;
          int sum = 0;
          while (ifs >> num){
            sum += num;
          }
          ifs.close();
          cout << sum << endl;
        }


    // Taks 11 Open and read a file of integers and words. Display the sum.
    ifstream mix("mixed.txt");
    if (!mix) {
            cerr << "Failed to open the file. Please try again.\n";
        } else {
          int num;
          int sum = 0;
          while (mix >> num){
            sum += num;
          }
          mix.close();
          cout << sum << endl;
        }

    //
    // Vectors
    //

    // Task 12 Filling a vector of ints
    vector <int> v;

    for (size_t i=10; i<=100; ++i){
      if (i % 2 != 0 ){
        v.push_back(i);
      }
    }
    

  
    // Task 13 Displaying the vector THREE times
    //         a) using the indices,
    for (size_t i=0; i < v.size(); ++i){
          cout << v[i] << endl;
        }
    //         b) using a "ranged for"
    for (int value : v){
          cout << value << endl;
        }
    //         c) using indices again but backwards
    for (size_t i=v.size(); i > 0; i--){
          cout << v[i] << endl;
        }

    // Task 14. Initialize a vector with the primes less than 20. 
    vector <int> primes(2,3,5,7,9)
    for (int value : v){
    }
    //
    // Function calls
    //
    
    // Task 15  Function to print a vector


    // Task 16  Function to double the values in a vector


    // Task 17  Function to double the values in a vector, using a ranged for 

    
}

//
// Function definitions for tasks 15-17
//

// Task 15. Function to display a vector of ints



// Task 16. Function to modify the vector, using indices



// Task 17. Function to modify the vector, using a ranged for


