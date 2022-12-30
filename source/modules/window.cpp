#include "window.h"

Window::Window()
: m_button("Hello World")   // creates a new button with label "Hello World".
{
  // Sets the margin around the button.
  m_button.set_margin(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  m_button.signal_clicked().connect(sigc::mem_fun(*this,
              &Window::on_button_clicked));

  // This packs the button into the Window (a container).
  set_child(m_button);
}

Window::~Window()
{
}

void Window::on_button_clicked()
{
  std::cout << "Hello World" << std::endl;
  std::vector<std::string> test;
  test.push_back("test");
  std::cout << test[0] << std::endl;
 }