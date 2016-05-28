#include<stdio.h>
#include<string.h>

#define LEN 11

#define BASE 127



int hash(char * str);
int opadhash(char ** table, int hash);

int main()
{
int i;
char *str1 = "apple";
char *str2 = "pear";
char *str3 = "papaya";
char *str4 = "orange";
char *str5 = "mango";
char *str6 = "kiwi";
char *str7 = "peach";

char *table[LEN];
for (i=0;i<LEN;i++) table[i] = "\0";



table[opadhash(table, hash(str1))] = str1;
table[opadhash(table, hash(str2))] = str2;
table[opadhash(table, hash(str3))] = str3;
table[opadhash(table, hash(str4))] = str4;
table[opadhash(table, hash(str5))] = str5;
table[opadhash(table, hash(str6))] = str6;
table[opadhash(table, hash(str7))] = str7;

//printf("hash str = %d\n", hash(str1));

//printf("hash str = %d\n", hash(str2));

//printf("hash str = %d\n", hash(str3));
//printf("%d\n", *(table[0]));

printf("opadhash = %d\n", opadhash(table, hash(str7)));
printf("cmp = %d\n", strcmp(table[1], str6));
printf("table[2] addr = %p, str6 addr = %p\n", table[2], str6);

for (i=0;i<LEN;i++)
{
	printf("table %d = ", i);
	fputs(table[i], stdout);
	printf("     at %p\n", table[i]);

}

}

int hash(char * str)
{
	long asc2string = 0;
	int asc2word;
	int key = 0;
	int i = 0;
	int a = 31415;
	int b = 27183; // for universal hash function


	while (str[i]!='\0')
	{
		/*
		//127 bit encoding for ASCII character
		asc2word = str[i];
		asc2string = (asc2string + asc2word) * BASE;
		i++;
		*/

		/*
		//upgrade 127 bit encoding to deal with long string: mod every step
		asc2word = str[i];
		key = (key * BASE + asc2word) % LEN;
		i++;
		*/


		//universal hash function with long string capability
		a = (a * b) % (LEN - 1);  //random coefficient
		asc2word = str[i];
		key = (key * a + asc2word) % LEN;
		i++;   //reduce collision to 1/LEN
		//printf("ascword = %d\n", asc2word);
		//printf("ascstring = %ld\n", asc2string);
	}
	//printf("ascstring = %ld\n", asc2string);
	//key = asc2string % LEN;   //part of 127 bit encoding without upgrade
	printf("key = %d\n", key);	
	return key;

}




int opadhash(char ** table, int hash)
{
	int key;
	int i = 0;

	key = hash + i;
	printf("table[key] = %d\n", *table[key]);
	while ( *(table[key]) != '\0' )
	{	
		i++;
		key = (hash + i) % LEN;
		if (i >= LEN) 
		{
			puts("table full");
			return -1;
		}
	}
	return key;
		
}





