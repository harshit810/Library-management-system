#include<fstream.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
int count;
int counts;
class library;
class student
{
	  int rollno,token,bno;
	  char name[50];
  public:
	  void getstud();
	  void display();
	  int getno()
	  {
	    return rollno;
	  }
	  char *getname()
	  {
	    return name;
	  }
	  int getbno()
	  {
	    return bno;
	  }
	  int gettoken()
	  {
	    return token;
	  }
	  void addtoken()
	  {
	    token=1;
	  }
	  void resettoken()
	  {
	     token=0;
	  }
	  void getsbno(int a)
	  {
	     bno=a;
	  }
}s1;


class library
{
	  int bookno;
	  char bookname[50],author[50],publisher[50];
  public:
	  void usermenu();
	  void getbook();
	  void adminmenu();
	  void modbook();
	  void displaybook(int , char [],char [],char []);
	  void searchbookname(char []);
	  void searchbookno(int );
	  void searchauthor(char []);
	  void searchpublisher(char []);
	  int getno()
	   {
	     return bookno;
	   }
	  char *getname()
	   {
	     return bookname;
	   }
	  char *getauthor()
	   {
	     return author;
	   }
	  char *getpublisher()
	   {
	     return publisher;
	   }

}l1;


void main()
{
	int n;
	void writestud(student );
	char pass[50]="admin",p[50];
	cout<<"   \t\t     library management system           \n";
	do
	{
	clrscr();
	cout<<"\n\t1 for student\n\t2 for admin\n\t3 exit\n";
	cin>>n;
	switch(n)
	{
		case 1:
			    clrscr();
			    cout<<"                         student \n";
			    l1.usermenu();
			    break;
		case 2:
			    cout<<"enter password\n";
			    cin>>p;
			    if(strcmp(p,pass)==0)
			    {
				    clrscr();
				    cout<<"                  admin\n";
				    l1.adminmenu();
			    }
			    else
			    {
				cout<<"\nwrong password\n";
			    }
				break;
		case 3:
			    cout<<"exiting\n";
			    break;
		default:
			     cout<<"wrong choice\n";
			     break;
	}
	}while(n!=3);
	getch();

 }
void library::usermenu()
{
   int c,m;
   char ch;
   void issuebook();
   void depositbook();
   cout<<"\n\t1 to issue\n\t2 to return\n\t3 return to main menu\n";
   cin>>m;
   switch(m)
   {
    case 1:
     clrscr();
     cout<<"\n\t1 search by name\n\t2 search by author\n\t3 search by publisher\n\t4 issue book\n\t5 return to main menu\n";
     cout<<"\nenter your choice (1-5)\n";
     cin>>c;
     clrscr();
     switch(c)
     {
	case 1:
		 cout<<"enter the book name\n";
		 gets(bookname);
		 l1.searchbookname(bookname);
		 break;
	case 2:
		 cout<<"enter the author name\n";
		 gets(author);
		 l1.searchauthor(author);
		 break;
	case 3:
		 cout<<"enter publisher name\n";
		 gets(publisher);
		 l1.searchpublisher(publisher);
		 break;
       case 4:
		 issuebook();
		 break;
	case 5:
		 return;
	default:
		 cout<<"wrong choice\n";
		 break;
     }
     break;
    case 2:
       cout<<"return\n";
       depositbook();
       break;
    case 3:
       return;
    default:
       cout<<"wrong choice\n";
       break;
  }
}

void library::adminmenu()
{
   int n,no;
   clrscr();
   void writebook(library );
   void modifybook(int );
   void deletebook(int );
   void students();
   clrscr();
   cout<<"\n\t1 add new book\n\t2 modify book data\n\t3 delete book \n\t4 students\n\t5 return to main menu\n";
   cin>>n;
   switch(n)
    {
       case 1:
		l1.getbook();
		writebook(l1);
		break;
       case 2:
		cout<<"\nenter book number \n";
		cin>>no;
		modifybook(no);
		break;
       case 3:
		cout<<"enter book no you want to delete\n";
		cin>>no;
		deletebook(no);
		break;
       case 4:
		students();
		break;
       case 5:
		return;
       default:
		cout<<"\nwrong choice ";
		break;
    }
}
void library::searchbookname( char name[])
{
   int flag=0,id;
   char nm[50],au[50],pub[50];
   ifstream fin("book.txt");
    if(!fin)
     {
       cout<<"\nerror in opening file\n";
     }
    else
     {
       while(!fin.eof())
	 {
	   fin>>id>>nm>>au>>pub;
	   if(strcmp(nm,name)==0)
	    {
	       cout<<"\nrecord found\n";
	       l1.displaybook(id,nm,au,pub);
	       flag=1;
	       break;
	    }
	 }
       if(flag==0)
	 {
	   cout<<"book does not exist\n";
	 }
       getch();
       fin.close();
     }
    getch();
}

void library::displaybook(int no,char name[],char auth[],char publish[])
{
  cout<<"\n-------------------\n";
  cout<<"book no     "<<no;
  cout<<"\nbook name "<<name;
  cout<<"\nauthor    "<<auth;
  cout<<"\npublisher "<<publish;
}
void library::searchauthor(char auth[])
{
   int flag=0,no;
   char nm[50],au[50],pub[50];
   ifstream fin("book.txt");
    if(!fin)
     {
       cout<<"\nerror in opening file\n";
     }
    else
     {
       while(!fin.eof())
	 {
	   fin>>no>>nm>>au>>pub;
	   if(strcmp(au,auth)==0)
	    {
	       cout<<"\nrecord found\n";
	       l1.displaybook(no,nm,au,pub);
	       flag=1;
	       break;
	    }
	 }
       if(flag==0)
	 {
	   cout<<"book does not exist\n";
	 }
       getch();
       fin.close();
     }
    getch();
}
void library::searchpublisher(char publish[])
{
   int flag=0,no;
   char nm[50],au[50],pub[50];
   ifstream fin("book.txt");
    if(!fin)
     {
       cout<<"\nerror in opening file\n";
     }
    else
     {
       while(!fin.eof())
	 {
	   fin>>no>>nm>>au>>pub;
	   if(strcmp(pub,publish)==0)
	    {
	       cout<<"\nrecord found\n";
	       l1.displaybook(no,nm,au,pub);
	       flag=1;
	       break;
	    }
	 }
       if(flag==0)
	 {
	   cout<<"book does not exist\n";
	 }
       getch();
       fin.close();
     }
     getch();
}


void library::getbook()
{
  cout<<"\nenter book number ";
  cin>>bookno;
  cout<<"\nenter book name ";
  gets(bookname);
  cout<<"\nenter author ";
  gets(author);
  cout<<"\nenter publisher ";
  gets(publisher);
  count++;
}
void writebook(library l1)
{
  ofstream fout("book.txt",ios::app);
  if(!fout)
  {
   cout<<"\nerror in opening file \n";
  }
  fout<<endl<<l1.getno()<<endl<<l1.getname()<<endl<<l1.getauthor()<<endl<<l1.getpublisher();
  cout<<"\nbook added to list ";
  getch();
  fout.close();
}
void deletebook(int num)
{
   int flag=0,no;
   char nm[50],au[50],pub[50];
   ifstream fin("book.txt");
   if(!fin)
     {
       cout<<"error in opening file \n";
     }
   else
   {
   ofstream fout("temp.txt",ios::out);
   while(!fin.eof())
    {
      fin>>no>>nm>>au>>pub;
      if(no!=num)
       {
	 fout<<endl<<no<<endl<<nm<<endl<<au<<endl<<pub;
       }
      else
       {
	 flag=1;
       }
    }
   fin.close();
   fout.close();
   if(flag==0)
    {
      cout<<"\nbook not found\n ";
      getch();
    }
   else
     {
       cout<<"\nrecord deleted successfully\n";
       getch();
     }
   remove("book.txt");
   rename("temp.txt","book.txt");
   }
   getch();
}
void modifybook(int num)
{
   int flag=0,no;
   char nm[50],au[50],pub[50],choice;
   ifstream fin("book.txt");
   if(!fin)
     {
       cout<<"error in opening file \n";
     }
   else
   {
   ofstream fout("temp.txt",ios::out);
   while(!fin.eof())
    {
      fin>>no>>nm>>au>>pub;
      if(no==num)
       {
	 if(flag!=1)
	 {
	 flag=1;
	 l1.displaybook(no,nm,au,pub);
	 cout<<"\nchange this entry (y/n) ";
	 cin>>choice;
	 if(choice=='y'||choice=='Y')
	 {
	   l1.getbook();
	   fout<<endl<<l1.getno()<<endl<<l1.getname()<<endl<<l1.getauthor()<<endl<<l1.getpublisher();
	 }
	 else
	   fout<<endl<<no<<endl<<nm<<endl<<au<<endl<<pub;
	 }
       }
      else
       {
	  fout<<endl<<no<<endl<<nm<<endl<<au<<endl<<pub;
       }
    }
   fin.close();
   fout.close();
   remove("book.txt");
   rename("temp.txt","book.txt");
   }
   getch();
}

void student::getstud()
{
   cout<<"\nenter roll number\n";
   cin>>rollno;
   cout<<"enter name \n ";
   gets(name);
   token=0;
   bno=0;
   counts++;
}
void writestud(student s)
{
   ofstream fout("student.txt",ios::app);
   fout<<endl<<s.getno()<<endl<<s.getname()<<endl<<s.getbno()<<endl<<s.gettoken();
   fout.close();
}

void student::display()
{
  int rno,tok,book;
  char sname[50];
  ifstream fin("student.txt");
  if(!fin)
  {
    cout<<"file does not exist \n";
  }
  else
  {
  while(!fin.eof())
   {
     fin>>rno>>sname>>book>>tok;
     cout<<"\nroll no "<<rno<<"\n name "<<sname<<" \nissued book no(0 shows no book issued) "<<book<<"\nno of book issued "<<tok<<"\n";
   }
  }
  fin.close();
  getch();
}
void students()
{
  void deletestud(int );
  int n,rno;
  clrscr();
  cout<<"\n\t1 add new student\n\t2 display all students\n\t3 delete student details\n";
  cin>>n;
  switch(n)
  {
    case 1:
	    s1.getstud();
	    writestud(s1);
	    counts++;
	    break;
    case 2:
	    s1.display();
	    break;
    case 3:
	    cout<<"enter roll number of student ";
	    cin>>rno;
	    deletestud(rno);
	    break;
    default:
	     cout<<"\nwrong choice\n";
	     break;
  }
}

void deletestud(int no)
{
   int flag=0,num,tok,sbno;
   char nm[50],ch;
   ifstream fin("student.txt");
   if(!fin)
     {
       cout<<"error in opening file \n";
     }
   else
   {
   ofstream fout("temp.txt",ios::out);
   while(!fin.eof())
    {
      fin>>num>>nm>>sbno>>tok;
      if(no!=num)
       {
	 fout<<endl<<num<<endl<<nm<<endl<<sbno<<endl<<tok;
       }
      else
       {
	 flag=1;
       }
    }
   fin.close();
   fout.close();
   if(flag==0)
    {
      cout<<"\nstudent not found\n ";
      getch();
    }
   else
     {
       cout<<"\nrecord deleted successfully\n";
       counts--;
       getch();
     }
   remove("student.txt");
   rename("temp.txt","student.txt");
   }
   getch();
}

void issuebook()
{
   int rno,num,tok,booknum,flag=0,found=0,bnum,boknu;
   char nm[50],name[50],auth[50],pub[50];
   ifstream fin("book.txt");
   ifstream f1("student.txt");
   ofstream fout("temp.txt");
   if(!f1)
   {
     cout<<"\nerror in opening file ";
   }
   else
   {
   cout<<"\nenter your roll number ";
   cin>>rno;
   while(!f1.eof())
     {
	f1>>num>>nm>>booknum>>tok;
	if(num==rno)
	  {
	    found=1;
	     if(tok==0)
	       {
		  cout<<"\nenter book number ";
		  cin>>bnum;
		  while(!fin.eof())
		    {
		       fin>>boknu>>name>>auth>>pub;
			if(boknu==bnum)
			  {
			     l1.displaybook(boknu,name,auth,pub);
			     flag=1;
			     tok=1;
			     booknum=boknu;
			     fout<<endl<<num<<endl<<nm<<endl<<booknum<<endl<<tok;
			     cout<<"\nbook issued successfully ";
			  }
		    }
		  if(flag==0)
		  {
		    //fout<<endl<num<<endl<<nm<endl<<booknum<<endl<<tok;
		    cout<<"\nbook does not exist ";
		  }
	       }
	     else
	     {
	       fout<<endl<<num<<endl<<nm<<endl<<booknum<<endl<<tok;
	       cout<<"\ndeposit book first ";
	     }
	  }
	else
	  fout<<endl<<num<<endl<<nm<<endl<<booknum<<endl<<tok;
     }
   if(found==0)
     cout<<"\nstudent record does not exist ";
   f1.close();
   fin.close();
   fout.close();
   remove("student.txt");
   rename("temp.txt","student.txt");
   }
   getch();
}

void depositbook()
{
   int rno,fine,day,snum,tok,sbno,bbno,found=0,flag=0;
   char sname[50],bname[50],auth[50],pub[50];
   ifstream f1("book.txt");
   ifstream fin("student.txt");
   ofstream fout("temp.txt");
   if(!fin)
   {
     cout<<"\nerror in opening file ";
   }
   else
   {
   cout<<"\nenter students roll number ";
   cin>>rno;
   while(!fin.eof())
    {
       fin>>snum>>sname>>sbno>>tok;
       if(rno==snum)
	 {
	    found=1;
	    if(tok==1)
	      {
	       while(!f1.eof())
	       {
		 f1>>bbno>>bname>>auth>>pub;
		 if(bbno==sbno)
		   {
		      l1.displaybook(bbno,bname,auth,pub);
		      flag=1;
		      cout<<"\nbook deposited in number of days ";
		      cin>>day;
		      if(day>15)
		      {
			fine=(day-15)*2;
			cout<<"\nfine to be deposited is Rs "<<fine;
		      }
		      tok=0;
		      sbno=0;
		      fout<<endl<<snum<<endl<<sname<<endl<<sbno<<endl<<tok;
		      cout<<"\nbook deposied successfully ";
		   }
		 }
	       if(flag==0)
	       {
	       fout<<endl<<snum<<endl<<sname<<endl<<sbno<<endl<<tok;
		cout<<"\nbook no does not exist ";
	       }
	      }
	  else
	  {
	    fout<<endl<<snum<<endl<<sname<<endl<<sbno<<endl<<tok;
	    cout<<"\nissue book first ";
	  }
	 }
       else
	 fout<<endl<<snum<<endl<<sname<<endl<<sbno<<endl<<tok;
    }
   if(found==0)
    {
      cout<<"\nstudent record not exist ";
    }
   f1.close();
   fin.close();
   fout.close();
   remove("student.txt");
   rename("temp.txt","student.txt");
   }
   getch();
}