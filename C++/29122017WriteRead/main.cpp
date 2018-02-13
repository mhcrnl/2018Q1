#include <iostream>
#include <fstream>

using namespace std;

class WriteReadFile{
public:
    void writeFile(string fileName){
        ofstream myfile;
        myfile.open(fileName);
        myfile<<"Scrie acest text in fila";
        myfile.close();
    }
    void readFile(string filename){

    }
};

int main()
{
    cout << "Hello world!" << endl;
    string fileName = "test.txt";
    WriteReadFile wrf;
    wrf.writeFile(fileName);
    return 0;
}
