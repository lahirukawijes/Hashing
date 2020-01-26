#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

#define t_size 101

#define prime 37

using namespace std;

string English , French , Spanish, Word, Word2 ;

struct translator{
	
	translator* next ;
	string EnglishWord ;
    string FrenchWord ;
    string SpanishWord;
    
};

struct translator* Hashtable[t_size];  

//For the HashFunction
long hashsup(int index){
    
	int i=1;
    long y=1;
    while(i<=index){
        y=y*37;
        i++;
    }
    
    return y;
}

//hash Function
int HashFuncion(string EnglishWord){
    
    int i=0;
    
	int len=EnglishWord.length();
    unsigned long temp=0;
    
    while(i<len){
        temp=temp+((long)EnglishWord[i]*hashsup(i));
        i++;
    }
	 
	return temp%t_size;
}

//Adding words into the linked list
void add(string EnglishWord, string FrenchWord, string SpanishWord){
    
	long index = HashFuncion(EnglishWord);
    
    for(int i = 0; i < t_size; i++){
    	translator *newtranslator=new translator();
    	newtranslator->EnglishWord=EnglishWord;
    	newtranslator->FrenchWord=FrenchWord;
    	newtranslator->SpanishWord=SpanishWord;
    	newtranslator->next=NULL;
		if(Hashtable[index]==NULL){
			 Hashtable[index]=newtranslator;

		}else{
			translator *temp=Hashtable[index];
			while(temp->next){
				temp=temp->next;
			}
			temp->next=newtranslator;
		}
           return ;
       
    }

}

//To check whether the word is input word is exisiting in the hash table
translator* search(string EnglishWord){
    int index=HashFuncion(EnglishWord);
     
        if(Hashtable[index]!=NULL){

            if(Hashtable[index]->EnglishWord==EnglishWord){
            	return Hashtable[index];
			}else{
				translator * temp=Hashtable[index];
				while(temp){
					if(temp->EnglishWord==EnglishWord){
						return temp;
					}
					temp=temp->next;
				}
			}
        }
    	cout<<"["<<EnglishWord<< "]"<<endl;

	return NULL;
}

//Reading the given CSV file 
void reading(){
	  ifstream dictionary("Dictionary.csv");
    if(!dictionary.is_open()) 
	cout << "Error : cannot read file! " << endl ;
	string line;
    while(getline(dictionary,line)){
		  int x=line.find(",");
		  English=line.substr(0,x);
		  string temp=line.substr(x+1,line.length()-x);
		  x=temp.find(",");
		  French=temp.substr(0,x);
		  Spanish=temp.substr(x+1,temp.length()-x);
        
        add(English,French,Spanish);
        
    }
	dictionary.close();
}

//reading the custom phrase text file
void reading2(){
	
	ifstream readFile2("input.txt");
    
     if(!readFile2.is_open()) 
		cout << "Error : cannot read file! " << endl ;
	string inputline2;
	
    while(getline(readFile2,inputline2)){
		int i=0;
		string temp=inputline2;
		cout<<"Translated Sentence in French : ";
		while(1){
		int x=temp.find(" ");
		
		if(x == -1){
			Word2 = temp;
			cout<< search(Word2)->FrenchWord;
			cout<<" ";
			break;
		}
			
		Word2=temp.substr(0,x);
		cout<<search(Word2)->FrenchWord;
		cout<<" ";
		temp=temp.substr(x+1,temp.length()-x);
		i+=x;
		}
        
    }
}
int main(){
    
    int Count = 0,key;

    cout <<"\n";
    cout <<"*******Welcome to English-French Dictionary*******\n";
    cout <<"\n";
  
	ifstream readFile("input.txt");
	
    if(!readFile.is_open()) 
		cout << "Error : cannot read file! " << endl ;
	string inputline;
	
	cout<<"English Sentence : ";
    while(getline(readFile,inputline)){
		int i=0;
		string temp=inputline;
		
		while(1){
		int x=temp.find(" ");
		
		if(x == -1){
			Word = temp;
			cout<<Word;
			cout<<" ";
			break;
		}
			
		Word=temp.substr(0,x);
		cout<<" ";
		cout<<Word;
		cout<<" ";
		temp=temp.substr(x+1,temp.length()-x);
		i+=x;
		}
        
    }
    reading();
    cout << endl;
    reading2();
 	cout << endl;
    
  
    
    return 0 ;
}

