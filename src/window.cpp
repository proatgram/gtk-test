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
    m_button1(),
    m_button2(),
    m_grid(),
    m_background()
{
    set_title("Test Application");
    set_default_size(240, 240);
    m_button1.signal_clicked().connect(sigc::mem_fun(*this, &window::onButton1));
    Glib::RefPtr<Gdk::Pixbuf> buff(Gdk::Pixbuf::create_from_file("/home/thetimbrick/Pictures/pic.jpg", 24, 24, false));
    Glib::RefPtr<Gdk::Pixbuf> back(Gdk::Pixbuf::create_from_file("/home/thetimbrick/Pictures/index.jpeg", 240, 240, false));
    Gtk::Image* im(Gtk::manage(new Gtk::Image()));
    Gtk::Image* background(Gtk::manage(new Gtk::Image()));
    
    im->set(buff);
    background->set(back);
    m_background.add(*background);
    m_button1.set_image(*im);
    m_grid.property_margin_top().set_value(6);
    m_grid.property_margin_bottom().set_value(6);
    m_grid.property_margin_left().set_value(6);
    m_grid.property_margin_right().set_value(6);
    m_grid.property_column_spacing().set_value(6);
    m_grid.property_row_spacing().set_value(6);
    m_grid.add(m_button1);
    m_grid.add(m_button2);
    m_background.add_overlay(m_grid);
    add(m_background);
    set_border_width(0);
    m_background.show_all();
}

void window::onButton1() {
    std::printf("Button Pressed\n");
}
