#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>

using namespace std;

//Main class
class QM
{
public:

int VARIABLES;

QM(int a)
{
   VARIABLES=a;
   

}

//function to get the boolean term letters
vector<string> getVars()
{
   vector<string> v;
   string letters[32];
   //string letters[]={"a1","a2","a3","a4","a5","a6","a7","a8","i","j","k","l","m","n","o",""};
   for(int i=0;i<32;++i)
   {
      letters[i]="a";
      letters[i].append(to_string(i));
   }


   for(int i=0;i<this->VARIABLES;i++)
    v.push_back(letters[i]);

   return v;
}

/*function to convert decimal to binary
* Eg: 14 = 1110
*/
string decToBin(int n)
{
   if ( n == 0 )
       return n+"";

   if ( n % 2 == 0 )
       return decToBin(n / 2) + "0";
   else
       return decToBin(n / 2) + "1";
}

//function to pad zeros to the binary equivalent of digits.
//Eg: If there are 4 variables, 2, that is 10 in binary is represented as 0010
string pad(string bin)
{
   int max=VARIABLES-bin.length();
   for(int i=0; i<max; i++)
       bin="0"+bin;
   return bin;
}

//function to check if two terms differ by just one bit
bool isGreyCode(string a,string b)
{
   int flag=0;
   for(int i=0;i<a.length();i++)
   {
       if(a[i]!=b[i])
        flag++;
   }
   return (flag==1);
}


string comp(string a,string b)
{
   string temp="";
   for(int i=0;i<a.length();i++)
   if(a[i]!=b[i])
       temp=temp+"-";
   else
       temp=temp+a[i];

   return temp;
}

//function to check if string b exists in vector a
bool is_inside(vector<string> a,string b)
{
   for(int i=0;i<a.size();i++)
     if(a[i].compare(b)==0)
      return true;
    return false;
}

//function to reduce minterms
vector<string> reduce(vector<string> minterms)
{
/*for (int i=0; i<minterms.size(); i++)
       cout << minterms[i]<<endl;
       cout <<endl;*/

      vector<string> newminterms;

      int max=minterms.size();
      int* checked = new int[max];
      for(int i=0;i<max;i++)
      {
          for(int j=i;j<max;j++)
          {
               //If a grey code pair is found, replace the differing bits with don't cares.
               if(isGreyCode(minterms[i],minterms[j]))
               {
                  checked[i]=1;
                  checked[j]=1;
                  if(!is_inside(newminterms,comp(minterms[i],minterms[j])))
                     newminterms.push_back(comp(minterms[i],minterms[j]));
               }
          }
      }

      //appending all reduced terms to a new vector
      for(int i=0;i<max;i++)
      {
          //cout<<checked[i]<<endl;
          if(checked[i]!=1 && ! is_inside(newminterms,minterms[i]))
           newminterms.push_back(minterms[i]);
      }

       delete[] checked;
   
       return newminterms;
}


//Converting the boolean minterm into the variables
// Eg: 011- becomes a'bc
string getValue(string a)
{
   string temp="";
   vector<string> vars=this->getVars();
   
   for(int i=0;i<a.length();i++)
   {
     if(a[i]!='-')
     {
        if(a[i]=='0')
         temp=temp+vars[i]+"\'";
        else
         temp=temp+vars[i];
     }
   }
   return temp;
}

//function to check if 2 vectors are equal
bool is_eq(vector<string> a,vector<string> b)
{
   if(a.size()!=b.size())
      return false;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        return false;
    }
    return true;
}

};

//Main function
int main ()
{
   char check='y';
   int flag=1;
   while(check=='y')
   {
      int no;
      cout<<endl<<"Enter the number of variables:"<<endl;
      cin>>no;
      if(no > 31 || no < 1)
      {
          cout << "Invalid number of variables (1-31)" << endl;
          continue;
      }
      QM q(no);

      string temp="";
      cout<<"Enter the minterms(RANGE=0-"<<pow(2,no)-1<<") separated by comma:"<<endl;
      cin>>temp;
      
      
      //splitting the input
      vector<string> minterms;
      istringstream f(temp);
      string s;
      while (getline(f, s, ','))
      {
          //cout << s << endl;
         int t=atoi(s.data());
         if (t>pow(2,no))
         {
			cout<<"Not Valid"<<endl;
			flag=0;
		 }	
         minterms.push_back(q.pad(q.decToBin(t)));
      }

      sort(minterms.begin(),minterms.end());
      if(flag)
      {
		do
		{
			minterms=q.reduce(minterms);
			sort(minterms.begin(),minterms.end());
		}while(!q.is_eq(minterms,q.reduce(minterms)));


		unsigned int i;
		cout << "The reduced boolean expression in SOP form:" << endl;
		for(i=0;i<minterms.size()-1; i++)
          cout<<q.getValue(minterms[i])<<"+";
		cout<<q.getValue(minterms[i])<<endl;
	  }
      cout<<"Would you like to enter another expression? (y/n)"<<endl;
      cin>>check;
   }
   cout<<endl<<"---END--"<<endl;
}
