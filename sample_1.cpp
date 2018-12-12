#include <stdio.h>
#include<string.h>
#include <iostream.h>
#include <process.h>
#include<Windows.h>
#include<vector>
#include <stack>
#include<conio.h>
#include <time.h>
using namespace std;
char lv_log[512] = {""};
#define	VALUE 2

//void	main ()
//{
//	struct timeb timebuffer;
//	struct tm t;
//	//char *timeline;
//	errno_t err;
//	ftime( &timebuffer );
//	//timeline = ctime( & ( timebuffer.time ) );
//	//ctime_s(timeline,DATE_SIZE,& ( timebuffer.time ) );
//
//	time (&timebuffer.time);
////	t = localtime (&timebuffer.time);
//	err = localtime_s (&t,&timebuffer.time);
//	sprintf_s (szTime,DATE_SIZE,"%02d:%02d:%02d:%d",t.tm_hour, t.tm_min,t.tm_sec,timebuffer.millitm);
//}

 
///*Quick sort*/
//void quicksort(int number[25],int first,int last){
//   int i, j, pivot, temp;
//
//   if(first<last){
//      pivot=first;
//      i=first;
//      j=last;
//
//      while(i<j){
//         while(number[i]<=number[pivot]&&i<last)
//            i++;
//         while(number[j]>number[pivot])
//            j--;
//         if(i<j){
//            temp=number[i];
//            number[i]=number[j];
//            number[j]=temp;
//         }
//      }
//
//      temp=number[pivot];
//      number[pivot]=number[j];
//      number[j]=temp;
//      quicksort(number,first,j-1);
//      quicksort(number,j+1,last);
//
//   }
//}
//
//int main(){
//   int i, count, number[25];
//
//   printf("How many elements are u going to enter?: ");
//   scanf("%d",&count);
//
//   printf("Enter %d elements: ", count);
//   for(i=0;i<count;i++)
//      scanf("%d",&number[i]);
//
//   quicksort(number,0,count-1);
//
//   printf("Order of Sorted elements: ");
//   for(i=0;i<count;i++)
//      printf(" %d",number[i]);
//
//   return 0;
//}


/*Merge Sort*/
//#define MAX_SIZE 5
//
//void merge_sort(int, int);
//void merge_array(int, int, int, int);
//
//int arr_sort[MAX_SIZE];
//
//int main() {
//  int i;
//
//  printf("Simple Merge Sort Example - Functions and Array\n");
//  printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
//  for (i = 0; i < MAX_SIZE; i++)
//    scanf("%d", &arr_sort[i]);
//
//  printf("\nYour Data   :");
//  for (i = 0; i < MAX_SIZE; i++) {
//    printf("\t%d", arr_sort[i]);
//  }
//
//  merge_sort(0, MAX_SIZE - 1);
//
//  printf("\n\nSorted Data :");
//  for (i = 0; i < MAX_SIZE; i++) {
//    printf("\t%d", arr_sort[i]);
//  }
//  getch();
//
//}
//
//void merge_sort(int i, int j) {
//  int m;
//
//  if (i < j) {
//    m = (i + j) / 2;
//    merge_sort(i, m);
//    merge_sort(m + 1, j);
//    // Merging two arrays
//    merge_array(i, m, m + 1, j);
//  }
//}
//
//void merge_array(int a, int b, int c, int d) {
//  int t[50];
//  int i = a, j = c, k = 0;
//
//  while (i <= b && j <= d) {
//    if (arr_sort[i] < arr_sort[j])
//      t[k++] = arr_sort[i++];
//    else
//      t[k++] = arr_sort[j++];
//  }
//
//  //collect remaining elements 
//  while (i <= b)
//    t[k++] = arr_sort[i++];
//
//  while (j <= d)
//    t[k++] = arr_sort[j++];
//
//  for (i = a, j = 0; i <= d; i++, j++)
//    arr_sort[i] = t[j];
//}

//void main()	// string reverse without recursion
//{
//   char str[50],temp;
//   int i,len;
//   
//   printf("Enter String : ");
//   scanf("%[^\n]",str);
//  // printf("%s",str);
//   len=strlen(str)-1;
//   //  printf("%d",len);
//   for(i=0;i<strlen(str)/2;i++)
//   {
//	  temp=str[i];
//      str[i]=str[len];
//      str[len--]=temp;
//   }
//   printf("\nReverse string :%s",str);
//   getch();
//}

//int main()		//Binary search
//{
//	int count, i, arr[30], num, first, last, middle;
//	cout<<"how many elements would you like to enter?:"; 
//    cin>>count;
//
//	for (i=0; i<count; i++)
//	{
//		cout<<"Enter number "<<(i+1)<<": "; 
//        cin>>arr[i];
//	}
//	cout<<"Enter the number that you want to search:"; 
//    cin>>num;
//
//	first = 0;
//	last = count-1;
//	middle = (first+last)/2;
//
//	while (first <= last)
//	{
//	   if(arr[middle] < num)
//	   {
//			first = middle + 1;
//	   }
//	   else if(arr[middle] == num)
//	   {
//			cout<<num<<" found in the array at the location "<<middle+1<<"\n"; 
//            break; 
//       } 
//	   else 
//	   { 
//            last = middle - 1; 
//       } 
//
//       middle = (first + last)/2; 
//    } 
//
//    if(first > last)
//	{
//	   cout<<num<<" not found in the array";
//	}
//	return 0;
//}

//DWORD WINAPI myThread(LPVOID lpParameter)
//{
//	unsigned int& myCounter = *((unsigned int*)lpParameter);
//	while(myCounter < 0xFFFFFFFF) ++myCounter;
//	return 0;
//}
//
//int main(int argc, char* argv[])
//{
//	using namespace std;
//
//	unsigned int myCounter = 0;
//	DWORD myThreadID;
//	HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);
//	char myChar = ' ';
//	while(myChar != 'q') {
//		cout << myCounter << endl;
//		myChar = getchar();
//	}
//	
//	CloseHandle(myHandle);
//	return 0;
//}
//int main()
//{
//	stack <int> stk1;
//	stack <int> stk2;
//	//cout<<stk.empty()<<endl;
//
//	cout<<"stack 1"<<endl;
//	for(int i=0 ;i< 10;i++)
//	{		
//		//stk1.push(i);
//		stk1.emplace(i + 1);
//		cout<<stk1.top()<<endl;
//	}
//	
//	swap(stk1,stk2);
//	cout<<"stack 2"<<endl;
//	while(!stk2.empty())
//	{
//		cout<<stk2.top()<<endl;
//		stk2.pop();
//	}
//
//	/*sprintf(lv_log,"%d",stk._Get_container());
//	cout<<lv_log;*/
//	//cout<<stk.size()<<endl;
//	//cout<<stk.top()<<endl;
//	
//	//cout<<stk.empty();
//	return 0;
//}
//int main()
//{
//	vector<int> v1;
//	cout<<"Number of elements in vector are:"<<v1.size()<<endl;
//
//	for(int i=0;i<20;i++)
//	{
//		v1.push_back(i*10);
//		cout<<v1[i]<<endl;
//	}
//	
//	cout<<"capacity of vector is:"<<v1.capacity()<<endl;
//	cout<<"Number of elements in vector are:"<<v1.size()<<endl;
//
//	//v1.pop_back();
//	//cout<<"capacity of vector is:"<<v1.capacity()<<endl;
//	//cout<<"Number of elements in vector are:"<<v1.size()<<endl;
//
//	vector<int>::iterator v = v1.begin();
//	v1.insert(v+(1),5);
//	v1.insert(v+(2),8);
//	v1.insert(v+(3),9);
//
//	cout<<"Number of elements in vector are:"<<v1.size()<<endl;
//	while(v != v1.end())
//	{
//		cout<<"Final vector elements are:"<<*v<<endl;
//		v++;
//	}
//	cout<<"Final capacity of vector is:"<<v1.capacity()<<endl;
//	return 0;
//}


//int *data ()
//{
//	int x = 10;
//	printf("%d",x);
//	return &x;
//}
//void main()
//{
//	int *p;
//	p = data();
//	printf("\n %d",*p);
//}
//class A
//{
//	public:
//	virtual void display()
//	{
//		cout<<"base class \n";
//	}
//};
//class B: virtual public A
//{
//	public:
//	void display()
//	{
//		cout<<"first derived class \n";
//	}
//};
//class C: virtual public A
//{
//	public:
//	void display()
//	{
//		cout<<"second derived class \n";
//	}
//};
//class D: public B,public C
//{
//	public:
//	void display()
//	{
//		cout<<"Last derived class \n";
//	}
//};
//int main()
//{
//	A *ptr_a;
//	B *ptr_b;
//	C *ptr_c;
//
//	C obj_c;
//	D obj_d;
//	ptr_a = &obj_d;
//	ptr_b = &obj_d;
//	ptr_b -> display();
//
//	ptr_c = &obj_d;
//	ptr_c -> display();
//
//	return 0;
//}
//int main()	//pyramid program
//{
//	int rows,s,i=0,k=0;
//	printf("Enter number of rows to display:");
//	scanf("%d",&rows);
//	for(i=1;i<=rows;i++, k=0)
//	{
//		for(s=1;s<= rows-i;s++)
//		{
//			printf(" ");
//		}
//		
//		while(k != 2*i-1)
//		{
//			printf("$");
//			++k;
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}

//int main()
//{
//    int i, space, rows, k=0;
//
//    printf("Enter number of rows: ");
//    scanf("%d",&rows);
//
//    for(i=1; i<=rows; i++, k=0)
//    {
//        for(space=1; space<=rows-i; space++)
//        {
//            printf("  ");
//        }
//
//        while(k != 2*i-1)
//        {
//            printf("* ");
//            ++k;
//        }
//
//        printf("\n");
//    }
//    
//    return 0;
//}

//class A				//virtual class 
//{
//	int x;
//	public:
//		virtual int setvalue() = 0;
//		/*{
//			x = 10;
//			cout<<x<<endl;
//			return x;
//		}*/
//
//		/*A()
//		{
//			cout<<"base class"<<endl;
//		}*/
//};
//
//class B
//{
//	int x; 
//	public:
//		virtual int setvalue()
//		{
//			x = 20;
//			cout<<x<<endl;
//			return x;
//		}
//		/*B()
//		{
//			cout<<"derv 1 "<<endl;
//		}*/
//};
//
//class C
//{
//	int x;
//	public:
//		int setvalue()
//		{
//			x = 30;
//			cout<<x<<endl;
//			return x;
//		}
//		/*C()
//		{
//			cout<<"derv 2 "<<endl;
//		}*/
//};
//
//class D : public B,public C
//{
//	int x;
//	public:
//		int setvalue()
//		{
//			x = 40;
//			cout<<x<<endl;
//			return x;
//		}
//		/*D()
//		{
//			cout<<"derv final "<<endl;
//		}*/
//};
//
//int main()
//{
//	D *p;
//	D obj_d;
//	//A &adr = obj_d;
//	//adr.setvalue();
//	p = &obj_d;	
//	p->setvalue();
//
//	return 0;
//}
//void main()
//{
//	int num;
//	int c = 0;
//	printf("enter number:");
//	scanf("%d",&num);
//	for(int i=1; i<=num; i++)
//	{
//		if(i % num == 0)
//		{
//			c++;
//		}
//		if(c == 2)
//		{
//			printf("number is prime");
//			return;
//		}
//	}
//	printf("number is not prime"); 
//}

//int Factorial(int);
//void main()
//{
//	int num,lv_ret;
//	printf("enter number:");
//	scanf("%d",&num);
//	for(int i=1; i<=num;i++)
//	{
//		lv_ret = Factorial(num);
//	}
//	printf("factorial of number is: %d",lv_ret);
//}
//
//int Factorial(int num)
//{
//	if(num == 0 || num == 1)
//		return 1;
//	else
//		return(num * Factorial(num - 1));
//}
//void Reverse(char str[],int index,int size);
//void main()
//{
//	char str[] = {""};
//	int i=0;
//	int size;
//	printf("\n Enter string:");
//	scanf("%s",&str);
//
//	size = strlen(str);
//	Reverse(str,i,size-1);
//
//	printf("\n reverse string are:%s",str);
//}
//void Reverse(char str[],int index,int size)
//{
//	char temp;
//	temp = str[index];
//	str[index] = str[size - index];
//	str[size - index] = temp;
//
//	if(index == size/2)
//	{
//		return;
//	}
//	Reverse(str,index+1,size);
//}
//
//class A				//virtual class 
//{
//	int x;
//	public:
//		virtual int setvalue() = 0;
//		/*{
//			x = 10;
//			cout<<x<<endl;
//			return x;
//		}*/
//
//		/*A()
//		{
//			cout<<"base class"<<endl;
//		}*/
//};
//
//class B: virtual public A
//{
//	int x; 
//	public:
//		int setvalue()
//		{
//			x = 20;
//			cout<<x<<endl;
//			return x;
//		}
//		/*B()
//		{
//			cout<<"derv 1 "<<endl;
//		}*/
//};
//
//class C : virtual public A
//{
//	int x;
//	public:
//		int setvalue()
//		{
//			x = 30;
//			cout<<x<<endl;
//			return x;
//		}
//		/*C()
//		{
//			cout<<"derv 2 "<<endl;
//		}*/
//};
//
//class D : public B,public C
//{
//	int x;
//	public:
//		int setvalue()
//		{
//			x = 40;
//			cout<<x<<endl;
//			return x;
//		}
//		/*D()
//		{
//			cout<<"derv final "<<endl;
//		}*/
//};
//
//int main()
//{
//	A *p;
//	D obj_d;
//	//A &adr = obj_d;
//	//adr.setvalue();
//	p = &obj_d;	
//	p->setvalue();
//
//	return 0;
//}
//void main()
//{
//
//}
//int main()		//	Dangling pointer
//{
//	int *p = NULL;
//	int i  = 0;
//	if(i == 1)
//	{
//		int x= 10;
//		p= &x;
//		//printf("p:[%d]",*p);
//	}
//
//	printf("%d",*p);
//}


//class A
//{
//public:
//    virtual const char* getName() { return "A"; }
//};
// 
//class B: virtual public A
//{
//public:
//    const char* getName() { return "B"; }
//};
// 
//class C: virtual public A
//{
//public:
//    const char* getName() { return "C"; }
//};
// 
//class D: public B,public C
//{
//public:
//    const char* getName() { return "D"; }
//};
// 
//int main()
//{
//    C c;
//	D d;
//	A *a;
//   // A &a = d;
//	
//    cout << "Base is a " <<a->getName() << '\n';
// 
//    return 0;
//}


//class ABC
//{
//	/*const int x=10;
//	static const int b = 20;*/
//	protected:
//	int x,y,p;
//	public:
//	void setvalue(int p,int y);
//	
//};
//
//class XYZ : public ABC
//{
//	int z;
//	public:
//		void setvalue(int,int);
//		void display()
//		{
//			x = p + y;
//			cout<<"final value:"<<x;
//		}
//};
//void setvalue(int p,int y)
//{
//	cout<<"enter value 1:";
//	cin>>p;
//	cout<<"enter value 2:";
//	cin>>y;
//}
//
//
//void main()
//{
//	//ABC ab;
//	XYZ xy;
//	
//	xy.setvalue(15,20);
//	xy.display();
//
//}


//union student
//{
//      int rollno;
//      char gender;
//      float marks;
//}s1;
//
//int main()
//{
//	s1.rollno = 20;
//	s1.marks =  80;
//	printf("\n %d",s1.rollno);
//}


//bool threadFinished = false;
//
//void test(void *param)
//{
//    cout << "In thread function" << endl;
//    Sleep(1000); // sleep for 1 second
//    cout << "Thread function ends" << endl;
//    threadFinished = true;
//    _endthread();
//}
//
//
//int main()
//{
//    cout << "Starting thread" << endl;
//
//    cout << _beginthread(test,0,NULL);
//    while(!threadFinished)
//    {
//        Sleep(10);
//    }
//    cout << "Main ends" << endl;
//    return 0;
//}

//int main(int argc, const char * argv[])
//{
//    int a[] = {1, 2, 3, 4, 5, 6};
//    cout << (1 + 3)[a] - a[0] + (a + 1)[2];
//}
//int x = 10;
//int calc(int x);
//int main()
//{
//  x= calc(x);
// printf("%d",x);
//}
//int calc(int x)
//{
//	printf("%d", x);
//	 x = x + 10 ;
//	 return x;
//}
//void main()
//{
//
//	//cout << 25u - 50;
////	char *lp_args[3]; 
////	char lv_temp[32] = {""};
////
////	sprintf(lv_temp,"ABCD");
////	lp_args[0] = lv_temp;
////	//printf("lv_temp [%s]",lp_args[0]);
////	memset(lv_temp,0,sizeof(lv_temp));
////	
////
////	sprintf(lv_temp,"PQRS");
////	lp_args[1] = lv_temp;
//////	printf("lv_temp [%s]",lp_args[1]);
////	memset(lv_temp,0,sizeof(lv_temp));
////
////	printf("lv_temp [%s]",lp_args[0]);
////	printf("lv_temp [%s]",lp_args[1]);
//
//	//int x=10;//local variable  
//	//static int y=10;//static variable  
//	//for(int i=1; i<5; i++)
//	//{
//	//	x=x+1;  
//	//	y=y+1;  
//	//	printf("%d\n",x);
//	//	printf("%d\n",y);
//	//}
//}
//
//class Base          //Abstract base class
//{
// public:
// virtual void show() = 0;            //Pure Virtual Function
//};
//
//void Base :: show()         //Pure Virtual definition
//{
//	cout << "Pure Virtual definition\n";
//}
//
//class Derived:public Base
//{
// void show()
// {
//	 cout << "Implementation of Virtual Function in Derived class"; 
// }
//};
//
//int main()
//{
// Base *b;
// Derived d;
// b = &d;
// b->show();
//}
 /*int binary(int a[],int n,int m,int l,int u);
int main(){

    int a[10],i,n,m,c,l,u;

    printf("Enter the size of an array: ");
    scanf("%d",&n);

    printf("Enter the elements of the array: " );
    for(i=0;i<n;i++){
         scanf("%d",&a[i]);
    }

    printf("Enter the number to be search: ");
    scanf("%d",&m);

    l=0,u=n-1;
    c=binary(a,n,m,l,u);
    if(c==0)
         printf("Number is not found.");
    else
         printf("Number is found.");

    return 0;
 }

int binary(int a[],int n,int m,int l,int u){

     int mid,c=0;

     if(l<=u){
          mid=(l+u)/2;
          if(m==a[mid]){
              c=1;
          }
          else if(m<a[mid]){
              return binary(a,n,m,l,mid-1);
          }
          else
              return binary(a,n,m,mid+1,u);
     }
     else
       return c;
}*/

//int main()
//{
//   int c, first, last, middle, n, search, array[100];
// 
//   printf("Enter number of elements\n");
//   scanf("%d",&n);
// 
//   printf("Enter %d integers\n", n);
// 
//   for (c = 0; c < n; c++)
//      scanf("%d",&array[c]);
// 
//   printf("Enter value to find\n");
//   scanf("%d", &search);
// 
//   first = 0;
//   last = n - 1;
//   middle = (first+last)/2;
// 
//   while (first <= last) {
//      if (array[middle] < search)
//         first = middle + 1;    
//      else if (array[middle] == search) {
//         printf("%d found at location %d.\n", search, middle+1);
//         break;
//      }
//      else
//         last = middle - 1;
// 
//      middle = (first + last)/2;
//   }
//   if (first > last)
//      printf("Not found! %d is not present in the list.\n", search);
// 
//   return 0;   
//}


//#include <iostream.h>
//using namespace std;
//
//class Polygon {
//  protected:
//    int width, height;
//  public:
//    void set_values (int a, int b)
//      { width=a; height=b; }
//};
//
//class Rectangle: public Polygon {
//  public:
//    int area()
//      { return width*height; }
//};
//
//class Triangle: public Polygon {
//  public:
//    int area()
//      { return width*height/2; }
//};
//
//int main () {
//  Rectangle rect;
//  Triangle trgl;
//  Polygon * ppoly1 = &rect;
//  Polygon * ppoly2 = &trgl;
//  ppoly1->set_values (2.5,3.5);
//  ppoly2->set_values (2.5,3.5);
//  cout << rect.area() << '\n';
//  cout << trgl.area() << '\n';
//  return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void main()
//{
//	int i;
//	char j,k;
//	for(i=71;i>=65;i--)
//	{
//		for(j=65;j<=i;j++)
//		{
//			printf("%c",j);
//		}
//		for(k=i;k>=65;k--)
//		{
//			printf("%c",k);
//		}
//	printf("\n");
//	}
//}
//#include<stdio.h>    
//#include<conio.h>    
//    
//long factorial(int n)    
//{    
//  if (n == 0)    
//    return 1;    
//  else    
//    return(n * factorial(n-1));    
//}    
//void main()    
//{    
//  int number;    
//  long fact;    
//   printf("Enter a number: ");    
//  scanf("%d", &number);     
//     
//  fact = factorial(number);    
//  printf("Factorial of %d is %ld\n", number, fact);    
//  getch();    
//}    
//int main () 
//{
//    int a = 1;
//    /*
//	printf("%d, %d, %d\n",a++,a,++a);
//    
//    printf("%d\n",a);
//    
//    printf("%d, %d\n",++a,a++);
//    printf("%d,%d\n",++a,a);
//    
//    printf("%d, %d, %d\n",a++,a,++a);
//    printf("%d\n",a);
//	  */
//	printf("%d, %d\n",++a,a++);
//   return 0;
//}

