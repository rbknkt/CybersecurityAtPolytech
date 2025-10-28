#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void commclr(FILE* readfile, FILE* writefile, int status)
{
	int readsymbol;

	if (status == 0)
	{
		int string = 0;

		while ((readsymbol = fgetc(readfile)) != EOF)
		{
			if (string == 0)
			{
				if (readsymbol == '/')
				{
					int tempsymbol = fgetc(readfile);

					if (tempsymbol == '/')
					{
						commclr(readfile, writefile, 1);
					}
					else if (tempsymbol == '*')
					{
						commclr(readfile, writefile, 2);
					}
					else
					{
						fprintf(writefile, "%c%c", readsymbol, tempsymbol);
					}
				}
				else if (readsymbol == '\"')
				{
					string = 1;
					fprintf(writefile, "%c", readsymbol);
				}
				else if (readsymbol == '\'')
				{
					string = 2;
					fprintf(writefile, "%c", readsymbol);
				}
				else
				{
					fprintf(writefile, "%c", readsymbol);
				}
			}
			else if (readsymbol == '\\')
			{
				fprintf(writefile, "%c", readsymbol);
				readsymbol = fgetc(readfile);
				fprintf(writefile, "%c", readsymbol);
			}
			else if (readsymbol == '\"' && string == 1)
			{
				string = 0;
				fprintf(writefile, "%c", readsymbol);
			}
			else if (readsymbol == '\'' && string == 2)
			{
				string = 0;
				fprintf(writefile, "%c", readsymbol);
			}
			else
			{
				fprintf(writefile, "%c", readsymbol);
			}
		}
	}
	else if (status == 1)
	{
		while ((readsymbol = fgetc(readfile)) != EOF)
		{
			if (readsymbol == '\\')
			{
				readsymbol = fgetc(readfile);

				if (readsymbol == '\n')
				{
					readsymbol = 0;
					break;
				}
			}
			else if (readsymbol == '\n')
			{
				break;
			}
		}

		if (readsymbol == 0)
		{
			commclr(readfile, writefile, 1);
		}
	}
	else if (status == 2)
	{
		int tempsymbol = fgetc(readfile);
		readsymbol = fgetc(readfile);

		while ((tempsymbol != '*' || readsymbol != '/') && !feof(readfile))
		{
			tempsymbol = readsymbol;
			readsymbol = fgetc(readfile);
		}
	}

	if (status == 0)
	{
		fclose(readfile);
		fclose(writefile);
	}
}

int main()
{
	FILE* readfile = fopen("project.txt", "r");

	int n;
	fscanf(readfile, "%d", &n);

	for (int i = 0; i < n; i++)
	{
		char name1[36], name2[36];

		fscanf(readfile, "%s", name1);

		strcpy(name2, name1);
		strcpy(strchr(name2, '.'), ".wc");

		commclr(fopen(name1, "r"), fopen(name2, "w"), 0);
	}

	fclose(readfile);
}