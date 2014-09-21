#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  const int MAXSIZE=256;
  int step, retval;
  FILE* fp;

  // Set up some string segments for combining with arguments.
  
  char start[MAXSIZE]="file ";
  char ending[MAXSIZE]=" | /usr/xpg4/bin/grep -q directory; exit $?";
  char state[MAXSIZE];
  char start2[MAXSIZE]="cat ";
  char ending2[MAXSIZE]="/* 2> /dev/null | wc -l";
  char result[MAXSIZE];
  
  for ( step=1;step<argc;step++ )
    {
      strcpy(state,start);                // Constructing the string to call.
      strncat(state,argv[step],MAXSIZE);
      strncat(state,ending,MAXSIZE);
      retval=system(state);               // System call to check if directory.
      if ( retval == 0 )
	{
	  strcpy(state,start2);
	  strncat(state,argv[step],MAXSIZE);
	  strncat(state,ending2,MAXSIZE);
	  fp=popen(state,"r");            // Pipe with the line count.
	  if ( fp == NULL )
	    {
	      cout << "Could not open command" << endl;
	      return 1;
	    }
	  else
	    {
	      fgets(result,256,fp);
	      cout << argv[step] << "		" << result;
	      pclose(fp);
	    }
	}
    }
  return 0;
}
