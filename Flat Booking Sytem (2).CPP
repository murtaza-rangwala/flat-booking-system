// Authors: Murtaza Hatim, Trisha Ann, Ahmed, Brian Peter
// Conceived Date: 23/12/2017


//APARTMENT RETAIL AND MANAGEMENT PROJECT : BOOKING OF FLATS

#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<dos.h>
#include<constrea.h>


struct real_estate
{ int bookingcode;
  int flatno;
  char bookingname[35];
  float amountpaid;
  float pendamt;
  float bcost;
  long telephoneno;
  char dob[12];
  char address[100];
  char email[15];
  char passportno[15];
  char panno[15];
  char paymentm[10];
  long chequeno;
  long accno;
  char bankname[25];
  char branchname[25];
 }R;


struct building
{ int flatno;
  int floor;
  int type;
  float cost;
  char direction;
  char status[12];
} B;


//Function Prototypes

void heading();
void login();
void menu();
void masthead();
void adminmenu();
void newcustomer();
void oldcustomer();
void bookedflats();
void cancelbooking();
void paymentpending();


//adminmenu(): Function for admin options; to create the flats details.

void adminmenu()
{  int d, no,flag;
   char ch,ans; clrscr();system("color 09");

   masthead();
   cout<<"\n\n\n\n\n\t\t\t\t MENU";
   cout<<"\n\t\t\t Building Details";
   cout<<"\n\t\t\t Back to Login Screen";
   d=10;
   ch=' ';
   while(ch!=13)
   {  gotoxy(23,d);
      cout<<'>';
      ch=getch();
      if(ch=='2')
      {  gotoxy(23,d);
         cout<<' ';
         d=11;
      }
      if(ch=='8')
      {  gotoxy(23,d);
         cout<<' ';
         d=10;
      }
   }
   switch(d)
   { case 10: { masthead();
                do
                {  xyz:
                   clrscr();system("color Fc"); masthead();
                   ofstream file1("BUILD.DAT",ios::binary|ios::app);
                   cout<<"\n\t\t               Flat Details ";
                   cout<<"\n             Flat Number        : ";
                   gotoxy(35,6);
                   cin>>no;

                   flag=0;
                   ifstream file2("BUILD.DAT",ios::binary|ios::app);
                   while(file2.read((char*)&B,sizeof(B)))
                   {
                     if(B.flatno==no)
                     {  flag=1;
                        break;
                     }
                   }
                   file2.close();

                  if(flag==1)
                  { cout<<"\n\n       Flat No. Already Exists";
                    cout<<"\n      Press any key to continue... ";
                    getch();
                    goto xyz;
                  }
                  else
                  { B.flatno=no;
                    cout<<"\n             Floor              : ";
                    gotoxy(35,8);
                    cin>>B.floor;
                    cout<<"\n             Type(2BHK/3BHK)    : ";
                    gotoxy(35,10);
                    cin>>B.type;
                    cout<<"\n             Direction(E/W/S/N) : ";
                    gotoxy(35,12);
                    cin>>B.direction;
                    cout<<"\n             Cost               : $ ";
                    gotoxy(37,14);
                    cin>>B.cost;
                    strcpy(B.status,"Available");
                    file1.seekp(0,ios::end);
                    file1.write((char*)&B, sizeof(B));
                 }

                 cout<<"\n\n\n       Would you like to add the details of another flat? ";
                 cin>>ans;
                 file1.close();
             }
             while(ans=='y'||ans=='Y');
             cout<<"\n      Press any key to return login screen... ";
             getch();
             login();
             break;
     }
   case 12:{ cout<<"\n      Press any key to return login screen... ";
             getch();
             login();
           }
      }
  }


/*newcustomer(): Function to read the details of new customer to book the flat
according to their choice.*/

void newcustomer()
{   int m,flag=0,flatbook,p,q, d,fl=0,A[25],i=0;
    char c, dir, w, ch;

    fstream file1("FLAT.DAT",ios::binary|ios::in|ios::out|ios::app);
    fstream file2("BUILD.DAT",ios::binary|ios::in|ios::out);
    clrscr();
    masthead();
    cout<<"\n\n\n\t\t\t\t MENU";
    cout<<"\n\t\t\t   Book a new flat";
    cout<<"\n\t\t\t   Back to Main Menu";
    d=8;
    ch=' ';
    while(ch!=13)
    { gotoxy(23,d);
      cout<<'>';
      ch=getch();
      if(ch=='2')
      {  d=9;;
         gotoxy(23,8);
         cout<<' ';
      }
     if(ch=='8')
     {   d=8;
         gotoxy(23,9);
         cout<<' ';
     }
    }
    switch(d)
     { case 8: { clrscr();
	    masthead();
	    cout<<"\n\t\t\t  Customer Details ";
       cout<<"\n\t\t\t ______________________";
       cout<<"\n\n\t      Customer Name           (Mr/ Mrs.): ";
	    cout<<"\n\n\t      Date Of Birth                     : ";
	    cout<<"\n\n\t      Current Adddress                  : " ;
	    cout<<"\n\n\t      Telephone No.                     : ";
       cout<<"\n\n\t      Email Id                          : ";
	    cout<<"\n\n\t      Passport No./Driver's Licence No. : ";
	    cout<<"\n\n\t      PAN Card No                       : ";

	    gotoxy(51,8);
	    gets(R.bookingname);
	    gotoxy(51,10);
	    gets(R.dob);
	    gotoxy(51,12);
       gets(R.address);
	    gotoxy(51,14);
       cin>>R.telephoneno;
	    gotoxy(51,16);
       gets(R.email);
       gotoxy(51,18);
       gets(R.passportno);
       gotoxy(51,20);
       gets(R.panno);
       cout<<"\n\n\t     Press any key to continue to the next step...";
	    getch();
	    cout<<"\n\t\t\t Loading.......";

	    for(long k=0;k<=1000000000;k++);

//Flat availablity checking

	    ABC:
	    clrscr();
	    masthead();
	    cout<<"\n\n\n\t Which direction do you wish to have your flat facing ?\n";
	    cout<<"\n\n\t\t\t              Flat no.";
	    cout<<"\n\t\t\t N - North      x01";
	    cout<<"\n\t\t\t S - South      x02";
	    cout<<"\n\t\t\t E - East       x03";
	    cout<<"\n\t\t\t W - West       x04";
	    cout<<"\n\t\t\t B - back to menu";
	    cout<<"\n\n\t\t  Enter your choice: ";
	    dir=getchar();
       dir=toupper(dir);
       if (dir=='B'||dir=='b')
	      break;
	    else
	    { cout<<"\n\n\t\t Loading available flats...";
	      for(long k=0;k<=10000;k++);
	      clrscr();
	      file2.seekg(0,ios::beg);
	      masthead();
	      cout<<"\n\n\t                    AVAILABLE FLATS";
	      cout<<"\n\n\t\t FLAT NO. | FLOOR | TYPE |    COST  | STATUS ";
	      m=10;
	      while(file2.read((char*)&B,sizeof(B)))
	      {
           if(B.direction==dir&&!strcmp(B.status,"Available"))
	        {  flag=1;
	           gotoxy(21,m);
	           cout<<B.flatno;A[i++]=B.flatno;
	           gotoxy(27,m);
	           cout<<'|';
	           gotoxy(31,m);
	           cout<<B.floor;
	           gotoxy(35,m);
	           cout<<'|';
	           gotoxy(37,m);
	           cout<<B.type<<"BHK";
              gotoxy(42,m);
	           cout<<'|';
	           gotoxy(45,m);
	           cout<<"$ "<<B.cost;
              gotoxy(54,m);
	           cout<<'|';
              gotoxy(56,m++);
	           cout<<B.status;
           }
         }
	      if(flag==0)
	      { cout<<"\n\n\n\t\t Sorry... No flats available in this category";
	        cout<<"\n\n\t\t Press any key to go back to the previous page...";
	        getch();
	        cout<<"\n\n\t\t Loading.....        ";
	        for(long k=0;k<=10000000;k++);
	         goto ABC;
         }

// Flat booking confirmation

       xyz:
	    cout<<"\n\n\t\t\t Enter the flat no. you wish to book: ";
	    cin>>flatbook;
       for(int j=0;j<i;j++)
       {   if(A[j]==flatbook)
            fl=1;
       }
       if(fl==0)
       {  cout<<"\n\n\n\t\t\t INVALID FLAT NO";
          goto xyz;
       }
	    cout<<"\n\n\t\t You have chosen flat no. "<<flatbook<<"  Floor  "<<B.floor<<"  "<<B.type<<"BHK";
       R.bcost=B.cost;
       cout<<"\n\n\n\n\t\t\t BOOKING CONFIRMNATION........";
       cout<<"\n\n\n\n\t\t Press any key to continue to the PAYMENT SCREEN...";
	    getch();

// Payment details

	    clrscr();
	    masthead();
	    cout<<"\n\t\t\t Payment Details";
	    cout<<"\n\n\t\t Mode of payment ";
	    cout<<"\n\t\t\t   Cash ";
	    cout<<"\n\t\t\t   Cheque ";
	    cout<<"\n\t(Use the arrow keys on the numpad to navigate your choice)";
	    p=8;
	    q=' ';
	    while(q!=13)
	    { gotoxy(20,p);
	      cout<<'>';
	      q=getch();
	      if(q=='2')
	      {gotoxy(20,p);
	       cout<<' ';
	       p=9;
       }
	      if(q=='8')
	      {gotoxy(20,p);
	       cout<<' ';
	       p=8;

         }
       }
	      if(p==8)
	      { strcpy(R.paymentm,"Cash");
	        cout<<"\n\n\n\t Amount Paid   :$ ";
	         cin>>R.amountpaid;
         }
	      else
	      { cout<<"\n\n\t\t\t BANK DETAILS";
           strcpy(R.paymentm,"Cheque");
	        cout<<"\n\n\t\t\t  Account No.      :";
           cin>>R.accno;
           cout<<"\n\n\t\t\t  Cheque No.       : ";
	        cin>>R.chequeno;
           cout<<"\n\n\t\t\t  Bank Name        : ";
	        gets(R.bankname);
	        cout<<"\n\n\t\t\t  Branch Name      : ";
	        gets(R.branchname);
	        cout<<"\n\n\n\t\t  Amount Paid      :$ ";
	        cin>>R.amountpaid;}
	        cout<<"\n\n\t\t\t\t  Loading...";

	        for(long k=0;k<=10000;k++);
	        R.flatno=flatbook;
	        file1.seekg(0,ios::end);
	        R.bookingcode=R.flatno+10000;
           R.pendamt=R.bcost-R.amountpaid;
	        file1.write((char*)&R,sizeof(R));

	        clrscr();
	        masthead();
           int fn=R.flatno;
	        cout<<"\n\n\t\t*** NOTIFICATION : BOOKING COMPLETE : BOOKING DETAILS ***";
           cout<<"\n\n\t\t\t Booking Code        : ";
           constream cout;
           cout<<setclr(WHITE);
           cout<<R.bookingcode;
           cout<<"\n  \t\t\t                      =========";
           cout<<"\n\n\t\t\tFlat no.            : "<<flatbook;
           cout<<"\n\n\t\t\tFloor               : "<<B.floor;
           cout<<"\n\n\t\t\tNo of Bed rooms     : "<<B.type<<"BHK";
           cout<<"\n\n\t\t\tPending Amount      : "<<R.pendamt;
           cout<<"\n\n\n\n\t\tPerforming transaction...Please wait...";
           getch();
           file2.close();
           file1.close();

           fstream file2("BUILD.DAT",ios::binary|ios::in|ios::out);
           file2.seekg(0,ios::beg);
	        while(file2.read((char*)&B,sizeof(B)))
	        {   if(B.flatno==fn)
	              {   file2.seekg(file2.tellg()-sizeof(B),ios::beg);
	                  strcpy(B.status,"Booked");
	                  file2.write((char*)&B,sizeof(B));
                 }
           }

	        file2.close();}
	        break;
         }
  case 9: { clrscr();
            menu();
	         break;
          }
         }
  }


//oldcustomer(): Exsisting customer details and pending payment.

void oldcustomer()
{   int sbookingcode, flag=0, ans, p, flat_book;
    char ch, q; float amt=0;
    fstream file1("FLAT.DAT",ios::binary|ios::in|ios::out);
    cout<<"\n\n\t\t\t CUSTOMER DETAILS";
    cout<<"\n\t\t\t ________________";
    cout<<"\n\n\n\n\t Enter the booking code : ";
    cin>>sbookingcode;
    while(file1.read((char*)&R,sizeof(R)))
    {    if(sbookingcode==R.bookingcode)
         {  flag=1;
            clrscr();
            masthead();
            cout<<"\n\t Booking Code                    : "<<R.bookingcode;
            cout<<"\n\t Customer Name                   :(Mr./Mrs.) "<<R.bookingname;
            cout<<"\n\t Date of Birth                   : "<<R.dob;
            cout<<"\n\t Current Address                 : "<<R.address;
            cout<<"\n\t Telephone no.                   : "<<R.telephoneno;
            cout<<"\n\t Email Id                        : "<<R.email;
            cout<<"\n\t Pan Card No.                    : "<<R.panno;
            cout<<"\n\t Passport number                 : "<<R.passportno;

            if(!strcmp(R.paymentm,"Cheque"))
            {     cout<<"\n\t Account No.                     : "<<R.accno;
                  cout<<"\n\t Cheque number                   : "<<R.chequeno;
                  cout<<"\n\t Bank Name                       : "<<R.bankname;
                  cout<<"\n\t Branch Name                     : "<<R.branchname;
            }
           cout<<"\n\t Amount Paid                     : $"<<R.amountpaid;
           if(R.pendamt>0)
           {  cout<<"\n\n\t\t     *** PAYMENT PENDING *** ";
              cout<<"\n\n\t\t Pending Amount      : "<<R.pendamt;
              cout<<"\n\n\n\n\n\t Do you want to proceed to the payment? ( Y / N )";
              cin>>ch;
              if(ch=='Y'||ch=='y')
	           {  clrscr();
	              masthead();
	              cout<<"\n\t\t\t Payment Details";
	              cout<<"\n\n\t\t Mode of payment ";
	              cout<<"\n\t\t\t   Cash ";
	              cout<<"\n\t\t\t   Cheque ";
	              cout<<"\n\t(Use the arrow keys on the numpad to navigate your choice)";
	              p=8;
	              q=' ';
	              while(q!=13)
	              {  gotoxy(20,p);
	                 cout<<'>';
	                 q=getch();
	                 if(q=='2')
	                 {  gotoxy(20,p);
	                    cout<<' ';
	                    p=9;
                    }
	                 if(q=='8')
	                 {   gotoxy(20,p);
	                     cout<<' ';
	                     p=8;
                    }
                 }
	              if(p==8)
	              {  strcpy(R.paymentm,"Cash");
	                 cout<<"\n\n\n\t Amount Paid   :$ ";
	                 cin>>amt;
                 }
	              else
	              {  cout<<"\n\n\t\t\t\t BANK DETAILS";
                    strcpy(R.paymentm,"Cheque");
	                 cout<<"\n\n\t\t\t\t  Account No.      :";
                    cin>>R.accno;
                    cout<<"\n\n\t\t\t\t  Cheque No.       : ";
	                 cin>>R.chequeno;
	                 cout<<"\n\n\t\t\t\t  Bank Name        : ";
	                 gets(R.bankname);
	                 cout<<"\n\n\t\t\t\t  Branch Name      : ";
	                 gets(R.branchname);
	                 cout<<"\n\n\t\t\t\t  Amount Paid      :$ ";
	                 cin>>amt;
                 }

         R.amountpaid+=amt;
         R.pendamt=R.bcost-R.amountpaid;
         file1.seekg(file1.tellg()-sizeof(R),ios::beg);
         file1.write((char*)&R,sizeof(R));
     }

	      cout<<"\n\n\t\t Loading...";

      if(ch=='N'||ch=='n')
      { cout<<"\n\n\t\t   *** NOTIFICATION : PAYMENT INCOMPLETE ***";
        cout<<"\n\n\t\t   Press any key to return to the Main Menu... ";
        getch();
        cout<<"\n Loading...";
        menu();
      }

      if(R.pendamt==0)
	      cout<<"\n\t\t    *** NOTIFICATION : TRANSACTION COMPLETE ***";
      else
         cout<<"\n\n\t\t   *** NOTIFICATION : PAYMENT COMPLETE ***";
    }
   }  file1.close();
      cout<<"\n\t\t Press any key to return to the Main Menu... ";
      getch();
      menu();
  }

      if(flag==0)
        {cout<<"\n        *** ERROR : INVALID BOOKING NUMBER *** \n";
         cout<<" \t   Press any key to go back to main menu... ";
         getch();
         cout<<"\n Loading...";
         menu();
          }
      file1.close();
 }


//bookedflats(): To display the booked flats details.

void bookedflats()

{  ifstream infile("FLAT.DAT",ios::binary);
   infile.seekg(0,ios::beg);
   clrscr();
   masthead();
   gotoxy(28,6);
   cout<<"DETAILS OF BOOKED FLATS";
   gotoxy(1,7);
   cout<<"BOOKING CODE |   BOOKING NAME   |   FLAT No.   |   AMOUNT PAID   |PENDING AMOUNT";
   gotoxy(1,8);
   cout<<"-------------|------------------|--------------|-----------------|--------------";
   int i=9;
   while(infile.read((char*)&R,sizeof(R)))
   {    gotoxy(3,i);
        cout<<R.bookingcode;
        gotoxy(14,i); cout<<"|";
        gotoxy(18,i);
        cout<<R.bookingname;
        gotoxy(33,i); cout<<"|";
        gotoxy(40,i);
        cout<<R.flatno;
        gotoxy(48,i); cout<<"|";
        gotoxy(53,i);
        cout<<"$"<<R.amountpaid;
        gotoxy(66,i); cout<<"|";
        gotoxy(70,i++);
        cout<<"$"<<R.pendamt;
   }
   cout<<"\n\n\n\t Press any key to go back to the Main Menu... ";
   getch();
   infile.close();
  }


//paymentpending: Pending payments details.

void paymentpending()

{  ifstream infile("FLAT.DAT",ios::binary);
   clrscr();
   masthead();
   gotoxy(28,6);
   cout<<"DETAILS OF BOOKED FLATS";
   gotoxy(10,7);
   cout<<"BOOKING CODE |   BOOKING NAME   |   FLAT No.   | PENDING AMOUNT";
   gotoxy(10,8);
   cout<<"-------------|------------------|--------------|---------------";
   int i=9;
   while(infile.read((char*)&R,sizeof(R)))
   {  if(R.pendamt>0)
      { gotoxy(12,i);
        cout<<R.bookingcode;
        gotoxy(23,i); cout<<"|";
        gotoxy(25,i);
        cout<<R.bookingname;
        gotoxy(42,i); cout<<"|";
        gotoxy(48,i);
        cout<<R.flatno;
        gotoxy(57,i); cout<<"|";
        gotoxy(60,i++);
        cout<<R.pendamt;
      }
   }
   cout<<"\n\n\n\t Press any key to go back to the Main Menu... ";
   getch();
   cout<<"\n Loading...";
   infile.close();
   menu();
  }


//cancelbooking(): Booking Cancellation

void cancelbooking()

{  int d, i, count=0; char ch; real_estate temp[35];
   ifstream infile("FLAT.DAT",ios::binary);
   int cbookingcode,fn,rf, flag=0;
   infile.seekg(0,ios::beg);
   gotoxy(5,18);

   do
   { clrscr();
     masthead();
     cout<<"\n\n\n\t\t\t\t MENU";
     cout<<"\n\t\t\t Cancel Booking";
     cout<<"\n\t\t\t Back to Main Menu";
     d=8;
     ch=' ';
     while(ch!=13)
     {   gotoxy(23,d);
         cout<<'>';
         ch=getch();
         if(ch=='2')
         {  d=9;
            gotoxy(23,8);
            cout<<' ';
         }
        if(ch=='8')
        {   d=8;
            gotoxy(23,9);
            cout<<' ';
        }
     }
   switch(d)
   {  case 8: { gotoxy(20,14); cout<<"Enter the booking code    : ";
                cin>>cbookingcode;
                i=0;
                while(infile.read((char*)&R,sizeof(R)))
	             { if(cbookingcode!=R.bookingcode)
	               { temp[i++]=R;}
	               else
                  {  fn=R.flatno; rf=R.amountpaid-1000;
	                  flag=1;
                  }
   }

   if(flag==1)
	     { cout<<"\n\n\t\t         *** NOTIFICATION :*******";
          cout<<"\n\n\t       BOOKING CODE "<<cbookingcode<<" HAS BEEN CANCELLED";
          constream cout;cout<<setclr(WHITE);

	       cout<<"\n\n\t   CANCELLATION FEE OF $1000.00 WILL BE DEDICTED FROM REFUND AMOUNT ";
          cout<<"\n\n\t                 REFUND AMOUNT   $  :"<<rf;
          fstream file2("BUILD.DAT",ios::binary|ios::in|ios::out);
          file2.seekg(0,ios::beg);
	       while(file2.read((char*)&B,sizeof(B)))
	       {   if(B.flatno==fn)
	           {  file2.seekg(file2.tellg()-sizeof(B),ios::beg);
	              strcpy(B.status,"Available");
	              file2.write((char*)&B,sizeof(B));
              }
            }
         }
   else
	   cout<<"\n\t\t *** ERROR : INVALID BOOKING CODE *** ";
	infile.close();
	ofstream outfile2("FLAT.DAT",ios::binary);
	count=i;
	for(int j=0 ; j<count ; j++)
	outfile2.write((char*)&temp[j],sizeof(temp[j]));
	cout<<"\n\n\t Press any key to go back to the Main Menu... ";
	getch();
   outfile2.close();
	cout<<"\n Loading...";
   menu();
	break;
  }
  case 9: { cout<<"\n Loading...";
	    	   menu();
	         break;
          }
  }
 }
  while(ch<=2);
  infile.close();
 }


//masthead(): To display page heading

void masthead()
{      //system("color 0c");
	   gotoxy(10,1);
	   cout<<"========================================================";
	   gotoxy(20,2);
	   cout<<" MARCO POLO CONSTRUCTIONS PVT. LTD";
	   gotoxy(9,3);
	   cout<<"  P.O BOX 23, MUMBAI, INDIA .Ph.no 25619783 / 25639379";
      gotoxy(10,4);
	   cout<<"========================================================";
 }


//heading(): Introduction screen

void heading()
{
      clrscr();system("color 0e");

	   char str1[]="APARTMENT MANAGEMENT";
      int t=15;

		for(int f=0;f<strlen(str1);f++)
		{ gotoxy(t,10);
		  printf("%c",str1[f]);
        Beep(600,200); // 500 hertz (C5) for 400 milliseconds
        Sleep(200);
        t=t+2;
       }
  char str[]="S Y S T E M";
       gotoxy(32,12);
		 for(int f=0;f<strlen(str);f++)
		 {  printf("%c",str[f]);;cout<<"\a";
		    Sleep(300);
		 }
  char str2[]="Presented by";
		 gotoxy(34,20);
		 for(int f=0;f<strlen(str2);f++)
		 {   cout<<"\a";printf("%c",str2[f]);
		    Sleep(300);
		 }
  char str3[]="TRISHA ANN THARAKAN";
		 gotoxy(32,22);
		 for(int f=0;f<strlen(str3);f++)
		 { printf("%c",str3[f]);
		   Sleep(300);
		 }
  char str4[]="XII B";
		 gotoxy(38,24);
		 for(int f=0;f<strlen(str4);f++)
		 { printf("%c",str4[f]);
		    Sleep(300);
          cout<<"\a";
       }
  }


//login(): login Screen

void login()

{ int i=0, flag=0;
  char username[10], password[10], c;
  do
  { clrscr();  system("color 0e");  clrscr();  system("color 0e");
    masthead();
    c=' ';
    i=0;
    gotoxy(37,7);
    cout<<"LOGIN";
    gotoxy(30,9);
    cout<<"Username  : ";
    gotoxy(30,10);
    cout<<"Password  : ";
    gotoxy(42,9);
    cin>>username;
    gotoxy(42,10);
    while(c!=13)
    { c=getch();
      if(c!=13)
      { if(c!=8)
        { password[i++]=c;
          cout<<"*";
        }
        else
        { gotoxy(35+(--i),10);
          cout<<" ";
          gotoxy(35+i,10);
        }
      }
          password[i]='\0';
    }
    gotoxy(33,17);
    cout<<"Connecting...\n";
    for(int j=0;j<25;j++)
    {cout<<"_";
     for(long k=0;k<=1000000;k++);
    }
    gotoxy(33,17);
    cout<<"\a                    ";
    gotoxy(31,17);
    cout<<"Authenticating...";
    gotoxy(25,18);
    for(int j=0;j<37;j++)
    { cout<<"_";
      for(long k=0;k<=100000000;k++);
    }
    gotoxy(31,17);
    cout<<"\a                    ";
    gotoxy(37,17);
    cout<<"Loading...";
    gotoxy(62,18);
    for(int j=0;j<19;j++)
    { cout<<"_";
      for(long k=0;k<=100000000;k++);
    }
    if((!strcmp(username,"user"))&&(!strcmp(password,"1234")))
    { flag=1;
      gotoxy(35,19);
      cout<<"Login Successful";
      for(long k=0;k<=100000000;k++);
      Sleep(500);
      menu();
    }
    else
     if((!strcmp(username,"admin"))&&(!strcmp(password,"superadmin")))
      {  flag=1;
         gotoxy(30,19);
         cout<<"Login Successful";
         Sleep(500);
         clrscr();
         adminmenu();}
     else
     {   gotoxy(32,19);
         cout<<"Login Unsuccessful";cout<<"\a";
         Sleep(500);
     }
  }
   while(flag==0);
 }


// Main menu (menu()): Customer options.

void menu()
{  int d=0;
   char c=' ';
   do
   {  clrscr(); system("color 0A");
      masthead();
      cout<<"\n\n\n\t\t\t\t MENU";
      cout<<"\n\t\t\t\t New Customer";
      cout<<"\n\t\t\t\t Old Customer";
      cout<<"\n\t\t\t\t Booked Flats";
      cout<<"\n\t\t\t\t Payment pending for booked flats";
      cout<<"\n\t\t\t\t Cancel Booking";
      cout<<"\n\t\t\t\t Logout";
      cout<<"\n\n\t\t(Use the arrow keys on the numpad to navigate) ";
      d=8;
      c=' ';
      while(c!=13)
      {  gotoxy(30,d);
         cout<<'>';
         c=getch();
         if(c=='2'&&d<13)
         {   d++;
             gotoxy(30,d-1);
             cout<<' ';
         }
         if(c=='8'&&d>8)
         {    d--;
              gotoxy(30,d+1);
              cout<<' ';
         }
      }
    switch(d)
    { case 8: { newcustomer();
	             break; }
      case 9: { clrscr();
                masthead();
                oldcustomer();
	             break; }
      case 10:{ bookedflats();
	             break; }
      case 11:{ paymentpending();
	             break; }
      case 12:{ cancelbooking();
	             break; }
      case 13:{ login();
                break; }
     }
   }
  while(d>7&&d<14); }


void main()
 {
  heading();
  textbackground(BLACK);
  textcolor(BLACK);
  login();
 }
