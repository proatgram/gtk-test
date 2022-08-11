/*
copyright (c) 2022 timothy hutchins

permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "software"), to deal
in the software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the software, and to permit persons to whom the software is
furnished to do so, subject to the following conditions:

the above copyright notice and this permission notice shall be included in all
copies or substantial portions of the software.

the software is provided "as is", without warranty of any kind, express or
implied, including but not limited to the warranties of merchantability,
fitness for a particular purpose and noninfringement. in no event shall the
authors or copyright holders be liable for any claim, damages or other
liability, whether in an action of contract, tort or otherwise, arising from,
out of or in connection with the software or the use or other dealings in the
software.
*/

#include <cstdio>
#include <cstdlib>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>
#include <gtkmm/settings.h>
#include <gtkmm/grid.h>
#include <gdkmm/pixbuf.h>
#include <gtkmm/container.h>
#include <gtkmm/box.h>
#include <gtkmm/overlay.h>

class window : public Gtk::Window {
    public:
        window();
    protected:
        void onButton1();

        Gtk::Button m_button1;
        Gtk::Button m_button2;
        Gtk::Grid m_grid;
        Gtk::Overlay m_background;
    private:
};
