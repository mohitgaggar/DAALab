#include "sm.h"
int searchFirstOccurrence(char *pattern, char *text)
{
    int m=strlen(pattern);
    int n=strlen(text);
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if(pattern[j]!=text[i+j])
                break;
            if(j==m-1)
                return  i;
        }
        
    }
    return -1;
}
int searchLastOccurrence(char * pattern, char * text)
{
    int m=strlen(pattern);
    int n=strlen(text);
    int j;
    for(int i=n-m+1;i>0;i--)
    {
        for(j=0;j<m;j++)
        {
            if(text[i+j]!=pattern[j])
            {
                break;
            }
        }
        if(j==m)
            return i;
    }  
    return -1;
}


// Find the number of occurrences of the pattern in the given text
int numOccurrences(char *pattern, char *text)
{
    int m=strlen(pattern);
    int n=strlen(text);
    int count =0;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if(pattern[j]!=text[i+j])
                break;
            if(j==m-1)
                count++;
        }
        
    }
    return count;
}
// Find the length of longest prefix of the pattern that matches a substring of the pattern
int longestPrefix(char *pattern, char *text)
{
    int m=strlen(pattern);
    int n=strlen(text);
    int j;
    int count =0,max=0,len=0;
    for(int i=0;i<n;i++)
    {
        for ( j=0;j<m;j++)
        {
            if(pattern[j]!=text[i+j])
                {
                    break;
                }
        }
        if(max < j)
            {
                max=j;
            }
        
    }
    return max;
}
// Count the number of characters compared while finding all occurences of the pattern in the given text
// Characters must be matched from left to right
int charactersCompared(char *pattern, char *text)
{
    int m=strlen(pattern);
    int n=strlen(text);
    int count =0;
    for(int i=0;i<n-m+1;i++)
    {
        for (int j=0;j<m;j++)
        {
            count++;
            if(pattern[j]!=text[i+j])
                break;
        }
        
    }
    return count;
}