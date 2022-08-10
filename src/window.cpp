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

#include "window.h"

window::window()  :
    m_button1()
{
    set_title("Test Application");
    set_default_size(240, 240);
    m_button1.signal_clicked().connect(sigc::mem_fun(*this, &window::onButton1));
    Gtk::Image *im(Gtk::manage(new Gtk::Image("/home/thetimbrick/Pictures/Cat.jpg")));
    m_button1.set_image(*im);
    add(m_button1);
    set_border_width(10);
    m_button1.show();
}

void window::onButton1() {
    std::printf("Button Pressed\n");
}
