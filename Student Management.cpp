#include<iostream>
#include<windows.h>
#include <unistd.h>
using namespace std;

struct Data{
	int id ;
	string firstName, lastName;
	float gpa;
};
typedef struct Node
	{
		Data data;
		Node *next, *prev;
	} node;
class LinkList{
	private:
		node* head;
		node* tail;// global
	public:
		LinkList()
		{
    		head = NULL;
    		tail = NULL;
		}
		node* create(int i, float g, string name1, string name2)
		{
	    	node* p = new Node();
	    	if(!p)
			{ 
        		cout<< "cannot create new node "<<endl;
				return 0;
			}
			else 
			{
				p->data.id = i;
				p->data.gpa = g;
				p->data.firstName = name1;
				p->data.lastName = name2;
				p->next = p->prev = NULL;
			}
			return p;
		}
		void destroy(void)
		{
	    	head = NULL;
	    	tail = NULL;
	    	cout<<"your list is deleted !"<<endl;
		}
		void print_list()
		{
	    	node* temp;
	    	temp = head;
	    	if(temp == NULL)
			{
            	cout<< "nothing to print ... the list is empty "<< endl;
            	return;
			}
	    	while(temp)
        	{
            	printInfo(temp);
            	temp = temp->next;
        	}
		}
		void printInfo(node* n)
		{
	   		if(n==NULL)
       		{
           		cout<<"sorry your list is empty ";
           		return ;
       		}
       		else
       		{
       			cout<< "full name: "<< n->data.firstName<< " "<< n->data.lastName<< endl;
				cout<< "ID: "<< n->data.id<< endl;
				cout<< "GPA: "<< n->data.gpa<< endl<< endl;
	    	}
		}
		int insertOreder(int i, float g, string name1, string name2)
		{
	    	node* temp;
	    	temp = head;
	    	
	    	if(temp == NULL)
        	{
            	node*n = create(i, g, name1, name2);
//         		n->prev = head;
          		head = n;
          		tail = n;
          		return 1;
        	}
        	else
        	{
        		node* n = create(i, g, name1, name2);
        		n->prev = tail;
        		tail->next = n;
        		tail = n;
        		
//        		while(temp == NULL)
//            	if(temp->next == NULL && temp->data.id < i)
//            	{
//                	node* n = create(i, g, name1, name2);
//                	n->prev = temp;
//                	temp->next = n;
//                	return 1;
//            	}
//            	else if(temp->next)
//            	if(temp->next == NULL && temp->data.id > i)
//            	{
//                	if(i == temp->data.id)
//                	{
//                    	cout<< "this student had available in the list make sure and enter again"<< endl;
//
//                	}
//                	node* n = create(i, g, name1, name2);
//                	n->next = temp;
//                	n->prev = head;
//                	temp->prev = n;
//                	head = n;
//                	return 1;
//            	}
//            	while(temp->data.id < i && temp->next != NULL)
//            	{
//					temp = temp->next;
//				}
//            	if(temp->data.id > i)
//            	{
//                	node* n = create(i, g, name1, name2);
//               		n->next = temp;
//                	n->prev = temp->prev;
//                	temp->prev->next = n;
//					return 1;
//
//            	}
//           		else if(i == temp->data.id)
//                {
//                    cout<< "this student available in the list make sure and enter again"<< endl;
//                }
//                else
//				{
//                	node* n = create(i, g, name1, name2);
//                 	n->prev = temp;
//                	temp->next = n;
//        			return 1;
//				}
    		}
        }
		int delete_by_id(int i)
		{
	    	node* temp = new node;
	    	temp = head;
	    	while(temp)
        	{
            	if(temp->data.id == i)
            	{
            		if(temp->prev == NULL)
            		{
            			temp->next->prev = NULL;
            			head = temp->next;
            			delete temp;
            			return 1;
            		}
            		else if(temp->next == NULL)
            		{
            			temp->prev->next = NULL;
            			delete temp;
            			return 1;
					}
					else
					{
						temp->prev->next = temp->next;
                		temp->next->prev = temp->prev;
                		temp->next = NULL;
                		temp->prev = NULL;
            			delete temp;
						return 1;
					}
            	}
            	else
            	{
                	temp = temp->next;
                }
        	}
       	}
		int search_by_id(int i)
		{
	    	node* temp;
	    	temp = head;
	    	while(temp)
        	{
            	if(temp->data.id == i)
            	{
                	cout<<" founded ^_^ ,  and his information is "<<endl;
                	printInfo(temp);
                	return 1;
            	}
            	else
            	{
                	temp = temp->next;

                }

        	}
        	return 0;
		}
		int sum()
		{
		    int c = 0;
	    	node* temp;
	    	temp = head;
	    	while(temp)
        	{
            	c++;
            	temp = temp->next;
        	}
        	return c;
		}

};
void menu()
{
	system("color 0A");
    LinkList l;
    int i;
    float g;
    string name1, name2;
    int choice, inchoice;
    while(1)
    {
    	system("CLS");
    	cout<< "-->Welcome my professor to the class program" <<endl;
    	cout<< "-->My program make you easily know everything about your students" <<endl;
        cout<<"\n\n";
		cout<< "    ----------------------Main Menu----------------------"<<endl;
		cout<< "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
		cout<< "\t|\t\t\t\t\t\t|"<<endl;
		cout<< "\t|    press 1 to add student in the list     \t|"<< endl;
		cout<< "\t|    press 2 to remove student from the list\t|"<< endl;
		cout<< "\t|    press 3 to search for student          \t|"<< endl;
		cout<< "\t|    press 4 to print all students          \t|"<< endl;
		cout<< "\t|    press 5 to get the number of students  \t|"<< endl;
		cout<< "\t|    press 6 to delete this list            \t|"<< endl;
		cout<< "\t|    press 7 to exit the program           \t|"<< endl;
		cout<< "\t| \t\t\t\t\t\t|"<< endl;
    	cout<< "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl<<endl;
    	cout<< "Enter your choice: ";
        cin>> choice;
        switch(choice)
        {
        case 1:
        	system("CLS");
            cout<< "First name: ";
            cin>> name1;
			cout<< "Last name: "; 
			cin>> name2;
			cout<< "ID: ";
			cin>>i;
			cout<< "GPA: "; 
			cin>> g;
          	l.insertOreder(i, g, name1, name2);
          	cout<< "press 0 to return main menu: ";
          	cin>> inchoice;
          	system("CLS");
            break;
        case 2:
        	system("CLS");
            cout<< "enter the id of student you want to delete ";
            cin>> i;
            l.delete_by_id(i);
            cout<< "press 0 to return main menu: ";
          	cin>> inchoice;
            break;
        case 3:
        	system("CLS");
            cout<< "enter the ID of student you need ";
            cin>> i;
            l.search_by_id(i);
            cout<< "press 0 to return main menu: ";
          	cin>> inchoice;
            break;
        case 4:
        	system("CLS");
            l.print_list();
            cout<< "press 0 to return main menu: ";
          	cin>> inchoice;
            break;
        case 5:
        	system("CLS");
            cout<< "the number of students is "<< l.sum()<< endl;
            cout<< "press 0 to return main menu: ";
            cin>> inchoice;
            break;
        case 6:
        	system("CLS");
        	cout<< "the list is deleting....";
            l.destroy();
            sleep(3);
            break;
       	case 7:
            break;
       	default:
       		system("CLS");
        	cout<< "this is wrong answer , try again!  "<<endl;
		}
	}
}


int main(){
	menu();
}
