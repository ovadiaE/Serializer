#include <stdio.h> /* For input / output */
#include <string.h> /* For string len */

typedef struct students
{
	char first_name[20];
	char last_name[20];
	
	struct grades
	{
		struct humanities 
		{
			unsigned int psychology;
			unsigned int music;
			unsigned int communications;
		} humanities;
		
		struct stem
		{
			unsigned int math;
			unsigned int biology;
			unsigned int economics;
		} stem;
		
		struct physical_ed
		{
			float handstands;
			float track;
		} physical_ed;
	
	} grades;
	
} student;

int CheckNameLength (size_t first, size_t last);
int WriteToFile (student first_student);
int CopyStruct (student first_student);

int main ()
{
	student Ovadia;
	char *first_temp = "Ovadia";
	char *last_temp = "Esquenazi";
	
	size_t first_len = strlen(first_temp);
	size_t last_len = strlen(last_temp);
		
	if( -1 == CheckNameLength(first_len, last_len))
	{
		return 1;
	}
	/* Initializing Name */
	strcpy(Ovadia.first_name, first_temp);
	strcpy(Ovadia.last_name, last_temp);	
	
	/* Initializing Humanities Struct */
	Ovadia.grades.humanities.psychology = 100;
	Ovadia.grades.humanities.music = 90;
	Ovadia.grades.humanities.communications = 100;
	
	/* Initializing stem Struct */
	Ovadia.grades.stem.math = 90;
	Ovadia.grades.stem.biology = 100;
	Ovadia.grades.stem.economics = 90;
	
	/* Initializing physical education Struct */
	Ovadia.grades.physical_ed.handstands = 100.00;
	Ovadia.grades.physical_ed.track = 100.00;
	
	if ( -1 == WriteToFile(Ovadia))
	{
		return 1;
	}
	
	if ( -1 == CopyStruct(Ovadia))
	{
		return 1;
	}
	
	return 0;
}


int WriteToFile(student first_student)
{	
	FILE *bin_file;
	bin_file = fopen("student_binary", "wb");
	
	if (NULL == bin_file)
	{
		printf("Failed to create file\n");
		return -1;
	}
	
	fwrite(&first_student, sizeof(first_student), 1, bin_file);
	
	fclose(bin_file);
	
	return 0;
}

int CopyStruct (student first_student)
{
	student new_student;
	
	FILE *bin_file = fopen("student_binary", "rb");
	
	if(NULL == bin_file)
	{
		printf("Failed to create file\n");
		return -1;
	}
	
	fread(&new_student, sizeof(student), 1, bin_file);
	
	fclose(bin_file);
	
	if ( !memcmp(&first_student, &new_student, sizeof(first_student) ))
	{
		printf("first_student and new_student contain same values\n");
	}
	else 
	{
		printf("Struct Values don't match\n");
		return -1;
	}

	return 0;
}

int CheckNameLength (size_t first, size_t last)
{
	if (first > 20)
	{
		printf("First Name too long, please get a new name\n");
		return -1;
	}
	
	if (last > 20)
	{	
		printf("Last Name too long, please get a new name\n");
		return -1;
	}
	
	return 0;
}
