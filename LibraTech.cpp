#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

struct TypeBook{
	string name, author, pub, serial; // pub = Publisher
};

struct TypePatron{
	string uname, ID;
};

class Art{
	private:
		char libArt[500] = 
        "\t\t\t      __...--~~~~~-._   _.-~~~~~--...__\n"
        "\t\t\t    //               `V'               \\\\ \n"
        "\t\t\t   //                 |                 \\\\ \n"
        "\t\t\t  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\\\ \n"
        "\t\t\t //__.....----~~~~._\\ | /_.~~~~----.....__\\\\\n"
        "\t\t\t====================\\\\|//====================\n"
        "\t\t\t                    `---`\n";
	public:
		void logoArt(){
			cout << "\n\t\t============================================================\n\n";
			cout << libArt;
			cout <<	"\t\t\t     _    _ _            _____       _    \n"
				    "\t\t\t    | |  (_) |__ _ _ __ |_   _|__ __| |_  \n"
				    "\t\t\t    | |__| | '_ \\ '_/ _` || |/ -_) _| ' \\ \n"
				    "\t\t\t    |____|_|_.__/_| \\__,_||_|\\___\\__|_||_|\n\n"
		    		"\t\t============================================================\n\n";
		}
		
		void loginArt(){
			cout << "\n\t\t============================================================\n\n";
			cout << libArt;
			cout << "\t\t\t\t    _              _      \n"
		            "\t\t\t\t   | |   ___  __ _(_)_ _  \n"
		            "\t\t\t\t   | |__/ _ \\/ _` | | ' \\ \n"
		            "\t\t\t\t   |____\\___/\\__, |_|_||_|\n"
		            "\t\t\t\t             |___/        \n\n";    
			cout <<	"\t\t============================================================\n\n";
		} 
		
		void menuArt(){
			cout << "\n\t\t============================================================\n\n";
			cout << libArt;
			cout << "\t\t\t  __  __       _        __  __              \n"
					"\t\t\t |  \\/  | __ _(_)_ _   |  \\/  | ___ _ _ _  _ \n"
					"\t\t\t | |\\/| |/ _` | | ' \\  | |\\/| |/ -_) ' \\ || |\n"
					"\t\t\t |_|  |_|\\__,_|_|_||_| |_|  |_|\\___|_||_\\_,_|\n\n";
			cout <<	"\t\t============================================================\n\n";
		}
		
		void bookArt(){
			cout << "\n\t\t============================================================\n\n";
			cout << libArt;
			cout << "\t\t\t  ___           _     __  __              \n"
					"\t\t\t | _ ) ___  ___| |__ |  \\/  | ___ _ _ _  _ \n"
					"\t\t\t | _ \\/ _ \\/ _ \\ / / | |\\/| |/ -_) ' \\ || |\n"
					"\t\t\t |___/\\___/\\___/_\\_\\ |_|  |_|\\___|_||_\\_,_|\n\n";
			cout <<	"\t\t============================================================\n\n";
		}
		
		void patronArt(){
			cout << "\n\t\t============================================================\n\n";
			cout << libArt;
			cout << "\t\t       ___      _                  __  __              \n"
	                "\t\t      | _ \\__ _| |_ _ _ ___ _ _   |  \\/  | ___ _ _ _  _ \n"
	                "\t\t      |  _/ _` |  _| '_/ _ \\ ' \\  | |\\/| |/ -_) ' \\ || |\n"
	                "\t\t      |_| \\__,_|\\__|_| \\___/_||_| |_|  |_|\\___|_||_\\_,_|\n\n";
            cout <<	"\t\t============================================================\n\n";
		}
};

class Book : public Art{
	private:
		TypeBook in, out, bor, ret;
		TypePatron p;
		string tempName = "temp.txt", line, temp, searchTerm = "";
		bool found = false;
		char cont;
		
	public:	
		void addBook(){
			ofstream in_b("books.txt", ios::app); // in_b is the name "Input Book". Append mode is used to keep/add to the data.
			if(!in_b){
				cout<<"\n\t\t Error Opening File.";
			}
			
			do{
				system("cls");
				bookArt();
				
				cout<<"\t\t Enter the Book Name: ";
				getline(cin, in.name);
				
				in_b << "Book Name: " << in.name << "\n";
						
				cout<<"\n\t\t Enter the Author Name: ";
				getline(cin, in.author);
				
				in_b << "Author: " << in.author << "\n";
				
				cout<<"\n\t\t Enter the Publisher Name: ";
				getline(cin, in.pub);
				
				in_b << "Publisher: " << in.pub << "\n";
				
				cout<<"\n\t\t Enter the Serial Number: ";
				cin >> in.serial;
				
				in_b << "Serial: " << in.serial << "\n";	
				
				cout<<"\n\t\t Press Escape to Exit";
	            cout<<"\n\t\t OR Press Enter to Keep Adding Books.";
	            cont = getch();
				Sleep(1000);	
			} while(cont != 27);
			
			in_b.close();
		}
		
		void searchBook(){
			system("cls");
			bookArt();
		
		    cout << "\t\t Enter the Search Term: ";
			cin.ignore();
		    getline(cin, searchTerm);
		
		    ifstream out_b("books.txt");
		    if (!out_b) {
		        cout << "\n\t\t\t Error Opening File." << endl;
		    }
			
		    while (getline(out_b, line)){
    			if(line.find("Book Name: ") != string::npos){
    				out.name = line;
				}
				else if(line.find("Author: " ) != string::npos){
        			out.author = line;
				}
				else if(line.find("Publisher: ") != string::npos){
        			out.pub = line;
				}
				else if(line.find("Serial: ") != string::npos){
        			out.serial = line;
        			if (out.name.find(searchTerm) != string::npos ||  out.author.find(searchTerm) != string::npos ||  out.pub.find(searchTerm) != string::npos || out.serial.find(searchTerm) != string::npos) {
			            cout << "\n\n\t\t Book Found:";
			            cout << "\n\n\t\t     " << out.name << endl;
			            cout << "\n\t\t     " << out.author << endl;
			            cout << "\n\t\t     " << out.pub << endl;
			            cout << "\n\t\t     " << out.serial << endl << endl;
			            
			            found = true;
					}
				}
		    }
		    
		    out_b.close();

		    if(!found)
		        cout << "\n\n\t\t Book Not Found." << endl;
		        
		    getch();
		}
		
		void borrowBook(){
		    system("cls");
		    bookArt();
		    TypeBook b;
		   
		
			cout << "\t\t Enter the Borrower's Details.\n\n";
		    cout << "\t\t Enter the Patron's Name: ";
		    getline(cin, p.uname);
		
		    cout << "\t\t Enter the Patron's ID: ";
		    cin >> p.ID;
		    
		    cout << "\n\t\t Enter the Book's Details.\n\n";
		    cout << "\t\t Enter the Search Term: ";
		    getline(cin, searchTerm);
		
			string fileName = "books.txt";
		    ifstream out_b(fileName);
		    ofstream tempFile(tempName), in_bor("borrow.txt", ios::app);
		    
		    if (!out_b && !in_bor) {
		        cout << "\n\t\t\t Error Opening File." << endl;
		    }
			
		    while (getline(out_b, line)) {
		    	if(line.find("Book Name: ") != string::npos){
    				out.name = line;
    				if (out.name.find(searchTerm) != string::npos || out.author.find(searchTerm) != string::npos || out.pub.find(searchTerm) != string::npos || out.serial.find(searchTerm) != string::npos){
    					continue;
					}
				}
				else if(line.find("Author: " ) != string::npos){
        			out.author = line;
        			if (out.name.find(searchTerm) != string::npos || out.author.find(searchTerm) != string::npos || out.pub.find(searchTerm) != string::npos || out.serial.find(searchTerm) != string::npos){
        				continue;
					}
				}
				else if(line.find("Publisher: ") != string::npos){
        			out.pub = line;
        			if (out.name.find(searchTerm) != string::npos || out.author.find(searchTerm) != string::npos || out.pub.find(searchTerm) != string::npos || out.serial.find(searchTerm) != string::npos){
        				continue;
					}
				}
				else if(line.find("Serial: ") != string::npos){
        			out.serial = line;
					if (out.name.find(searchTerm) != string::npos || out.author.find(searchTerm) != string::npos || out.pub.find(searchTerm) != string::npos || out.serial.find(searchTerm) != string::npos) {
			            temp = out.name + "\n" + out.author + "\n" + out.pub + "\n" + out.serial;
			            in_bor << temp << endl;
			            found = true;
			            continue;
			        }
			    }
				
			    tempFile << line << endl; // Write lines not related to the book being removed
			}
	    	
		    out_b.close();
		    in_bor.close();
			tempFile.close();
			
		    if(found){
		    	remove(fileName.c_str());
				rename(tempName.c_str(), fileName.c_str()); 
		        cout << "\t\t Book has been Borrowed by " << p.uname << endl;
				
		    } 
			else{
		        remove("temp.txt");  
		        cout << "\t\t Book not Found (It could've been already borrowed)." << endl;
		    }
		    
		    getch();
		}

		void returnBook(){
			jump:
			system("cls");
			bookArt();
			
			cout << "\t\t Enter the Search Term: ";
			getline(cin, searchTerm);
			
			string fileName = "borrow.txt";
			ifstream bor_b(fileName);
			ofstream in_b("books.txt", ios::app), tempFile(tempName);
			
			if (!in_b && !bor_b) {
		        cout << "\n\t\t\t Error Opening File." << endl;
		    }
			
			while(getline(bor_b, line)){
				if(line.find("Book Name: ") != string::npos){
    				out.name = line;
    				continue;
				}
				else if(line.find("Author: " ) != string::npos){
        			out.author = line;
        			continue;
				}
				else if(line.find("Publisher: ") != string::npos){
        			out.pub = line;
        			continue;
				}
				else if(line.find("Serial: ") != string::npos){
        			out.serial = line;
        			if(out.name.find(searchTerm) != string::npos || out.author.find(searchTerm) != string::npos || out.pub.find(searchTerm) != string::npos || out.serial.find(searchTerm) != string::npos){
        				cout << "\n\n\t\t Book Found:";
			            cout << "\n\n\t\t     " << out.name << endl;
			            cout << "\n\t\t     " << out.author << endl;
			            cout << "\n\t\t     " << out.pub << endl;
			            cout << "\n\t\t     " << out.serial << endl;
        				cout << "\n\t\t The Following Book will be Returned.";
        				getch();
        				
						temp = out.name + "\n" + out.author + "\n" + out.pub + "\n" + out.serial;
			            in_b << temp << endl;
			            found = true;
			            continue;
					}
        		}
        		
        		tempFile << line << endl;	
			}
			
			bor_b.close();
			in_b.close();
			tempFile.close();
			
			if(found){
		    	remove(fileName.c_str());
				rename(tempName.c_str(), fileName.c_str()); 
		        cout << "\n\t\t Book has been Returned." << endl;
				
		    } 
			else{
		        remove("temp.txt");  
		        cout << "\t\t Book not Found." << endl;
		    }
		    
		    getch();
		}
};

class Patron : public Art{
	private:
		TypePatron p;
		char cont;
		string line;
	public:
		void addPatron(){
			
			ofstream in_p("patron.txt", ios::app);
			ifstream out_p("patron.txt");
			if (!in_p && !out_p) {
		        cout << "\n\t\t\t Error Opening File." << endl;
		    }
			
			do{
				bool proceedFlag = true;
				out_p.seekg(0);

				system("cls");
				patronArt();

				cout << "\t\t Enter the Patron's Username: ";
				cin.ignore();
				getline(cin, p.uname);
				
				cout << "\t\t Enter the Patron's ID: ";
				cin >> p.ID;
				
				while (getline(out_p, line)){
					if("Name: " + p.uname == line || "ID: " + p.ID == line){
						proceedFlag = false;
						break;
					} else {
						proceedFlag = true;
					}
				}

				if(proceedFlag){
					in_p << "Name: " << p.uname << "\n";
					in_p << "ID: " << p.ID << "\n";
				} else {
					cout << "\n\t\t Error! Username OR ID already exists.\n";
				}

				cout<<"\n\t\t Press Escape to Exit";
	            cout<<"\n\t\t OR Press Enter to Keep Adding Patrons.";
	            cont = getch();
	            
				Sleep(1000);
			} while(cont != 27);
			
			in_p.close();
		}
		
		void listPatron(){ //formerly search patron
			system("cls");
			patronArt();
			
			cout << "\t\t The List of Current Registered Patrons: \n\n";
			
			ifstream out_p("patron.txt");
			if(!out_p){
				cout << "\t\t\t Error Opening File." << endl;
			}
			
			int count = 0;
		    while (getline(out_p, line)){
		    	count++;
		    	cout << "\t\t    " << line << endl;
		    	if(count == 2){
		    		cout << "\n";
		    		count = 0;
				}
			}

			getch();
		}
};

class Function : public Art{
	private:
		string u_name, u_pass; //info from the user
		string s_name, s_pass; //info saved to login
		string a_name = "admin", a_pass = "bypass"; //info for admin to login
		char c4p; //character for pushback
		bool flag = false;
		Book b;
		Patron p;
	public:
		
		
		void front(){
			logoArt();
			cout << "\t\tLibraTech: A \"Library Management System\", a project aimed \n\t\tto create a mock-up version of an actual management system.\n\n\t\t";
			Sleep(2000);
		}
		
		void login(){
			
			jump:
			system("cls");
			loginArt();
			
			cout<<"\t\t\t Username: "; //do not add spaces while entering the username
			cin>>u_name;
			cout<<"\t\t\t Password: "; //do not add spaces while entering the password
			c4p = getch();
			
			while(c4p != 13){
				u_pass.push_back(c4p);
				cout<<"*";
				c4p = getch();
			}
			
			cout<<endl<<endl;
			if((u_name == s_name || u_name == a_name) && (u_pass == s_pass || u_pass == a_pass)){
					cout<<"\t\t\t Access Granted.";
					Sleep(1000);
				}
				else{
					cout<<"\t\t\t Invalid Username or Password.\n\n\t\t\t ";
					system("pause");
					u_pass = "";
					goto jump;
				}
		}
		
		void menu(){
			char choice;

			do{
				system("cls");
				menuArt();
			
				cout << "\t\t\t Welcome to \033[32mLibraTech's\033[0m Main Menu \n\n";
				cout << "\t\t\t 1. Add Book.\n";
				cout << "\t\t\t 2. Search Book.\n";
				cout << "\t\t\t 3. Borrow Book.\n";
				cout << "\t\t\t 4. Return Book.\n";
				cout << "\t\t\t 5. Add Patron.\n";
				cout << "\t\t\t 6. List Patrons.\n";
				cout << "\t\t\t 7. Edit Username OR Password.\n";
				cout << "\t\t\t OR Press Escape to Exit.\n";
				cout << "\n\t\t\t Enter Your Choice: ";
				choice = getch();
				cout << choice;

				if(choice == 27){
					cout<<"You Chose To End The Program. "<<endl;
					break;
				}
				
				else{
					getch();
					switch (choice){
			            case '1':
				            b.addBook();
			                break;
			            case '2':
			                b.searchBook();
			                break;
			            case '3':
			                b.borrowBook();
			                break;
			            case '4':
			                b.returnBook();
			                break;
			            case '5':
			                p.addPatron();
			                break;
			            case '6':
			                p.listPatron();
			                break;
		            	case '7':
		            		//Edit Username or Pass logic
		                	break;
			            default:
			                cout << "\n\n\t\t\t Invalid Choice, Try Again.\n";
			                break;
	        		}
				}
			}while(true);
		}
};

int main(){
	Function x;
	
	x.front();
	x.login();
	x.menu();

    return 0;
};
