#include<stdio.h>
#include "horspool.h"
#include<stdlib.h>
#include<string.h>
/*
* Given the pattern fill the shift table used by Horspool's algorithm
* Table[pattern[i]] indicates the amount to be shifted when there is mismatch
* Initialize all the elements of Table with the length of the pattern    
* The table size can be 26
*/
int *buildShiftTable(char *pattern)
{
    int * table=(int*)malloc(sizeof(int)*26);
    int i;
    for(i=0;i<26;i++)
    {
        table[i]=strlen(pattern);
    }
    for(i=0;i<(strlen(pattern)-1);i++)
    { 
        table[pattern[i]-'A']=strlen(pattern)-i-1;
    }
    for(i=0;i<26;i++)
    {
        printf("%d ",table[i]);
    }
    return table;
}

/*
* Implement the horspool's string matching algoritm using the buildShiftTable()
  function to build the shift table.
* Compute offset of the first and last occurence of pattern in the text,
  In case of no occurrences of the pattern the value should be set to -1.
* Compute the number of occurences of the pattern in the text.
* Compute the number of characters compared while finding all occurences of the pattern in the given text
* Characters must be matched from left to right
*/

Result *horspoolStringMatch(char *pattern, char *text)
{
    int * table=buildShiftTable(pattern);
    Result * r = (Result*)malloc(sizeof(Result));
    int i,j,count=0;
    for(i=0;i<strlen(text);i++)
    {
        int flag=1;
        for(j=(strlen(pattern)-1);j>=0;j--)
        {
            if(text[i+strlen(pattern)-j]!=pattern[j])
            {
                i=i+table[text[i+strlen(pattern)-j-1]-'A']-(strlen(pattern)-j-1)-1;
                flag=0;
            }
        }
        if(flag==1)
        {
            count++;
            if(count==1)
            {
                r->firstOccurrence=i;
                r->lastOccurrence=i;
            }
            else
            {
                r->lastOccurrence=i;
            }
            
        }
    }
    return r;
    
}
