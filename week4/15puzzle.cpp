
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Radio_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Light_Button.H> // needed to use the Fl_Box class
#include<iostream>
using namespace std;


char * intTostring(int v)
{
char *s = new char[sizeof(int)];
sprintf(s,"%d",v);
return s;
}

class MyButton : public Fl_Button {
	public:
		MyButton (int x, int y, int w, int h, const char *l); 
		int handle(int e); // e is incoming mouse event of different kinds
    bool buttonused = false;
    int index_x;
    int index_y;
 };

MyButton :: MyButton (int x,int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {
    index_x = x/100;
    index_y = y/100;
}

int MyButton :: handle (int e) {
	if (e==FL_PUSH)  { 
        label(" ");
        buttonused = true;
	}
	
	return 1;
}


int main(int argc, char *argv[]) {
    	Fl_Window *window;

window = new Fl_Window (900,900,"DEMO"); // outer window

MyButton *Buttons[16];
       
 int a=1;

 for(int i=0;i<15;i++)
 {
   Buttons[i] = new MyButton(200+(100*(i%4)),200+(100*(i/4)),100,100,intTostring(a));
   a++;
 }

 Buttons[15] = new MyButton(500,500,100,100," ");
     
window->color(FL_WHITE);
Buttons[15] ->color(FL_RED);
window->end();
window->show();

for(;;)
{
   for(int i=0;i<15;i++)
    {
      if(Buttons[i]->buttonused)
       {
         int x_check = abs((Buttons[15]->index_x)-(Buttons[i]->index_x));
         int y_check = abs((Buttons[15]->index_y)-(Buttons[i]->index_y));
         int total_check = x_check + y_check;
         if(total_check ==1)
           {
             MyButton * tempbutton;
             tempbutton = Buttons[i];
             Buttons[i] = Buttons[15];
             Buttons[15]= tempbutton;
           }
         
       }
       break;
    }

}
	

return(Fl::run());  // the process waits from here on for events
}


