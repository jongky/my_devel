#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*******************************************************************/
/* [01] Pointers.1 : Basic                                         */
/*  Results :
    Address of var variable: bffd8b3c
    Address stored in ip variable: bffd8b3c
    Value of *ip variable: 20                                      */
/*******************************************************************/
int main () 
{

   int  var = 20;   /* actual variable declaration */
   int  *ip;        /* pointer variable declaration */

   ip = &var;  /* store address of var in pointer variable*/

   printf("Address of var variable: %x\n", &var  );
   /* address stored in pointer variable */
   printf("Address stored in ip variable: %x\n", ip );
   /* access the value using the pointer */
   printf("Value of *ip variable: %d\n", *ip );
   return 0;
}

/*******************************************************************/
/* [01] Pointers.2 : Basic                                         */
/*  Results :
    strcpy( str3, str1) :  Hello
    strcat( str1, str2):   HelloWorld
    strlen(str1) :  10                                             */
/*******************************************************************/
int main () 
{

   char str1[12] = "Hello";
   char str2[12] = "World";
   char str3[12];
   int  len ;

   /* copy str1 into str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );

   /* concatenates str1 and str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );

   /* total lenghth of str1 after concatenation */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );

   return 0;
}
/*******************************************************************/
/* [02] String.1 : Basic                                           */
/*******************************************************************/
size_t my_strlen(const char* str)
{
  if (str == NULL) {
    return 0;
  }
  int length = 0;
  const char *ch = str;
  while (*ch != '\0') {
    length++;
    ch++;
  }
  return length;
}

/*******************************************************************/
/* [03] String.1 : Basic                                           */
/*******************************************************************/
char* my_strchr(const char* str, int c)
{
  if (str == NULL) {
    return NULL;
  }
  while (*str != '\0') {
    if (*str == c)
      return (char*) str;
    str++;
  }
  return NULL;
}

/*******************************************************************/
/* [01] API to check Endian                                        */
/*******************************************************************/
int checkEndian(void)
{
	int i = 0x00000001;
    if ( ((char *) &i)[0])
    	printf(“Little Endian !!\n”);
    else
    	printf(“Big Endian !! \n”);
}

/*******************************************************************/
/* [02] API swap Endian                                            */
/*******************************************************************/
int main(void)
{
	int A = 0x11223344;
    int B = 0;

    B = (A >> 24 )  |
        ((A >> 16) & 0x00FF00) |
        ((A << 8) & 0x00FF0000) |
        ((A << 24) & 0xFF000000);    
}

/*******************************************************************/
/* [03] API to swap two values w/o using Pointer                   */
/*******************************************************************/
int swap(void)
{
	int a = 5, b = 10;

    a = a + b;
    b = a - b;
    a = a - b;
    printf (“ A= %d, B= %d \n”, a, b);
}

/*******************************************************************/
/* [04] API to reverse a value                                     */
/*******************************************************************/
int reverseValue()
{
	int num,r,reverse=0;

    printf("Enter any number: ");
    scanf("%d",&num);

    while(num){
    	r=num%10;
        reverse=reverse*10+r;
        num=num/10;
    }
    printf("Reversed of number: %d",reverse);
    return 0;
}

/*******************************************************************/
/* [05] API to find Max Sub Array Summary in an Array                                     */
/*******************************************************************/
int max(int x, int y)
{ return (y > x)? y : x; }
 
int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0], i;
   int curr_max = a[0];
 
   for (i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

/*******************************************************************/
/* [06] API to transform the string to as below 
    aaabbdcccccf = a3b2d1c5f1                                      */
/*******************************************************************/
int transformString()
{
  char str[50];
  printf("Enter a string \n");
  gets(str);

  int i;
  int c=1;
  printf("%c",str[0]);
  for(i=1;i<=strlen(str);i++)
  {
      if (str[i]!=str[i-1])
       {

        printf("%d",c);
        printf("%c",str[i]);
         c=1;
       }
       else if(str[i]==str[i-1])
       {
           c++;
       }
  }
}

/*******************************************************************/
/* [07] API to find first Non repeated char
/*******************************************************************/
char returnFirstNonRepeatedChar( char * str )
{
    int i, repeated = 0;
    int len = strlen(str);

    for( i = 0; i < len; i++ )
    {
        repeated = 0;
        for( j = 0; j < len; j++ )
        {
            if( i != j && str[i] == str[j] ) {
                repeated = 1;
                break;
            }
        }        
        // Found the first non-repeated character 
        if( repeated == 0 ) {  
            return str[i];
        }
    }
    return '';
}

/*******************************************************************/
/* [08] API to reverse the String
/*******************************************************************/
void reverse_string(char *str)
{
    if ((str == 0) || (*str == 0))
        return;

    char *start = str;
    char *end = start + strlen(str) - 1;  /* -1 for \0 */
    char temp;
    while (end > start)
    {
        temp = *start;
        *start = *end;
       *end = temp;
        ++start;
        --end;
    }
}

/*******************************************************************/
/* [09] API to reverse the order of Words in String
/*******************************************************************/
void reverseWords( char * str )
{
    int i = 0, j = 0;
    reverseString( str, strlen(str) ); // tsaf yrev si rac yM
    while( 1 ) // Loop forever
    {
        // Found a word or reached the end of sentence
        if( *(str+j) == ' ' || *(str+j) == '\0') 
        {
            reverseString( str+i, j-i );
            i = j+1;
        }
        if( *(str+j) == '\0')
        {
            break;
        }
        j++;
    }
}
void reverseString(char* str, int len)
{
    int i, j;
    char temp;
    i=j=temp=0;

    j=len-1;
    for (i=0; i<j; i++, j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}

/*******************************************************************/
/* [09] API to count repeated elements in an Array
     input is {1,1,1,1,2,2,2,3,3,4}
     output is 1=4 2=3  3=2  4=1
/*******************************************************************/
int main() {
  int input[] = {1,1,1,1,2,2,2,3,3,4};

  if (sizeof(input) == 0) return 0;

  int prev = input[0];
  int count = 1;
  int i;
  int ARRAYSIZE = sizeof(input) / sizeof(int);

  for (i = 1; i < ARRAYSIZE; i++) {
    if (input[i] == prev) {
      count++;
    } else {
      printf("%d=%d ", prev, count);
      prev = input[i];
      count = 1;
    }

  }
  printf("%d=%d\n", prev, count);
  return 0;
}

/*******************************************************************/
/* [10] Program for Fibonacci Series in C
     sequence is obtained by adding previous two numbers. 
     For example 0, 1, 1, 2, 3, 5, 8, 13.                          */
/*******************************************************************/
#include<stdio.h>
int main()
{
    int first=0,second=1,third,i,n;
 
    printf("Enter how many elements?");
    scanf("%d",&n);
    printf("\n%d %d",first,second);
 
    for(i=2;i<n;++i)
    {
        third=first+second;
        printf(" %d",third);
        first=second;
        second=third;
    }
    
    return 0;
}

/*******************************************************************/
/* [10] Program for Fibonacci Series in C
     sequence is obtained by adding previous two numbers. 
     For example 0, 1, 1, 2, 3, 5, 8, 13.                          */
/*******************************************************************/
int bitCount(unsigned int value)
{
	unsigned int count = 0; 
    while (value > 0) 
    { // until all bits are zero 
		if ((value & 1) == 1) // check lower bit 
    		count++; 
		value >>= 1; // shift bits, removing lower bit 
	} 
    return count; 
}
