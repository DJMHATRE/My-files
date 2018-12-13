#define WIN32_LEAN_AND_MEAN
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
//#define DEFAULT_PORT "16001"
#define DEFAULT_PORT "16000"

#define	HEADER_SIZE		7
//int printclient();
void printclient(LPVOID lpParameter);
void createMailThread(LPVOID lpParameter);
void elog_thread(FILE *fp,char *av_msg);
void elog(char *av_msg);
void get_time (char *lv_sz_time);
int GetSocketSpecificError(SOCKET Socket);
int recv_msg(unsigned int ap_cltsock,char *ap_output_buff, int av_toread,int av_type);
int pv_count = 0;
int pv_threads = 0;
int pv_success = 0;
int pv_failure  = 0;
int  pv_wait=0;
int  pv_mail_count=0;
int pv_machine_no=0;
int temp_count = 0;
char *pp_mon[]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
HANDLE hMutex;
int pv_thread_process_count = 0;
/*
typedef struct mailsToProcess
{
	int		threadNo;
	int		mailCnt;

}mailsToProcess;
*/
typedef struct mailNumber
{
	int		threadNo;
	int		mailNo;
	FILE *fp;	

}mailNumber;

int main(int argc, char *argv[]){
	int retvalfunc = 0;
	int mailCount = 0;
	int threadCount = 0;
	char *lp_param		=	NULL;
	int tot_mails = 0;
	char lv_log[256] = {""};

	printf("Enter no of threads to create : ");
	scanf("%d",&threadCount);

	printf("Enter no of mails to send : ");
	scanf("%d",&pv_mail_count);

	printf("Enter Machine No : ");
	scanf("%d",&pv_machine_no);

	tot_mails = threadCount * pv_mail_count;
	sprintf(lv_log, "It will try to send threadCount[%d] * mailCount[%d] = %d mails\n",threadCount, pv_mail_count, tot_mails);
	printf("%s\n",lv_log);
	elog(lv_log);

	int processhalf = 0;
	//int halfcheck = 0;
	processhalf = threadCount / 2;

	for(int j = 1; j <=threadCount; j++)
	{
		
		if(processhalf == pv_thread_process_count)
		{
			while(pv_thread_process_count >0 || pv_count != 0)
			{
				printf("\nThread process count [%d] and waiting for mails to complete [%d]", pv_thread_process_count, pv_count);
				Sleep(500);
			}
			//halfcheck++;
		}


		if(_beginthread(createMailThread,2048*2,(LPVOID)j) <= 0)//sending thread number
		{
			printf("\n Failed to create thread no [%d]\n",j);
			continue;
		}

		
		Sleep(100);
		
	}

	while(pv_thread_process_count >0 || pv_count != 0)
	{
		printf("\nThread process count [%d] and waiting for mails to complete [%d]", pv_thread_process_count, pv_count);
		Sleep(1000);
	}
	
	/*
	while(pv_count != 0)
	{
		//temp_count++;
		//printf("In While loop no oF TImES[%d]\n",temp_count);
		printf("\nWaiting for threads to complete [%d]", pv_count);
		Sleep(1000);
	}
	*/
	sprintf(lv_log,"Mail Sending has been done successfully Success[%d],Failure[%d]", pv_success, pv_failure);
	elog(lv_log);
	printf("\n %s", lv_log);
	getch();
	pv_threads = 0;
	pv_failure = 0;
	pv_success = 0;
	return 0;
}//int main(int argc, char *argv[])

void createMailThread(void *lpParameter)
{
	pv_thread_process_count++;
	

	int mailCnt = 0;
	int threadNo = (int) lpParameter;

	FILE *fp_log = NULL;
	char lv_log_file_name[100]={""};
	char lv_log[100]={""};

	sprintf(lv_log_file_name,"thread%d.txt",threadNo);
	fp_log = fopen(lv_log_file_name,"a");
	if(fp_log==NULL)
	{
		sprintf(lv_log,"fail to create file with thread[%d]",threadNo);
		elog(lv_log);
	}
	
	int thread_creation_failed = 0;
	int mailNo = 0;
	int j = 0;
	for(j = 0; j <pv_mail_count; j++)
	{
		pv_count++;
		char lv_fromID[64] = {0};
		char lv_toID[64] = {0};
		char lv_subject[64] = {0};
		char lv_mailBody[64] = {0};
		//char lv_file_thread_no [64] = {0};

		char	lv_buffer[300]="";
		char    lv_send_data[500] = "";
		char	lv_recv_buffer[DEFAULT_BUFLEN]	= {""};
		int		lv_send_data_len = 0;
		//char	*lp_send_data_len = NULL;
		int		lv_status, lv_Send_Flag;
		WSADATA	wsaData;
		char	lv_log[512]	= {""};

		struct	sockaddr_in serveraddr;
		SOCKET	client;
		int lv_len = 0;
		int lv_nleft = 0;
		int lv_total = 0;
		int	n = 0;
		mailNo = j+1;
		sprintf_s(lv_buffer,"|2215|helpdesk1@kotaksecurities.com|1|arjun.sarankulu@kotak.com|0||0||testSubject[%d] with threadNo[%d] on machine[%d]|Param1^Param2^Param3|3|User_Id.tmpl|0|D://Arjun Sarankulu//Project_Test.docx|1|",mailNo,threadNo,pv_machine_no);
		strcpy_s(lv_send_data,500,lv_buffer);
		lv_send_data_len = strlen(lv_send_data);

		sprintf_s(lv_buffer,"%07d%s",lv_send_data_len,lv_send_data);
		printf("\nData String : %s\n",lv_buffer);

		if((WSAStartup(MAKEWORD(2,2) ,&wsaData))!=0)
		{
			sprintf(lv_log, "Error in Socket Connection.....%ld for mail[%d],thread[%d]\n", WSAGetLastError(),mailNo,threadNo);
		
			elog_thread(fp_log,lv_log);
			printf("\nError in Socket Connection.....\n");
			pv_count--;
			pv_failure++;
			return ;
		}

		client=socket(AF_INET,SOCK_STREAM, 0);

		if(client==SOCKET_ERROR)
		{
			sprintf(lv_log, "Error in creating socket.....%ld for mail[%d],thread[%d]\n", WSAGetLastError(),mailNo,threadNo);
			elog_thread(fp_log,lv_log);
			printf("\nError in creating socket.....");
			pv_count--;
			pv_failure++;
			return ;
		}

		serveraddr.sin_family=AF_INET;
		//serveraddr.sin_port=htons(16001);
		serveraddr.sin_port=htons(17001);
		serveraddr.sin_addr.s_addr= inet_addr("10.6.202.46");//INADDR_ANY;
		
		//connecting to the server
		if((connect(client,(struct sockaddr *)&serveraddr,sizeof(serveraddr))!=0))
		{		
			//sprintf(lv_log,"Error occurred on the socket: %ld.", GetSocketSpecificError(client));
			//elog(lv_log);
			sprintf(lv_log, "Error in connection....%ld for mail[%d],thread[%d]\n", WSAGetLastError(),mailNo,threadNo);
			elog_thread(fp_log,lv_log);
			printf(lv_log);
		
			pv_count--;
			pv_failure++;
			closesocket(client);
			WSACleanup();
			return ;		
		}

		lv_len = strlen(lv_buffer);
		lv_nleft = lv_len;
		while(lv_total < lv_len)
		{
			n = send(client,lv_buffer+lv_total,lv_nleft,0);
			if(n == -1)
			{
				sprintf(lv_log,"Error in sending data to server mail[%d],thread[%d]\n", mailNo,threadNo);
				elog_thread(fp_log,lv_log);
				printf(lv_log);
			
				pv_failure++;
				pv_count--;
				closesocket(client);
				WSACleanup();
				return ;
			}
			lv_total = lv_total + n;
			lv_nleft = lv_nleft - n;


		}

		memset(&lv_buffer,0,sizeof(lv_buffer));

		char	*lp_buff		=	NULL;
		int lv_ret  = 0;
		int	lv_read	= 0;
		lp_buff = (char *)malloc(HEADER_SIZE+1);
		memset(lp_buff,0,HEADER_SIZE+1);
	
		lv_ret = recv_msg(client,lp_buff,0,1);

		if(lv_ret == -1)
		{
			sprintf(lv_log,"Error in receiving header data from server, mail[%d],thread[%d]\n", mailNo,threadNo);
			elog_thread(fp_log,lv_log);
			pv_failure++;
			pv_count--;
			closesocket(client);
			WSACleanup();
			return ;
		}
		else 
		{
			lv_read = atoi(lp_buff);
			free(lp_buff);
			lp_buff = NULL;

			lp_buff = (char *)malloc(lv_read+1);
			memset(lp_buff,0,lv_read+1);

			lv_ret = recv_msg(client,lp_buff,lv_read,2);
			if(lv_ret < 0)
			{
				sprintf(lv_log,"Error in receiving data from server, mail[%d],thread[%d]\n", mailNo,threadNo);
				elog_thread(fp_log,lv_log);
				pv_failure++;
				pv_count--;
				closesocket(client);
				WSACleanup();
				return ;
			}
			else
			{
				printf("\nSuccess : %s\n", lp_buff);
				if(lp_buff)
				{
					free(lp_buff);
					lp_buff =0;
				}				
			}
		}

		pv_success++;
		pv_count--;
	
		memset(lv_buffer,0,255);   
		closesocket(client);
		WSACleanup();
	}//for(j = 0; j <pv_mail_count; j++)

	//sprintf(lv_log,"threads created for thread[%d] : %d and thread creation failed[%d]",threadNo,j,thread_creation_failed);
	//elog_thread(fp_log,lv_log);
	
	while(j != pv_mail_count)
	{
		printf("\n Main Thread ID [%d] waiting to complete\n", threadNo);
		Sleep(1000);
	}
	

	pv_thread_process_count--;
	if(fp_log)
		fclose(fp_log);
	
}

void printclient(void *lpParameter)
{
	pv_count++;
	mailNumber *mail = (mailNumber*) lpParameter;

	char lv_fromID[64] = {0};
	char lv_toID[64] = {0};
	char lv_subject[64] = {0};
	char lv_mailBody[64] = {0};
	//char lv_file_thread_no [64] = {0};

	char	lv_buffer[300]="";
	char    lv_send_data[500] = "";
	char	lv_recv_buffer[DEFAULT_BUFLEN]	= {""};
	int		lv_send_data_len = 0;
	//char	*lp_send_data_len = NULL;
	int		lv_status, lv_Send_Flag;
	WSADATA	wsaData;
	char	lv_log[512]	= {""};

	struct	sockaddr_in serveraddr;
	SOCKET	client;
	int lv_len = 0;
	int lv_nleft = 0;
	int lv_total = 0;
	int	n = 0;
	int mailNo = 0;
	int threadNo = 0;
	FILE *fp = NULL;

	mailNo   = mail->mailNo;
	threadNo = mail->threadNo;
	fp		= mail->fp;

	sprintf_s(lv_buffer,"|2215|helpdesk1@kotaksecurities.com|1|arjun.sarankulu@kotak.com|0||0||testSubject[%d] with threadNo[%d]|Param1^Param2^Param3|3|User_Id.tmpl|0|D://Arjun Sarankulu//Project_Test.docx|1|",mailNo,threadNo);
	strcpy_s(lv_send_data,500,lv_buffer);
	lv_send_data_len = strlen(lv_send_data);

	sprintf_s(lv_buffer,"%07d%s",lv_send_data_len,lv_send_data);
	printf("\nData String : %s\n",lv_buffer);

	if(mail)
	{
		free(mail);
		mail = NULL;
	}

	//sprintf(lv_file_thread_no,"Thread%d.txt",threadNo);

	char lv_test[2]={""};

	if((WSAStartup(MAKEWORD(2,2) ,&wsaData))!=0)
	{
		sprintf(lv_log, "Error in Socket Connection.....%ld for mail[%d],thread[%d]\n", WSAGetLastError(),mailNo,threadNo);
		
		elog_thread(fp,lv_log);
		printf("\nError in Socket Connection.....\n");
		pv_count--;
		pv_failure++;
		return ;
	}

	client=socket(AF_INET,SOCK_STREAM, 0);
	
	if(client==SOCKET_ERROR)
	{
		sprintf(lv_log, "Error in creating socket.....%ld for mail[%d],thread[%d]\n", WSAGetLastError(),mailNo,threadNo);
		elog_thread(fp,lv_log);
	   printf("\nError in creating socket.....");
	   pv_count--;
	   pv_failure++;
	   return ;
	}

	//initialization of socket family port address..
	serveraddr.sin_family=AF_INET;
	//serveraddr.sin_port=htons(16001);
	serveraddr.sin_port=htons(17001);
	serveraddr.sin_addr.s_addr= inet_addr("10.6.202.46");//INADDR_ANY;

	//connecting to the server
	if((connect(client,(struct sockaddr *)&serveraddr,sizeof(serveraddr))!=0))
	{		
		//sprintf(lv_log,"Error occurred on the socket: %ld.", GetSocketSpecificError(client));
		//elog(lv_log);
		sprintf(lv_log, "Error in connection....%ld for mail[%d],thread[%d]\n", WSAGetLastError(),mailNo,threadNo);
		elog_thread(fp,lv_log);
		printf(lv_log);
		
		pv_count--;
		pv_failure++;
		closesocket(client);
		WSACleanup();
		return ;		
	}

	lv_len = strlen(lv_buffer);
	lv_nleft = lv_len;
	while(lv_total < lv_len)
	{
		n = send(client,lv_buffer+lv_total,lv_nleft,0);
		if(n == -1)
		{
			sprintf(lv_log,"Error in sending data to server mail[%d],thread[%d]\n", mailNo,threadNo);
			elog_thread(fp,lv_log);
			printf(lv_log);
			
			pv_failure++;
			pv_count--;
			closesocket(client);
			WSACleanup();
			return ;
		}
		lv_total = lv_total + n;
		lv_nleft = lv_nleft - n;
	}

	memset(&lv_buffer,0,sizeof(lv_buffer));

	char	*lp_buff		=	NULL;
	int lv_ret  = 0;
	int	lv_read	= 0;
	lp_buff = (char *)malloc(HEADER_SIZE+1);
	memset(lp_buff,0,HEADER_SIZE+1);
	
	lv_ret = recv_msg(client,lp_buff,0,1);

	if(lv_ret == -1)
	{
		sprintf(lv_log,"Error in receiving header data from server, mail[%d],thread[%d]\n", mailNo,threadNo);
		elog_thread(fp,lv_log);
		pv_failure++;
		pv_count--;
		closesocket(client);
	    WSACleanup();
		return ;
	}
	else 
	{
		lv_read = atoi(lp_buff);
		free(lp_buff);
		lp_buff = NULL;

		lp_buff = (char *)malloc(lv_read+1);
		memset(lp_buff,0,lv_read+1);

		lv_ret = recv_msg(client,lp_buff,lv_read,2);
		if(lv_ret < 0)
		{
			sprintf(lv_log,"Error in receiving data from server, mail[%d],thread[%d]\n", mailNo,threadNo);
			elog_thread(fp,lv_log);
			pv_failure++;
			pv_count--;
			closesocket(client);
			WSACleanup();
			return ;
		}
		else
		{
			printf("\nSuccess : %s\n", lp_buff);
			if(lp_buff)
			{
				free(lp_buff);
				lp_buff =0;
			}				
		}
	}

	pv_success++;
	pv_count--;
	
	

	memset(lv_buffer,0,255);   
	closesocket(client);
	WSACleanup();
	
	return ;
}

void elog(char *av_msg)
{
	FILE *fp;
	char lv_tm[128]={""};
	
	fp = fopen("test.txt","a");	

	if(fp)
	{
		get_time(lv_tm);
		fprintf(fp,"%s: %s",lv_tm,av_msg);
		fflush(fp);
		fclose(fp);
	}
}

void elog_thread(FILE *fp, char *av_msg)
{
	char lv_tm[128]={""};

	if(fp)
	{
		get_time(lv_tm);
		fprintf(fp,"%s: %s",lv_tm,av_msg);
		fflush(fp);
	}
}

void get_time (char *lv_sz_time)
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	sprintf(lv_sz_time," %02d %s %04d %02d:%02d:%02d:%03d:",t.wDay,pp_mon[t.wMonth - 1],t.wYear,t.wHour, t.wMinute,t.wSecond,t.wMilliseconds);
}

int GetSocketSpecificError(SOCKET Socket)
{
     int nOptionValue;
     int nOptionValueLength = sizeof(nOptionValue);

     //Get error code specific to this socket
     getsockopt(Socket, SOL_SOCKET, SO_ERROR, (char*)&nOptionValue, 
                                            &nOptionValueLength);

     return nOptionValue;
}

int recv_msg(unsigned int ap_cltsock,char *ap_output_buff, int av_toread,int av_type)
{
	int		nleft			= 0;
	int		nread			= 0;
	int		ntotal			= 0;
	int		lv_toBeRead		= 0;
	
	char	*header_buff	= NULL;
	char	*tempbuff		= NULL;
	char	*output_buff	= NULL;

	char	lv_log[256]		= {""};
	
	if(av_type == 1)
	{
		nleft = HEADER_SIZE;

		header_buff = (char *) malloc(HEADER_SIZE + 1);
		memset(header_buff, 0, (HEADER_SIZE + 1));
		
		tempbuff = (char *)malloc(HEADER_SIZE + 1);
		memset(tempbuff,0,(HEADER_SIZE+1));

		int ntotread = 0;
		while (nleft > 0)
		{
			nread = recv(ap_cltsock, tempbuff, nleft, 0);
			if( nread <= 0)
			{
				//sprintf(lv_log,"Socket %d hung up while recieving header, Exit", ap_cltsock);
				//elog(lv_log,1);
				return -1;
			}

			nleft -= nread;
			ntotread += nread;

			tempbuff[nread]=0;
			strcat(header_buff, tempbuff);
			memset(tempbuff,0,(HEADER_SIZE+1));
		}

		if(ntotread != HEADER_SIZE)
		{
			sprintf(lv_log, "Socket <%d> did not recieve proper Header Data, Exptected <%d>, Recieved<%d>, Exit",ap_cltsock, HEADER_SIZE, ntotread);
			elog(lv_log);
			return -2;
		}

		header_buff[HEADER_SIZE] = 0;
		strcpy_s(ap_output_buff,HEADER_SIZE + 1,header_buff);		
		free(header_buff);
		free(tempbuff);
		tempbuff	= NULL;
		header_buff = NULL;
		
		return 0;
	}
	else if(av_type == 2)
	{
		tempbuff = (char *)malloc(av_toread+1);
		memset(tempbuff,0,av_toread+1);

		output_buff = (char *)malloc(av_toread+1);
		memset(output_buff,0,av_toread+1);

		nleft = av_toread;
		ntotal = nleft;
		lv_toBeRead = nleft;
		
		while (nleft > 0)
		{

			nread = recv(ap_cltsock, tempbuff, nleft, 0);
			//if( (nread = recv(ap_cltsock, tempbuff, nleft, 0)) <=0)
			if( nread <= 0)
			{
				sprintf(lv_log,"Socket %d hung up while recieving Data, Exit", ap_cltsock);
				elog(lv_log);
				return -1;
			}
			nleft -= nread;
			tempbuff[nread]=0;
			strcat(output_buff, tempbuff);
			memset(tempbuff,0,ntotal+1);
		}
		output_buff[ntotal] = 0;
		strcpy_s(ap_output_buff, av_toread+1,output_buff);
		if(output_buff)
		{
			free(output_buff);
			output_buff = 0;
		}
		if(tempbuff)
		{
			free(tempbuff);
			tempbuff = 0;
		}
		if(av_toread != ntotal)
		{
			//elog("error on reading Data", 1);
			sprintf(lv_log, "Socket <%d> did not recieve proper data, Exptected <%d>, Recieved<%d>, Exit",ap_cltsock, av_toread, ntotal);
			elog(lv_log);
			return -3;
		}

		return ntotal;
	}
	return -1;
	
}