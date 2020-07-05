#include <iostream>
#include <fstream>
using namespace std;

//Place these at the global level
ifstream in("input.txt");		//input.txt is the file that we read from
ofstream out("output.txt");	//output.txt is the file that we write into

int clean(){
      string com;  //comment
       while (in.peek()=='\n' || in.peek()=='/' || in.peek()==' ' || in.peek()=='\t'){
           if (in.peek()=='/' )
              getline(in, com);  //read the entire line because it is a comment
           else
              in.get();    //eat the newline, space and tab characters
      }
      return 1;
}


int stringPosition (char *A, char B)
{
	int position = 0;
	bool found = false;
	
	for (int i=0; i<= sizeof (A) && found==false;++i)
	{
		if(A[i]==B)
		{
			found = true;
		}
		
		else if (found == false && i== sizeof(A)-1)
		{
			position=-1;
		}
		
		else
		{
			++position;
		}
		
		
	}
	
	return position;
}


void stringConcatenation (char *A, char *B)
{
	bool x = false;
	int i = 0;
	
	for (;1<=sizeof(A) && x == false; ++i)
	{
		if (A[i]=='\0')
		{
			x = true;
		}
		
		if (x == true)
		{
			for (int j =0; j<= sizeof (B);++j,++i)
			{
				A[i] = B[j];
			}
		}
	}
	
	
}


bool stringCompare (char *A, char * B)
{
	bool x = true;
	for (int i =0; i<= sizeof(A) && x == true; ++i)
	{
		x = (A[i]==B[i]);
	}
	return x;
}


void stringCopy (char *A, char *B)
{
	int i;
	
	for(i=0; B[i] != '\0'; ++i)
	{
		A[i]=B[i];
	}
	
	A[i]='\0';
}


void stringLength (char * A)
{
	int l = 0;
	char temp [sizeof(A)+1]= {" "};
	for (int i=0; A[i] != '\0'; ++i)
	{
		++l;		
	}
	
	for (int i=0; i<=sizeof(A); ++i)
	{
		temp[i+1] = A[i];
	}
	
	for (int i =0; i<= sizeof(temp); ++i)
	{
		if (i==0)
		{
			A[i] = l + '0';
			
		}
		else
		{
			A[i]=temp[i];
		}
			
	}
}


void populate(char A[][15], char B[][15])
{
	for (int i=0; clean() && in.good(); ++i)
	{
		in >> A[i]>> B[i];
	}
	
	in.close();
}

int main ()
{
	char A[5][15], B[5][15];
	populate (A,B);
	out<<"string copy :\n";
	stringCopy(A[0],B[0]);
	out<<A[0]<<" "<<B[0]<<endl;
	
	bool same;
	out<<"\nString Compare :\n";
	same = stringCompare(A[1],B[1]);
	if (same)
	{
		out<<A[1]<<" and "<<B[1]<< " are the same\n";
	}
	else
	{
		out<<A[1]<<" and "<<B[1]<< " are different\n";
	}
	
	out<<"\nString Concatenation :\n";
	
	stringConcatenation(A[2],B[2]);
	
	out<<A[2]<<endl;
	
	int position;
	out<<"\nString Position :\n";
	
	
	position= stringPosition (A[3],B[3][0]);
	out<<"The Position of "<< B[3][0]<< " in " << A[3]<<" is "<<position<<endl;
	
	out<<"\nString length test:\n";
	stringLength(A[4]);
	for (int i = 0; A[4][i] !='\0';++i)
	{
		out<<A[4][i]<<" ";
	}
	
	in.close();
    out.close();
    
	return 0; 
}
