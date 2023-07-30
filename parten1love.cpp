#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Your Number " << endl;
    cin >> n;

    /******************************* PRINTING STARTS IN A SQUARE FORM
       int n ;
       cin >> n;
       int i = 1;

       while ( i <= n ){

           int j = 0;


           while (j < n)
           {
               cout<<" * ";
               j++;
           }

           cout<<endl;
           i++;

       }*/
    /******************************* PRINTING STARTS IN A SQUARE FORM

       int n ;
       cin >> n;
       int i = 1;

       while (i<=n)
       {
           int j = 1;
           while (j<=n)
           {
               cout<<i<<" ";
               j++;
           }
           cout<<endl;
           i++;

       }*/
    /*******************************

       int n ;
       cin>>n;
       int  i = 1;
       while (i <= n)
       {
           int j = 1;
           while ( j <= n )
           {
               cout<<j<<" ";
               j++;
           }
           cout<<endl;
           i++;
       }*/
    /*******************************
    int i = 1;
    int count= 1 ;
       while ( i <= n )
       {
           int j = 1;
           while (j <= n)
           {
               cout<<count<<" ";
               count = count +1;
               j++;
           }
           cout<<endl;
           i++;
       }*/
    /*******************************
       int row = 1;
       while (row <= n)
       {
           int col = 1;
           while ( col <= row )
           {
               cout<<" * ";
               col++;

           }
           cout<<endl;
           row++;

       }*/
    /*******************************
       int row = 1;
       int count = 1;
       while (row <= n)
       {
           int col = 1;
           while ( col <= row )
           {
               cout<<count<<" ";
               col++;
               count++;
           }
           cout<<endl;
           row++;

       }*/
    /*******************************
       int row = 1;

       while (row <= n)

       {
           int col = 1;
           int val = row;
           while ( col <= row )
           {
               cout<<val<<" ";
               val++;
               col++;
           }
           cout<<endl;
           row++;

       }
       int row = 1;

       while (row <= n)

       {
           int col = 1;
           while ( col <= row )
           {
               cout<<(row+col)-1<<" ";
               col++;
           }
           cout<<endl;
           row++;

       }*/
    /*******************************
   int row = 1;

       while (row <= n)

       {
           int col = 1;
           while ( col <= row )
           {
               cout<<row-col+1<<" ";
               col++;
           }
           cout<<endl;
           row++;

       }*/
    /*******************************
       int row = 1;
       while ( row <= n )
       {
           char c = 'A';
           int col = 1;
           while ( col <= n)
           {
               cout<<char(c+row-1)<<" ";
               col++;
           }
           cout<<endl;
           row++;

       }*/
    /*******************************
       int row = 1;

       char c = 'A';
       while ( row <= n )
       {

           int col = 1;
           while ( col <= n)
           {

               cout<<c<<" ";
               c = c+1;
               col++;
           }
           cout<<endl;
           row++;

       }*/
    /*******************************
       int row = 1;


       while ( row <= n )
       {

           int col = 1;
           while ( col <= n)
           {

               cout<<char(row+col-2+'A')<<" ";

               col++;
           }
           cout<<endl;
           row++;

       }*/
    /*******************************
       int row = 1;
       char c = 'A';
       while (row<= n)

       {
           int col = 1 ;
           while (col <= row)
           {

               cout<<c<<" ";
               c++;
               col++;
           }
           cout<<endl;
           row++;
       }*/
    /*******************************
       int row = 1;
       while ( row <= n )
       {
           int col = 1;
           while ( col <= row )
           {
               char c = 'A';
               cout<<char(c+row+col-2)<<" ";
               col++;
           }
           cout<<endl;
           row++;
       }*/
    /*******************************
       int row = 1;

       while ( row <= n )

       {
           char c = 'A'+n-row;
           int col = 1;
           while ( col <= row )
           {

               cout<<c<<" ";
               c = c +1;
               col++;
           }
           cout<<endl;
           row++;
       }*/
    /*******************************
           *
         * *
       * * *
     * * * *

    int row = 1;
    while (row <= n)
    {
        // Space Print Karlo pehele
        int space = n - row;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }
        // Star Print Karlo
        int col = 1;
        while (col <= row)
        {
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }*/
    /*******************************
     * * * *
     * * *
     * *
     *


    int row  = 1 ;
    while (row <= n)
    {

        int col = 1 ;
        int stars = n-row+1 ;
        while ( col <= stars )
        {
            cout<< " *";
            col++;
        }
        cout << endl;
        row++;
    }*/
    /*******************************
     * * * *
      * * *
       * *
        *

    int row = 1 ;
    while ( row <= n )
    {
        // space printing
        int space = row -1 ;
        while ( space )
        {
            cout << " ";
            space--;
        }
        // printing star;
        int col = 1 ;
        int star = n- row +1 ;
        while (star)
        {
            cout << " *";
            star--;
            col++;
        }

        cout << endl;
        row++ ;
    }*/
    /*******************************
           1
         1 2 1
       1 2 3 2 1
     1 2 3 4 3 2 1

    int row = 1 ;
    while (row <= n)
    {
        //Print Karo space
        int space = n-row ;
        while (space)
        {
            cout << " ";
            space= space - 1 ;
        }



        //Print 2nd triangle

        int j = 1;
        while (j <= row )
        {
            cout << j;
            j = j + 1;
        }



        //Print 3rd Triangle

        int start = row - 1;
        while (start)
        {
            cout<< start;
            start--;
        }


        cout << endl;
        row++;

    }*/
    /*******************************
     1 2 3 4 5 5 4 3 2 1
     1 2 3 4 * * 4 3 2 1
     1 2 3 * * * * 3 2 1
     1 2 * * * * * * 2 1
     1 * * * * * * * * 1
     */

    // int row = 1 ;
    // while ( row <= n )
    // {
    //     // printing 1st triangle
    //     int col = 1 ;
    //     int count = n -row+1;
    //     while ( count )
    //     {
    //         cout << col ;
    //         col++;
    //         count--;
    //     }
    //     //Printing 2nd triangle
    //     int j = 2;
    //     while (j <= row )
    //     {
    //         cout << "*";
    //         j = j + 1;
    //     }
    //     // Printing 3rd triangle
    //     int star = row - 1;
    //     while ( star )
    //     {
    //         cout << "*";
    //         star--;
    //     }
    //     // Printing 4th triangle
    //     int num = n-row+1;
    //     while ( num )
    //     {
    //         cout << num;
    //         num--;
    //     }

    //     cout << endl ;
    //     row++;
    // }

    for (int i = 0; i < n; i++)
    {
        // Spcae

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // Star

        for (int k = 0; k < (i + k + 1); k++)
        {
            cout << "*";
        }
        cout << endl;
        // Space

        // for (int j = 0 ; j <  ; j++)
        // {
        //     cout << " " ;
        // }
    }
    return 0;
}