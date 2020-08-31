#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]){
ifstream fin;
ofstream fout;
char ch;
int i;
string record, read;
if(argc<5){ //if less than 5 arguments in command prompt
    cerr<<"Usage: caesarcipher mode sourcefile mode outputfile";
    exit(EXIT_FAILURE); //exit
}
else if(argc==5){ //if there are 5 arguments
    fin.open(argv[2]); //open input.txt
    fout.open(argv[4]); //open output.txt
    if(*argv[3]!='e' && *argv[3]!='d'){ //if its not encrypt or decrypt
        cerr<<"Invalid mode. Next time, enter e for encrypt or d for decrypt.";
        exit(EXIT_FAILURE);
    }
    if(!fin){ //if input file doesn't exist
        cerr<<argv[2]<<" cannot be opened.";
        exit(EXIT_FAILURE);
    }
    if(!fout){ //if output file doesn't exist
        cerr<<argv[4]<<" cannot be opened.";
        exit(EXIT_FAILURE);
    }
    fin.close(); //close input file
    fout.close(); //close output file
    if(argv[1][0]=='r' && argv[1][1]=='e' && argv[1][2]=='c' && argv[1][3]=='o' && argv[1][4]=='r' && argv[1][5]=='d'){ //for record
        if(*argv[3]=='e'){ //to encrypt
            cout<<"Using uppercase letters, enter the text to be encrypted (add Ctrl + Z at the end): ";
            fout.open(argv[2], ios_base::out | ios_base::trunc);
            cin.get(ch);
            while(cin.fail()==false){ //while there are still characters to read or not ctrl + z
                record+=ch;
                cin.get(ch);
            }
            fout<<record; //put original into input.txt
            fout.close();
            for(i=0; i<record.size(); i++){
                if(record[i]=='X' || record[i]=='Y' || record[i]=='Z'){ //if x y or z loop back to beginning of alphabet
                    record[i]-=23;
                }
                else if(record[i]>=65 && record[i]<=87){ //shift 3 characters down
                    record[i]+=3;
                }
            }
            fout.open(argv[4], ios_base::in);
            fout<<record; //put encrypted message into output.txt
            fout.close();
            fin.close();
            cout<<"The orginal mesesage has been recorded in input.txt."<<endl<<"The encrypted message has been recorded in output.txt."<<endl;
        }
        else if(*argv[3]=='d'){ //to decrypt
            cout<<"Using uppercase letters, enter the text to be decrypted (add Ctrl + Z at the end): ";
            fout.open(argv[2], ios_base::out | ios_base::trunc);
            cin.get(ch);
            while(cin.fail()==false){ //see comments above
                record+=ch;
                cin.get(ch);
            }
            fout<<record;
            fout.close();
            for(i=0; i<record.size(); i++){
                if(record[i]=='A' || record[i]=='B' || record[i]=='C'){ //if a b or c loop to end of alphabet
                    record[i]+=23;
                }
                else if(record[i]>='D' && record[i]<='Z'){//shift 3 characters up
                    record[i]-=3;
                }
            }
            fout.open(argv[4], ios_base::in);
            fout<<record;
            fin.close();
            fout.close();
            cout<<"The original message has been recorded into "<<argv[2]<<endl<<"The decrypted message has been recorded in "<<argv[4]<<endl;
        }
    }
    else if(argv[1][0]=='r' && argv[1][1]=='e' && argv[1][2]=='a' && argv[1][3]=='d'){ //for read
        if(*argv[3]=='e'){
            fin.open(argv[2], ios_base::in);
            while(fin.get(ch)){
                read+=ch; //get input from input file
            }
            for(i=0; i<read.size(); i++){ //see above comments
                if(read[i]=='X' || read[i]=='Y' || read[i]=='Z'){
                    read[i]-=23;
                }
                else if(read[i]>=65 && read[i]<=87){
                    read[i]+=3;
                }
            }
            fout.open(argv[4], ios_base::out | ios_base::trunc);
            fout<<read;
            fin.close();
            fout.close();
            cout<<"The original message has been read in "<<argv[2]<<endl<<"The encrypted message has been recorded in "<<argv[4]<<endl;
        }
        else if(*argv[3]=='d'){ //see comments above
            fin.open(argv[2], ios_base::in);
            while(fin.get(ch)){
                read+=ch;
            }
            for(i=0; i<read.size(); i++){
                if(read[i]=='A' || read[i]=='B' || read[i]=='C'){
                    read[i]+=23;
                }
                else if(read[i]>='D' && read[i]<='Z'){
                    read[i]-=3;
                }
            }
            fout.open(argv[4], ios_base::out | ios_base::trunc);
            fout<<read;
            fin.close();
            fout.close();
            cout<<"The original message has been read in "<<argv[2]<<endl<<"The decrypted message has been recorded in "<<argv[4]<<endl;
        }
    }
}
return 0;
}
