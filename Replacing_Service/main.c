#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE  30
typedef unsigned char U8;
typedef char C8;
typedef enum
{
    STRING_NOT_MATCHED = -1,
    STRING_MATCHED = 0
}tenuCompareState;


int compare_string(const U8 *first, const U8 *second, U8 u8StringSize);
int compare_string(const U8 *first, const U8 *second, U8 u8StringSize)
{
    tenuCompareState enuStringCompareState = STRING_MATCHED;
    if(u8StringSize < 1)
    {
        enuStringCompareState = STRING_NOT_MATCHED;
    }
    else
    {
        while((enuStringCompareState == STRING_MATCHED)&&(u8StringSize > 0))
        {
            if(*first==*second)
            {
                first++;
                second++;
                u8StringSize--;
            }
            else
            {
                enuStringCompareState = STRING_NOT_MATCHED;
            }

        }
    }

    return enuStringCompareState;
}

int main()
{
    tenuCompareState enuStringCompareState = STRING_NOT_MATCHED;
    U8 au8InputCommand[200];

    U8 au8FileNameSize[100];
    U8 au8FileNameIndex[100];

    U8 u8FOptIndex = 0  ;
    U8 u8BOptIndex = 0 ;
    U8 u8LOptIndex = 0  ;
    U8 u8IOptIndex = 0  ;

    U8 u8FromStringIndex = 0 ;
    U8 u8FromStringSize = 0 ;
    U8 u8ToStringIndex = 0 ;
    U8 u8ToStringSize = 0 ;
    U8 u8SpacerStringIndex = 0 ;

    U8 u8TempStringIndex = 0 ;
    U8 u8TempStringPosIndex = 0 ;

    U8 u8FileNameIndex = 0 ;
    U8 u8FileIndex = 0 ;
    FILE *FilePointer[10];
    FILE *FilePointerBkp[10];


    char au8StringNameFile[20];
    U8 u8Counter = 0 ;
    int a;
    U8 u8TempFromStringSize;
    U8 u8TempCounter = 0 ;
    unsigned long u32TempFileAdd = 1 ;

    /*  FILE* myFile = fopen("file.txt",     );*/
    printf("Please enter a command:\n");
    /*_flushall ();*/
    /*_CRTIMP int __cdecl __MINGW_NOTHROW	scanf (const char*, ...);*/
    /*scanf("%80s" ,au8InputCommand);*/
    scanf ("%[^\n]s", au8InputCommand);
    printf("%s\n",au8InputCommand);
    enuStringCompareState = compare_string((const U8 *)&au8InputCommand[0] , (const U8 *)"replace ", 8);

    if(enuStringCompareState == STRING_MATCHED)
    {
        printf("MATCHED\n");
        /* get options */
        enuStringCompareState = STRING_NOT_MATCHED;
        u8TempStringIndex = 8 ;
        while((enuStringCompareState == STRING_NOT_MATCHED)&&(u8TempStringIndex < 100))
        {
            enuStringCompareState = compare_string((const U8 *)&au8InputCommand[u8TempStringIndex] , (const U8 *)" -- ", 4);
            if(enuStringCompareState == STRING_NOT_MATCHED)
            {
                u8TempStringIndex++;
            }
            else
            {
                u8SpacerStringIndex = u8TempStringIndex + 1;
            }

        }

    }
    if(enuStringCompareState == STRING_MATCHED)
    {
        printf("MATCHED\n");
        /* get options */
        enuStringCompareState = STRING_NOT_MATCHED;
        u8TempStringIndex--;
        while((enuStringCompareState == STRING_NOT_MATCHED)&&(u8TempStringIndex > 7))
        {
            enuStringCompareState = compare_string((const U8 *)&au8InputCommand[u8TempStringIndex] , (const U8 *)" ", 1);
            if(enuStringCompareState == STRING_NOT_MATCHED)
            {
                u8TempStringIndex--;
            }

            }
        u8ToStringIndex = u8TempStringIndex + 1;
        u8ToStringSize = (u8SpacerStringIndex - u8ToStringIndex ) - 1;

    }
    if(enuStringCompareState == STRING_MATCHED)
    {
        printf("MATCHED\n");
        /* get options */
        enuStringCompareState = STRING_NOT_MATCHED;
        u8TempStringIndex--;
        while((enuStringCompareState == STRING_NOT_MATCHED)&&(u8TempStringIndex > 7))
        {
            enuStringCompareState = compare_string((const U8 *)&au8InputCommand[u8TempStringIndex] , (const U8 *)" ", 1);
            if(enuStringCompareState == STRING_NOT_MATCHED)
            {
                u8TempStringIndex--;
            }

        }
        u8FromStringIndex = u8TempStringIndex + 1;
        u8FromStringSize = (u8ToStringIndex - u8FromStringIndex ) - 1;

    }
    if(enuStringCompareState == STRING_MATCHED)
    {
        printf("MATCHED\n");
        u8FOptIndex = 0  ;
        /* get options */
        enuStringCompareState = STRING_NOT_MATCHED;
        u8TempStringIndex = u8FromStringIndex - 2;
        while((enuStringCompareState == STRING_NOT_MATCHED)&&(u8TempStringIndex > 7))
        {
            enuStringCompareState = compare_string((const U8 *)&au8InputCommand[u8TempStringIndex] , (const U8 *)"-f", 2);
            if(enuStringCompareState == STRING_NOT_MATCHED)
            {
                u8TempStringIndex--;
            }
            else
            {
                u8FOptIndex = u8TempStringIndex  ;
            }

        }


        u8BOptIndex = 0 ;
        /* get options */
        enuStringCompareState = STRING_NOT_MATCHED;
        u8TempStringIndex = u8FromStringIndex - 2;
        while((enuStringCompareState == STRING_NOT_MATCHED)&&(u8TempStringIndex > 7))
        {
            enuStringCompareState = compare_string((const U8 *)&au8InputCommand[u8TempStringIndex] , (const U8 *)"-b", 2);
            if(enuStringCompareState == STRING_NOT_MATCHED)
            {
                u8TempStringIndex--;
            }
            else
            {
                u8BOptIndex = u8TempStringIndex  ;
            }

        }
        u8LOptIndex = 0  ;
        /* get options */
        enuStringCompareState = STRING_NOT_MATCHED;
        u8TempStringIndex = u8FromStringIndex - 2;
        while((enuStringCompareState == STRING_NOT_MATCHED)&&(u8TempStringIndex > 7))
        {
            enuStringCompareState = compare_string((const U8 *)&au8InputCommand[u8TempStringIndex] , (const U8 *)"-l", 2);
            if(enuStringCompareState == STRING_NOT_MATCHED)
            {
                u8TempStringIndex--;
            }
            else
            {
                u8LOptIndex = u8TempStringIndex  ;
            }

        }
        u8IOptIndex = 0  ;
        /* get options */
        enuStringCompareState = STRING_NOT_MATCHED;
        u8TempStringIndex = u8FromStringIndex - 2;
        while((enuStringCompareState == STRING_NOT_MATCHED)&&(u8TempStringIndex > 7))
        {
            enuStringCompareState = compare_string((const U8 *)&au8InputCommand[u8TempStringIndex] , (const U8 *)"-i", 2);
            if(enuStringCompareState == STRING_NOT_MATCHED)
            {
                u8TempStringIndex--;
            }
            else
            {
                u8IOptIndex = u8TempStringIndex  ;
            }
        }

        enuStringCompareState = STRING_MATCHED;
    }

    if(enuStringCompareState == STRING_MATCHED)
    {
        /* get file names */
        u8TempStringIndex = u8SpacerStringIndex + 2;
        u8FileNameIndex = 0 ;
        while(u8TempStringIndex < 80)
        {
            enuStringCompareState = compare_string((const U8 *)&au8InputCommand[u8TempStringIndex] , (const U8 *)".txt", 4);
            if(enuStringCompareState == STRING_MATCHED)
            {
                enuStringCompareState = STRING_NOT_MATCHED;
                u8TempStringPosIndex = u8TempStringIndex ;
                while(enuStringCompareState == STRING_NOT_MATCHED)
                {

                    enuStringCompareState = compare_string((const U8 *)&au8InputCommand[u8TempStringPosIndex] , (const U8 *)" ", 1);
                    if(enuStringCompareState == STRING_NOT_MATCHED)
                    {
                        u8TempStringPosIndex--;
                    }
                    else
                    {
                        u8TempStringPosIndex++;
                        printf("%d\n",u8TempStringPosIndex );
                        au8FileNameSize[u8FileNameIndex] = (u8TempStringIndex - u8TempStringPosIndex ) + 4;
                        printf("%d\n",au8FileNameSize[u8FileNameIndex] );
                        au8FileNameIndex[u8FileNameIndex] = u8TempStringPosIndex;
                        printf("%d\n",au8FileNameIndex[u8FileNameIndex] );
                    }
                }
                u8FileNameIndex++;
            }
            u8TempStringIndex++;
        }
        enuStringCompareState = STRING_MATCHED;
    }
    if(enuStringCompareState == STRING_MATCHED)
    {
        /* Backup files */
        if( u8BOptIndex != 0)
        {
            /* make a backup of files */
            for(u8FileIndex = 0 ; u8FileIndex < u8FileNameIndex  ; u8FileIndex++)
            {
                for(u8Counter = 0 ; u8Counter < au8FileNameSize[u8FileIndex] ; u8Counter++)
                {
                    au8StringNameFile[u8Counter] =  au8InputCommand[au8FileNameIndex[u8FileIndex] + u8Counter];
                }
                au8StringNameFile[u8Counter] = '\0';


                FilePointer[u8FileIndex] = (FILE *)fopen( (const char *) &au8StringNameFile[0], "rb");


                au8StringNameFile[u8Counter - 4] = '_';
                au8StringNameFile[u8Counter - 3] = 'B';
                au8StringNameFile[u8Counter - 2] = 'K';
                au8StringNameFile[u8Counter - 1] = 'P';
                au8StringNameFile[u8Counter] = '.';
                au8StringNameFile[u8Counter + 1] = 't';
                au8StringNameFile[u8Counter + 2] = 'x';
                au8StringNameFile[u8Counter+ 3 ] = 't';
                au8StringNameFile[u8Counter + 4] = '\0';

                FilePointerBkp[u8FileIndex] = (FILE *)fopen( (const char *) &au8StringNameFile[0], "wb");

                a = fgetc(FilePointer[u8FileIndex]);
                while( a  != EOF)
                {
                    fputc(a , FilePointerBkp[u8FileIndex]);
                    a = fgetc(FilePointer[u8FileIndex]);
                }
                fclose( (FILE *)FilePointer[u8FileIndex] );
                fclose( (FILE *)FilePointerBkp[u8FileIndex] );
            }
        }
        enuStringCompareState = STRING_MATCHED;
    }
    if(enuStringCompareState == STRING_MATCHED)
    {
        if( u8LOptIndex != 0)
        {
            /* make a backup of files */
            for(u8FileIndex = 0 ; u8FileIndex < u8FileNameIndex  ; u8FileIndex++)
            {
                for(u8Counter = 0 ; u8Counter < au8FileNameSize[u8FileIndex] ; u8Counter++)
                {
                    au8StringNameFile[u8Counter] =  au8InputCommand[au8FileNameIndex[u8FileIndex] + u8Counter];
                }
                au8StringNameFile[u8Counter] = '\0';

                FilePointer[u8FileIndex] = (FILE *)fopen( (const char *) &au8StringNameFile[0], "r+");
                if(u8IOptIndex != 0)
                {
                    /* all */
                }
                else
                {
                    /* similar */
                }
                fclose( (FILE *)FilePointer[u8FileIndex] );
            }
        }
        if( u8FOptIndex != 0)
        {
            /* make a backup of files */
            for(u8FileIndex = 0 ; u8FileIndex < u8FileNameIndex  ; u8FileIndex++)
            {
                for(u8Counter = 0 ; u8Counter < au8FileNameSize[u8FileIndex] ; u8Counter++)
                {
                    au8StringNameFile[u8Counter] =  au8InputCommand[au8FileNameIndex[u8FileIndex] + u8Counter];
                }
                au8StringNameFile[u8Counter] = '\0';

                FilePointer[u8FileIndex] = (FILE *)fopen( (const char *) &au8StringNameFile[0], "r+");
                if(u8IOptIndex != 0)
                {
                    /* all */
                }
                else
                {
                    /* similar */
                }
                fclose( (FILE *)FilePointer[u8FileIndex] );
            }
        }
        if((u8LOptIndex == 0)&&( u8FOptIndex == 0))
        {
            /* make a backup of files */
            for(u8FileIndex = 0 ; u8FileIndex < u8FileNameIndex  ; u8FileIndex++)
            {
                for(u8Counter = 0 ; u8Counter < au8FileNameSize[u8FileIndex] ; u8Counter++)
                {
                    au8StringNameFile[u8Counter] =  au8InputCommand[au8FileNameIndex[u8FileIndex] + u8Counter];
                }
                au8StringNameFile[u8Counter] = '\0';

                FilePointer[u8FileIndex] = (FILE *)fopen( (const char *) &au8StringNameFile[0], "r+");
                if(u8IOptIndex != 0)
                {
                    /* non sensitive */
                    a = 'S';
                    fseek(FilePointer[u8FileIndex], 0, SEEK_SET);
                    while( a  != EOF)
                    {
                        u8TempFromStringSize = u8FromStringSize;
                        u8TempCounter = 0 ;
                        enuStringCompareState = STRING_MATCHED;
                        u32TempFileAdd = ftell(FilePointer[u8FileIndex]);
                        enuStringCompareState = STRING_MATCHED;
                        while( (u8TempFromStringSize > 0) &&(enuStringCompareState == STRING_MATCHED))
                        {
                            a = fgetc(FilePointer[u8FileIndex]);
                            if( a == (int)au8InputCommand[u8FromStringIndex + u8TempCounter])
                            {
                                enuStringCompareState = STRING_MATCHED;
                            }
                            else
                            {
                                enuStringCompareState = STRING_NOT_MATCHED;
                            }
                            u8TempFromStringSize--;
                            u8TempCounter++;
                        }

                        if(enuStringCompareState == STRING_MATCHED)
                        {
                            /* replace */
                            u8TempCounter = ftell(FilePointer[u8FileIndex]);
                            fseek(FilePointer[u8FileIndex], u32TempFileAdd, SEEK_SET);
                            u8TempCounter = ftell(FilePointer[u8FileIndex]);
                            u8TempFromStringSize = u8ToStringSize;
                            for(u8TempCounter  = 0 ; u8TempCounter < u8ToStringSize; u8TempCounter++)
                            {
                                fputc(au8InputCommand[u8ToStringIndex + u8TempCounter] , FilePointer[u8FileIndex]);
                            }

                            u32TempFileAdd = ftell(FilePointer[u8FileIndex]);
                            u32TempFileAdd -= 1 ;
                            fseek(FilePointer[u8FileIndex], u32TempFileAdd, SEEK_SET);
                            u8TempCounter = ftell(FilePointer[u8FileIndex]);
                            fseek(FilePointer[u8FileIndex], u32TempFileAdd, SEEK_SET);
                            u8TempCounter = ftell(FilePointer[u8FileIndex]);

                        }
                        else
                        {
                            u32TempFileAdd += 1;
                        }
                    }
                }
                else
                {
                    /* similar */
                    a = 'S';
                    fseek(FilePointer[u8FileIndex], 0, SEEK_SET);
                    while( a  != EOF)
                    {
                        u8TempFromStringSize = u8FromStringSize;
                        u8TempCounter = 0 ;
                        enuStringCompareState = STRING_MATCHED;
                        u32TempFileAdd = ftell(FilePointer[u8FileIndex]);
                        enuStringCompareState = STRING_MATCHED;
                        while( (u8TempFromStringSize > 0) &&(enuStringCompareState == STRING_MATCHED))
                        {
                            a = fgetc(FilePointer[u8FileIndex]);
                            if( a == (int)au8InputCommand[u8FromStringIndex + u8TempCounter])
                            {
                                enuStringCompareState = STRING_MATCHED;
                            }
                            else
                            {
                                enuStringCompareState = STRING_NOT_MATCHED;
                            }
                            u8TempFromStringSize--;
                            u8TempCounter++;
                        }

                        if(enuStringCompareState == STRING_MATCHED)
                        {
                            /* replace */
                            u8TempCounter = ftell(FilePointer[u8FileIndex]);
                            fseek(FilePointer[u8FileIndex], u32TempFileAdd, SEEK_SET);
                            u8TempCounter = ftell(FilePointer[u8FileIndex]);
                            u8TempFromStringSize = u8ToStringSize;
                            for(u8TempCounter  = 0 ; u8TempCounter < u8ToStringSize; u8TempCounter++)
                            {
                                fputc(au8InputCommand[u8ToStringIndex + u8TempCounter] , FilePointer[u8FileIndex]);
                            }

                            u32TempFileAdd = ftell(FilePointer[u8FileIndex]);
                            u32TempFileAdd -= 1 ;
                            fseek(FilePointer[u8FileIndex], u32TempFileAdd, SEEK_SET);
                            u8TempCounter = ftell(FilePointer[u8FileIndex]);
                            fseek(FilePointer[u8FileIndex], u32TempFileAdd, SEEK_SET);
                            u8TempCounter = ftell(FilePointer[u8FileIndex]);

                        }
                        else
                        {
                            u32TempFileAdd += 1;
                        }
                    }
                }
                fclose( (FILE *)FilePointer[u8FileIndex] );
            }

        }
    }
    if(enuStringCompareState == STRING_NOT_MATCHED)
    {
        printf("Error in paremeters\n");
    }

    return 0;
}
