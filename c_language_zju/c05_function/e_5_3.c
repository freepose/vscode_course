
// Example 5-3: Use a function to determine whether a number is a perfect square. 
// Define a function IsSquare(n) that returns 1 if n is a perfect square, and 0 otherwise. Do not use any math library functions.

#include <stdio.h>
#include <math.h>

int IsSquare( int n );

int main()
{
    int n;

    scanf("%d", &n);
    if ( IsSquare(n) ){
		printf("YES\n");
	}else{
		printf("NO\n");
	} 

    return 0;
}

int IsSquare (int n)				
{
		int i;
	
		for(i = 1; n > 0; i = i + 2){
			n = n - i;
		}
		if(n == 0){
			return 1; 		
		}else{
			return 0; 		
		}							
}
