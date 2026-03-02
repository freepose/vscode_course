
// Example 7-2: Calculate the first n numbers of the Fibonacci sequence (1≤n≤46), 
// i.e., 1, 1, 2, 3, 5, …,55, and output them in a format of 5 numbers per line. If the last line has fewer than 5 numbers, it should also be wrapped.

# include <stdio.h>

# define MAXN 46					

int main(void)
{
    int i, n;
    int fib[MAXN] = {1, 1};        	

    printf ("Enter n: ");           
    scanf ("%d", &n); 
    if(n >= 1 && n <= 46 ){
        
        for(i = 2; i < n; i++){   
            fib[i] = fib[i - 1] + fib[i - 2];
        } 

        
        for(i = 0; i < n; i++){ 
            printf("%11d", fib[i]);
            if((i + 1) % 5 == 0){  	
                printf("\n"); 
            }  
        }
        if(n % 5 != 0){      		
            printf("\n");
        } 
    }else{
        printf("Invalid Value.\n");	
    }

    return 0;
}  

// Enter n: 10
// 1          1          2          3          5
// 8         13         21         34         55