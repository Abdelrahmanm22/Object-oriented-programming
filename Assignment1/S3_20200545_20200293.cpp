#include <iostream>
#include <windows.h>
using namespace std;
void SetColor(int ForgC)
{
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

class ColoredBox
{
    private:
        char character;
        int width,length,color;
        static int area;

    public:

        ColoredBox(int l,int w)
        {
            width=w;
            length=l;
            color=15;
            character='#';
            area=length * width;

        }
        ColoredBox(int l,int w,int c,char r)
        {
            width=w;
            length=l;
            color=c;
            character=r;
            int t=length *width;
            if(area<t)
            {
                area=length * width;
            }

        }

        ~ColoredBox()
        {
            delete cb1;
            delete cb2;
        }
        void setCharacter(char r)
        {
            character=r;
        }
        char getCharacter()
        {
            return character;
        }
        void setColor(int c)
        {
            color=c;
        }
        int getColor()
        {
            return color;
        }
        void display()
        {
            for(int x=0;x<length;x++)
            {
                for(int y=0;y<width;y++)
                {
                    SetColor(color);
                    cout<<character;
                }
                cout<<endl;
            }
            SetColor(15);
        }
        void displayTransposed()
        {
            for(int x=0;x<width;x++)
            {
                for(int y=0;y<length;y++)
                {
                    SetColor(color);
                    cout<<character;
                }
                cout<<endl;
            }
            SetColor(15);
        }
        void displayWider()
        {
            for(int x=0;x<length;x++)
            {
                for(int y=0;y<width;y++)
                {
                    SetColor(color);
                    cout<<character<<" ";
                }
                cout<<endl;
            }
            SetColor(15);
        }
        void displayChess(int col2)
        {
            for(int x=1;x<=length;x++)
            {
                for(int y=1;y<=width;y++)
                {
                    if ((x+y)%2==0)
                    {
                        SetColor(color);
                        cout<<character;
                    }
                    else
                    {
                        SetColor(col2);
                        cout<<character;
                    }
                }
                cout<<endl;
            }
            SetColor(15);
        }
        int getArea()
        {
            return length * width;
        }
        static int getMaxArea()
        {
            return area;
        }

};
int ColoredBox::area=0;
int main()
{
    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len>>wid;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);
    cb1->display();
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    cout<<"Displaying Transposed: "<<endl;
    cb1->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb1->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area="<<cb1->getArea();
    cout<<endl<<"Max Area="<<cb1->getMaxArea();
    delete cb1;

    cout<<endl<<"Enter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColoredBox* cb2;
    cb2 = new ColoredBox(len,wid,col,boxChar);
    cb2->display();
    cout<<"Displaying Transposed: "<<endl;
    cb2->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb2->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb2->displayChess(col2);
    cout<<"Displaying original again:"<<endl;
    cb2->display();
    cout<<endl<<"Area="<<cb2->getArea();
    cout<<endl<<"Max Area="<<cb2->getMaxArea();
    delete cb2;
    return 0;
}
