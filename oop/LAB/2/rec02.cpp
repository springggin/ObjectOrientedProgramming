/*
  rec02_start.cpp
  spring 2024
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Hydrocarbon{
    vector <string> names;
    int carb;
    int hyd;
};

void open_file(ifstream& jab);
void fill_vector( ifstream& jab, vector<Hydrocarbon>& vh)

int main(){
  //Define variables for the stream and vector. 
  ifstream jab;
  open_file(jab);

  vector <Hydrocarbon> hydrocarbons;
  fill_vector(jab, hydrocarbons);

}

//Call a function to open the stream.
void open_file(ifstream& jab){ //everytime get file input, reference !!
  string filename;
  
  while(true){
    cout << "Enter file name:" << endl;
    cin >> filename;
    jab.open(filename);

    if (!jab){
      cerr << "failed to open " << filename << endl;
    }else{
      break;
    }
  }
}

//Call a function to fill the vector from the stream.
void fill_vector( ifstream& jab, vector<Hydrocarbon>& vh){
  Hydrocarbon h;
  while (getline(jab, row) ){
    insert_info(row, vh)
  }
}

//Call a function to display the vector
//string display(vector ??){}

//Call a function to sort the vector, in place.
//void sorting(vector ???){}

//Call a function to display the vector.
//void sorting(){}

//function to insert the information
void insert_info(string row,vector<Hydrocarbon>& vh){
  string name;
  jab >> name;
  vh[find_location(name)].name.push_back(name);



}
//A function to find the location of a formula object
int find_location(string obj){
  while()
  if vh[i].carb == obj

  return ind;


}
//A function to print out a single formula object.
