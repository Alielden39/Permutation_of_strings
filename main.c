#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int length, char **ptr);
int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;

    return 0 ;
}




int next_permutation(int length, char **ptr)
{
   int key = length - 1 ;
   while(  (key>0) && ( strcmp(  ptr[key-1],ptr[key] )  >=0  )   )  // find key which is element bigger than his previous
   {
       key-- ;
   }
   if( key<=0 )
   {
       return 0 ;
   }
//////////////////////////////////////
    int successor = length -1 ;
    while(  strcmp(  ptr[key-1] , ptr[successor]  ) >=0  ) // find successor which is element bigger than the element smaller than key even if is the key
    {
        successor--;
    }
    char *temp = NULL ;

    temp = ptr[successor] ;  // swap the successor , the element smaller than key
    ptr[successor]= ptr[key-1] ;
    ptr[key-1] = temp ;
//////////////////////////////////////
    successor = length -1 ;
    while( key < successor ) // reverse the middle and wings
    {
        temp = ptr[key] ;
        ptr[key] = ptr[successor] ;
        ptr[successor] = temp ;
        successor-- ;
        key++ ;
    }
    return 1 ;
}
