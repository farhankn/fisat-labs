#include<stdio.h>
main()
{
  char c;
  printf("Enter a character ");
  scanf("%c",&c);
  if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    printf("\nThe entered character is a vowel\n");
  else 
    printf("\nThe entered character is a consonant\n");
}
