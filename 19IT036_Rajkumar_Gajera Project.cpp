#include<iostream>
#include<string>
using namespace std;
int n,h;

class placed_student{
    protected:                  // CLASS PLACED_STUDENT
        float package=0;            //THIS CLASS IS THE PARENT CLASS
        int company_id=0;
        string company_name="";
        int company_dis=0;
    //string type;
public:
    void get_placed_data(){
        cout<<"package=";
        cin>>package;
        cout<<"company id=";    //TO update the placed students
        cin>>company_id;
        cout<<"company name=";
        cin>>company_name;
        cout<<"company distance=";
        cin>>company_dis;
    }
};

class student:public placed_student{

    string name;            // CLASS STUDENT IS INHERITING FROM THE CLASS PLACED_STUDENT
    float cpi;              //THE STUDENT CLASS IS THE CHILD CLASS
    string dep;
    int int_exp;
    protected:
        int placed;
    public:
        int id;
    void get_data()
    {
        cout<<"id=";       // take the inputs from the user
        cin>>id;
        cout<<"name=";
        cin>>name;
        cout<<"cpi=";
        cin>>cpi;
        cout<<"dep=";
        cin>>dep;
        cout<<"work experience(in months)=";
        cin>>int_exp;
    }
    void put_data()
    {
        cout<<endl<<"\n\nid="<<id<<"\nname="<<name<<"\ncpi="<<cpi<<"\ndep="<<dep<<"\nwork experience="<<int_exp;    //TO display the data
        if(placed==1)
        {
            cout<<"\npackage"<<package<<"\ncompany id="<<company_id;
        }
    }
    friend void insert_placed(int,student []);       //to update placed student data
    friend student get_name(string,student []);     // to search by name
    friend student get_by_id(int,student []);   // to search by id
    friend void search_data(student []);        //function to search with different options
};


void insert_placed(int a,student b[])
{
    for(int i=0;i<n;i++)
    {
        if(a==b[i].id)
        {
            b[i].placed=1;
            b[i].get_placed_data();
        }
    }
}

student get_by_id(int a,student b[]){
    student c;
    c.id=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(a==b[i].id)
        {
            flag=1;
            c=b[i];
            break;
        }
    }
    if(flag==1)
    return c;
    else
    {
        return c;
    }

}
student get_name(string a,student b[])
{
    student c;
    c.id=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(a==b[i].name)
        {
            flag=1;
            c=b[i];
            break;
        }
    }
    if(flag==1)
    return c;
    else
    {
        return c;
    }
}

void search_data(student s[])
{
    string name;
    int b,j=0;
    int id;
    int x,flag=0;
    student a;
    cout<<"\n\n\nChoose Any Option\n1.Search by name\n2.Search by id\n3.Less than Package\n4.Greater than Package\n5.Equal package\n6.Total Placed Students\n7.Total Not Placed Students\n8.Greater then CPI\n9.Less than CPI\n10.Equally CPI\nEnter Option:";
    cin>>x;
    switch(x)
    {
        case 1: cout<<"\nEnter Name=";
                cin>>name;
                a = get_name(name,s);
                if(a.id!=0)
                {
                    a.put_data();
                }
                else
                {
                    cout<<"Not Found";
                }
                break;

        case 2: cout<<"\nEnter id=";
                cin>>id;
                a = get_by_id(id,s);
                if(a.id!=0)
                {
                    a.put_data();
                }
                else
                {
                    cout<<"Not Found";
                }
                break;
        case 3: cout<<"Enter Maximum Package";
                cin>>b;
                for(int i=0;i<n;i++)
                {
                    if(b>=s[i].package)
                    {
                        flag=1;
                        s[i].put_data();
                    }
                }
                if(flag==0) cout<<"No data available";
                break;
        case 4: cout<<"Enter Minimum Package";
                cin>>b;
                for(int i=0;i<n;i++)
                {
                    if(b<=s[i].package)
                    {
                        flag=1;
                        s[i].put_data();
                    }
                }
                if(flag==0) cout<<"No data available";
                break;
        case 5: cout<<"Enter Package";
                cin>>b;
                for(int i=0;i<n;i++)
                {
                    if(b==s[i].package)
                    {
                        flag=1;
                        s[i].put_data();
                    }
                }
                if(flag==0) cout<<"No data available";
                break;
        case 6:
                for(int i=0;i<n;i++)
                {
                    if(s[i].placed==1)
                    {
                        flag=1;
                        j++;
                    }
                }
                cout<<"\n\nTotal placed students="<<j;
                break;
        case 7:
                for(int i=0;i<n;i++)
                {
                    if(s[i].placed==0)
                    {
                        flag=1;
                        j++;
                    }
                }
                cout<<"\n\nTotal Non-placed students="<<j;
                break;
        case 8: cout<<"Enter Maximum CPI";
                cin>>b;
                for(int i=0;i<n;i++)
                {
                    if(b>=s[i].cpi)
                    {
                        flag=1;
                        s[i].put_data();
                    }
                }
                if(flag==0) cout<<"No data available";
                break;
        case 9: cout<<"Enter Minimum CPI=";
                cin>>b;
                for(int i=0;i<n;i++)
                {
                    if(b<=s[i].cpi)
                    {
                        flag=1;
                        s[i].put_data();
                    }
                }
                if(flag==0) cout<<"No data available";
                break;
        case 10:cout<<"Enter Cpi=";
                cin>>b;
                for(int i=0;i<n;i++)
                {
                    if(b==s[i].cpi)
                    {
                        flag=1;
                        s[i].put_data();
                    }
                }
                if(flag==0) cout<<"No data available";
                break;
    }
}

void star()
{
    cout<<endl<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
}
void intro()
{
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"||||||||    NAME= Gajera Rajkumar                                                                             ||||||||||||||||||"<<endl;
    cout<<"||||||||    Project name= Collage student data                                                                ||||||||||||||||||"<<endl;
    cout<<"||||||||    I.D. NO.=19IT036                                                                                  ||||||||||||||||||"<<endl;
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
}

main()
{
    int id;
    intro();
    cout<<"Enter number Of students"<<endl;
    cin>>n;
    star();
    student s[n];
    for(int i=0;i<n;i++)
    {
        s[i].get_data();
        cout<<"\n";
    }

    int x;
    reswitch:
    star();
    cout<<"\n\n\nChoose any option\n1.Enter placed student Entry\n2.Search Student\n3.Show all student data.\n4.Exit\nEnter Option:";
    cin>>x;
    star();
    switch(x)
    {
        case 1: cout<<"Enter placed student id=";
                cin>>id;
                insert_placed(id,s);
                goto reswitch;
        case 2: cout<<"\t\t\t\tSearch student data:-";
                search_data(s);
                goto reswitch;
        case 3: cout<<"\t\t\t\tSTUDENT ALL DATA:-";
                for(int i=0;i<n;i++)
                {
                    s[i].put_data();
                    cout<<"\n";
                }
                goto reswitch;
        case 4: break;
    }
}
