
// Example 8-9: Find the smallest string. Input n strings and output the smallest string among them.
// Program A: Process strings

#include <stdio.h>

#include <string.h>

int main( )
{
	int i, n;
    char sx[80], smin[80];  
	  
    scanf("%d", &n); 
    scanf("%s", sx);
    
    strcpy(smin, sx); 
    for(i = 1; i < n; i++){
    	scanf("%s", sx);
       	if(strcmp(sx, smin) < 0){
       		strcpy(smin, sx);
	   	}     
    }
    printf("min is %s\n", smin);

    return 0;
}    

// 5
// tool key about zoo sea
// min is about