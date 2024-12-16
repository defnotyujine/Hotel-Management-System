#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<windows.h>
#include<vector>



using namespace std;


class hotel
{

	int room_no;
	char fname[30];
	char mname[30];
	char lname[30];
	char address[50];
	char phone[20];
	char email[30];
	int numoftenants;
	int totalrooms = 50;
	int totalchoices = 6;
	int totalchoices2 = 2;
	


public:

	void main_menu();
	void add();
	void display();
	void rooms();
	void edit(); 
	int check(int);
	void modify(int);
	void delete_rec(int);
	void iloveubb();
	void exception1();
	void exception2();
	void tiangge();
	void prompt();
	
};







void hotel::main_menu()
{
	
	string welcome = "\n\n\n\t\t\t\t\t\t      **WELCOME**"
		 "\n\t\t\t\t\t\t          TO"
		 "\n\t\t\t\t\t   **JPENC HOTEL AND VACATION HOUSE**";
	int p = 0;
	int n = 0;
	int choice;
	
	while (choice != 6)
	{
		system("cls");
		while ( welcome [p] != '\0')
	{
		cout << welcome [p];
		if ( welcome[p]!= ' ' && welcome[p]!= '\n')
		Sleep (30);
		p++;
	}
//		cout << "\n\n\n\t\t\t\t\t\t      **WELCOME**";
//		cout << "\n\t\t\t\t\t\t          TO";
//		cout << "\n\t\t\t\t\t   **JPENC HOTEL AND VACATION HOUSE**";
		cout << "\n\n\n\t\t\t\t\t\t************************" << endl;
		cout << "\t\t\t\t\t\t***                  ***" << endl;
		cout << "\t\t\t\t\t\t**                    **" << endl;
		cout << "\t\t\t\t\t\t*     *MAIN MENU*      *" << endl;
		cout << "\t\t\t\t\t\t**                    **" << endl;
		cout << "\t\t\t\t\t\t***                  ***" << endl;
		cout << "\t\t\t\t\t\t************************" << endl;
		
		cout << "\n\n\t\t\t\t\t      ****************************" << endl;
		cout << "\t\t\t\t\t      *   How can we help you?   *" << endl;
		cout << "\t\t\t\t\t      *   1.BOOK A ROOOM         *" << endl;
		cout << "\t\t\t\t\t      *   2.CUSTOMER RECORDS     *" << endl;
		cout << "\t\t\t\t\t      *   3.ROOMS ALLOCATED      *" << endl;
		cout << "\t\t\t\t\t      *   4.EDIT RECORD          *" << endl;
		cout << "\t\t\t\t\t      *   5.FOOD & BEVERAGE MENU *" << endl;
		cout << "\t\t\t\t\t      *   6.EXIT                 *" << endl;
		cout << "\t\t\t\t\t      ****************************" << endl;
		cout << "\n\t\t\t\t\t           ENTER YOUR CHOICE: ";
		cin >> choice;
		
		switch (choice)
		{

		case 1:	add();
			break;    

		case 2: display();
			break;

		case 3: rooms();
			break;

		case 4:	edit();
			break;
			
		case 5:	tiangge();
			break;

		case 6: prompt();
			break;

		default:
			{
				cout << "\n\t\t\t\t\t\t      Wrong choice!";
				cout << "\n\t\t\t\t\t       Press any key to continue!";
				getch();
			}
	
		}

	}

}







void hotel::add()
{

	system("cls");
	int r, flag;
	ofstream fout("Record.dat", ios::app);

	cout << "\n\n\n\n\n\t\t\t\t\t\t*******************************" << endl;
	cout << "\t\t\t\t\t\t*   STANDARD ROOMS (1-25)     *" << endl;
	cout << "\t\t\t\t\t\t*    DELUXE ROOMS  (26-40)    *" << endl;
	cout << "\t\t\t\t\t\t*    LUXURY ROOMS  (41-50)    *" << endl;
	cout << "\t\t\t\t\t\t*******************************" << endl;
//	cout << "\n\t\t\t\t\t\tEnter Your Desired Room Number:";
//	cin >> r;
	
	try
	{
		cout << "\n\t\t\t\t\t\tEnter Your Desired Room Number: ";
		cin >> r;
		
		if (r > totalrooms)
		{
			throw r;
		}
	}
	
	catch (int e)
	{
		cout << "\n\t\t\t\t\t\t\t     ERROR!";
		getch();
		exception1();
		getch();
		iloveubb();
		
	}
	
	
	
	flag = check(r);

	if (flag)

		cout << "\n\n\t\t\t\t\t\t    Room Number Unavailable!";

	else
	{

		room_no = r;
		cout << "\n\t\t\t\t\t*************************************************";
		cout << "\n\t\t\t\t\t PLEASE FILL IN THE NECESSARY INFORMATION NEEDED ";
		cout << "\n\t\t\t\t\t*************************************************";

		cout << "\n\n\t\t\t\t\t        Enter Your First Name: ";
		cin >> fname;
		
		cout << "\n\t\t\t\t\t        Enter Your Middle Initial: ";
		cin >> mname;
		
		cout << "\n\t\t\t\t\t        Enter Your Last Name: ";
		cin >> lname;
		
		cout << "\n\t\t\t\t\t        Enter Your Complete Address: ";
		cin >> address; 
		
		cout << "\n\t\t\t\t\t        Enter Your Phone Number: ";
		cin >> phone;
		
		cout << "\n\t\t\t\t\t        Enter Your Email Address: ";
		cin >> email;
		
		cout << "\n\t\t\t\t\t        (Maximum of 5 Occupants per Room)";
		cout << "\n\t\t\t\t\t        Enter the Number of Tenants:";
		cin >> numoftenants;

		fout.write((char*)this, sizeof(hotel));
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t*********************************************************" << endl;
		cout << "\n\t\t\t\t**THANK YOU FOR CHOOSING JPENC HOTEL AND VACATION HOUSE**!";
		cout << "\n\t\t\t\t  **YOUR BOOKING DETAILS HAS BEEN SUCCESSFULLY ADDED**";
		cout << "\n\t\t\t\t**********************************************************";
	}

	cout << "\n Press any key to continue!!";

	getch();
	fout.close();

}







void hotel::display()
{

	system("cls");

	ifstream fin("Record.dat", ios::in);
	int r, flag;

	cout << "\n\n\n\t\t\t\tEnter the room number to see the customer's details: " << endl;
	cin >> r;

	while (!fin.eof())
	{

		fin.read((char*)this, sizeof(hotel));
		if (room_no == r)
		
		{

			system("cls");
			cout << "\n\n\n\n\n\t\t\t\t*****************************************************************";
			cout << "\n\t\t\t\t   **Thank you for choosing JPENC Hotel & Vacation House!**";
			cout << "\n\t\t\t\t         **These are your Personal Information**        ";
			cout << "\n\t\t\t\t**Please double check if the following information are correct**";
			cout << "\n\t\t\t\t*****************************************************************";

			cout << "\n\n\t\t\t\t  Room no: " << room_no;
			cout << "\n\t\t\t\t  First Name: " << fname;
			cout << "\n\t\t\t\t  Middle Initial: " << mname;
			cout << "\n\t\t\t\t  Last Name: " << lname;
			cout << "\n\t\t\t\t  CompleteAddress: " << address;
			cout << "\n\t\t\t\t  Phone no: " << phone;
			cout << "\n\t\t\t\t  Email Address: " << email;
			cout << "\n\t\t\t\t  Number of Tenants: " << numoftenants << endl;
			flag = 1;
			break;

		}

	}

	if (flag == 0)
	cout << "\n\n\n\t\t\t\t **Sorry Room no. not found nor vacant!**";
	cout << "\t\t\t\t\t     Press any key to continue!";

	getch();
	fin.close();
}






void hotel::rooms()
{

	system("cls");

	ifstream fin("Record.dat", ios::in);

	cout << "\n\n\t\t\t\t   **************************************";
	cout << "\n\t\t\t\t           List Of Rooms Allotted";
	cout << "\n\t\t\t\t   **************************************";
	
	while (!fin.eof())
	
	{

		fin.read((char*)this, sizeof(hotel));
		cout << "\n\n\t\t\t\t\tRoom Number:        " << room_no << "\n\t\t\t\t\tFirst Name:         " << fname;
		cout << "\n\t\t\t\t\tMiddle Initial:     " << mname << "\n\t\t\t\t\tLast Name:          " << lname; 
		cout << "\n\t\t\t\t\tAddress:   \t    " << address << "\n\t\t\t\t\tPhone Number:       " << phone << "\n\t\t\t\t\tEmail Address:      " << email;
		cout << "\n\t\t\t\t\tNumber of Tenants:  " << numoftenants;

	}

	cout << "\n\n\n\t\t\t\t\t   Press any key to continue!";
	getch();
	fin.close();

}







void hotel::edit()
{

	system("cls");

	int choice, r;


	cout << "\n\n\n\t\t\t\t\t\t************************" << endl;
	cout << "\t\t\t\t\t\t***                  ***" << endl;
	cout << "\t\t\t\t\t\t**                    **" << endl;
	cout << "\t\t\t\t\t\t*     *EDIT MENU*      *" << endl;
	cout << "\t\t\t\t\t\t**                    **" << endl;
	cout << "\t\t\t\t\t\t***                  ***" << endl;
	cout << "\t\t\t\t\t\t************************" << endl;

	cout << "\n\n\n\t\t\t\t\t    ********************************" << endl;
	cout << "\t\t\t\t\t    *   1.UPDATE CUSTOMER RECORD   *" << endl;
	cout << "\t\t\t\t\t    *   2.DELETE CUSTOMER RECORD   *" << endl;
	cout << "\t\t\t\t\t    ********************************" << endl;
//	cout << "\n\t\t\t\t\t\t   ENTER YOUR CHOICE: " << endl;
//	cin >> choice;

	try
	{
		cout << "\n\t\t\t\t\t\t   ENTER YOUR CHOICE: " << endl;
		cin >> choice;
		
		if (choice > totalchoices2)
		{
			throw choice;
		}
	}
	
	catch (int e)
	{
		cout << "\n\t\t\t\t\t\t\t ERROR!";
		getch();
		exception2();
		iloveubb();
		getch();
		
	}
	
	system("cls");

	cout << "\n\n\n\t\t\t\t Enter the Room Number that you want to Modify: ";
	cin >> r;

	switch (choice)
	{

	case 1:	modify(r);
		break;
		
	case 2:	delete_rec(r);
		break;


	default: cout << "\n Invalid choice!";

	}
	cout << "\n\n\n Press any key to continue!";

	getch();
}


int hotel::check(int r)
{

	int flag = 0;

	ifstream fin("Record.dat", ios::in);

	while (!fin.eof())
	{

		fin.read((char*)this, sizeof(hotel));
		if (room_no == r)
		{

			flag = 1;
			break;

		}

	}

	fin.close();
	return(flag);

}






void hotel::modify(int r)
{

	long pos, flag = 0;
	
	fstream file("Record.dat", ios::in | ios::out | ios::binary);
	
	while (!file.eof())
	{

		pos = file.tellg();
		file.read((char*)this, sizeof(hotel));

		if (room_no == r)
		{

			cout << "\n\t\t\t\t\t\t********************";
			cout << "\n\t\t\t\t\t\t UPDATE INFORMATION ";
			cout << "\n\t\t\t\t\t\t********************";


			cout << "\n\t\t\t\t\t        Enter First Name: ";
			cin >> fname;
			
			cout << "\t\t\t\t\t        Enter Middle Initial: ";
			cin >> mname;
			
			cout << "\t\t\t\t\t        Enter Last Name: ";
			cin >> lname;
			
			cout << " \t\t\t\t\t        Enter Complete Address: ";
			cin >> address; 
			
			cout << " \t\t\t\t\t        Enter Phone Number: ";
			cin >> phone;
			
			cout << " \t\t\t\t\t        Enter Email Address: ";
			cin >> email;
			
			cout << " \t\t\t\t\t        Enter Number of Tenants: ";
			cin >> numoftenants;
			
			file.seekg(pos);
			file.write((char*)this, sizeof(hotel));
			cout << "\n Information Updated!";
			flag = 1;
			break;

		}

	}

	if (flag == 0)
		cout << "\n\t\t\t\t      Sorry Room Number not Found nor Vacant!";
	file.close();

}







void hotel::delete_rec(int r)
{

	int flag = 0;
	char ch;
	ifstream fin("Record.dat", ios::in);
	ofstream fout("temp.dat", ios::out);

	while (!fin.eof())
	{

		fin.read((char*)this, sizeof(hotel));
		if (room_no == r)

		{
			
			cout << "\n\t\t\t\t\t        ********************";
			cout << "\n\t\t\t\t\t         DELETE INFORMATION ";
			cout << "\n\t\t\t\t\t        ********************";
			cout << "\n\t\t\t\t\t         First Name: " << fname;
			cout << "\n\t\t\t\t\t         Middle Initial: " << mname;
			cout << "\n\t\t\t\t\t         Last Name: " << lname;
			cout << "\n\t\t\t\t\t         Address: " << address;
			cout << "\n\t\t\t\t\t         Phone no: " << phone;
			cout << "\n\t\t\t\t\t         Email Address: " << email;
			cout << "\n\t\t\t\t\t         Number of Tenants: " << numoftenants;
			cout << "\n\n\t\t\t\t Are you sure you want to DELETE this record? (y/n): ";
			cin >> ch;

			if (ch == 'n')
				fout.write((char*)this, sizeof(hotel));
			flag = 1;

		}

		else
			fout.write((char*)this, sizeof(hotel));

	}

	fin.close();
	fout.close();

	if (flag == 0)
		cout << "\n Sorry Room Number not found nor Vacant!";

	else
	{

		remove("Record.dat");
		rename("temp.dat", "Record.dat");

	}

}







void hotel::exception1()
{
	
	int x=0;
	string bbq = "\n\n\t\t\t\t\tERROR 404!!! Maximum Number of Rooms is only 50!";
	
	while ( bbq [x] != '\0')
	{
		
		cout << bbq [x];
		if ( bbq[x]!= ' ' && bbq[x]!= '\n')
		Beep(600, 50);
		Sleep (50);
		x++;
		
	}
	
}







void hotel::exception2()
{
	
	int x=0;
	string hotdog = "\n\n\t\t\t\t\t\tWRONG CHOICE! TRY AGAIN";
	while ( hotdog [x] != '\0')
	{
		cout << hotdog [x];
		if ( hotdog[x]!= ' ' && hotdog[x]!= '\n')
		Beep(600, 50);
		Sleep (100);
		x++;
	}
	
}






void hotel::iloveubb()
{
	
	cout << "ERROR!";
	iloveubb();
	
}






void hotel::prompt()
{
		
		AllocConsole();
        	if (MessageBox(FindWindowA("ConsoleWindowClass", NULL), "Do you want to exit?  ", "Thank you for choosing JPENC hotel and Vacation house"
			, MB_CANCELTRYCONTINUE | MB_ICONHAND | MB_DEFBUTTON2 | MB_SYSTEMMODAL) == IDCANCEL);
        	 
}






void hotel::tiangge()
{
	
	vector <int> a;
	int y;
	int z;
	char b;
	string breh = "\n\t\t\t\t\t\t    **JPENC FOOD AND BEVERAGES**";
	string bruh = "\n\t\t\t\t\t\t           **APPETIZERS**       ";
	string brah = "\n\t\t\t\t\t\t           **MAIN ENTREES**     ";
	string brarah ="\n\t\t\t\t\t\t\t     **DESSERTS**";      
	int x=0;
	int q=0;
	int c=0;
	int w=0;
	

		system ("cls");

		cout << "\n\n\n\t\t\t\t\t\t    ****************************";
		
		while ( breh [x] != '\0')
	{
		cout << breh [x];
		if ( breh[x]!= ' ' && breh[x]!= '\n')
		Beep(600, 50);
		Sleep (30);
		x++;
	}
	
		//cout << "\n\t\t\t\t\t\t    **JPENC FOOD AND BEVERAGES**";
		cout << "\n\t\t\t\t\t\t    ****************************";
		
		getch();
		
		cout << "\n\n\n\t\t\t\t\t\t           **************       ";
		
		while ( bruh [q] != '\0')
	{
		cout << bruh [q];
		if ( bruh[q]!= ' ' && bruh[q]!= '\n')
		Sleep (25);
		q++;
	}
	
		//cout << "\n\t\t\t\t\t\t           **APPETIZERS**       ";
		cout << "\n\t\t\t\t\t\t           **************       ";

		cout << "\n\n\n\t\t\t\t\t       RUTABAGA AND TOASTED HAZELNUT SOUP - $12";
		cout << "\n\t\t\t\t\tSoy roasted hazelnu, horseradish cream, Challerhocker";

		cout << "\n\n\t\t\t\t\t      MARINATED LOCAL OYSTER MUSHROOM SALAD - $16";
		cout << "\n\t\t\t\t      pig ear terrine, pickled plum jelly, jerusalem artichoke,";
		cout << "\n\t\t\t\t       Bosc pear with mint, petit greens, red wine mousseline";
		cout << "\n\t\t\t\t                        **Half Portion - $9**       ";

		cout << "\n\n\t\t\t\t\t\t       DAY BOAT SCALLOPS - $14";
		cout << "\n\t\t\t\t\t\tfennel, prosciutto, black bean sauce";
		
		getch();
		
		cout << "\n\n\n\t\t\t\t\t\t           ****************";
		
		while ( brah [c] != '\0')
	{
		cout << brah [c];
		if ( brah[c]!= ' ' && brah[c]!= '\n')
		Sleep (25);
		c++;
	}
	
		//cout << "\n\t\t\t\t\t\t           **MAIN ENTREES**       ";
		cout << "\n\t\t\t\t\t\t           ****************";    

		cout << "\n\n\n\t\t\t\t\t\t   GRILLED FAROE ISLAND SALMON - $26";
		cout << "\n\t\t\t\t   quinoa, osyter mushrooms, brussels sprout leaves, beet mustard";

		cout << "\n\n\t\t\t\t\t\t     PAN ROASTED DUCK BREAST - $29";
		cout << "\n\t\t\t\t\t  herbed farro, orange-frisee salad, honey gastrique";

		cout << "\n\n\t\t\t\t\t\t CRISPY DUCK IN PORT CHERRY SAUCE - $36";
		cout << "\n\t\t\t\t     roasted turnips, parsnips, rutabaga and carrots with cornmeal,";
		cout << "\n\t\t\t\t\t\tjohnny cake wrapped duck confit, bok choy";

		cout << "\n\n\t\t\t\t\t\t    TENDERLOIN OF BEEF WELLINGTON - $48";
		cout << "\n\t\t\t\t\t\t      foie gras, spinach, duxelle";
		cout << "\n\t\t\t\t\t\t     **Add Red Wine for $2 extra**";
		
		getch();
			
		cout << "\n\n\n\t\t\t\t\t\t\t     ************";
		
		while ( brarah [w] != '\0')
	{
		cout << brarah [w];
		if ( brarah[w]!= ' ' && brarah[w]!= '\n')
		Sleep (25);
		w++;
	}
	
		//cout << "\n\t\t\t\t\t\t\t     **DESSERTS**";
		cout << "\n\t\t\t\t\t\t\t     ************";

		cout << "\n\n\n\t\t\t\t\t\t\t TRES LECHES CAKE - $9";
		cout << "\n\t\t\t\t\t\tstrawberry compote, strawberry balsamic";

		cout << "\n\n\t\t\t\t\t\t\t KEY LIME PUDDING - $8";
		cout << "\n\t\t\t\t\t\t    Chantilly cream & wafer cookies";

		cout << "\n\n\t\t\t\t\t\t\t  BlACK ICE CREAM - $9";
		cout << "\n\t\t\t\t\t\t\t    Black Raspberry";
	
		getch();

    	cout<<"\n\n\n\t\t\t\t\t         Enter the Prices of your chosen meal:";
    	cout<<"\n\t\t\t\t\t           (Maximum of 5 orders per person) " <<endl;

    
    for(int i=0; i<5; i++)
    {
      cin>>y;
      a.push_back(y);
      
    } 
    
    
	while (!a.empty())
 	 {
    	z += a.back();
    	a.pop_back();
 	 }
 	 cout <<"\n\t\t\t\t\t\t       Your Partial Bill is: $"<< z-5 <<"\n\n" <<endl;
 	 
 	 getch();
 	 
}






int main()
{
	
	hotel h;


	system("Color 0E");
	cout << "\n\n\t ***********************************************************************************************" << endl;
	cout << "\t ***********************************************************************************************" << endl;
	cout << "\t ***************************************   WELCOME TO   ****************************************" << endl;
	cout << "\t ***********************************************************************************************" << endl;
	cout << "\t ***********************************************************************************************" << endl;
	cout << "\t *********            *          ***              *        *********   **                *******" << endl;
	cout << "\t *********            *   *****  ***   ************    *   *********   *      ******************" << endl;
	cout << "\t *************    *****   *****  ***   ************    **   ********   *     *******************" << endl;
	cout << "\t *************    *****   *****  ***   ************    ***   *******   *    ********************" << endl;
	cout << "\t *************    *****          ***              *    ****   ******   *    ********************" << endl;
	cout << "\t *************    *****   **********   ************    *****   *****   *    ********************" << endl;
	cout << "\t *************    *****   **********   ************    ******   ****   *    ********************" << endl;
	cout << "\t *******    **    *****   **********   ************    *******   ***   *     *******************" << endl;
	cout << "\t *******    **    *****   **********   ************    ********   **   *      ******************" << endl;
	cout << "\t *******          *****   **********              *    *********   *   **                *******" << endl;
	cout << "\t ***********************************************************************************************" << endl;
	cout << "\t ***********************************************************************************************" << endl;
	cout << "\t ********************************  HOTEL AND VACATION HOUSE ************************************" << endl;
	cout << "\t ***********************************************************************************************" << endl;
	cout << "\t ***********************************************************************************************" << endl;

	getch();

	h.main_menu();
	return 0;
	
}




