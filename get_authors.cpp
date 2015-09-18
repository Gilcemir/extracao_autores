#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
using namespace std;

int main () {
    setlocale(LC_ALL,"Portuguese");
    string line;
    ifstream myfile ("input.txt");
    ofstream myOutputFile;
    myOutputFile.open("autores.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            string author;     
            int tam = line.length();

            cout<<line[tam-3]<<line[tam-2]<<line[tam-1]<<endl;
            myOutputFile<<line[tam-3]<<line[tam-2]<<line[tam-1]<<endl;

            for(int i = 0 ;i<tam;i++) {

                if(line[i]==','){
                    i++;
                    cout<<author<<endl;
                    myOutputFile<<author<<endl;
                    author.clear();
                }else if(line[i]==' ' && line[i+1]=='-'){
                    cout<<author<<endl;
                    myOutputFile<<author<<endl;
                    author.clear();
                    break;
                }else{
                    author+=line[i];
                }


            }

        }
        myfile.close();
        myOutputFile.close();
    }

    else cout << "Unable to open file";

    return 0;
}
