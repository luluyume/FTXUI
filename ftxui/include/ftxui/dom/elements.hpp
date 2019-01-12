#ifndef FTXUI_DOM_ELEMENTS_HPP
#define FTXUI_DOM_ELEMENTS_HPP

#include <functional>

#include "ftxui/dom/node.hpp"
#include "ftxui/screen/color.hpp"

namespace ftxui {

using Element = std::unique_ptr<Node>;
using Elements = std::vector<Element>;
using Decorator = std::function<Element(Element)>;

// --- Layout ----
Element vbox(Elements);
Element hbox(Elements);
Element dbox(Elements);

// -- Flexibility --
Element filler();
Element flex(Element);
Decorator size(size_t width, size_t height);

// --- Widget --
Element text(std::wstring text);
Element separator();
Element gauge(float ratio);
Element frame(Element);
Element window(Element title, Element content);
Element spinner(int charset_index, size_t image_index);

// -- Decorator ---
Element bold(Element);
Element dim(Element);
Element inverted(Element);
Element underlined(Element);
Element blink(Element);

Decorator color(Color);
Decorator bgcolor(Color);
Element color(Color, Element);
Element bgcolor(Color, Element);

// --- Util ---
Element hcenter(Element);
Element vcenter(Element);
Element center(Element);
Element align_right(Element);

// --- Util ---
Element nothing(Element element);

// Pipe elements into decorator togethers.
// Examples: text("ftxui") | bold | underlined;
Element operator|(Element, Decorator);
Decorator operator|(Decorator, Decorator);

// Make container able to take any number of children as input.
#include "take_any_args.hpp"
TAKE_ANY_ARGS(vbox)
TAKE_ANY_ARGS(hbox)
TAKE_ANY_ARGS(dbox)

};  // namespace ftxui

#endif /* end of include guard: FTXUI_DOM_ELEMENTS_HPP */