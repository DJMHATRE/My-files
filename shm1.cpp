#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

typedef struct std_sm
{
	char User_name[30];
	int User_id;
}std_sm;
HANDLE pv_hMFile;


void main()
{
	
	int lv_count  = 0;
	std_sm *pp_sm = NULL;
    HANDLE hMFile;

	
	char ch, file_name[50];
	FILE *fp;
 
	strcpy_s(file_name,50,"D:\\dhiraj\\student.txt");
	fp = fopen(file_name,"r");

	   
 	long lv_size = sizeof(std_sm) * 10;
	hMFile = CreateFileMapping((HANDLE)0xFFFFFFFF,NULL,PAGE_READWRITE,0,lv_size,"STDSHR");  
   
	if(hMFile == NULL)
	{
		perror("shared memory creation failed");
		return;
	}
	else
	{
		perror("Students shared memory created");
	}
		

    lv_size = sizeof(std_sm) * 10;
	pv_hMFile = OpenFileMapping(
					   FILE_MAP_ALL_ACCESS,                    
					   FALSE,                
					   "STDSHR");               
 
	if (pv_hMFile == NULL) 
	{ 
		perror("Could not open shared memory");
		return;
	}  
	pp_sm = (std_sm *) MapViewOfFile(pv_hMFile,             
						FILE_MAP_ALL_ACCESS,   
						0,                   
						0,                   
						0);

	if(pp_sm == NULL)
	{
		perror("shared memory failed");
		CloseHandle(pv_hMFile);
		return;
	}
	else
	{
		perror("shared memory started");
	}
     while (!feof(fp))
	 {
		 fscanf(fp,"%s",pp_sm[lv_count].User_name);
		 fscanf(fp,"%d",&pp_sm[lv_count].User_id);
		 lv_count++;
	 }

	while(1)
	{
		Sleep(1000);
	}
  CloseHandle(hMFile);
}
